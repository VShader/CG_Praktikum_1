#ifndef VERTEXMANIPULATIONWIDGET_H
#define VERTEXMANIPULATIONWIDGET_H

#include <QWidget>
#include <QSignalMapper>


namespace Ui {
    class VertexManipulationWidget;
}


class VertexManipulationWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::VertexManipulationWidget *ui;
    QSignalMapper *mapper;

public:
    explicit VertexManipulationWidget(QWidget *parent = NULL);
    ~VertexManipulationWidget();

public slots:
    void setVertexColor();

signals:
    void valueChanged_1(double value);

};

#endif  //VERTEXMANIPULATIONWIDGET_H
