int pinsOut[] = {10, 9, 8, 14, 13, 12, 11, 15};
unsigned char pos = 0;
unsigned char pos2 = 7;
int pinsIn = 7;

void setup() {
	// put your setup code here, to run once:
	for (int i=0; i<8; i++){
		pinMode(pinsOut[i], OUTPUT);}
	pinMode(pinsIn, INPUT);
}

void loop() {
	if(digitalRead(pinsIn)){
		digitalWrite(pinsOut[pos2], HIGH);
		digitalWrite(pinsOut[pos],HIGH);
		if (++pos > 7) pos = 0;
		digitalWrite(pinsOut[pos],LOW);
		delay(200);
	}
	else {
		digitalWrite(pinsOut[pos],HIGH);
		digitalWrite(pinsOut[pos2],HIGH);
		if (--pos2 < 0) pos2 = 7;
		digitalWrite(pinsOut[pos2],LOW);
		delay(200);
	}
	
}
