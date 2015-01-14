/*
	_____						_													 _____	 __	 __
 |	__ \				 (_)												/ ____| |	 \/	 |
 | |	| |	 _ __		_	 __		__	 ___	 _ __	 | |			| \	 / |
 | |	| | | '__| | | \ \ / /	/ _ \ | '__| | |			| |\/| |
 | |__| | | |		 | |	\ V /	 |	__/ | |		 | |____	| |	 | |
 |_____/	|_|		 |_|	 \_/		\___| |_|			\_____| |_|	 |_|
                                                                                                                        
Useful functions for using motor enconders and gyro sensors. Input in centimeters is APPROXIMATE!
Written by Ethan Tucker
*/

/*
 __ __   ____  ____   ____   ____  ____   _        ___   _____
|  |  | /    ||    \ |    | /    ||    \ | |      /  _] / ___/
|  |  ||  o  ||  D  ) |  | |  o  ||  o  )| |     /  [_ (   \_ 
|  |  ||     ||    /  |  | |     ||     || |___ |    _] \__  |
|  :  ||  _  ||    \  |  | |  _  ||  O  ||     ||   [_  /  \ |
 \   / |  |  ||  .  \ |  | |  |  ||     ||     ||     | \    |
  \_/  |__|__||__|\_||____||__|__||_____||_____||_____|  \___|
                                                              
*/
//Number of encoder units in one rotation
const int rotation = 1440;

//Circumference of a robot wheel
const float wheelCircumference = 31.902;

//Default gyro sensor offset
int offset = 598;

/*
 _____                          _              ______                      _    _                    
|  ___|                        | |             |  ___|                    | |  (_)                   
| |__   _ __    ___   ___    __| |  ___  _ __  | |_    _   _  _ __    ___ | |_  _   ___   _ __   ___ 
|  __| | '_ \  / __| / _ \  / _` | / _ \| '__| |  _|  | | | || '_ \  / __|| __|| | / _ \ | '_ \ / __|
| |___ | | | || (__ | (_) || (_| ||  __/| |    | |    | |_| || | | || (__ | |_ | || (_) || | | |\__ \
\____/ |_| |_| \___| \___/  \__,_| \___||_|    \_|     \__,_||_| |_| \___| \__||_| \___/ |_| |_||___/
                                                                                                                                                                                                          
*/

//Converts cenimeters to encoder units
int centimetersToUnits(int centimeters)
{
	float rotationPerCm = rotation / wheelCircumference;
	return rotationPerCm * centimeters;
}

//Converts encoder units to cenimeters
int unitsToCentimeters(long units)
{
	float cmPerRotation = wheelCircumference / rotation;	// .02 "cm per units"
	return cmPerRotation * units;
}

//Runs 1 motor for a certain number of encoder units at a certin power
void runMotor(tMotor chosenMotor, int power, int units)
{
	nMotorEncoder[chosenMotor] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[chosenMotor] = power;
	while(abs(nMotorEncoder[chosenMotor]) < units)
	{
	}
	motor[chosenMotor] = 0;
	nMotorEncoder[chosenMotor] = 0;
	wait1Msec(100);
}

//Runs 1 motor for a certain distance in CM at a certin power
void runMotorByCm(tMotor chosenMotor, int power, int cm)
{
	runMotor(chosenMotor, power, centimetersToUnits(cm));
}

//Runs 2 motors for a certain number of encoder units at a certin power
void runTwoMotors(tMotor motor1, tMotor motor2, int power, int units)
{
	nMotorEncoder[motor1] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[motor1] = power;
	motor[motor2] = power;
	while(abs(nMotorEncoder[motor1]) < units)
	{

	}
	motor[motor1] = 0;
	motor[motor2] = 0;
	nMotorEncoder[motor1] = 0;
	wait1Msec(100);
}

//Runs 2 motors for a certain distance in CM at a certin power
void runTwoMotorsByCm(tMotor motor1, tMotor motor2, int power, int cm)
{
	runTwoMotors(motor1, motor2, power, centimetersToUnits(cm));
}

