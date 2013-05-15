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
    void vertexChanged(const double x, const double y, const double z, const QColor &color, const int widgetNumber);

};

#endif  //VERTEXMANIPULATIONWIDGET_H
