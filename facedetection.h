#ifndef FACEDETECTION_H
#define FACEDETECTION_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include <opencv2/objdetect.hpp>

#include <QFileDialog>
#include <QProgressBar>
#include <QCheckBox>

using namespace cv;
using namespace std;

class FaceDetection
{
public:
    FaceDetection();
    void DetectPhoto(QString photo, QCheckBox *detectEyes);
    void DetectLiveCamera(QCheckBox *detectEyes);
    void DetectMultiplePhotos(QString dir, QStringList photos, QProgressBar *progress, QCheckBox *detectEyes);
    ~FaceDetection();
private:
    CascadeClassifier frontalFace_casc_clasif;
    CascadeClassifier eye_casc_clasif;
    CascadeClassifier eye_glasses_casc_clasif;
    Mat detectFace(Mat &img, bool detectEyes);
};

#endif // FACEDETECTION_H
