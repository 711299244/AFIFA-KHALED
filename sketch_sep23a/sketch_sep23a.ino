#include <math.h>
#define SENS_PIN 0
// here to calcul the Temperature by hard method 
double Temperature(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            
 return Temp;
}
//open serial port, sets rate to 9600 bps
void setup() {
Serial.begin(9600);
}
// method to display the result  on serial monitor 
void loop() {
  int i;
while (i <=1023){ 
    int  Result=Temperature(analogRead(i));
    Serial.print( "    The Temperature in Fahrenheit  is :  ");
   Serial.println(Result);
   i=i+5;
   }
delay(2000);
}
//linearly calcul Temperature
int method_easy_calcul(int x_value)
{
  
 int temp;
 temp=0.1632*x_value-50.514;
 return(temp); 
  
  
  }
//print method to linearly calcul Temperature
  void print_method() {
  
    int  Result=method_easy_calcul(analogRead(SENS_PIN));
    Serial.print( "    The Temperature   is :  ");
   Serial.println(Result); 
   
delay(500);
}
