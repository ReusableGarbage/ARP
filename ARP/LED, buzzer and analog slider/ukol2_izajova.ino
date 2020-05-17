#define Pot1 18


int displayPiny[] = {3,7,11,17,2,6,10,16,1,5,9,15,0,4,8,14};

int analogVystup; // sem se ulozi cislo z analog slideru
int cisloArray[4]; // tady se cislo z analog slideru ulozi do array
int cislo=0;
int cisloRozklad;


void setup() 
{
	for (int i=0; i<16; i++){
		pinMode(displayPiny[i], OUTPUT);
		digitalWrite(displayPiny[i], LOW);
	} pinMode(12, OUTPUT);
	
}

void loop() 
{
	for (cislo;cislo<10000;cislo++)
	{ 
		analogVystup = analogRead(Pot1);
		cisloRozklad = cislo;
		for (int x=3;x>=0;x--)
		{
			cisloArray[x]=cisloRozklad%10;
			cisloRozklad/=10; //rozdeleni cisla na tisicovky, stovky, desitky a jednotky
		}
		
		for (int n=0;n<4;n++)
		{
			if (cisloArray[n]==1)digitalWrite(displayPiny[n+12],HIGH); //0001 atd
			if (cisloArray[n]==2)digitalWrite(displayPiny[n+8],HIGH); 
			if (cisloArray[n]==3){	digitalWrite(displayPiny[n+12],HIGH);
				digitalWrite(displayPiny[n+8],HIGH);}
			if (cisloArray[n]==4)digitalWrite(displayPiny[n+4],HIGH);
			if (cisloArray[n]==5){	digitalWrite(displayPiny[n+4],HIGH);
				digitalWrite(displayPiny[n+12],HIGH);}
			if (cisloArray[n]==6){	digitalWrite(displayPiny[n+4],HIGH);
				digitalWrite(displayPiny[n+8],HIGH);}
			if (cisloArray[n]==7){	digitalWrite(displayPiny[n+4],HIGH);
				digitalWrite(displayPiny[n+8],HIGH);
				digitalWrite(displayPiny[n+12],HIGH);}
			if (cisloArray[n]==8)digitalWrite(displayPiny[n],HIGH);
			if (cisloArray[n]==9){	digitalWrite(displayPiny[n],HIGH);
				digitalWrite(displayPiny[n+12],HIGH);}  
		}
		delay(analogVystup); 
		for (int m=0; m<16; m++) digitalWrite(displayPiny[m], LOW);
	}
	cislo=0;
	
}
