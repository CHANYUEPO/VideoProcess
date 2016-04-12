#ifndef FGDETECTOR_H
#define FGDETECTOR_H
#include "highgui.h"
#include <opencv/cvaux.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/contrib/contrib.hpp"
class FGDetector: public CvFGDetector
{
public:
    FGDetector();
    virtual IplImage* GetMask();
    virtual void Process(IplImage* img);
    virtual void Release();
    virtual void BlobDetection(cv::Mat &img);
private:
    IplImage * p_mask;
    cv::BackgroundSubtractorMOG2 mog;
};

#endif // FGDETECTOR_H
