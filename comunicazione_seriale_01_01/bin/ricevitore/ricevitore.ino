#define controlPin  12
byte comando;


void setup(){
  Serial.begin(9600);
  pinMode(controlPin,   OUTPUT);
 }
void loop(){

  if (Serial.available () > 0){
    
    comando = Serial.read ();
    switch (comando){
      case B000:
      digitalWrite(controlPin, HIGH);
      Serial.println("acc");
      break;
      case B001:
      digitalWrite(controlPin,LOW);
      Serial.println("spento");
      break;
      }  
    }
  delay(10);

  
 }



 //CAMBIA!!!!!!!!!!!
