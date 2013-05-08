#include <QtGui>
#include <QtOpenGL>
#include <GL/glu.h>

#include "cube.h"


VertexButton::VertexButton(QWidget *parent) : QToolButton(parent)
{

}

void VertexButton::setButtonColor(const QColor &color)
{
    int r, g, b, a;
    color.getRgb(&r, &g, &b, &a);
    QString styleSheetStr = QString("* { background-color: rgb(") +
    QString::number(r) + QString(",") + QString::number(g)
    + QString(",") + QString::number(b) + QString(")}");
    this->setStyleSheet(styleSheetStr);
}



Cube::Cube(QWidget *parent)
    : QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));

    rotationX = -21.0;
    rotationY = -57.0;
    rotationZ = 0.0;
    faceColors[0] = Qt::red;
    faceColors[1] = Qt::green;
    faceColors[2] = Qt::blue;
    faceColors[3] = Qt::yellow;

    Point[0] = new VertexPoints(-1.0, -1.0, 1.0, faceColors[1]);   //  4,8 .---. 3,7
    Point[1] = new VertexPoints(1.0, -1.0, 1.0, faceColors[2]);    //      |   |
    Point[2] = new VertexPoints(1.0, 1.0, 1.0 , faceColors[0]);    //  1,5 .---. 2,6
    Point[3] = new VertexPoints(-1.0, 1.0, 1.0, faceColors[3]);

    Point[4] = new VertexPoints(-1.0, -1.0, -1.0, faceColors[0]);
    Point[5] = new VertexPoints(1.0, -1.0, -1.0, faceColors[3]);
    Point[6] = new VertexPoints(1.0, 1.0, -1.0, faceColors[1]);
    Point[7] = new VertexPoints(-1.0, 1.0, -1.0, faceColors[2]);
}

Cube::~Cube()
{
    for(unsigned short i=0; i<8; i++)   delete Point[i];
}

void Cube::initializeGL()
{
    qglClearColor(Qt::black);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void Cube::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat x = GLfloat(width) / height;
    glFrustum(-x, +x, -1.0, +1.0, 4.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

void Cube::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
}

void Cube::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void Cube::mouseMoveEvent(QMouseEvent *event)
{
    GLfloat dx = GLfloat(event->x() - lastPos.x()) / width();
    GLfloat dy = GLfloat(event->y() - lastPos.y()) / height();

    if (event->buttons() & Qt::LeftButton) {
        rotationX += 180 * dy;
        rotationY += 180 * dx;
        updateGL();
    } else if (event->buttons() & Qt::RightButton) {
        rotationX += 180 * dy;
        rotationZ += 180 * dx;
        updateGL();
    }
    lastPos = event->pos();
}

void Cube::mouseDoubleClickEvent(QMouseEvent *event)
{
    int face = faceAtPosition(event->pos());
    if (face != -1) {
        QColor color = QColorDialog::getColor(faceColors[face], this);
        if (color.isValid()) {
            faceColors[face] = color;
            updateGL();
        }
    }
}

void Cube::draw()
{


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(rotationX, 1.0, 0.0, 0.0);
    glRotatef(rotationY, 0.0, 1.0, 0.0);
    glRotatef(rotationZ, 0.0, 0.0, 1.0);

    glBegin(GL_QUAD_STRIP);
        qglColor(Point[3]->color);
        glVertex3fv(Point[3]->vertex);
        qglColor(Point[0]->color);
        glVertex3fv(Point[0]->vertex);
        qglColor(Point[2]->color);
        glVertex3fv(Point[2]->vertex);
        qglColor(Point[1]->color);
        glVertex3fv(Point[1]->vertex);

        qglColor(Point[6]->color);
        glVertex3fv(Point[6]->vertex);
        qglColor(Point[5]->color);
        glVertex3fv(Point[5]->vertex);

        qglColor(Point[7]->color);
        glVertex3fv(Point[7]->vertex);
        qglColor(Point[4]->color);
        glVertex3fv(Point[4]->vertex);

        qglColor(Point[3]->color);
        glVertex3fv(Point[3]->vertex);
        qglColor(Point[0]->color);
        glVertex3fv(Point[0]->vertex);
    glEnd();

    glBegin(GL_QUADS);
        qglColor(Point[7]->color);
        glVertex3fv(Point[7]->vertex);
        qglColor(Point[3]->color);
        glVertex3fv(Point[3]->vertex);
        qglColor(Point[2]->color);
        glVertex3fv(Point[2]->vertex);
        qglColor(Point[6]->color);
        glVertex3fv(Point[6]->vertex);

        qglColor(Point[0]->color);
        glVertex3fv(Point[0]->vertex);
        qglColor(Point[4]->color);
        glVertex3fv(Point[4]->vertex);
        qglColor(Point[5]->color);
        glVertex3fv(Point[5]->vertex);
        qglColor(Point[1]->color);
        glVertex3fv(Point[1]->vertex);
    glEnd();

}

int Cube::faceAtPosition(const QPoint &pos)
{
    const int MaxSize = 512;
    GLuint buffer[MaxSize];
    GLint viewport[4];

    makeCurrent();

    glGetIntegerv(GL_VIEWPORT, viewport);
    glSelectBuffer(MaxSize, buffer);
    glRenderMode(GL_SELECT);

    glInitNames();
    glPushName(0);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix(GLdouble(pos.x()), GLdouble(viewport[3] - pos.y()),
                  5.0, 5.0, viewport);
    GLfloat x = GLfloat(width()) / height();
    glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
    draw();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    if (!glRenderMode(GL_RENDER))
        return -1;
    return buffer[3];
}


void Cube::ChangeVertex(const GLfloat x, const GLfloat y, const GLfloat z, const QColor &color, const int widgetNumber)
{
    /*
    this->vertex[0] = x;
    this->vertex[1] = y;
    this->vertex[2] = z;
    this->color = color;
    */
}
