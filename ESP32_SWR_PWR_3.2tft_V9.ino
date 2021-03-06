//############################################################################################
//This software is free to use. Its a SWR for HF, UHF and VHF. ( PE1PWR Wim Schilperoort)
//Its based on a ESP32 with TFT ILI9431 display 3.2 inch ads1115 and a Arduino 5 volt relay. 
//For more precision I have used a asd1115 AD converter. 
//You can used a relay for transceiver protection. D32 is allready in the script for 5 volt Arduino relay. 
//Protection niveau will be for a SWR of 1:3 and higher. It will activated relay till SWR is below 1:3. 
//##############################################################################################
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h" 
#include <Wire.h>
#include <Adafruit_ADS1015.h>

 Adafruit_ADS1115 ads(0x48);
      float Vfwd = 0.0;      
      float Vrev = 0.0;    
    
     
// For the Adafruit shield, these are the default.
#define TFT_CLK 18
#define TFT_MISO 23
#define TFT_MOSI 19
#define TFT_DC 2
#define TFT_CS 15
#define TFT_RST 4
#define TOUCH_CS 5   // Chip select pin (T_CS) of touch screen
#define SPI_TOUCH_FREQUENCY  2500000
#define SPI_READ_FREQUENCY  20000000
#define SPI_FREQUENCY  40000000 
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);// TFT 3.2 scherm

// Varibles
           
      float Pfwd;
      float Prev;
      float SWR;
      const int relay = 32;
  
void setup ()
{
      // Opbouw display.
       ads.begin();
       tft.begin();
       pinMode(relay, OUTPUT);
       tft.setRotation(45);
       tft.fillScreen(ILI9341_NAVY);
       tft.setTextColor(ILI9341_WHITE, ILI9341_NAVY);  
       tft.setCursor (5, 1); 
       tft.setTextSize(1);    
       tft.print("ESP32 SWR Versie 3.0");
       tft.setCursor (210, 230);  
       tft.setTextSize(1);    
       tft.print("HF SWR PWR PE1PWR ");
       tft.setTextColor(ILI9341_WHITE, ILI9341_NAVY); 
       tft.setTextSize(1); 
       tft.setCursor(0,28);
       tft.print(" PWR");  // Building PWR.
       tft.setRotation(90); 
       tft.setCursor (5,47); //+19  
       tft.fillRect(43,5,16,310,ILI9341_WHITE);
       tft.drawRect(44,4,17,312,ILI9341_WHITE);
       tft.setTextColor(ILI9341_BLACK, ILI9341_WHITE); 
       tft.setRotation(45);
       tft.print("X10     0.5    1     2    3   4   5  6  7  8  9 10");   // Scale PWR 
       tft.setCursor (0,85); 
       tft.setTextColor(ILI9341_WHITE, ILI9341_NAVY); 
       tft.print(" REV"); // Building REV. 
       tft.setRotation(90);        
       tft.setCursor (5,104);  
       tft.fillRect(100,5,17,310,ILI9341_WHITE);
       tft.drawRect(101,4,17,312,ILI9341_WHITE);
       tft.setTextColor(ILI9341_BLACK, ILI9341_WHITE); 
       tft.setRotation(45);        
       tft.print("X10     0.5    1     2    3   4   5  6  7  8  9 10");    // Scale REV  
       tft.setCursor (0,167);  
       tft.setTextColor(ILI9341_WHITE, ILI9341_NAVY);        
       tft.print(" SWR"); // Building SWR.
       tft.setRotation(90);        
       tft.fillRect(185,5,14,310,ILI9341_WHITE); // Level White SWR
       tft.drawRect(186,4,15,312,ILI9341_WHITE); // Level White SWR
       tft.fillRect(185,5,14,85,ILI9341_RED);// Level red SWR
       tft.drawRect(186,4,15,85,ILI9341_RED);// Level red SWR
       tft.setRotation(45); 
       tft.setTextColor(ILI9341_BLACK, ILI9341_WHITE);        
       tft.setCursor (5,189);  
       tft.print("           1.1   1.5    2           3");    // Scale SWR White part.
       tft.fillRect(251,4,65,28,ILI9341_BLACK); // Background power Black
       tft.drawRect(250, 3, 66, 30,ILI9341_WHITE); 
       tft.fillRect(251,145,65,28,ILI9341_BLACK); // Background power Black
       tft.drawRect(250,146, 66, 30,ILI9341_WHITE); 
  
}     
       
