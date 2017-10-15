
#include <math.h>
#define SENSOR_PIN A5

//There are many way to perfect temperature measurement procedures
// The most common technique is to transform floating-point numbers to integers using a scaling factor

//1-Calculate the values beforehand in excel and just store them as integer as a look-up table in code

//2- Fixed-point decimal calculations.

//3- Use 32 bit fixed point calculations to get decent results if you attempt to use the polynomial functions.

double array_ab[4][3]{
  {200.0,0.3321,- 54.596},
  {300.0,0.1125,-29.866},
  {900.0,0.1254,-37.924},
  {1023.0,1.3449,-1155.5},


};


int array_[200][2] = {
  {10, -60},
  {20, -50},
  {30, -44},
  {40, -40},
  {50, -36},
  {60, -33},
  {70, -30},
  {80, -28},
  {90, -25},
  {100, -23},
  {110, -21},
  {120, -19},
  {130, -18},
  {140, -16},
  {150, -15},
  {160, -13},
  {170, -12},
  {180, -10},
  {190, -9},
  {200, -8},
  {210, -6},
  {220, -5},
  {230, -4},
  {240, -3},
  {250, -2},
  {260, 0},
  {270, 1},
  {280, 2},
  {290, 3},
  {300, 4},
  {310, 5},
  {320, 6},
  {330, 7},
  {340, 8},
  {350, 9},
  {360, 10},
  {370, 11},
  {380, 12},
  {390, 13},
  {400, 14},
  {410, 15},
  {420, 16},
  {430, 17},
  {440, 18},
  {450, 19},
  {460, 20},
  {470, 21},
  {480, 22},
  {490, 23},
  {500, 24},
  {510, 25},
  {520, 26},
  {530, 27},
  {540, 28},
  {550, 29},
  {560, 30},
  {570, 31},
  {580, 32},
  {590, 33},
  {600, 34},
  {610, 35},
  {620, 37},
  {630, 38},
  {640, 39},
  {650, 40},
  {660, 41},
  {670, 42},
  {680, 44},
  {690, 45},
  {700, 46},
  {710, 48},
  {720, 49},
  {730, 51},
  {740, 52},
  {750, 54},
  {760, 55},
  {770, 57},
  {780, 58},
  {790, 60},
  {800, 62},
  {810, 64},
  {820, 66},
  {830, 68},
  {840, 70},
  {850, 72},
  {860, 75},
  {870, 77},
  {880, 80},
  {890, 83},
  {900, 87},
  {910, 91},
  {920, 95},
  {930, 99},
  {940, 104},
  {950, 110},
  {960, 117},
  {970, 125},
  {980, 135},
  {990, 148},
  {1000, 168},
  {1010, 201},
  {1020, 301},
  {1023, 475}
};
//open serial port, sets rate to 9600 bps
void setup() {
Serial.begin(9600);
}

//***********************************************************************
// here to calcul the Temperature by hard method 
double Temperature(int RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1))); 
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
Temp = Temp - 273.15;            
 return Temp;
}
//******************************************************************************

double method_to_get_temp(int ADC_vale, double  A, double B){
// String v = (A / 100);              
//v= v + '.' + (A% 100);    
//Serial.println(v);
double  temp;
 temp=A*ADC_vale+B;
 return(temp);
  
  }

  int calucte(int ACD2){
 int i = 0;
 while(array_[i][0] < ACD2)
 {
  i++;
 }
 return(array_[i][1]);  
}
//*********************************************************************
// method to display the result  on serial monitor 
void loop() {
  int ADC;  
  int c= 0;
int i = 0;
bool  IsLightOn = true;
ADC = analogRead(SENSOR_PIN);
    Serial.println(ADC);
  while((i<=4) && ( IsLightOn))
  {
    i++;
    if(ADC<=  array_ab[i][0])
    {
      IsLightOn = false;
      Serial.println(i);
    }
  }
  // The most common technique is to transform floating-point numbers to integers using a scaling factor

  Serial.println(int (method_to_get_temp(ADC, array_ab[i][1],array_ab[i][2])));
  c++;
    
   }
    
