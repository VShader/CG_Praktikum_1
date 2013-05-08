#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
//    void VertexChanged(const GLfloat x, const GLfloat y, const GLfloat z, const QColor &color, const int widgetNumber);
};

#endif // MAINWINDOW_H
