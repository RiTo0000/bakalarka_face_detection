#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

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
                            "Vyber fotografie na detekciu obrazu",
                            "/home",
                            "Images (*.png *.xpm *.jpg)");

    // vyber directory na detekovane obrazky
    QString dir = QFileDialog::getExistingDirectory(this, tr("Vyber priecinok na spracovane fotografie"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);

    face.DetectMultiplePhotos(dir, photos, ui->ProgBar_fromFile);
}

void MainWindow::on_Btn_detectFromLiveCam_clicked()
{
    face.DetectLiveCamera();
}

void MainWindow::on_Btn_detectDefaultPhoto_clicked()
{
    face.DetectPhoto();
}

