unsigned int input,x,kontrola;

void setup() {
	Serial.begin(9600);
}

void loop() {
	if(Serial.available()){
		input = Serial.readString().toInt();
		kontrola = input;
		if (input>0&&input<9999){
			if (input == 2 || input == 1){	Serial.print(input);Serial.println(" je prvocislo.");}else{
				Serial.print("Rozklad cisla ");Serial.print(input);Serial.print(" na prvocisla: ");
				while (input%2==0){
					Serial.print("2 ");
					input=input/2;}
				
				for (x=3;x<input; x=x+2){
					while (input%x == 0){
						Serial.print(x);Serial.print(" ");
						input = input/x;
					}}
				
				if (input > 2){
					Serial.print(input); if(x==kontrola){
						Serial.println(" je prvocislo.");}
				}
				Serial.println(" ");
			}}else{	Serial.println("spatne cislo");}
	}}