//Runs 4 motors for certain number of encoder units at a certin power
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotors(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power, int units)
{
	nMotorEncoder[motor1] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[motor1] = power;
	motor[motor2] = power;
	motor[motor3] = power;
	motor[motor4] = power;
	while(abs(nMotorEncoder[motor1]) < units)
	{


	}
	motor[motor1] = 0;
	motor[motor2] = 0;
	motor[motor3] = 0;
	motor[motor4] = 0;
	nMotorEncoder[motor1] = 0;
	wait1Msec(100);
}



//Runs 4 motors for a certain distance in CM at a certin power
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsByCm(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power, int cm)
{
	runFourMotors(motor1, motor2, motor3, motor4, power, centimetersToUnits(cm));
}

//Runs 4 motors for a certain number of encoder units at two diffrent powers
//power1 is applied to motors 1 and 3. power2 is applied to motors 2 and 4.
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsWithDifferentPower(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power1, int power2, int units)
{
	nMotorEncoder[motor1] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[motor1] = power1;
	motor[motor2] = power2;
	motor[motor3] = power1;
	motor[motor4] = power2;
	while(abs(nMotorEncoder[motor1]) < units)
	{


	}
	motor[motor1] = 0;
	motor[motor2] = 0;
	motor[motor3] = 0;
	motor[motor4] = 0;
	nMotorEncoder[motor1] = 0;
	wait1Msec(100);
}

//Runs 4 motors for a certain distance in CM at two diffrent powers
//power1 is applied to motors 1 and 3. power2 is applied to motors 2 and 4.
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsWithDifferentPowerByCM(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power1, int power2, int cm)
{
	runFourMotorsWithDifferentPower(motor1, motor2, motor3, motor4, power1, power2, centimetersToUnits(cm));
}

//Runs 4 motors for a certain number of encoder units at a certain powers
//The encoders are not rest afterwards
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsNoReset(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power, int units)
{
	int startVal = nMotorEncoder[motor1];
	if(units < 0)
	{
		units = -units;
	}
	motor[motor1] = power;
	motor[motor2] = power;
	motor[motor3] = power;
	motor[motor4] = power;
	while(abs(nMotorEncoder[motor1] - startVal) < units)
	{


	}
	motor[motor1] = 0;
	motor[motor2] = 0;
	motor[motor3] = 0;
	motor[motor4] = 0;
	wait1Msec(100);
}

//Runs 4 motors for a certain distance in CM at a certain powers
//The encoders are not rest afterwards
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsByCmNoReset(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power, int cm)
{
	runFourMotorsNoReset(motor1, motor2, motor3, motor4, power, centimetersToUnits(cm));
}

/*
   ______                                   ______                          __     _                        
  / ____/   __  __   _____  ____           / ____/  __  __   ____   _____  / /_   (_)  ____    ____    _____
 / / __    / / / /  / ___/ / __ \         / /_     / / / /  / __ \ / ___/ / __/  / /  / __ \  / __ \  / ___/
/ /_/ /   / /_/ /  / /    / /_/ /        / __/    / /_/ /  / / / // /__  / /_   / /  / /_/ / / / / / (__  ) 
\____/    \__, /  /_/     \____/        /_/       \__,_/  /_/ /_/ \___/  \__/  /_/   \____/ /_/ /_/ /____/  
         /____/                                                                                             
*/

//Calibrate the gyro sensor by averaging reading for a turn rate of 0.
void calibrateGyro(tSensors gyro)
{
	int total = 0;
	for(int i = 0; i < 5; i++)
	{
		total += SensorValue(gyro);
	}
	offset = total / 5;
}

//turn the robot in a number of degrees
void turnDegrees(tSensors gyro, tMotor side, int degrees, int power)
{
	motor[side] = power;
	while(degrees > 0)
	{
		wait1Msec(1000);
		int rate = SensorValue(gyro) - offset;
		degrees -= abs(rate);
	}
	motor[side] = 0;
}

