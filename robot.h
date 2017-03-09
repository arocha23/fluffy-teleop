#ifndef ROBOT
#define ROBOT

#include <WPILib.h>
#include <iostream>
#include <cmath>
#include "CANTalon.h"

#define A_BUTTON 1
#define B_BUTTON 2
#define X_BUTTON 3
#define Y_BUTTON 4
#define RB_BUTTON 5
#define LB_BUTTON 6
#define BACK_BUTTON 7
#define START_BUTTON 8
#define ANALOG_BUTTON_CLICK_RIGHT 9
#define ANALOG_BUTTON_CLICK_LEFT 10

#define AXIS_ANALOG_RIGHT_X 1
#define AXIS_ANALOG_LEFT_X 2
#define AXIS_ANALOG_RIGHT_Y 3
#define AXIS_ANALOG_LEFT_Y 4
#define AXIS_TRIGGER_LEFT 5
#define AXIS_TRIGGER_RIGHT 6

inline double dabs(double d) { return d > 0.0 ? d : -d; } // Absolute value of a double precision floating point number
inline bool IsReasonable(double axisVal) { return dabs(axisVal) > 0.2; } // Ensures the axis is intentionally engaged
inline float square(double num) { return num * num; } //Return the square of the the given number

using namespace std;

class Robot: public IterativeRobot 
{
private:
    Joystick Operator;
    Joystick Driver;
    CANTalon FrontLeftDrive;
    CANTalon FrontRightDrive;
    CANTalon BackLeftDrive;
    CANTalon BackRightDrive;
    RobotDrive DriveTrain;
    
    double moveVal;
    double turnVal;
    
public:
    Robot();
    void DisabledInit();
    void RobotInit();
    void AutonomousInit();
    void AutonomousPeriodic();
    void TeleopInit();
    void TeleopPeriodic();
    
    void SetDriveMotors(float left, float right);
    void ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs);
    
    };
#endif
    
