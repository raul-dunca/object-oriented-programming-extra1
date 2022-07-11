#pragma once

#include <QWidget>
#include "ui_QtWidgetsClass.h"
#include "Observer.h"
#include "Service.h"
#include <cmath>
#include <QMessageBox>

class QtWidgetsClass : public QWidget,public Observer
{
	Q_OBJECT

public:
	QtWidgetsClass(Service& s,Driver d,QWidget *parent = Q_NULLPTR);
	~QtWidgetsClass();
	void populate()
	{
		
		this->ui.listWidget->clear();
		for (auto r : this->serv.get_reports_serv())
		{
			if (abs(r.get_laltitude() - this->d.get_laltitude()) <= 10 and abs(r.get_longitude() - this->d.get_longitude() <= 10))
			{
				
				auto item = new QListWidgetItem{ QString::fromStdString("Report: " + r.get_description() + ", at location: " + to_string(r.get_laltitude()) + " - " + to_string(r.get_longitude()) + ", reporter: " + r.get_reporter() + "and valid: " + r.get_validated()) };
				this->ui.listWidget->addItem(item);
			}
		}
	}
	void add()
	{
		string s = this->ui.descriptionEdit->text().toStdString();
		string lal= this->ui.laltitudeEdit->text().toStdString();
		string lon = this->ui.longitudeEdit->text().toStdString();
		if (s == "" or lal=="" or lon=="")
		{
			QMessageBox m;
			m.critical(0, "Error", "Please fill all the line edits!");
			m.setFixedSize(500, 200);
			return;
		}
		else
		{
			int la = stoi(lal);
			int lo = stoi(lon);
			if (abs(la - this->d.get_laltitude()) > 10 or abs(lo - this->d.get_longitude() > 10))
			{
				QMessageBox m;
				m.critical(0, "Error", "Location to far!!");
				m.setFixedSize(500, 200);
				return;
			}
			else
			{
				this->serv.add_serv(Reports{ s,this->d.get_name(),la,lo,"false" });
			}
		}
	}
	void validate()
	{
		string s = this->ui.descriptionEdit->text().toStdString();
		string lal = this->ui.laltitudeEdit->text().toStdString();
		string lon = this->ui.longitudeEdit->text().toStdString();
		if (s == "" or lal == "" or lon == "")
		{
			QMessageBox m;
			m.critical(0, "Error", "Please fill all the line edits!");
			m.setFixedSize(500, 200);
			return;
		}
		else
		{
			int la = stoi(lal);
			int lo = stoi(lon);
			for (auto r : this->serv.get_reports_serv())
			{
				if (r.get_description() == s and r.get_laltitude() == la and r.get_longitude() == lo)
				{
					if (r.get_validated() == "true")
					{
						QMessageBox m;
						m.critical(0, "Error", "You can validate open reports!");
						m.setFixedSize(500, 200);
						return;
					}
					else
					{
						this->serv.validate_serv(r,this->d);

					}

				}
			}
		}
	}
	void update()override
	{
		for(auto dr: this->serv.get_drivers_serv())
			if (dr.get_name() == this->d.get_name())
			{
				this->d.set_score(dr.get_score());
				this->d.set_status(dr.get_status());
			}
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
	}
private:
	Ui::QtWidgetsClass ui;
	Driver d;
	Service& serv;
};
