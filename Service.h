#pragma once
#include "Repo.h"
#include "Observer.h"
class Service: public Subject
{
public:
	Service(Repo r) :r{ r }
	{

	}
	vector<Driver> get_drivers_serv()
	{
		return this->r.get_drivers();
	}
	vector<Reports> get_reports_serv()
	{
		return this->r.get_reports();
	}
	void add_serv(Reports r)
	{
		this->r.add(r);
		ofstream g("reports.txt");
		for (auto a : this->get_reports_serv())
		{
			g << a.get_description() << ";" << a.get_reporter() << ";" << a.get_laltitude() << ";" << a.get_longitude() << ";" << a.get_validated() << endl;
		}
		this->notify();
	}
	void validate_serv(Reports r,Driver d)
	{
		this->r.validate(r,d);
		ofstream g("reports.txt");
		for (auto a : this->get_reports_serv())
		{
			g << a.get_description() << ";" << a.get_reporter() << ";" << a.get_laltitude() << ";" << a.get_longitude() << ";" << a.get_validated() << endl;
		}
		this->notify();
	}


private:
	Repo r;
};