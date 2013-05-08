#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>

class MyPanelOpenGL : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyPanelOpenGL(QWidget *parent = 0);
    
signals:
    
public slots:
    void changeSides(int sides);
    void changeRadius(double radius);

private:
    int sides;
    double radius;


protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    
};

#endif // MYPANELOPENGL_H
