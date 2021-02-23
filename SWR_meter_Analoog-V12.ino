

// This software is free to use for your own projects. 
// its full C++ 

#include <SPI.h>
#include <SD.h>
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "SWR_ILI9341.h"
#include <Wire.h>
#include <Adafruit_ADS1015.h>


Adafruit_ADS1115 ads(0x48); // AD converter module 

// Variable
      float Vfwd = 0.0;      
      float Vrev = 0.0; 
      float Pfwd;
      float Prev;
      float SWR;
      float PfwdA;
      float start_angleA = -2.5, end_angleA = -0.62, last_valueA = -1, input_valueA = 0.00;
      float start_angleB = -2.5, end_angleB = -0.62, last_valueB = -1, input_valueB = 0.00;
      int a = 240, b = 125, c = 75, scalB = 0;  // Meter needle a,b coordinates plus radius all in pixels, values are design for a 320x240 screen
      int x = 75,  y = 125, r = 75, scalA = 0;  // Meter needle X,Y coordinates plus radius all in pixels, values are design for a 320x240 screen
      const int LEDPIN = 26;
      const int PushButton = 13; // Unlock relay after high SWR 1:3.
      const int relay = 32;

     
void setup()
{    
     tft.begin();     // Starting TFT display support
     tft.setRotation(3);   // Rotate through 270-degrees
     tft.fillScreen(ILI9341_BLACK); // Clear display.
     ads.begin(); // Start asd1115 module
     #include "SWR_color.h" // Building display colors en text
     pinMode(LEDPIN, OUTPUT);
     pinMode(PushButton, INPUT);
     pinMode(relay, OUTPUT);
}
void display_meterA(float scalA)// Draw analog meterA.
{
    tft.fillCircle(x,y,5, ILI9341_GREEN);
    for (float i = start_angleA; i < end_angleA; i = i + 0.01)
    {
    tft.drawPixel(x + cos(i) * r, y + sin(i) * r, ILI9341_WHITE); // center point is (x,y)
    tft.drawPixel(x + cos(i) * r * 1.01, y + sin(i) * r * 1.01, ILI9341_WHITE);
    }
    for (float i = start_angleA; i < end_angleA; i = i + (end_angleA-start_angleA)*major_graduations)  
    {
    tft.drawLine(x + cos(i) * r, y + sin(i) * r, x + cos(i) * r * 1.1, y + sin(i) * r * 1.1, ILI9341_WHITE); 
    tft.setCursor(x + cos(i) * r * 1.16-3, y + sin(i) * r * 1.16);
    tft.setTextSize(1);
    tft.println(scalA,0);
    scalA++; 
    }
} 
void display_valueA (float PfwdA)
{
    tft.fillCircle(x,y,5, ILI9341_GREEN);
    int x2,y2;
    x2 = x + cos(start_angleA+(end_angleA-start_angleA)*major_graduations*last_valueA) * r * 0.98;
    y2 = y + sin(start_angleA+(end_angleA-start_angleA)*major_graduations*last_valueA) * r * 0.98;
    if (last_valueA != PfwdA) 
    {
    tft.drawLine(x, y, x2, y2, ILI9341_BLACK);
    }
    x2 = x + cos(start_angleA+(end_angleA-start_angleA)*major_graduations*PfwdA) * r * 0.98;
    y2 = y + sin(start_angleA+(end_angleA-start_angleA)*major_graduations*PfwdA) * r * 0.98;
    tft.drawLine(x, y, x2, y2, ILI9341_GREEN);
    last_valueA = PfwdA; 
}
void display_meterB(float scalB) //SWR
{
    for (float f = start_angleB; f < end_angleB; f = f + 0.01)
    {
    tft.drawPixel(a + cos(f) * c, b + sin(f) * c, ILI9341_WHITE); // center point is (a,b)
    tft.drawPixel(a + cos(f) * c * 1.01, b + sin(f) * c * 1.01, ILI9341_WHITE);
    }
    for (float f = start_angleB; f < end_angleB; f = f + (end_angleB-start_angleB)*major_graduations)  
    {
    tft.drawLine(a + cos(f) * c, b + sin(f) * c, a + cos(f) * c * 1.1, b + sin(f) * c * 1.1, ILI9341_WHITE); 
    tft.setCursor(a + cos(f) * c * 1.16-3, b + sin(f) * c * 1.16);
    scalB++; 
    }
} 
                                   
