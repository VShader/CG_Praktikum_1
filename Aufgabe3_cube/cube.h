#ifndef Cube_H
#define Cube_H

#include <QGLWidget>

class VertexPoints : public QObject{
    Q_OBJECT

public:
    VertexPoints(GLfloat x, GLfloat y, GLfloat z, const QColor &color) : vertex({x, y, z}),
       color(color) {}
    QColor color;
    GLfloat vertex[3];

public slots:
    void ChangeVertex(GLfloat x, GLfloat y, GLfloat z, const QColor &color)
    {
        this->vertex[0] = x;
        this->vertex[1] = y;
        this->vertex[2] = z;
        this->color = color;
    }
};



class Cube : public QGLWidget
{
    Q_OBJECT

public:
    Cube(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

private:
    void draw();
    int faceAtPosition(const QPoint &pos);

    GLfloat rotationX;
    GLfloat rotationY;
    GLfloat rotationZ;
    QColor faceColors[4];
    QPoint lastPos;
};

#endif
