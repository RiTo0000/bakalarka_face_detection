#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <facedetection.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Btn_detectFromFile_clicked();

    void on_Btn_detectFromLiveCam_clicked();

    void on_Btn_detectDefaultPhoto_clicked();

private:
    Ui::MainWindow *ui;
    FaceDetection face;
};
#endif // MAINWINDOW_H
