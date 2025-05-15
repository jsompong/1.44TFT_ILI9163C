// Henry's Bench
//  1.44"  128 * 128  SPI  V1.1 Display Tutorial

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>


// Definition of WHITE
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

String myString = "1";
char myChar = 'A';
/*
Your Connections to an Uno (Through a Level Shifter)

 LED to 3.3V
 SCK to D13
 SDA to D11
 A0 to D8
 RST to D9
 CS to D10
 GND to GND
 VCC to 3.3V 
 */
 
#define __CS 10
#define __DC 9

// Declare an instance of the ILI9163
TFT_ILI9163C tft = TFT_ILI9163C(__CS, 8, __DC);  

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("1.44TFT_ILI9163C");
  tft.begin();
  tft.setBitrate(16000000);
  tft.clearScreen();
  tft.setRotation(2);
  tft.fillScreen();
}

void loop(){
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(500);                       // wait for a second
   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   delay(500);   
  tft.fillScreen(BLACK);
  tft.setCursor(30, 10);
  tft.setTextColor(RED);  
  tft.setTextSize(2);
  tft.println("1.44TFT_ILI9163C");
  
  tft.setCursor(50, 40);
  tft.setTextColor(GREEN);  
  tft.setTextSize(2);

  tft.println("Test");
  tft.setCursor(20, 70);
  tft.setTextColor(BLUE);  
  tft.setTextSize(2);
  tft.println("Arduino");
  delay(1000);
  tft.clearScreen();
  
  tft.fillScreen(YELLOW);
  tft.setCursor(30, 10);
  tft.setTextColor(RED);  
  tft.setTextSize(2);
  tft.println("15/05/2025");
  tft.setCursor(50, 40);
  tft.setTextColor(GREEN);  
  tft.setTextSize(2);
  tft.println("LCD_9163.ino");
  tft.setCursor(20, 70);
  tft.setTextColor(BLUE);  
  tft.setTextSize(2);
  tft.println(myChar);
  delay(1000);
  tft.clearScreen();
  myChar++;
  Serial.println(myChar);

  tft.fillScreen(RED);
  tft.setCursor(5, 5);
  tft.setTextColor(YELLOW);  
  tft.setTextSize(1);
  tft.println(myString);
    
  tft.setCursor(5, 25);
  tft.setTextColor(GREEN);  
  tft.setTextSize(2);
  tft.println(myString += myChar);
  
  tft.setCursor(5, 50);
  tft.setTextColor(BLUE);  
  tft.setTextSize(3);
  tft.println("SCK to D13");
  
  tft.setCursor(5, 90);
  tft.setTextColor(BLACK);  
  tft.setTextSize(4);
  tft.println("SDA to D11");
  delay(1000);
  tft.clearScreen();
 // myString++;
  tft.fillScreen();
  // tft.drawCircle(x, y, radius, color);
  tft.drawCircle(64, 64, 60, WHITE);
  delay(1000);
  tft.clearScreen();
  
  tft.fillScreen();
  //tft.drawLine(x1, y1, x2, y2, color);
  tft.drawLine(5, 5, 120, 120,  YELLOW);
  delay(1000);
  tft.clearScreen();
  
  tft.fillScreen();
  //tft.drawFastHLine(x, y, w, color1);
  tft.drawFastHLine(4, 64, 120, WHITE);
  delay(1000);
  tft.clearScreen();
  
  tft.fillScreen();
  //tft.drawFastVLine(x, y, w, color1);
  tft.drawFastVLine(64, 5, 120, WHITE);
  delay(1000);
  tft.clearScreen();
    
  tft.fillScreen();
  //tft.drawRect(cx-i2, cy-i2, i, i, color);
  tft.drawRect(5, 5, 123, 123, WHITE);
  delay(1000);
}

