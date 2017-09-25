#include <math.h>

#define SENS_PIN 0

int tab[200][2] = {
  { -10 , 0 },
{ 0 , -273 },
{ 10 , -55 },
{ 20 , -45 },
{ 30 , -39 },
{ 40 , -35 },
{ 50 , -31 },
{ 60 , -28 },
{ 70 , -25 },
{ 80 , -23 },
{ 90 , -21 },
{ 100 , -19 },
{ 110 , -17 },
{ 120 , -15 },
{ 130 , -13 },
{ 140 , -12 },
{ 150 , -10 },
{ 160 , -9 },
{ 170 , -8 },
{ 180 , -6 },
{ 190 , -5 },
{ 200 , -4 },
{ 210 , -3 },
{ 220 , -2 },
{ 230 , -1 },
{ 240 , 0 },
{ 250 , 1 },
{ 260 , 2 },
{ 270 , 3 },
{ 280 , 4 },
{ 290 , 5 },
{ 300 , 6 },
{ 310 , 6 },
{ 320 , 7 },
{ 330 , 8 },
{ 340 , 9 },
{ 350 , 10 },
{ 360 , 11 },
{ 370 , 12 },
{ 380 , 13 },
{ 390 , 14 },
{ 400 , 15 },
{ 410 , 16 },
{ 420 , 16 },
{ 430 , 17 },
{ 440 , 18 },
{ 450 , 19 },
{ 460 , 20 },
{ 470 , 21 },
{ 480 , 22 },
{ 490 , 23 },
{ 500 , 23 },
{ 510 , 24 },
{ 520 , 25 },
{ 530 , 26 },
{ 540 , 27 },
{ 550 , 28 },
{ 560 , 29 },
{ 570 , 30 },
{ 580 , 31 },
{ 590 , 32 },
{ 600 , 33 },
{ 610 , 34 },
{ 620 , 35 },
{ 630 , 36 },
{ 640 , 37 },
{ 650 , 38 },
{ 660 , 39 },
{ 670 , 40 },
{ 680 , 41 },
{ 690 , 42 },
{ 700 , 43 },
{ 710 , 44 },
{ 720 , 45 },
{ 730 , 47 },
{ 740 , 48 },
{ 750 , 49 },
{ 760 , 50 },
{ 770 , 52 },
{ 780 , 53 },
{ 790 , 55 },
{ 800 , 56 },
{ 810 , 58 },
{ 820 , 59 },
{ 830 , 61 },
{ 840 , 63 },
{ 850 , 65 },
{ 860 , 67 },
{ 870 , 69 },
{ 880 , 72 },
{ 890 , 74 },
{ 900 , 77 },
{ 910 , 80 },
{ 920 , 83 },
{ 930 , 86 },
{ 940 , 90 },
{ 950 , 95 },
{ 960 , 100 },
{ 970 , 106 },
{ 980 , 114 },
{ 990 , 124 }
};

// Hard way to calculate the Temp
int Calcul_Temp(int RawADC)
{
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;
 return (Temp);
}

// Display the tab like in Excel
void createTab()
{
 int i = 0;
 while (i < 1000)
  {
    Serial.print("{ ");
    Serial.print(i);
    Serial.print(" , ");
    Serial.print(int(Calcul_Temp(i)));
    Serial.println(" },");
    i = i + 10;
  }
  delay(10000000);
}

// Esay way to calculate the temp with the tab
int Calcul_Temp_Tab(int RawADC)
{
 int i = 0;
 while(tab[i][0] < RawADC)
 {
  i++;
 }
 return (tab[i][1]);  
}

// Function for unit_testing
void Unit_Test()
{
  int adc;
  adc = 1;
  while( adc<990) {
    int temp = Calcul_Temp_Tab(adc);
    Serial.print(adc);
    Serial.print(" , ");
    Serial.println(temp);
    adc = adc + 1;
  }
}

void setup() {
 Serial.begin(57600);
 Unit_Test();
 delay(10000000);
}

void loop()
{
 int RawADC = analogRead(SENS_PIN);
 Serial.print(RawADC);
 Serial.print(" ");
 Serial.println(Calcul_Temp_Tab(RawADC));
 delay(1000);
}
