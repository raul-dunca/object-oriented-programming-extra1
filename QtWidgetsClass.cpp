#include "QtWidgetsClass.h"

QtWidgetsClass::QtWidgetsClass(Service& s, Driver d,QWidget *parent)
	: QWidget(parent),serv{s},d{d}
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->d.get_name()));
	this->serv.addObserver(this);
	this->populate();
	this->ui.scoreabel->setText(QString::fromStdString(to_string(this->d.get_score())));
	this->ui.laltitudeLabel->setText(QString::fromStdString(to_string(this->d.get_laltitude())));
	this->ui.longitudeLabel->setText(QString::fromStdString(to_string(this->d.get_longitude())));
	this->ui.statusLabel->setText(QString::fromStdString(this->d.get_status()));
	if (this->d.get_status() == "baby")
	{
		this->ui.listWidget->setStyleSheet("background-color: yellow");
	}
	if (this->d.get_status() == "grown-up")
	{
		this->ui.listWidget->setStyleSheet("background-color: blue");
	}
	if (this->d.get_status() == "knight")
	{
		this->ui.listWidget->setStyleSheet("background-color: green");
	}
	QApplication::connect(this->ui.addReport, &QPushButton::clicked, this, &QtWidgetsClass::add);
	QApplication::connect(this->ui.validateButton, &QPushButton::clicked, this, &QtWidgetsClass::validate);
	
}

QtWidgetsClass::~QtWidgetsClass()
{
}
