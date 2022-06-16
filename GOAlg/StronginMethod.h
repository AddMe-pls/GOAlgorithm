#pragma once
#include <iostream>
#include <vector>
#include "Task.h"
#include <fstream>

struct Trial {
	double x, y;
};


class StronginMethod {
private:
	
	Task* pTask;
	std::vector<Trial> Trials;
	Trial BestTrial, CurrTrial;
	std::size_t t;
	double eps;
	double r, m;
	std::size_t itercount;
	std::ofstream trialsData;

	void FirstIteration();
	void CalculateNextTrial();
	void CalculateM();
	double CalculateR(int i);
	bool CheckStopCondition();

public:

	StronginMethod(Task* task, double _eps, std::size_t count, double _r) : pTask(task), eps(_eps), itercount(count), r(_r) { Trials.reserve(itercount); }
	void Solve();
	Trial GetOptVal();

};

