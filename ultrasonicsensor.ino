int trigPin=10;
int echoPin=9; 
long time; //stores time taken
int distance; //stores distance 

//setup repeats only once
void setup()
{
  pinMode(10, OUTPUT);//transmits pulse
  pinMode(9, INPUT);//recieves pulse
  
  
  //standard, relatively slow speed for serial communication, but it's reliable and works well
  //9600 bps stands for 9600 bits per second, which is the baud rate used in serial communication
  //It means 9600 binary bits (1s or 0s) are transmitted every second over the serial connection.
  Serial.begin(9600);//begins comms //Start serial communication at 9600 bps
}

void loop() //this repeats continously
{
  digitalWrite(10, LOW); //clearing the previous state {cleared}
  delayMicroseconds(2);//a small delay
  
  digitalWrite(10, HIGH);//high-signal transmits //// Send a 10us HIGH pulse
  delayMicroseconds(10);
  digitalWrite(10,LOW);//sets to low to stop Transmission
  
  //calculate distance
  
  time=pulseIn(9, HIGH);//// Measure how long the echoPin stays HIGH
  //calculate time of flight
  //time taken for the ultrasonic pulse to travel to the object and back.
  
  //0.034 cm per microsecond is the speed of sound
  distance=(time*0.034)/2;//d=sxt
  //its double distance, we need only the distance of the object
  
  
  Serial.print("Distance:");
  Serial.println(distance);
  
}
