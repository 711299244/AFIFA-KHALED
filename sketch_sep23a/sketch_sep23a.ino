#include <math.h>
//I write in this code the hard method to get the Temperature and the easy method to get the Temperature
//***************************************************************** 
//open serial port, sets rate to 9600 bps
void setup() {
Serial.begin(9600);
pinMode(A4, INPUT);
}
//*********************************************************************
// method to display the result  on serial monitor 
void loop() {
  int ADC;    
    ADC = analogRead(A4);
    Serial.println(" The ADC value is : ");
    Serial.println(ADC);
    Serial.println("The Temperature value is : ");
    Serial.println(method_to_get_temp(ADC));
    delay(1000);
    
    
}
//***********************************************************************
// here to calcul the Temperature by hard method 
//double Temperature(int RawADC) {
 //double Temp;
// Temp = log(10000.0*((1024.0/RawADC-1))); 
// Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
// Temp = Temp - 273.15;            
 //return Temp;
//}
//******************************************************************************
//Easy method to get the Temprature
int method_to_get_temp(int ADC_vale){
  
  int temp;
 temp=0.1629*ADC_vale-50.489;
 return(temp);
}
   
    
   
