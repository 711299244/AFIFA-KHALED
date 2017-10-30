

// here  we determent the pin
//Connect the LED's long (+) leg to port 13 and the leg (-) to the Gnd port next to port 13
int led  = 13 ;
//Connect the positive power cord of the sensor to the 5 v port on the breadboard, and the negative power cord toint data;
int data;
//Gnd port on the breadboard.
// Plug the Signal cable into port 9 on the card.
int pir = 9 ; 
//Connect the reel power cord to the 5 v port on the breadboard, and the negative power cord to the
//Gnd port on the breadboard.
// Connect the signal cable to port 10 on the card
int relay = 10 ;
//here intial value to motion
int motion = 0 ; 
int pirstate = LOW ; 

//open serial port,
void setup() {
 Serial.begin(4800); 
  pinMode(led, OUTPUT) ;
  pinMode(relay , OUTPUT);
  pinMode(pir , INPUT); 
  
}

// method to display the result  on serial monitor
void loop(){
 //  if(Serial.available()){
   // data = Serial.read();
    //if(data == 'A'){
    //  digitalWrite(13,HIGH);
   // }
   // else {
   //   digitalWrite(13,LOW);
   // }
 // }
  
  motion = digitalRead(pir);
//this loop it will check if the motion is high , it will put  (relay , LOW);   (led , HIGH); by using    digitalWrite(); function
  if ( motion == HIGH ){
    
   digitalWrite(relay , LOW);
   digitalWrite(led , HIGH);
  
  if( pirstate == LOW){
     pirstate = HIGH;   

        //delay(1000);
  }  
}
//here will check if the motion is low , it will put (led , LOW), (relay , HIGH); by using    digitalWrite(); function

else {

 digitalWrite(led , LOW);
 digitalWrite(relay , HIGH);
// delay(300); 
 
 if ( pirstate == HIGH)
    pirstate = LOW;
} 

  if(Serial.available()){
    data = Serial.read();
    if(data == 'A'){
      digitalWrite(13,HIGH);
    }
    else {
      digitalWrite(13,LOW);
    }
  }
}
