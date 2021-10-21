#include "Task.h"

double Task::GetA() {
	return A;
}

double Task::GetB() {
	return B;
}

double FTask::CalculateFunction(double x) {
	return -x*sin(x);
}

double STask::CalculateFunction(double x) {
	return -sin(x) - sin(2/3*x);
}

double THTask::CalculateFunction(double x) {
	return 2 * cos(x) - cos(2*x);
}

double FTTask::CalculateFunction(double x) {
	return pow(x, 6) - 15* pow(x, 4) + 27* pow(x, 2) + 250;
}