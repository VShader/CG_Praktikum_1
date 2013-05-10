#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Hi";
    connect(ui->dockWidgetContents, SIGNAL(valueChanged_1(double)), this, SLOT(printValue(double)));
//    qDebug() << ui->dockWidgetContents->;

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::printValue(double value)
{
    qDebug() << value;
}

/*
void MainWindow::VertexChanged(const GLfloat x, const GLfloat y, const GLfloat z, const QColor &color, const int widgetNumber)
{
}
*/

