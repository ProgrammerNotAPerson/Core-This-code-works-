int motor_old=0;
int motor_oldB=0;
int count=0;
int motor_cur=0;
int vel_cur;
int motor_curB=0;
int vel_curB;
int target_vel1;
int target_vel2;
bool power=false;
bool speedSet;
bool speedSetB;
bool shoot=false;
int A1=90;//90 and 77 scored 130
int FA2=77;
int	F1S8=80+(count*2);//farthest
int F2S8=67+(count*2);
int	F1S7=66+(count*2);//speed 7
int	F2S7=53+(count*2);
int	F1S6=61+(count*2);//speed 6
int	F2S6=48+(count*2);
int	F1S5=57+(count*2);//speed 5
int F2S5=44+(count*2);
int	F1S4=51+(count*2);//speed 4
int	F2S4=38+(count*2);
int	F1S3=51+(count*2);//speed 3
int	F2S3=32+(count*2);
int	F1S2=51+(count*2);//speed 2
int F2S2=32+(count*2);
int	F1S1=80+(count*2);//closest
int	F2S1=20+(count*2);
int speed;
task speedControlBottom(){
	while(true){
		if(shoot==true){
			motor_cur=abs(nMotorEncoder[F1]);
			vel_cur=abs(motor_cur-motor_old);
			motor_old=motor_cur;
			if(vel_cur<target_vel1){
				motor[F1]=127;
				speedSet=false;}
			else{
				switch(speed){
				case 9 :
					motor[F1]=A1;
					break;
				case 8 :
					motor[F1]=F1S8;
					break;
				case 7 :
					motor[F1]=F1S7;
					break;
				case 6 :
					motor[F1]=F1S6;
					break;
				case 5 :
					motor[F1]=F1S5;
					break;
				case 4 :
					motor[F1]=F1S4;
					break;
				case 3 :
					motor[F1]=F1S3;
					break;
				case 2 :
					motor[F1]=F1S2;
					break;
				case 1 :
					motor[F1]=F1S1;
					break;
				default :
					motor[F1]=0;}
				speedSet=true;
			}
			wait1Msec(20);}}}
task speedControlTop(){
	while(true){
		if(shoot==true){
			motor_curB=abs(nMotorEncoder[F2]);
			vel_curB=abs(motor_curB-motor_oldB);
			motor_oldB=motor_curB;
			if(vel_curB<target_vel2){
				motor[F2]=127;
				speedSetB=false;}
			else{
				switch(speed){
				case 9 :
					motor[F2]=FA2;
					break;
				case 8 :
					motor[F2]=F2S8;
					break;
				case 7 :
					motor[F2]=F2S7;
					break;
				case 6 :
					motor[F2]=F2S6;
					break;
				case 5 :
					motor[F2]=F2S5;
					break;
				case 4 :
					motor[F2]=F2S4;
					break;
				case 3 :
					motor[F2]=F2S3;
					break;
				case 2 :
					motor[F2]=F2S2;
					break;
				case 1 :
					motor[F2]=F2S1;
					break;
				default :
					motor[F2]=0;}
				speedSetB=true;
}wait1Msec(20);}}}
task LED (){//trigger for shooting balls
	while(true){
		if(speedSet==true&&speedSetB==true&&shoot==true){
			SensorValue(led)=1;
		}
		else{
			SensorValue(led)=0;}}}
task Flywheel8 (){//these tasks allow for continuation of flywheel power
	motor[F1]=F1S8;//this is where the count is added to the motor power
	motor[F2]=F2S8;
	target_vel1=16;
	target_vel2=15;
	speed=8;
	shoot=true;
}
task Flywheel7 (){
	motor[F1]=F1S7;
	motor[F2]=F2S7;
	target_vel1=15;
	target_vel2=14;
	speed=7;
	shoot=true;
}
task Flywheel6 (){
	motor[F1]=F1S6;
	motor[F2]=F2S6;
	target_vel1=14;
	target_vel2=13;
	speed=6;
	shoot=true;
}
task Flywheel5 (){
	motor[F1]=F1S5;
	motor[F2]=F2S5;
	target_vel1=13;
	target_vel2=12;
	speed=5;
	shoot=true;
}
task Flywheel4 (){
	motor[F1]=F1S4;
	motor[F2]=F2S4;
	target_vel1=12;
	target_vel2=11;
	speed=4;
	shoot=true;
}
task Flywheel3 (){
	motor[F1]=F1S3;
	motor[F2]=F2S3;
	target_vel1=11;
	target_vel2=10;
	speed=3;
	shoot=true;
}
task Flywheel2 (){
	motor[F1]=F1S2;
	motor[F2]=F2S2;
	target_vel1=16;
	target_vel2=7;
	speed=2;
	shoot=true;
}
task Trigger (){//trigger for shooting balls
	clearTimer(T1);
	if(shoot==true){
		while(time1[T1]<250){
			motor[servo]=127;}
		motor[servo]=0;}
}
task FlywheelS (){
	motor[F1]=0;
	motor[F2]=0;
	shoot=false;
	count=0;
	target_vel1=0;
	target_vel2=0;
}
void TriggerA (){
	clearTimer(T1);
	while(time1[T1]<250){
		motor[servo]=127;}
	motor[servo]=0;
}
task FlywheelA (){
while(true){
if(power==false){
	motor[F1]=A1;//this is where the count is added to the motor power
	motor[F2]=FA2;
	target_vel1=16;
	target_vel2=15;
	speed=9;
	shoot=true;
}}}
task AutoA (){
while(true){
	if(speedSet==true&&speedSetB==true&&power==false){
		wait1Msec(200);
		TriggerA();}}}
	/*task AutoT (){
	if(speedSet==true&&speedSetB==true){
	clearTimer(T1);
	if(shoot==true){
	while(time1[T1]<250){
	motor[servo]=122;}
	motor[servo]=-127;}}}*/
