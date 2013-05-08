#include "vertexManipulationWidget.h"
#include "ui_vertexManipulationWidget.h"
#include <QDebug>
#include <QtGui>


VertexManipulationWidget::VertexManipulationWidget(QWidget *parent) : QWidget(parent),
    ui(new Ui::VertexManipulationWidget)
{
    ui->setupUi(this);

    connect(ui->doubleSpinBox_Vertex_x_0, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_1, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_2, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_3, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_4, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_5, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_6, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_7, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));

    connect(ui->toolButton_Vertex_0, SIGNAL(triggered(QAction*)), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_1, SIGNAL(triggered()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_2, SIGNAL(triggered()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_3, SIGNAL(triggered()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_4, SIGNAL(triggered()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_5, SIGNAL(triggered()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_6, SIGNAL(triggered()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_7, SIGNAL(triggered()), this, SLOT(setVertexColor()));
}

VertexManipulationWidget::~VertexManipulationWidget()
{
    delete ui;
}

void VertexManipulationWidget::setVertexColor()
{
    if(QObject::sender()->objectName() == ui->toolButton_Vertex_0->objectName())
    {
        QColorDialog::getColor();
    }
}

