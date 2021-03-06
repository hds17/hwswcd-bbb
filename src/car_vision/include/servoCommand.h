#ifndef SERVOCOMMAND_H_
#define SERVOCOMMAND_H_

// car model parameter
#define MODEL_LENGTH 30 // cm
#define MODEL_WIDTH 20 // cm
#define CARTOX_MAX_SPEED 0x7F // max speed value of CARTOX

#include <math.h>
#include "servoControl.h"

class servoCommand : servoControl {
  private:
    // every motor need another servo id
    int _servoId;
    // turn motor left or right (- or + degree value) 
    // -> in pwm value
    int _servoDegree;
    // motor speed
    // (at the moment this is only a variable for backward and
    // forward motion. 
    // -> in pwm value
    int _servoSpeed;
    // cartox degree value
    int _degree;
    // Set range of the motor
    // - min = minimum distance to obstacle -> turn motor off
    // - max = maximum distance to obstacle -> max motor value
    int _minDist;
    int _maxDist;
    // motor range describes the range to calculate pwm signals
    // for the motor
    float _motorRange;
    /*
     * Calculate PWM value of degree value to change the
     * steering angle
     */
    int calcPWMFromDegree(float degree);
    /*
     * Calculate PWM value of speed input to move the car
     */
    int calcPWMFromSpeed(float speed);
  public:
    /*
     * Constructor set all motor values to "zero" position
     * (car is not moving)
     */
    servoCommand(bool car); //default constructor
    /*
     * Get position (degree value) of servo
     * This function gets the value of the PWM value of duty cycle of the
     * class servoControl and will return at the end only a degree value,
     */
    float getServoPosDeg();
    /*
     * Move forward or backward
     * -> as we have no incremental sensor we can only set a speed value
     *  and the servoControl class will calculate this value in some
     *  PWM signal
     */
    void move(float distance);
    /*
     * Turn left or right in degree
     * right = + degree
     * left = - degree
     */
    void turn(float degree);
    /*
     * Set min and max distance to initialize motor
     */
    void setMinMaxDistance(int min, int max);
    
};
#endif // SERVOCAMMAND_H_
