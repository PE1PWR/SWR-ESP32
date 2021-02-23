  /// Bouw rood gedeelte op SWR meter 
   

    tft.setCursor(0,0);   // Zet de cursur helemaal in deb hoek bovenaan.
    tft.setTextSize(2);   // text size to normal for the ILI9341
    tft.print("       HF SWR meter"); // Display title
    tft.drawCircle(x,y,5, ILI9341_GREEN); // Teken een circel in de center van de meterA
    tft.drawRoundRect(2,22, 318, 200, 15, ILI9341_GREEN);   // Teken lijn om de meters. Buitenkant.
    tft.fillRoundRect(2,22, 318, 200, 15, ILI9341_GREEN);   // Vul alles met groen op binnen deze ring.
    tft.fillRoundRect(2,22, x+78,y+32, 15, ILI9341_BLACK);  // Bouw zwarte achtergond op van meterA.
    tft.fillRoundRect(167,22,x+78,y+33, 15, ILI9341_BLACK); // Bouw zwarte achtergond op van meterB.
    tft.drawRoundRect(2,22, x+78,y+32, 15, ILI9341_GREEN);  // Bouw rand groen op van meterA die zwarte achtergrond overschrijft.
    tft.drawRoundRect(167,22,x+78,y+33, 15, ILI9341_GREEN); // Bouw rand groen op van meterB die zwarte achtergrond overschrijft. 
    tft.setCursor (x-28,y+65) ;   
    tft.setTextColor(ILI9341_BLACK);
    tft.print("POWER");// Zet POWER in groene gedeelte
    tft.setCursor (a-14,b+65);
    tft.print("SWR");  // Zet SWR in groene gedeelte
    tft.setTextSize(1);
    tft.setCursor(a-2,b-95);
    tft.setTextColor(ILI9341_WHITE);
    tft.print("5");   // Schaal indicatie SWR 
    tft.setCursor(a-35,b-90);
    tft.setTextColor(ILI9341_WHITE);
    tft.print("3");   // Schaal indicatie SWR
    tft.setCursor(a-64,b-73);
    tft.setTextColor(ILI9341_WHITE);
    tft.print("0");   // Schaal indicatie SWR
    tft.drawTriangle(241, 42, 241, 50, 255, 43, ILI9341_RED);  // start 1e rode blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(241, 42, 241, 50, 255, 43, ILI9341_RED);
    tft.drawTriangle(241, 50, 255, 43, 255, 50, ILI9341_RED);
    tft.fillTriangle(241, 50, 255, 43, 255, 50, ILI9341_RED);  // end 1e rode blok SWR
    tft.drawTriangle(257, 44, 255, 50, 270, 47, ILI9341_RED); // start 2e rode blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(257, 44, 255, 50, 270, 47, ILI9341_RED);
    tft.drawTriangle(256, 50, 270, 47, 270, 55, ILI9341_RED);
    tft.fillTriangle(256, 50, 270, 47, 270, 55, ILI9341_RED);  // end 2e rode blok SWR
    tft.drawTriangle(272, 48, 269, 56, 284, 55, ILI9341_RED); // start 3e rode blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(272, 48, 269, 56, 284, 55, ILI9341_RED);
    tft.drawTriangle(270, 56, 284, 55, 282, 60, ILI9341_RED);
    tft.fillTriangle(270, 56, 284, 55, 282, 60, ILI9341_RED);  // end 3e rode blok SWR
    tft.drawTriangle(284, 55, 281, 61, 297, 64, ILI9341_RED); // start 4e rode blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(284, 55, 281, 61, 297, 64, ILI9341_RED);
    tft.drawTriangle(281, 61, 297, 64, 293, 69, ILI9341_RED);
    tft.fillTriangle(281, 61, 297, 64, 293, 69, ILI9341_RED);  // end 4e rode blok SWR
    tft.drawTriangle(297, 65, 293, 71, 307, 77, ILI9341_RED); // start 5e rode blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(297, 65, 293, 71, 307, 77, ILI9341_RED);
    tft.drawTriangle(292, 71, 307, 77, 301, 80, ILI9341_RED);
    tft.fillTriangle(292, 71, 307, 77, 301, 80, ILI9341_RED);  // end 5e rode blok SWR
    tft.drawTriangle(226, 43, 226, 50, 240, 42, ILI9341_ORANGE);  // start 1e Orange blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(226, 43, 226, 50, 240, 42, ILI9341_ORANGE);
    tft.drawTriangle(226, 50, 240, 42, 240, 50, ILI9341_ORANGE);  
    tft.fillTriangle(226, 50, 240, 42, 240, 50, ILI9341_ORANGE);  // end 1e orange blok SWR
    tft.drawTriangle(210, 47, 213, 53, 224, 43, ILI9341_ORANGE);  // start 2e Orange blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(210, 47, 213, 53, 224, 43, ILI9341_ORANGE);
    tft.drawTriangle(213, 53, 224, 43, 225, 50, ILI9341_ORANGE);  
    tft.fillTriangle(213, 53, 224, 43, 225, 50, ILI9341_ORANGE);  // end 2e orange blok SWR
    tft.drawTriangle(197, 53, 199, 59, 210, 47, ILI9341_GREEN);  // start 1e green blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(197, 53, 199, 59, 210, 47, ILI9341_GREEN);  
    tft.drawTriangle(199, 59, 210, 47, 213, 55, ILI9341_GREEN);  
    tft.fillTriangle(199, 59, 210, 47, 213, 55, ILI9341_GREEN);  // end 1e green blok SWR
    tft.drawTriangle(185, 63, 187, 68, 196, 54, ILI9341_GREEN);  // start 2e green blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(185, 63, 187, 68, 196, 54, ILI9341_GREEN);  
    tft.drawTriangle(187, 68, 196, 54, 198, 60, ILI9341_GREEN);  
    tft.fillTriangle(187, 68, 196, 54, 198, 60, ILI9341_GREEN);  // end 2e green blok SWR
    tft.drawTriangle(185, 63, 187, 68, 196, 54, ILI9341_GREEN);  // start 3e green blok SWR (2 triangles tegen elkaar)
    tft.fillTriangle(185, 63, 187, 68, 196, 54, ILI9341_GREEN);  
    tft.drawTriangle(173, 75, 177, 79, 184, 64, ILI9341_GREEN);  
    tft.fillTriangle(173, 75, 177, 79, 184, 64, ILI9341_GREEN);  // end 3e green blok SWR
    tft.drawTriangle(178, 80, 184, 64, 188, 70, ILI9341_GREEN);  
    tft.fillTriangle(178, 80, 184, 64, 188, 70, ILI9341_GREEN);  // end 3e green blok SWR
