#include <iostream>
#include <vector>
#include "StronginMethod.h"
#include "Task.h"

int main()
{
    Task* pTask = new FTTask();
    StronginMethod solv(pTask, 0.0001, 500, 2);
    solv.Solve();
    Trial OptVal = solv.GetOptVal();
    std::cout <<"Optimal value F = "<< OptVal.y << std::endl;
    std::cout << "Optimal value x = " << OptVal.x << std::endl;

}
