unsigned int vstup,sirka,vyska,nahodne,nahodneKonec;
int minimum = 99;
int maximum = 0;
void setup() {
	Serial.begin(9600);
}

void loop() {
	if(Serial.available()){
		vstup = Serial.readString().toInt();
		if(vstup>0&&vstup<11){
			for(vyska=0;vyska<vstup;vyska++){
				for(sirka=0;sirka<vstup-1;sirka++){
					nahodne = random(0,99);
					if (nahodne<minimum)minimum=nahodne;
					if (nahodne>maximum)maximum=nahodne;
					if (nahodne<10){	Serial.print("  ");Serial.print(nahodne);}
					else{	Serial.print(" ");Serial.print(nahodne);}
				}
				nahodneKonec = random(0,99);
				if (nahodneKonec<minimum)minimum=nahodneKonec;
				if (nahodneKonec>maximum)maximum=nahodneKonec;
				if (nahodneKonec<10){	Serial.print("  ");Serial.println(nahodneKonec);}
				else{	Serial.print(" ");Serial.println(nahodneKonec);}
			}
			Serial.print("Maximum: ");Serial.println(maximum);
			Serial.print("Minimum: ");Serial.println(minimum);
			Serial.println("konec");
		}
		else {
			Serial.println("spatne cislo.");
		}
		
	}}
