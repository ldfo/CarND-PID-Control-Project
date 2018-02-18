#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

	total_error = 0;

	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;

	error_p = 0;
	error_i = 0;
	error_d = 0;
	n_step = 0;
}

void PID::UpdateError(double cte) {
	if (step == 0)
		error_d = 0;

	else
		error_d = cte - error_p;
	error_p = cte;
	error_i += cte;

	total_error += cte*cte;
	step++;
}

double PID::TotalError() {
	return total_error;

}

double PID::GetCorrectionValue() {
	double correction_value;

	correction_value = -( Kp * error_p
						+ Kd * error_d
						+ Ki * error_i);

	return correction_value;
}


