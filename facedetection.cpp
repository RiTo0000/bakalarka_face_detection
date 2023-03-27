#include "facedetection.h"

FaceDetection::FaceDetection()
{
    frontalFace_casc_clasif.load("D:/Desktop/School/3.Rocnik/Bakalarka/program/Qt_Face_Detection/haarcascades/haarcascade_frontalface_default.xml");
    eye_glasses_casc_clasif.load("D:/Desktop/School/3.Rocnik/Bakalarka/program/Qt_Face_Detection/haarcascades/haarcascade_eye_tree_eyeglasses.xml");
    eye_casc_clasif.load("D:/Desktop/School/3.Rocnik/Bakalarka/program/Qt_Face_Detection/haarcascades/haarcascade_eye.xml");

    if (frontalFace_casc_clasif.empty() || eye_casc_clasif.empty())
    {
        cout << "Cascade classifiers not loaded" << endl;
    }
}

void FaceDetection::DetectPhoto()
{
    string path = "D:/Desktop/School/3.Rocnik/Bakalarka/program/Qt_Face_Detection/TestFiles/test.jpg";
    Mat img, detectedImage;
    img = imread(path);
    detectedImage = this->detectFace(img);
    imshow("Testovaci image", img);
//    imshow("Rozpoznany image", detectedImage);
    waitKey(0);
}

void FaceDetection::DetectLiveCamera()
{
    VideoCapture webcam(0);
    Mat img, detected_image;
    int exit_key = -1;
    namedWindow("Webcam", WINDOW_AUTOSIZE);

    while (true)
    {
        webcam.read(img);
        detected_image = this->detectFace(img);
        imshow("Webcam", img);
        exit_key = waitKey(1);
        if (exit_key == 27) {
            break;
        }
        exit_key = getWindowProperty("Webcam", WND_PROP_VISIBLE);
        if (exit_key == 0) {
            break;
        }
    }
    destroyWindow("Webcam");
}

void FaceDetection::DetectMultiplePhotos(QString dir, QStringList photos, QProgressBar *progress)
{
    Mat img, detectedImage;
    QString photo;
    String path, resultPath;
    bool test;
    double progressValue = 0.00, forIter = 0.00, photosLength = photos.length();
    foreach (photo, photos) {
        forIter++;
        progressValue = ( forIter / photosLength ) * 100;
        path = photo.toStdString();
        img = imread(path);
        resultPath = dir.toStdString() + path.substr(path.find_last_of("/"));
        detectedImage = this->detectFace(img);
        test = imwrite(resultPath, detectedImage);
        progress->setValue(progressValue);
//        imshow("UndetectedPhoto",img);
//        imshow("DetectedPhoto", detectedImage);
//        waitKey(0);

    }
}

FaceDetection::~FaceDetection()
{

}

Mat FaceDetection::detectFace(Mat &img)
{
    vector<Rect> faces, eyes;
    Mat grayImage;

    cvtColor(img, grayImage, COLOR_BGR2GRAY);

    Mat detectedFace;

    frontalFace_casc_clasif.detectMultiScale(grayImage, faces, 1.1, 10);

    for (int i = 0; i < faces.size(); i++) {
//        detectedFace = detectedImage(faces[i]);
//        eye_casc_clasif.detectMultiScale(detectedFace, eyes, 1.1, 10);
        //select fase pre detekciu oci
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 2);

        detectedFace = grayImage(faces[i]);
        eye_casc_clasif.detectMultiScale(detectedFace, eyes, 1.1, 10);
        for (int j = 0; j < eyes.size(); ++j) {
//            Point center_of_detected_eye(eyes[j].x + eyes[j].width / 2, eyes[j].y + eyes[j].height / 2);
            Point center_of_detected_eye(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
            circle(img, center_of_detected_eye, eyes[j].height / 2, Scalar(255, 0, 0), 2);
        }
        if (eyes.size() == 0) {
            eye_glasses_casc_clasif.detectMultiScale(detectedFace, eyes, 1.1, 10);
            for (int j = 0; j < eyes.size(); ++j) {
    //            Point center_of_detected_eye(eyes[j].x + eyes[j].width / 2, eyes[j].y + eyes[j].height / 2);
                Point center_of_detected_eye(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
                circle(img, center_of_detected_eye, eyes[j].height / 2, Scalar(0, 255, 0), 2);
            }
        }
    }

    return img;
}

