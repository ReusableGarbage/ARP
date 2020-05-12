
int pins[] = {10, 9, 8, 14, 13, 12, 11, 15};
unsigned char pos = 3;
unsigned int spozdeni;
void setup()  {
	pinMode(0, INPUT);
	pinMode(1, INPUT);
	for(int i=0; i<8; i++){
		pinMode(pins[i], OUTPUT);
	}
} 

void loop(){
	if ( digitalRead(0) == HIGH && digitalRead(1) == HIGH) spozdeni=50;
	if ( digitalRead(0) == LOW && digitalRead(1) == HIGH) spozdeni=100;
	if ( digitalRead(0) == LOW && digitalRead(1) == LOW) spozdeni=500;
	if ( digitalRead(0) == HIGH && digitalRead(1) == LOW) spozdeni=1000;
	digitalWrite(pins[pos], HIGH);//zhasnout LED
	if(++pos > 7) pos = 0;	//posuv na dalsi pozici
	digitalWrite(pins[pos], LOW);	//rozsvitit dalsi
	delay(spozdeni);			//cekani 200ms
}

