/* 
 * Rui Santos  
 * Complete Project Details http://randomnerdtutorials.com 
*/ 
 
int sensorPin=7; 
int val =0; 
 
void setup(){ 
  pinMode(sensorPin, INPUT); 
  Serial.begin (9600); 
} 
   
void loop (){ 
  val =analogRead(0); 
  Serial.print (val); 
  Serial.print('\n');
  delay(50); 
} 
