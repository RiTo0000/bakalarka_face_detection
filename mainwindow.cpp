#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_detectFromFile_clicked()
{
    // vyber obrazky na detekovanie
    QStringList photos = QFileDialog::getOpenFileNames(
                            this,
                            "Vyber fotografie na detekciu tváre",
                            "/home",
                            "Images (*.png *.xpm *.jpg)");

    if (photos.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Neboli zvolené žiadne fotografie");
        msgBox.setWindowTitle("Chyba");
        msgBox.exec();
        return;
    }

    // vyber directory na detekovane obrazky
    QString dir = QFileDialog::getExistingDirectory(this, tr("Vyber priecinok na spracovane fotografie"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    if (dir.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Nebol zvolený žiaden priečinok na spracované fotografie");
        msgBox.setWindowTitle("Chyba");
        msgBox.exec();
        return;
    }

    face.DetectMultiplePhotos(dir, photos, ui->ProgBar_fromFile, ui->CheckBox_EyeDetection);

}

void MainWindow::on_Btn_detectFromLiveCam_clicked()
{
    face.DetectLiveCamera(ui->CheckBox_EyeDetection);
}

void MainWindow::on_Btn_detectDefaultPhoto_clicked()
{
    // vyber obrazky na detekovanie
    QString photo = QFileDialog::getOpenFileName(
                            this,
                            "Vyber fotografiu na detekciu tváre",
                            "/home",
                            "Images (*.png *.xpm *.jpg)");
    if (photo.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Nebola zvolená žiadna fotografia");
        msgBox.setWindowTitle("Chyba");
        msgBox.exec();
        return;
    }

    face.DetectPhoto(photo, ui->CheckBox_EyeDetection);
}

