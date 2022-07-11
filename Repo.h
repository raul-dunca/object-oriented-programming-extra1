#pragma once
#include "Domain.h"
#include<vector>
#include <fstream>
#include <sstream>
class Repo
{
public:
	Repo()
	{
		ifstream f("drivers.txt");
		string buffer;
		string n, st, la, lo, sc;
		while (getline(f, buffer))
		{
			stringstream ss(buffer);
			getline(ss, n, ';');
			getline(ss, st, ';');
			getline(ss, la, ';');
			getline(ss, lo, ';');
			getline(ss, sc, ';');
			this->drivers.push_back(Driver{ n,st,stoi(la),stoi(lo),stoi(sc) });
		}
		ifstream r("reports.txt");
		string buffer2;
		string d, rn, lal, lon, val;
		while (getline(r, buffer))
		{
			stringstream sss(buffer);
			getline(sss, d, ';');
			getline(sss, rn, ';');
			getline(sss, lal, ';');
			getline(sss, lon, ';');
			getline(sss, val, ';');
			this->reports.push_back(Reports{ d,rn,stoi(lal),stoi(lon),val });
		}

	}
	void add(Reports r)
	{
		this->reports.push_back(r);
	}
	void validate(Reports r,Driver d)
	{
		for (int i = 0; i < this->reports.size(); i++)
		{
			if (this->reports[i].get_description() == r.get_description() and this->reports[i].get_reporter() == r.get_reporter())
			{
				this->reports[i].incr(d.get_name());
				if (this->reports[i].get_validate_cnt() == 3)
				{
					this->reports[i].set_valid();
					for (int j = 0; j < this->reports.size(); j++)
					{
						if (this->drivers[j].get_name() == this->reports[i].get_reporter())
							this->drivers[j].inc_score();
					}
				}
			}
		}
		
	}
	vector<Driver> get_drivers()
	{
		return this->drivers;

	}
	vector<Reports> get_reports()
	{
		return this->reports;
	}
	
	
private:
	std::vector<Driver> drivers;
	std::vector<Reports> reports;
};

