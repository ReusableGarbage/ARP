#define Pot1 A0
#define BUZZER_DIO A5

#define OFF HIGH
#define ON LOW

int displayPiny[] = {3,7,11,2,6,10,1,5,9,0,4,8};
//tohle jsou piny pro posledni tri displeje. Prvni displej totiz bude vzdy jen 1 nebo 0.

int analogVystup; // sem se ulozi cislo z analog slideru
int analogArray[4]; // tady se cislo z analog slideru ulozi do array


void setup() 
{
	for (int i=0; i<=12; i++)
		pinMode(i, OUTPUT);
	
	for (int y=0; y<=12; y++)
		digitalWrite(y, LOW); //vsechny displeje nejdrive nastavime na 0
	
	pinMode(A1, OUTPUT); digitalWrite(A1, LOW);
	
	pinMode(BUZZER_DIO, OUTPUT);
	digitalWrite(BUZZER_DIO, OFF);
	
}

void loop() 
{
	
	analogVystup = analogRead(Pot1);
	
	for (int x=3;x>=0;x--)
	{
		analogArray[x]=analogVystup%10;
		analogVystup/=10; //rozdeleni cisla na tisicovky, stovky, desitky a jednotky
	}
	for (int n=1;n<4;n++) //kontroluje cisla na stovkach, desitkach a jednotkach a podle toho nastavi piny
	{
		if (analogArray[n]==1)digitalWrite(displayPiny[n+8],HIGH); //0001 atd
		if (analogArray[n]==2)digitalWrite(displayPiny[n+5],HIGH); 
		if (analogArray[n]==3){	digitalWrite(displayPiny[n+5],HIGH);
			digitalWrite(displayPiny[n+8],HIGH);}
		if (analogArray[n]==4)digitalWrite(displayPiny[n+2],HIGH);
		if (analogArray[n]==5){	digitalWrite(displayPiny[n+2],HIGH);
			digitalWrite(displayPiny[n+8],HIGH);}
		if (analogArray[n]==6){	digitalWrite(displayPiny[n+2],HIGH);
			digitalWrite(displayPiny[n+5],HIGH);}
		if (analogArray[n]==7){	digitalWrite(displayPiny[n+2],HIGH);
			digitalWrite(displayPiny[n+5],HIGH);
			digitalWrite(displayPiny[n+8],HIGH);}
		if (analogArray[n]==8)digitalWrite(displayPiny[n-1],HIGH);
		if (analogArray[n]==9){	digitalWrite(displayPiny[n-1],HIGH);
			digitalWrite(displayPiny[n+8],HIGH);}		
	}
	if(analogArray[0]==1) digitalWrite(A1,HIGH); //tohle checkuje prvni dispej
	digitalWrite(BUZZER_DIO, ON);
	delay(500);

	digitalWrite(BUZZER_DIO, OFF);
	for (int m=0; m<=12; m++) digitalWrite(m, LOW); //resetuje vsechny cisla na nulu
	digitalWrite(A1, LOW);
}