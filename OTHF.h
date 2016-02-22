/**********************************************************************************************************************
Copyright 2016 Henry Cerbone

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

|-----------------------------------------------------------------------------------------------------------------------|

The following define statement allows us to help teams without an autonomous score points.This can be very important for
teams as it allows for better alliance selectability and for the winning of autonomous.We hope to rewrite this file every
year to better fit the game.The statement below simply uses the statement DriveMotors to allow for an easily configurable
autonomous code that is also easy to reference.
*************************************************************************************************************************/
#pragma systemFile
#define DriveMotors(x,t)  do{\
																switch(t)\{//Remember to alter the motor ports based on the teams wiring
															case D :\
																motor[port1]=x;\
																motor[port2]=x;\
																motor[port3]=-x;\
																motor[port4]=-x;\
																break;\
															case F :\
																motor[port5]=x;\
																motor[port6]=x;\
																break;\
															case A :\
																motor[port7]=x;\
																motor[port8]=x;\
																break;\}
														}while(0)
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
The following funtion was created to better evaluate wait time in relation ot distance traveled for robots in need.
The formula simply takes the variables drive base, wheel diameter, and gear ratio to calculate the time it would
take the given robot to travel the diagonal of the field from the alliance starting tile.  It does this by calculating
distance robot must travel in terms of number of displacement then finds the amount displace per wheel revolution.
Using these two numbers the function calculates wait time by rewriting the formula speed = distance/time.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
float AutoDriveCalc(float driveBase, float wheelDiameter, float gearRatio)
{
	float travelDistance=15.6205/driveBase;
	float velcoityPerMsecond=wheelDiameter*PI*(0.00166*gearRatio);
	float waitTime=travelDistance/velcoityPerMsecond;
	return waitTime;}
/*Note: If you have any questions feel free to email the creator of this file at theSTEMkid6965@gmail.com
Please give credit if reused in later seasons to:
Henry Cerbone on behalf of the ftcExchangeStudents 96965*/
