#include <math.h>

#define SENS_PIN 0
 
// ADC , Temp , Coef i - 1
int tab[110][3] = {
{ 1 , -8698 , 1860 },
{ 10 , -6032 , 266 },
{ 20 , -5063 , 96 },
{ 30 , -4447 , 61 },
{ 40 , -3985 , 46 },
{ 50 , -3609 , 37 },
{ 60 , -3290 , 31 },
{ 70 , -3010 , 28 },
{ 80 , -2760 , 25 },
{ 90 , -2532 , 22 },
{ 100 , -2323 , 20 },
{ 110 , -2128 , 19 },
{ 120 , -1946 , 18 },
{ 130 , -1774 , 17 },
{ 140 , -1611 , 16 },
{ 150 , -1455 , 15 },
{ 160 , -1306 , 14 },
{ 170 , -1163 , 14 },
{ 180 , -1025 , 13 },
{ 190 , -892 , 13 },
{ 200 , -763 , 12 },
{ 210 , -637 , 12 },
{ 220 , -514 , 12 },
{ 230 , -395 , 11 },
{ 240 , -278 , 11 },
{ 250 , -163 , 11 },
{ 260 , -50 , 11 },
{ 270 , 59 , 10 },
{ 280 , 168 , 10 },
{ 290 , 276 , 10 },
{ 300 , 382 , 10 },
{ 310 , 486 , 10 },
{ 320 , 590 , 10 },
{ 330 , 692 , 10 },
{ 340 , 794 , 10 },
{ 350 , 895 , 10 },
{ 360 , 995 , 10 },
{ 370 , 1095 , 10 },
{ 380 , 1194 , 9 },
{ 390 , 1293 , 9 },
{ 400 , 1391 , 9 },
{ 410 , 1490 , 9 },
{ 420 , 1588 , 9 },
{ 430 , 1686 , 9 },
{ 440 , 1784 , 9 },
{ 450 , 1883 , 9 },
{ 460 , 1981 , 9 },
{ 470 , 2080 , 9 },
{ 480 , 2179 , 9 },
{ 490 , 2279 , 10 },
{ 500 , 2379 , 10 },
{ 510 , 2479 , 10 },
{ 520 , 2581 , 10 },
{ 530 , 2683 , 10 },
{ 540 , 2786 , 10 },
{ 550 , 2889 , 10 },
{ 560 , 2994 , 10 },
{ 570 , 3100 , 10 },
{ 580 , 3207 , 10 },
{ 590 , 3316 , 10 },
{ 600 , 3426 , 11 },
{ 610 , 3537 , 11 },
{ 620 , 3651 , 11 },
{ 630 , 3766 , 11 },
{ 640 , 3883 , 11 },
{ 650 , 4002 , 11 },
{ 660 , 4123 , 12 },
{ 670 , 4247 , 12 },
{ 680 , 4374 , 12 },
{ 690 , 4503 , 12 },
{ 700 , 4636 , 13 },
{ 710 , 4772 , 13 },
{ 720 , 4911 , 13 },
{ 730 , 5055 , 14 },
{ 740 , 5203 , 14 },
{ 750 , 5355 , 15 },
{ 760 , 5512 , 15 },
{ 770 , 5675 , 16 },
{ 780 , 5844 , 16 },
{ 790 , 6020 , 17 },
{ 800 , 6203 , 18 },
{ 810 , 6394 , 19 },
{ 820 , 6594 , 20 },
{ 830 , 6804 , 21 },
{ 840 , 7026 , 22 },
{ 850 , 7260 , 23 },
{ 860 , 7508 , 24 },
{ 870 , 7773 , 26 },
{ 880 , 8057 , 28 },
{ 890 , 8363 , 30 },
{ 900 , 8695 , 33 },
{ 910 , 9058 , 36 },
{ 920 , 9458 , 40 },
{ 930 , 9904 , 44 },
{ 940 , 10407 , 50 },
{ 950 , 10985 , 57 },
{ 960 , 11661 , 67 },
{ 970 , 12475 , 81 },
{ 980 , 13491 , 101 },
{ 990 , 14833 , 134 },
{ 1000 , 16772 , 193 },
{ 1010 , 20114 , 334 },
{ 1020 , 30128 , 1001 },
};

// Hard way to calculate the Temp
float Calcul_Temp(int RawADC)
{
 float Temp;
 float var_c = 3435.0;
 float var_d = 10000.0;
 float var_e = 298.15;
 
 Temp = 1.0 / (( 1.0 / var_e ) + 1.0 / var_c *log(1024.0 / float(RawADC) - 1.0 ));
 
 /*
  * Old calculation methode
  * Temp = log(10000.0*((1024.0/RawADC-1))); 
  * Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  */
 Temp = Temp - 273.15;
 return (Temp);
}

// Display the tab like in Excel
void Create_Tab()
{
 int i = 1;
 int tmp;
 int tmp2 = -27300;
 while (i < 1024)
  {
    Serial.print("{ ");
    Serial.print(int(i));
    Serial.print(" , ");
    /* multiplaction per 100 to transform float from the Excel
    to int and save it into the tab */
    tmp = int(Calcul_Temp(i)* 100);
    Serial.print(tmp);
    Serial.print(" , ");
    Serial.print((tmp - tmp2) / 10);
    Serial.println(" },");
    tmp2 = tmp;
    if (i == 1)
      i = 0;
    i = i + 10;
  }
  delay(10000000);
}

// Esay way to calculate the temp with the tab
float Calcul_Temp_Tab(int RawADC)
{
 int i = 0;
 int res = 0;
 
 while(tab[i][0] < RawADC && i < 990)
 {
  i++;
 }
    if (RawADC % 10== 0)
    {
       res = tab[i][1];
    }
    else
    {
       res = tab[i - 1][1] + (tab[i][2] * (RawADC % 10));
    }
    /* divide by 100 to get the floating result from integer */
   return (float(res) / 100); 
}

// Function for unit_testing
void Unit_Test()
{
  int adc;
  adc = 1;
  while( adc<990) {
    float temp = Calcul_Temp_Tab(adc);
    Serial.print(adc);
    Serial.print(" , ");
    Serial.println(temp);
    adc = adc + 1;
  }
  delay(10000000);
}

void setup() {
 Serial.begin(57600);
 Unit_Test();
 //Create_Tab();
}

void loop()
{
 int RawADC = analogRead(SENS_PIN);
 Serial.print(RawADC);
 Serial.print(" ");
 Serial.println(Calcul_Temp_Tab(RawADC));
 delay(1000);
}
