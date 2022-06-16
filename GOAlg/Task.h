#pragma once
#include <cmath>
#include <iostream>

class Task
{
protected:
	double A, B;
public:
	virtual double GetA();
	virtual double GetB();
	virtual double CalculateFunction(double x) = 0;
};

class FTask : public Task
{
public:
	FTask() { A = 0; B = 10; };
	double CalculateFunction(double x) override;
};

class STask : public Task
{
public:
	STask() { A = 3.1; B = 20.4; };
	double CalculateFunction(double x) override;
};

class THTask : public Task
{
public:
	THTask() { A =-1.57; B = 6.28; };
	double CalculateFunction(double x) override;
};

class FTTask : public Task
{
public:
	FTTask() { A = -4; B = 4; };
	double CalculateFunction(double x) override;
};

class FITask : public Task
{
public:
	FITask() { A = 0; B = 3; };
	double CalculateFunction(double x) override;
};