#pragma once
#include <string>
using namespace std;
class Driver
{
public:
	Driver(string n, string s, int lat, int lon, int sc) :name{ n }, status{ s }, latitude{ lat }, longitude{ lon }, score{ sc }
	{

	}
	string get_name()
	{
		return this->name;
	}
	string get_status()
	{
		return this->status;
	}
	int get_laltitude()
	{
		return this->latitude;
	}
	int get_longitude()
	{
		return this->longitude;
	}
	int get_score()
	{
		return this->score;
	}
	void inc_score()
	{
		this->score++;
		if (this->score >= 10)
			this->status = "grown-up";
		if (this->score >= 15)
			this->status = "knight";
	}
	void set_score(int news)
	{
		this->score = news;
	}
	void set_status(string st)
	{
		this->status = st;
	}

private:
	string name;
	string status;
	int latitude;
	int longitude;
	int score;
};

class Reports
{
public:
	Reports(string d, string r, int lal, int lon, string va) :description{ d }, reporter{ r }, latitude{ lal }, longitude{ lon }, validated{ va }
	{

	}
	string get_description()
	{
		return this->description;
	}
	string get_reporter()
	{
		return this->reporter;
	}
	int get_laltitude()
	{
		return this->latitude;
	}
	int get_longitude()
	{
		return this->longitude;
	}
	

	string get_validated()
	{
		return this->validated;
	}
	int get_validate_cnt()
	{
		return this->validate_cnt;
	}
	void incr(string name)
	{
		auto it = std::find(this->whovalidated.begin(), this->whovalidated.end(),name);
		if (it == this->whovalidated.end())
		{
			this->whovalidated.push_back(name);
			this->validate_cnt++;
		}
	}
	void set_valid()
	{
		this->validated = "true";
	}

private:
	string description;
	string reporter;
	int latitude;
	int longitude;
	string validated;
	int validate_cnt = 1;
	std::vector<string> whovalidated;
};
