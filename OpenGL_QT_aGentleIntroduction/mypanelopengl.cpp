#include "mypanelopengl.h"
#include <cmath>
#include <GL/glu.h>

MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent), sides(3), radius(1.0)
{
    setFormat(QGL::DoubleBuffer | QGL::DepthBuffer);
}

void MyPanelOpenGL::changeSides(int sides)
{
    if(sides != this->sides)
    {
        this->sides = sides;
        this->updateGL();
    }
}

void MyPanelOpenGL::changeRadius(double radius)
{
    if(radius != this->radius)
    {
        this->radius = radius;
        this->updateGL();
    }
}

void MyPanelOpenGL::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void MyPanelOpenGL::resizeGL(int width, int height)
{
    double xMin=0, xMax=10, yMin=0, yMax=10;

    glViewport(0, 0, (GLint)width, (GLint)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1, 1, -1, 1, 0, 0);
    gluOrtho2D(-1, 1, -1, 1);

    if(width > height)
    {
        height = height ? height : 1;
        double newWidth = (xMax - xMin) * width/height;
        double difWidth = newWidth - (xMax - xMin);
        xMin = 0.0 + difWidth/2.0;
        xMax = 10 + difWidth/2.0;
    }
    else
    {
        width = width?width:1;
        double newHeight = (yMax - yMin)*width/height;
        double difHeight = newHeight - (yMax - yMin);
        yMin = 0.0 + difHeight / 2.0;
        yMax = 10 + difHeight / 2.0;
    }

//    glOrtho(xMin, xMax, yMin, yMax, 0, 0);
    gluOrtho2D(xMin, xMax, yMin, yMax);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


void MyPanelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslated(5.0, 5.0, 0.0);
    glLineWidth(1);
    glColor3f(0, 0.7f, 0.7f);

    glBegin(GL_POLYGON);
        for(int i=0; i < sides; i++)
        {
            glVertex2f(radius*cos(i*2*3.14159265/sides),
                       radius*sin(i*2*3.14159265/sides));
        }
    glEnd();


    glLineWidth(2);
    glColor3f(0, 1, 0);

    glBegin(GL_LINE_LOOP);
        for(int i=0; i < sides; i++)
        {
            glVertex2f(radius*cos(i*2*3.14159265/sides),
                       radius*sin(i*2*3.14159265/sides));
        }
    glEnd();
}
