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

    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte) {
    i_error += cte;
    d_error = cte - p_error;
    p_error = cte;
}

double PID::TotalError() {
  // at higher speeds 
    total_error = Kp * p_error
                + Ki * i_error
                + Kd * d_error;
    return total_error;

}