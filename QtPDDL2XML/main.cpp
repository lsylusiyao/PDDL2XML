#include "QtPDDL2XML.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication a(argc, argv);
	QtPDDL2XML w;
	w.show();
	return a.exec();
}
