#ifndef FACEDETECTION_H
#define FACEDETECTION_H

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include <opencv2/objdetect.hpp>

#include <QFileDialog>
#include <QProgressBar>

using namespace cv;
using namespace std;

class FaceDetection
{
public:
    FaceDetection();
    void DetectPhoto();
    void DetectLiveCamera();
    void DetectMultiplePhotos(QString dir, QStringList photos, QProgressBar *progress);
    ~FaceDetection();
private:
    CascadeClassifier frontalFace_casc_clasif;
    CascadeClassifier eye_casc_clasif;
    CascadeClassifier eye_glasses_casc_clasif;
    Mat detectFace(Mat &img);
};

#endif // FACEDETECTION_H