void display_valueB (float SWR)   // Draw analog meterB.
    {
    tft.fillCircle(a,b,5, ILI9341_GREEN);
    int a2,b2;
    a2 = a + cos(start_angleB+(end_angleB-start_angleB)*major_graduations*last_valueB) * c * 0.98;
    b2 = b + sin(start_angleB+(end_angleB-start_angleB)*major_graduations*last_valueB) * c * 0.98;
    if (last_valueB != SWR); 
   {
    tft.drawLine(a, b, a2, b2, ILI9341_BLACK);
   }
    a2 = a + cos(start_angleB+(end_angleB-start_angleB)*major_graduations*SWR) * c * 0.98;
    b2 = b + sin(start_angleB+(end_angleB-start_angleB)*major_graduations*SWR) * c * 0.98;
    tft.drawLine(a, b, a2, b2, ILI9341_GREEN);
    last_valueB = SWR; 
} 
 
void loop()
{
         display_meterA(0); // Start building meterA(PWR)
         display_meterB(0); // Start building meterB(SWR)
         int16_t adc0;  // Read input voltage from Vfwd A0 asd1115
         int16_t adc1;  // Read input voltage from Vrev A1 asd1115 
         adc0 = ads.readADC_SingleEnded(0);
         adc1 = ads.readADC_SingleEnded(1);
         Vfwd = (adc0 * 0.1875)/1000; // Formula for adjust voltage (Vfwd)
         Vrev = (adc1 * 0.1875)/1000; // Formula for adjust voltage (Vrev)
         Pfwd = (Vfwd * Vfwd)*10.5; // Formula wattage Pfwd
         Prev = (Vrev * Vrev)*10.5; // Formula wattage Prev
         PfwdA = (Vfwd * Vfwd)*10.5 /10 ; // Correction formula for analog power meter     
         float fp = sqrt ( Prev / Pfwd ); // Formula SWR Prev / Pfwd int is fp
         SWR = ( 1 + fp ) / ( 1 - fp ); // Formula second part SWR 1+fp / 1-fp                          
         SWR = constrain(SWR, 1, 99.9); // some more than 100 // go further 
         if (Pfwd <= 1) SWR=1; // Stabilised swr meter when power = 0. 
         if (PfwdA >= 10)
             {
              PfwdA = 10;
             }           // Protection analog meter. 100W max
             input_valueA = (PfwdA);   // Take niveau input for meterA (power) 
             display_valueA(PfwdA); // Undraw then Draw the meter needle (PWR)
          int Push_button_state = digitalRead(PushButton); // Unlock protection relay after high SWR 1:3
              if ( Push_button_state == HIGH) // Read state of button
              {
                  digitalWrite(relay, LOW); // Shutdown protection relay
              }  
              if ( Push_button_state == HIGH) // Read state of button  
                {
                  digitalWrite(LEDPIN, LOW); // Shutdown red LED 
                }


                  
         {
         tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
         tft.setTextSize(1);
         tft.setCursor (x-55,y+20);
         tft.print("F");
         tft.setCursor (x-40,y+20) ; // Show digital info "F" whitin in meterA(POWER) 
         if (Vfwd <= 1.0) // after if stops 1 decimal digital info. >= 10 W

            {
             tft.print(Pfwd, 1); //   after if stops 1 decimal digital info. >= 10 W
             tft.print(" ");
            }
             else 
                {
                tft.print(Pfwd, 0); // Above 10 W till 100W.
                tft.print(" ");
                }
         }      
        
         {
         tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
         tft.setTextSize(1);
         tft.setCursor (x+10,y+20);
         tft.print("R");
         tft.setCursor (x+30,y+20);  // Show digital info "R" whitin in meterA(POWER) 
         if (Vrev <= 1.0) // Niveau om door te gaan na 10 watt
             { 
             tft.print(Prev, 1);  // after if stops 1 decimal digital info. >= 10 W
             tft.print(" ");
             }
         
            else 
               {
               tft.print(Prev, 0); // Above 10 W till 100W.
               tft.print(" ");
                }}     
      
        {
       int swr = (SWR / 4.2) * 310;// Adjust formula for correct SWR digital whitin meter.(SWR)
        tft.setCursor(a-14,b+20);
        tft.print(SWR,1);
        if (SWR >= 3) // If SWR above 1:3 powerup protection relais.
           { 
           digitalWrite(relay, HIGH);  // Relay on above SWR 1:3 and stay on till button will release protection
           digitalWrite(LEDPIN, HIGH);
           }
            
          tft.print(" ");
        }
             
        if (SWR > 10)          
             {
              SWR=10;
             }              //  // Protection analog meter. max SWR 1:10 max
             input_valueB = (SWR);  // Take niveau input for MeterB (SWR)
             display_valueB(SWR);   // Undraw then Draw the meter needle (SWR)
                    
   }  // End loop

     

// ---------------------------------------------------
