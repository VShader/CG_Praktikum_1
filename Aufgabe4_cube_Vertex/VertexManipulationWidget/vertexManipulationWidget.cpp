#include "vertexManipulationWidget.h"
#include "ui_vertexManipulationWidget.h"
#include <QDebug>
#include <QtGui>


VertexManipulationWidget::VertexManipulationWidget(QWidget *parent) : QWidget(parent),
    ui(new Ui::VertexManipulationWidget)
{
    ui->setupUi(this);

    /*
    connect(ui->doubleSpinBox_Vertex_x_0, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_1, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_2, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_3, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_4, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_5, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_6, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_7, SIGNAL(valueChanged(double)), this, SLOT(setVertexColor()));
    */

    mapper = new QSignalMapper(this);
//    mapper->setMapping(ui->toolButton_Vertex_0, );

    connect(ui->toolButton_Vertex_0, SIGNAL(clicked()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_1, SIGNAL(clicked()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_2, SIGNAL(clicked()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_3, SIGNAL(clicked()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_4, SIGNAL(clicked()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_5, SIGNAL(clicked()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_6, SIGNAL(clicked()), this, SLOT(setVertexColor()));
    connect(ui->toolButton_Vertex_7, SIGNAL(clicked()), this, SLOT(setVertexColor()));
    connect(ui->doubleSpinBox_Vertex_x_0, SIGNAL(valueChanged(double)), this, SIGNAL(valueChanged_1(double)));
    ui->doubleSpinBox_Vertex_x_0->value();
}

VertexManipulationWidget::~VertexManipulationWidget()
{
    delete ui;
}

void VertexManipulationWidget::setVertexColor()
{
    QToolButton *tempButton = static_cast<QToolButton *>( sender());
    QColor color = QColorDialog::getColor();
    int r, g, b, a;
    color.getRgb(&r, &g, &b, &a);
    QString styleSheetStr = QString("* { background-color: rgb(") +
    QString::number(r) + QString(",") + QString::number(g)
    + QString(",") + QString::number(b) + QString(")}");
    tempButton->setStyleSheet(styleSheetStr);
}

/*void VertexManipulationWidget::valueChanged(double value)
{
    qDebug() << "Hallo Signal";
}*/

