#pragma systemFile
int powerE=0;
task Acquisition (){//task for controlling acquisition
	motor[A]=127;
	motor[A2]=127;
}
task AcquisitionS (){
	motor[A]=0;
	motor[A2]=0;
}
void liftControl (){
	if(vexRT[Btn8U]==1){
			powerE=1;}
		if(vexRT[Btn8D]==1){
			powerE=2;}
		if(vexRT[Btn8D]==0&&vexRT[Btn8U]==0){
			powerE=0;}
		switch (powerE) {
		case 1:
			if(SensorValue(bottomT)==0){
				motor[E]=-127;}
			else{
				motor[E]=0;}
			break;
		case 2:
			if(SensorValue(bottomL)==0){
				motor[E]=127;}
			else{
				motor[E]=0;}
			break;
		case 0:
			motor[E]=0;
			break;
		}}
