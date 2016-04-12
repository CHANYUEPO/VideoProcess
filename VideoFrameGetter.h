#ifndef VIDEOFRAMEGETTER_H
#define VIDEOFRAMEGETTER_H
#include "highgui.h"
#include <opencv/cvaux.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/contrib/contrib.hpp"
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
using namespace cv;
class VideoFrameGetter
{
public:
    VideoFrameGetter(QString dir_name);
    IplImage *getNextFrame();
    int getCurrent_frame_count();
    QString getCurrent_frame_name();
private:
    void captureNextFrame();
    void init();
    IplImage *_frame;
    CvCapture *_capture;
    CvCapture *_temp1_capture;
    CvCapture *_temp2_capture;
    int frame_count;
    int count;
    QString directory_name;
    QFileInfo current_file;
    QFileInfoList current_files;
};
#endif // VIDEOFRAMEGETTER_H
