#include "FGDetector.h"
#include <vector>
using namespace cv;
FGDetector::FGDetector()
    :p_mask(0)
{
    SetTypeName("SD");
}
IplImage*FGDetector::GetMask()
{
    return p_mask;
}
void FGDetector::BlobDetection(cv::Mat &img)
{
    // Setup SimpleBlobDetector parameters.
    SimpleBlobDetector::Params params;

    // Change thresholds
//    params.minThreshold = 255;
//    params.maxThreshold = 255;

    // Filter by Area.
    params.filterByArea = true;
    params.minArea = 10;

    // Filter by Circularity
//    params.filterByCircularity = true;
//    params.minCircularity = 0.1;

    // Filter by Convexity
//    params.filterByConvexity = true;
//    params.minConvexity = 0.87;

    // Filter by Inertia
//    params.filterByInertia = true;
//    params.minInertiaRatio = 0.01;

    #if CV_MAJOR_VERSION < 3   // If you are using OpenCV 2

      // Set up detector with params
      SimpleBlobDetector detector(params);

      // You can use the detector this way
      // detector.detect( im, keypoints);

    #else

      // Set up detector with params
      Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);

      // SimpleBlobDetector::create creates a smart pointer.
      // So you need to use arrow ( ->) instead of dot ( . )
      // detector->detect( im, keypoints);

    #endif

    std::vector<KeyPoint> keypoints;
    detector.detect(img,keypoints);
    // Draw detected blobs as red circles.
    // DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
    Mat im_with_keypoints;
    drawKeypoints(img, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
}
void FGDetector::Process(IplImage* img)
{
    Mat frame(img);
    Mat thresh_frame;
    std::vector<Mat>   channels;
    std::vector<Vec4i> hierarchy;
    std::vector<vector<Point> > contours;
    Mat foreGround;
    if (frame.empty())
    {
        std::cerr<<"frame is empty!";
        return;
    }

    mog(frame,foreGround, 0.01);
    IplImage fore = foreGround;
    cvErode(&fore, &fore);
    cvDilate(&fore, &fore,0,3);
    threshold(foreGround, foreGround, 128, 255, CV_THRESH_BINARY);
    //BlobDetection(foreGround);
    thresh_frame = foreGround.clone();
    findContours(thresh_frame, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_TC89_KCOS, Point(0, 0));
    Mat drawing = Mat::zeros(thresh_frame.size(), CV_8UC1);
    for (size_t i = 0; i < contours.size(); i++)
    {

        if (contourArea(contours[i]) > 200)
            drawContours(drawing, contours, i, Scalar::all(255), CV_FILLED, 8,hierarchy);
    }

    //thresh_frame = drawing;


    IplImage tmp = drawing;


    if (!p_mask)

        p_mask = cvCreateImage(cvGetSize(&tmp), tmp.depth, 1);


    cvCopy(&tmp, p_mask);
}
void FGDetector::Release()
{
    if (p_mask)
        cvReleaseImage(&p_mask);
}
