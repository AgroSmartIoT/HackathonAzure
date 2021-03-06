#include <dht.h>
dht DHT;
#define DHT11_PIN 2
unsigned long startTime;

int motorPin=5;

void setup() {

  pinMode(motorPin,OUTPUT);
 
  Serial.begin(9600);

  pinMode(3,INPUT);

  pinMode(6, OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  int i = 0;
  for(i=6; i < 14; i++)
    pinMode(i,OUTPUT);

}

void loop() {
  
  digitalWrite (9, HIGH);
  delay(1000);
  digitalWrite(9,LOW);
  
  int chk = DHT.read11(DHT11_PIN);
  int ambient_temperature = DHT.temperature;
  int ambient_humidity = DHT.humidity;
  
  Serial.print("Temperature = ");
  Serial.println(ambient_temperature);
  ambientTemperatureLevel(ambient_temperature);
  

  digitalWrite (10, HIGH);
  delay(1000);
  digitalWrite(10,LOW);
  
}

void ambientTemperatureLevel(int ambient_temperature){
  int flashing_led = 0;
  if(ambient_temperature > 0 && ambient_temperature <= 15 ){ //Turn on the Green LED
    Serial.println("It's Cold");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (8, HIGH);
      delay(50);
      digitalWrite (8, LOW);
      delay(50);
    };
  }else if(ambient_temperature > 15 && ambient_temperature <= 29 ){ //Turn on the Yellow LED
    Serial.println("It's Warm");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (7, HIGH);
      delay(50);
      digitalWrite (7, LOW);
      delay(50);
    };
  }else if(ambient_temperature > 29 && ambient_temperature < 40 ){ //Turn on the Red LED   
    Serial.println("It's Hot");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
        digitalWrite (6, HIGH);
      delay(50);
      digitalWrite (6, LOW);
      delay(50);
    };
  };
 }

void ambientHumidityLevel(int ambient_humidity){
  int flashing_led = 0;
  if(ambient_humidity > 0 && ambient_humidity <= 30 ){ //Turn on the Green LED
    Serial.println("It's Dry");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (8, HIGH);
      delay(50);
      digitalWrite(8,LOW);
      delay(50);
    };
  }else if(ambient_humidity > 30 && ambient_humidity <= 60 ){ //Turn on the Yellow LED
    Serial.println("It's Wet");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (7, HIGH);
      delay(50);
      digitalWrite(7,LOW);
      delay(50);
    };
  }else if(ambient_humidity > 60 && ambient_humidity <= 100 ){ //Turn on the Red LED
    Serial.println("It's Too Wet");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (6, HIGH);
      delay(50);
      digitalWrite(6,LOW);
      delay(50);
    };
  };
 }

void soilMoistureLevel(int soil_moisture){
  int flashing_led = 0;
  if(soil_moisture > 400 && soil_moisture <= 600 ){ //Turn on the Green LED
    Serial.println("It's Too Wet");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (8, HIGH);
      delay(50);
      digitalWrite (8, LOW);
      delay(50);
    };
  }else if(soil_moisture > 600 && soil_moisture <= 800 ){ //Turn on the Yellow LED
    Serial.println("It's Wet");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (7, HIGH);
      delay(50);
      digitalWrite (7, LOW);
      delay(50);
    };
  }else if(soil_moisture > 800 ){ //Turn on the Red LED
    Serial.println("It's Dry");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (6, HIGH);
      delay(50);
      digitalWrite (6, LOW);
      delay(50);
      
    }
    digitalWrite(motorPin,HIGH); //Turn on the MicroBomb
    delay(3000);
    digitalWrite(motorPin,LOW);
  };
  }

void waterLevelInTheContainer(int water_level){
  int flashing_led = 0;
  if(water_level == 0 || water_level <= 15){ //Turn on the Red LED
    Serial.println("It's Empty");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (6, HIGH);
      delay(50);
      digitalWrite(6,LOW);
      delay(50);
    };
  }else if(water_level > 15 && water_level <= 350 ){ //Turn on the Yellow LED
    Serial.println("It's Almost Empty");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (7, HIGH);
      delay(50);
      digitalWrite(7,LOW);
      delay(50);
    };
  }else if(water_level > 350){ //Turn on the Green LED
    Serial.println("It's OK");
    for (flashing_led = 0; flashing_led <= 5; flashing_led++){ 
      digitalWrite (8, HIGH);
      delay(50);
      digitalWrite(8,LOW);
      delay(50);
    };
  };
  }

  void numberOfProgram(int counter){
    int i = 0;
    for(i = 0; i < counter; i++){
      digitalWrite (9, HIGH);
      delay(250);
      digitalWrite(9,LOW);
      delay(250);
    };
    }