void loop(){ 

        {
         int16_t adc0;
         int16_t adc1;
         adc0 = ads.readADC_SingleEnded(0);
         adc1 = ads.readADC_SingleEnded(1);
         Vfwd = (adc0 * 0.1875)/1000;
         Vrev = (adc1 * 0.1875)/1000;
        } 
         Pfwd = (Vfwd * Vfwd)*10.5;
         Prev = (Vrev * Vrev)*10.5;         
         float fp = sqrt ( Prev / Pfwd ); // Formula SWR Prev / Pfwd int is fp
         SWR = ( 1 + fp ) / ( 1 - fp ); // Formula second part SWR 1+fp / 1-fp                          
         SWR = constrain(SWR, 1, 99.9); // some more than 100 // go further 
          
 /////////////////////// Vanaf hier power en SWR waarde op display pr0jecteren      
       tft.setRotation(45); // rotate screen right position        
            
       tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
       tft.setTextSize(2);
       tft.setCursor (266,12) ; // go to Column, Row 
       if (Vfwd <= 1.0)
       {
       tft.print(Pfwd, 1);
       tft.print(" ");
       }
       else 
       {
       tft.print(Pfwd, 0);
       tft.print(" ");
       }
   
tft.setRotation(90);  // rotate bargraph right position
        
        //  FWD bargrap
        { 
        int pwr = ((Vfwd) / 3.4) * 309;  // Bar Graph ijken fwd
        tft.drawRect(59, 4, 22, 312,ILI9341_WHITE);
        if (Vfwd >= 3.2)
        tft.fillRect(60,315-pwr,20,pwr,ILI9341_RED);
        else tft.fillRect(60,315-pwr,20,pwr,ILI9341_GREEN);
        tft.fillRect(60,315-309,20,309-pwr,ILI9341_BLACK);
        } //  end bargraph      
   
tft.setRotation(90); //roteer bargraph right position 
        
        //  REV bargraph
        {  
        int rev = ((Vrev)/ 3.4) * 310; // Bar Graph ijken rev
        tft.drawRect(115, 4, 22, 312,ILI9341_WHITE);
        if (Vrev >= 1.0)
        tft.fillRect(116,315-rev,20,rev,ILI9341_RED);
        else tft.fillRect(116,315-rev,20,rev,ILI9341_GREEN); 
        tft.fillRect(116,315-310,20,310-rev,ILI9341_BLACK);
        }   //  end bargraph      

tft.setRotation(45); // rotate screen right position        

        // SWR bargraph
        
      {  int swr = (SWR / 4.2) * 310;// Bar graph formula for accurate swr
        tft.setCursor (257,154);
        tft.print(SWR,1);
        if (SWR >= 3)
           digitalWrite(relay, HIGH);
           if (SWR <= 3)
           digitalWrite(relay, LOW);   
        tft.print(" ");
        tft.setRotation(90); //rotate bargraph right position 
        tft.drawRect(199, 4, 22, 312,ILI9341_WHITE);
        if (SWR >=3)
        tft.fillRect(200,315-swr,20,swr,ILI9341_RED);
        else tft.fillRect(200,315-swr,20,swr,ILI9341_GREEN);
        tft.fillRect(200,315-310,20,310-swr,ILI9341_BLACK);
        }
tft.setRotation(45); // rotate screen start position
           

  } //end loop
