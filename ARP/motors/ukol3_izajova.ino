//MDCMOTOR zapojeny na portu D

int rychlost;

void setup() {
	pinMode(3, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	if (Serial.available()){
		rychlost = Serial.readString().toInt();
		if (rychlost > -1 && rychlost <256){
		 analogWrite(3,rychlost);}else{Serial.println("spatne cislo");}
		}
}

