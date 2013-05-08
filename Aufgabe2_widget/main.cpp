#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("CG Praktikum");

    QPushButton button("Drueck mich!");
    QLabel label("Hallo ich bin ein Label ^^");

    QVBoxLayout vLayout;
    vLayout.addWidget(&label);
    vLayout.addWidget(&button);

    QObject::connect(&button, SIGNAL(clicked()),
                        &app, SLOT(quit()) );

    window.setLayout(&vLayout);
    window.show();

	return app.exec();
}
