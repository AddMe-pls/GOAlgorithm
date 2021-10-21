#include "StronginMethod.h"

void StronginMethod::FirstIteration() {
	Trial fpoint = { pTask->GetA(), pTask->CalculateFunction(pTask->GetA()) };
	Trial lpoint = { pTask->GetB(), pTask->CalculateFunction(pTask->GetB()) };
	
	Trials.push_back(fpoint);
	Trials.push_back(lpoint);
	
	pTask->CalculateFunction(pTask->GetA()) < pTask->CalculateFunction(pTask->GetB()) ? BestTrial = fpoint : BestTrial = lpoint;
	CurrTrial = lpoint;
	t = 1;
}

void StronginMethod::CalculateNextTrial() {
	CurrTrial.x = (Trials[t].x + Trials[t-1].x) / 2 - (Trials[t].y - Trials[t-1].y) / (2*m);
	CurrTrial.y = pTask->CalculateFunction(CurrTrial.x);
}

void StronginMethod::CalculateM() {
	double M = -1;
	for (std::size_t i = 1; i < Trials.size(); i++) {
		double tmp = fabs((Trials[i].y - Trials[i - 1].y) / (Trials[i].x - Trials[i - 1].x));
		if (tmp > M)
			M = tmp;
	}
	(M == 0) ? m = 1 : m = M * r;
}

double StronginMethod::CalculateR(int i) {
	return (m * (Trials[i].x - Trials[i - 1].x) + pow((Trials[i].y - Trials[i - 1].y), 2) / (m * (Trials[i].x - Trials[i-1].x)) - 2 * (Trials[i].y + Trials[i-1].y));
}

bool StronginMethod::CheckStopCondition() {
	return fabs(Trials[t].x - Trials[t - 1].x) < eps;
}

void StronginMethod::Solve() {
	FirstIteration();
	while (!CheckStopCondition()) {
		CalculateM();
		CalculateNextTrial();
		Trials.insert(Trials.begin() + t, CurrTrial);

		double MaxR = -10000;
		for (std::size_t i = 1; i < Trials.size(); i++) {
			double CurrR = CalculateR(i);
			if (CurrR > MaxR) {
				MaxR = CurrR;
				t = i;
			}
		}
		if (CurrTrial.y < BestTrial.y)
			BestTrial = CurrTrial;
	}
}

Trial StronginMethod::GetOptVal() {
	return BestTrial;
}