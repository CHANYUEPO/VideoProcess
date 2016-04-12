#include <stdio.h>
#include <cv.h>
#include <ml.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FGDetector.h"
#include <map>
using namespace cv;
using namespace std;
#include "VideoFrameGetter.h"
int main(int argc, char *argv[])
{
    VideoFrameGetter frameGetter("/home/liutong/test");
//    CvCapture *tempCapture=NULL;
//    CvCapture *capture=NULL;
//    capture=cvCaptureFromAVI("/home/liutong/00011.AVI");
//    CvCapture *capture1=cvCaptureFromAVI("/home/liutong/uprightcolor.avi");
//    if(!capture)
//    {
//        cout<<"the video file does'nt exit!"<<endl;
//        return 0;
//    }
    cvNamedWindow("origin_img", WINDOW_AUTOSIZE);
    //cvNamedWindow("pre_img", WINDOW_AUTOSIZE);
      //cvNamedWindow("post_img", WINDOW_AUTOSIZE);
//    cvNamedWindow("final_img", WINDOW_AUTOSIZE);



    //创建BLOBTRACK模块，并设定每个模块值
//    CvBlobTrackerAutoParam1 params;
//    CvBlobTrackerAuto* tracker;
//    FGDetector fg;

//    params.pFG = &fg;
//    params.FGTrainFrames = 0;
//    params.pBD = cvCreateBlobDetectorCC();
//    params.pBT = cvCreateBlobTrackerMS();
//    params.pBTA = cvCreateModuleBlobTrackAnalysisHistPVS();
//    //params.pBTA->SetFileName("analysis.txt");
//    params.pBTGen = cvCreateModuleBlobTrackGen1();
//    params.pBTGen->SetFileName("trajectories.csv");
//    params.pBTPP = cvCreateModuleBlobTrackPostProcKalman();
//    tracker =cvCreateBlobTrackerAuto1(&params);

    //先统计每个blob在前10帧的位置


//    map<int,std::vector<cv::Point2f> > blob_positions_map;

//    map<int,int> blob_oritetaion_map;

//    map<int,int> blob_flag_map;

//    int in=0,out=0;


    IplImage *pImg = frameGetter.getNextFrame();
    while(pImg!=NULL)
    {
//        CvSize scale = cvSize(pImg->width, pImg->height);

//        IplImage* maskImg = cvCreateImage(scale, 8, 1);

//        //设定边界计数区域；
//        float y_min = pImg->height*0.25;
//        float y_max = pImg->height*0.75;
//        float x_min = pImg->width*0.125;
//        float x_max = pImg->width*0.875;


//        Point l_bottom = Point(x_min, y_max);
//        Point r_bottom = Point(x_max, y_max);

        //fg.Process(pImg);
        //IplImage* maskImagtemp = fg.GetMask();
        //cvResize(maskImagtemp, maskImg);
        //tracker->Process(pImg, maskImg);

//        if (pImg)
//        {
//            IplImage*   pI = cvCloneImage(pImg);
//            char        str[1024];
//            CvFont      font;
//            int         i;
//            int         line_type = CV_AA;   // Change it to 8 to see non-antialiased graphics.
//            cvInitFont(&font, CV_FONT_HERSHEY_PLAIN, 0.7, 0.7, 0, 1, line_type);
//            CvSize  TextSize;
//            sprintf(str, "%s", "IN:");
//            CvPoint ppp1 = cvPoint(20, 20);
//            cvGetTextSize(str, &font, &TextSize, NULL);
//            cvPutText(pI, str, ppp1, &font, CV_RGB(0, 255, 255));
//            sprintf(str, "%s", "OUT:");
//            CvPoint ppp2 = cvPoint(20, 30);
//            cvGetTextSize(str, &font, &TextSize, NULL);
//            cvPutText(pI, str, ppp2, &font, CV_RGB(0, 255, 255));
//            sprintf(str, "%d", in);
//            CvPoint ppp3 = cvPoint(70, 20);
//            cvGetTextSize(str, &font, &TextSize, NULL);
//            cvPutText(pI, str, ppp3, &font, CV_RGB(0, 255, 255));
//            sprintf(str, "%d", out);
//            CvPoint ppp4 = cvPoint(70, 30);
//            cvGetTextSize(str, &font, &TextSize, NULL);
//            cvPutText(pI, str, ppp4, &font, CV_RGB(0, 255, 255));
//            Mat bounding;
//            bounding = cv::Mat(pI);
//            Mat maskbounding;
//            maskbounding = cv::Mat(maskImg);

//            //参数为：承载的图像、起始点、结束点、颜色、粗细、线型
//            line(bounding, l_bottom, r_bottom, Scalar(0, 0, 255));
//            //针对每一帧track检测到的blob进行处理
//            cout << tracker->GetBlobNum() << endl;

//            for (int i = tracker->GetBlobNum(); i > 0; i--)
//            {
//                CvSize textsize;//将blobtrtack得到的blob块进行椭圆标注，并加注blob的标号以体现跟踪的效果
//                CvBlob* pB = tracker->GetBlob(i-1);//得到第i-1个blob块
//                CvPoint p = cvPoint(cvRound(pB->x * 256), cvRound(pB->y * 256));
//                CvSize  s = cvSize(MAX(1, cvRound(CV_BLOB_RX(pB) * 256)), MAX(1, cvRound(CV_BLOB_RY(pB) * 256)));
//                int c = cvRound(255 * tracker->GetState(CV_BLOB_ID(pB)));

//                CvPoint p1 = cvPoint(cvRound(pB->x) - cvRound(CV_BLOB_RX(pB)), cvRound(pB->y) - cvRound(CV_BLOB_RY(pB)));
//                CvPoint p2 = cvPoint(cvRound(pB->x) + cvRound(CV_BLOB_RX(pB)), cvRound(pB->y) + cvRound(CV_BLOB_RY(pB)));
//                cvEllipse(pI,p,s,0, 0, 360,CV_RGB(c, 255 - c, 0), cvRound(1 + (3 * 0) / 255), CV_AA, 8);
//                rectangle(maskbounding, p1, p2, Scalar(255, 0, 0));

//                p.x >>= 8;
//                p.y >>= 8;
//                s.width >>= 8;
//                s.height >>= 8;
//                sprintf(str, "%03d", CV_BLOB_ID(pB));
//                cvGetTextSize(str, &font, &TextSize, NULL);
//                p.y -= s.height;
//                cvPutText(pI, str, p, &font, CV_RGB(0, 255, 255));

//               //将每个blob的坐标记录

//                cv::Point2f blob_point((CV_BLOB_CENTER(pB).x),(CV_BLOB_CENTER(pB).y));

//                map<int,std::vector<cv::Point2f> >::iterator it=blob_positions_map.find(CV_BLOB_ID(pB));
//                if(it==blob_positions_map.end())
//                {
//                    std::vector<cv::Point2f> point_list;
//                    point_list.push_back(blob_point);
//                    blob_positions_map[CV_BLOB_ID(pB)]=point_list;
//                    blob_oritetaion_map[CV_BLOB_ID(pB)]=0;
//                    blob_flag_map[CV_BLOB_ID(pB)]=-1;
//                }
//                else
//                {
//                   int size=it->second.size();
//                   if(size>10)
//                   {
//                       if(blob_point.y-it->second.at(0).y>0)
//                       {
//                           blob_oritetaion_map[CV_BLOB_ID(pB)]=1;
//                       }
//                       if(blob_point.y-it->second.at(0).y<0)
//                       {
//                            blob_oritetaion_map[CV_BLOB_ID(pB)]=-1;
//                       }
//                   }

//                  it->second.push_back(blob_point);




//                 }
//                if(blob_flag_map[CV_BLOB_ID(pB)]==-1)
//                {
//                    //判断是否有blob进入边界区域，并且判断了方向，并计
//                    float blob_y = CV_BLOB_CENTER(pB).y;

//                    if (blob_y < y_min && blob_oritetaion_map[CV_BLOB_ID(pB)] == -1)
//                    {
//                         out++;
//                         blob_flag_map[CV_BLOB_ID(pB)]=0;//重置flag防止二次计数
//                    }
//                    if (blob_y > y_max && blob_oritetaion_map[CV_BLOB_ID(pB)] == 1)
//                    {
//                          in++;
//                          blob_flag_map[CV_BLOB_ID(pB)]=0;//重置flag防止二次计数
//                    }

//                }
//                else
//                {
//                    if(blob_flag_map[CV_BLOB_ID(pB)]==0)
//                        blob_flag_map[CV_BLOB_ID(pB)]++;
//                }



//            }
//             map<int,int>::iterator iter;
//             for(iter=blob_flag_map.begin();iter!=blob_flag_map.end();++iter)
//             {
//                 if(iter->second>2)
//                 {


//                     map<int,std::vector<cv::Point2f> >::iterator it=blob_positions_map.find(iter->first);
//                     blob_positions_map.erase(it);
//                     map<int,int>::iterator i=blob_oritetaion_map.find(iter->first);


//                 }
//                 blob_flag_map.erase(iter);



//             }




//            cvShowImage("origin_img", pImg);
//            cvShowImage("pre_img", maskImg);
//            cvShowImage("post_img",pI);

//            pImg = cvQueryFrame(tempCapture);
//            if(!pImg)
//            {
//                tempCapture=capture1;
//            }
//            pImg = cvQueryFrame(tempCapture);
//            cvWaitKey(1);


//       }

        cvShowImage("origin_img", pImg);
       // cvShowImage("pre_img", maskImg);
       // cvShowImage("post_img",pI);
        pImg = frameGetter.getNextFrame();
        cvWaitKey(1);
}
//    cvDestroyAllWindows();
//    if (capture)cvReleaseCapture(&capture);
//    if (params.pBT)cvReleaseBlobTracker(&params.pBT);
//    if (params.pBD)cvReleaseBlobDetector(&params.pBD);
//    if (params.pBTGen)cvReleaseBlobTrackGen(&params.pBTGen);
//    if (params.pBTA)cvReleaseBlobTrackAnalysis(&params.pBTA);
//    if (params.pFG)cvReleaseFGDetector(&params.pFG);
//    if (tracker)cvReleaseBlobTrackerAuto(&tracker);
    return 0;
}
