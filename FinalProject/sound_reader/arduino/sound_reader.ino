/*
 * Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
*/

int ledPin=0;
int sensorPin=7;
int val =0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}
  
void loop (){
  val =analogRead(1);
  Serial.print ("20 , ");
  Serial.print (val);
  Serial.print (", 27\n");
  delay(100);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val==HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}


