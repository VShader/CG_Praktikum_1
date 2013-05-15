#ifndef VERTEXMANIPULATIONWIDGET_H
#define VERTEXMANIPULATIONWIDGET_H

#include <QWidget>
#include <QSignalMapper>
#include <QToolButton>


namespace Ui {
    class VertexManipulationWidget;
}


class VertexManipulationWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::VertexManipulationWidget *ui;
    void init();
    void setButtonColor(QToolButton * const button, const QColor &color);

public:
    explicit VertexManipulationWidget(QWidget *parent = NULL);
    ~VertexManipulationWidget();

public slots:
    void setVertexColor();

signals:
    void valueChanged_1(double value);

};

#endif  //VERTEXMANIPULATIONWIDGET_H
