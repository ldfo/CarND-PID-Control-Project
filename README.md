# PID Controller
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)


## The Project
The main objective of this project is to write a PID controller and optimize hyperparameters for the test track.

## Describe the effect each of the P, I, D components had in your implementation.

The Proportional Integral Derivative is a commonly used method to control 

### Proportional term

> The proportional is just an output value that is proportional to the current error value.
The proportional term is given by:

>P_out = Kp * crosstrack_error
>Kp is called the proportional gain constant.
>When we set Kp to a very large value the output can become unstable. In contrast a small Kp will result in small output response to a large input error and a less sensitive controller.

### Integral term

>The contribution from the integral term is proportional to both the magnitude of the error and the duration of the error. 

>The integral term is given by
I_out = Ki * integral_error

>The integral term accelerates the movement of the process towards setpoint and eliminates the residual steady-state error that occurs when the proportional term is too high.

### Differential term

> The derivative term is the component that reduces the difference value of error. This acts as a dampener for the overshooting of the P component steering the car lightly to the other direction.

>The derivative term is given by
D_out = Kd * derivative_error


## Fine tuning hyperparameters

>For choosing hyperparameters I started with values I suspected were ok, I started with a very high Kp but I observed big oscilations on the steering. Then I started to dial up the Differential term. I got good results with Kp around 0.2 and Kd around 2. I started with a small Ki term and started to go up but I observed worse results so I left it at 0.001. 
After a while of trial and error I arrived at Kp=0.195, Ki=0.001 and Kd=2.1

>As a next step I want to implement a more robust method of calculating the hyperparameters.