#include "mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

/*
void MainWindow::VertexChanged(const GLfloat x, const GLfloat y, const GLfloat z, const QColor &color, const int widgetNumber)
{
}
*/

