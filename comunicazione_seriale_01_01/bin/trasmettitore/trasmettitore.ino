byte mex;
int photoPin = A0;
int val = 0;

void setup()
 {
 Serial.begin(9600);
 pinMode(photoPin, INPUT);
 }
void loop(){
  val = analogRead(photoPin);

  
  val>=1000?mex=B000:mex=B001;

  
  Serial.println(val);
  Serial.write(mex);
  

  delay(10);
 }
