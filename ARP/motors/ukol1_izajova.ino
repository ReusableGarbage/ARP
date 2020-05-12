#include <Stepper.h>
Stepper myStepper(100, 16,17,2,3);            
int vstup;

void setup() {
	myStepper.setSpeed(30);
	Serial.begin(9600);
	
}

void loop() {
	if(Serial.available()){
		vstup= Serial.readString().toInt();
		if (vstup > -101 && vstup < 101){
			myStepper.step(vstup);} else {	Serial.println("spatne cislo");}
		
	}}

