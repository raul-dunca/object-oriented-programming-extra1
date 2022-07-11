#pragma once
#include <vector>
#include <algorithm>
class Observer
{
public:
	void virtual update() = 0;
	virtual ~Observer() {}
};

class Subject
{
private:
	std::vector<Observer*> observers;

public:
	void notify()
	{
		for (auto o : this->observers)
			o->update();
	}
	void addObserver(Observer* o)
	{
		this->observers.push_back(o);
	}
	void removeObserver(Observer* o)
	{
		auto it = std::find(this->observers.begin(), this->observers.end(), o);
		if (it != this->observers.end())
		{
			this->observers.erase(it);
		}
	}

};