#include "VideoFrameGetter.h"
#include <QDir>

VideoFrameGetter::VideoFrameGetter(QString dir)
{
    _frame=NULL;
    _capture=NULL;
    frame_count=0;
    count=0;
    directory_name=dir;
    init();
}
void VideoFrameGetter::init()
{
    QDir dir(directory_name);
    if(dir.exists())
    {
        dir.setFilter(QDir::Files);
        current_files=dir.entryInfoList();
    }
    if(current_files.size()>1)
    {
        current_file=current_files.first();
        _capture=cvCaptureFromAVI(current_file.absoluteFilePath().toStdString().c_str());
    }
}

int  VideoFrameGetter::getCurrent_frame_count()
{
    return frame_count;
}
QString VideoFrameGetter::getCurrent_frame_name()
{
    return current_file.fileName();
}
void VideoFrameGetter::captureNextFrame()
{
    if(_capture)
    {
        _frame=cvQueryFrame(_capture);
        frame_count++;
        if(_frame==NULL && current_files.size()>1)
        {
            current_files.removeFirst();
            current_file=current_files.first();
            _capture=cvCaptureFromAVI(current_file.absoluteFilePath().toStdString().c_str());
            _frame=cvQueryFrame(_capture);
            frame_count=0;
        }
    }
}
IplImage *VideoFrameGetter::getNextFrame()
{
    captureNextFrame();
    return _frame;
}
