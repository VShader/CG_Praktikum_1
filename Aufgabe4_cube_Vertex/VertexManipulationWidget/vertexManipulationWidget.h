#ifndef VERTEXMANIPULATIONWIDGET_H
#define VERTEXMANIPULATIONWIDGET_H

#include <QWidget>


namespace Ui {
    class VertexManipulationWidget;
}


class VertexManipulationWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::VertexManipulationWidget *ui;

public:
    explicit VertexManipulationWidget(QWidget *parent = NULL);
    ~VertexManipulationWidget();

public slots:
    void setVertexColor();

};

#endif  //VERTEXMANIPULATIONWIDGET_H
