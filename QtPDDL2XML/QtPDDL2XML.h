#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtPDDL2XML.h"

class QtPDDL2XML : public QMainWindow
{
	Q_OBJECT

public:
	QtPDDL2XML(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtPDDL2XMLClass ui;
};