//turn the robot in a number of degrees using both motors. The second motor rotates backward.
void turnDegrees(tSensors gyro, tMotor side, tMotor otherSide, int degrees, int power)
{
	motor[side] = power;
	motor[otherSide] = -power;
	while(degrees > 0)
	{
		wait1Msec(1000);
		int rate = SensorValue(gyro) - offset;
		degrees -= abs(rate);
	}
	motor[side] = 0;
	motor[otherSide] = 0;
}

//turn the robot in a number of degrees using two motors on the same side
void turnDegreesSameSide(tSensors gyro, tMotor side, tMotor sideBack, int degrees, int power)
{
	motor[side] = power;
	motor[sideBack] = power;
	while(degrees > 0)
	{
		wait1Msec(1000);
		int rate = SensorValue(gyro) - offset;
		degrees -= abs(rate);
	}
	motor[side] = 0;
	motor[sideBack] = 0;
}

//turn the robot in a number of degrees using four motors.
void turnDegrees(tSensors gyro, tMotor side, tMotor sideBack, tMotor otherSide, tMotor otherSideBack, int degrees, int power)
{
	motor[side] = power;
	motor[otherSide] = -power;
	motor[sideBack] = power;
	motor[otherSideBack] = -power;
	while(degrees > 0)
	{
		wait1Msec(1000);
		int rate = SensorValue(gyro) - offset;
		degrees -= abs(rate);
	}
	motor[side] = 0;
	motor[otherSide] = 0;
	motor[sideBack] = 0;
	motor[otherSideBack] = 0;
}

//Drive foward stablized by the gyro sensor. Gyro sensor must point foward.
void gyroDriveFoward(tSensors gyro, tMotor left, tMotor right, int defaultPower, long msecs)
{
	motor[left] = defaultPower;
	motor[right] = defaultPower;
	while(msecs > 0)
	{
		wait1Msec(1);
		msecs--;
		if(SensorValue(gyro) > offset)//turning right
		{
			motor[left] = motor[left] + 1;
		}
		if(SensorValue(gyro) < offset)//turning left
		{
			motor[right] = motor[right] + 1;
		}
	}
}

//Combine motor encoders and gyro sensors for:
/*
              )    (      (      (         (          )      *      (         )                      (         )       )  
 (  (      ( /(    )\ )   )\ )   )\ )      )\ )    ( /(    (  `     )\ )   ( /(     (        *   )   )\ )   ( /(    ( /(  
 )\))(   ' )\())  (()/(  (()/(  (()/(     (()/(    )\())   )\))(   (()/(   )\())    )\     ` )  /(  (()/(   )\())   )\()) 
((_)()\ ) ((_)\    /(_))  /(_))  /(_))     /(_))  ((_)\   ((_)()\   /(_)) ((_)\  ((((_)(    ( )(_))  /(_)) ((_)\   ((_)\  
_(())\_)()  ((_)  (_))   (_))   (_))_     (_))_     ((_)  (_()((_) (_))    _((_)  )\ _ )\  (_(_())  (_))     ((_)   _((_) 
\ \((_)/ / / _ \  | _ \  | |     |   \     |   \   / _ \  |  \/  | |_ _|  | \| |  (_)_\(_) |_   _|  |_ _|   / _ \  | \| | 
 \ \/\/ / | (_) | |   /  | |__   | |) |    | |) | | (_) | | |\/| |  | |   | .` |   / _ \     | |     | |   | (_) | | .` | 
  \_/\_/   \___/  |_|_\  |____|  |___/     |___/   \___/  |_|  |_| |___|  |_|\_|  /_/ \_\    |_|    |___|   \___/  |_|\_| 
                                                                                                                          
*/
void runTwoMotorsWithGyro(tMotor left, tMotor right, int power, int units)
{
	nMotorEncoder[left] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[left] = power;
	motor[right] = power;
	while(abs(nMotorEncoder[left]) < units)
	{
		if(SensorValue(gyro) > offset)//turning right
		{
			motor[left] = motor[left] + 1;
		}
		if(SensorValue(gyro) < offset)//turning left
		{
			motor[right] = motor[right] + 1;
		}
	}
	motor[left] = 0;
	motor[right] = 0;
	nMotorEncoder[left] = 0;
	wait1Msec(100);
}
