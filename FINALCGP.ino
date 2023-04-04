#include <FastLED.h>
#include <dht11.h>
#define DHT11PIN 4
dht11 DHT11;

// #define LED_STRIP1_PIN 1
#define LED_STRIP2_PIN 2 //turns on long led strip
#define NUM_LEDS 120
#define sensor A0


int gasLevel = 0;
CRGB leds[NUM_LEDS];
const int button1Pin = 7;
const int button2Pin = 8;
int button1State = 0;
int button2State = 0;
bool airQuality;
bool humidity;


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  FastLED.addLeds<WS2812B, LED_STRIP2_PIN, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_STRIP2_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
}
void loop() {

  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);


  if (humidity) {
    showHumdity();
  }
  if (airQuality) {
    showCarbonDioxide();
  }


  if (button1State == HIGH) {
    //yellow button
    Serial.println("Carbon Doxide");
    humidity = false;
    airQuality = true;
  }

  if (button2State == HIGH) {
    //green button
    Serial.println("Humidity");
    humidity = true;
    airQuality = false;
  }

}

void showHumdity() {
    FastLED.clear();

  int chk = DHT11.read(DHT11PIN);
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  float humidityLevel = (float)DHT11.humidity;
  // float humidityLevel = 24;

  Serial.print("Temperature   (C): ");
  Serial.println((float)DHT11.temperature, 2);

  Serial.println(analogRead(0));

 
    if (humidityLevel < 25) {
     for (int i = 0; i < 4; i++){ 
      leds[i] = CRGB(255, 0, 0);
     }
     for (int j = 68; j < 72 ; j++){
            leds[j] = CRGB(255, 0, 0);
     }
       for (int k = 24; k < 28; k++){ 
      leds[k] = CRGB(255, 0, 0);
     }
     for (int l = 90; l < 94 ; l++){
            leds[l] = CRGB(255, 0, 0);
     }
    } else if (humidityLevel > 25 && humidityLevel < 70) {

     for (int i = 0; i < 6; i++){ 
      leds[i] = CRGB(0, 0, 128);
     }
     for (int j = 66; j < 72 ; j++){
            leds[j] = CRGB(0, 0, 128);
     }
       for (int k = 23; k < 30; k++){ 
      leds[k] = CRGB(0, 0, 128);
     }
     for (int l = 89; l < 95 ; l++){
            leds[l] = CRGB(0, 0, 128);
     }



    } else  {
        for (int i = 0; i < 120; i++){ 
      leds[i] = CRGB(255, 0, 0); 
    }
    delay(100)  ;
  FastLED.show();
  delay(100);
  FastLED.clear();
  delay(100);
  FastLED.show();
    }
    // leds[i] = CRGB(44, 178, 210);
    // // leds[i] = CHSV(colorBlue, 87, 127);

 
  FastLED.show();

}


void showCarbonDioxide() {
    FastLED.clear();

  // gasLevel = analogRead(0);
    gasLevel = 260;
  Serial.println(analogRead(0));
  
    if (gasLevel < 90) {
   for (int i = 0; i < 4; i++){ 
      leds[i] = CRGB(128, 100, 0);
     }
     for (int j = 68; j < 72 ; j++){
            leds[j] = CRGB(128, 100, 0);
     }
       for (int k = 24; k < 28; k++){ 
      leds[k] = CRGB(128, 100, 0);
     }
     for (int l = 90; l < 94 ; l++){
            leds[l] = CRGB(128, 100, 0);
     }

       
    }else if (gasLevel > 100 && gasLevel < 250) {
      for (int i = 0; i < 6; i++){ 
      leds[i] = CRGB(128, 100,0);
     }
     for (int j = 66; j < 72 ; j++){
            leds[j] = CRGB(128, 100, 0);
     }
       for (int k = 23; k < 30; k++){ 
      leds[k] = CRGB(128, 100, 0);
     }
     for (int l = 89; l < 95 ; l++){
            leds[l] = CRGB(128, 100, 0);
     }
    
    } else if (gasLevel > 250 && gasLevel < 500) {
     for (int i = 0; i < 8; i++){ 
      leds[i] = CRGB(128, 100,0);
     }
     for (int j = 64; j < 72 ; j++){
            leds[j] = CRGB(128, 100, 0);
     }
       for (int k = 23; k < 32; k++){ 
      leds[k] = CRGB(128, 100, 0);
     }
     for (int l = 87; l < 95 ; l++){
            leds[l] = CRGB(128, 100, 0);
     }
    } else {
       for (int i = 0; i < 120; i++){
      leds[i] = CRGB(128, 100, 0);
    }
  delay(100)  ;
  FastLED.show();
  delay(100);
  FastLED.clear();
  delay(100);
  FastLED.show();
    // int colorPink= CRGB(155,50,50);
    // leds[i] = CHSV(colorPink, 87, 127);
    }
  FastLED.show();
}
