SWR ESP32 TFT3.2 The software is free to use. It is a SWR meter built with an ESP-32, ASD1115 and a tft 3.2 Touch. The touch is in the schematic but has not yet been used in this programming. Current version is 3.01 ( release V9 has a relay protection extra)

The script was written for a TFT 3.2 320 X 240 screen. If you are going to use a smaller screen, the image will not be automatically adjusted. It is intended that this is possible in the new version.

There are plans to use the ESP32 to control the SWR and protect the output stage. 100 watts is the maximum power for this SWR version. A higher power is possible if you adjust the calculation and set the scale X100. Also make sure that the input voltage at the ADS1115 does not exceed 5 volts. In that situation, use 2 resistors to divide the voltage.

The touch will be used to adjust the scale via a setup menu for more than 100 watts.

The reason that an ADS1115 (16 bits) was used as an AD converter is because the ESP32 AD converter had too small a range that is linear. 800 to 2200 mv (12 bits). Up to 150mv and after 2200mv it is done with linearity. It also emerged that the AD of the ESP32 is very unstable. An extra capacitor used to separate HF from the DC voltage did not work. That ADS1115 is stable is shown by the fact that no capacitor is placed at the input. THE ADS1115 is quite linear over a wide range. This is what you see in the value of calculations and the effect on the display. It is very quiet and stable.

The formula used for the SWR calculation VSWR = 1+ (Pref / Pfwd) / 1− (Pref / Pfwd) In the programming you can adjust the scale yourself and calibrate it if necessary.

Note the design has been tested with USB 5 volts. In practice this will be around 4.5V. If you want to use a battery of 3.7 volts, put in a converter to 5 volts. If the values expire after using a 5v module, you can adjust them yourself in the code. Will perform a test itself to check progress. If this is the case, I will enter 2 codes one for USB 5v and one for a battery with 5 volt module.
And now there is allready another version with protecion relay. Its V9 version. More info see script.



# SWR-ESP32
SWR ESP32 TFT3.2
De software is vrij te gebruiken. Het is een SWR meter gebouwt met een ESP-32, ASD1115 en een tft 3.2 Touch. De touch staat wel in het schema maar is nog niet gebruikt in deze programmering. Huidige versie is 3.0

Het script is geschreven voor voor een TFT 3.2 320 X 240 scherm. Als je een kleiner scherm gaat gebruiken zal het beeld niet automatisch aangepast worden. Het is wel de bedoeling dat dit in de nieuwe versie wel mogelijk is.

Er zijn plannen om de ESP32 in te gaan zetten om de SWR te controleren en de eindtrap te beschermen. 100 watt is het maximum vermogen voor deze SWR uitvoering. Een hoger vermogen is mogelijk als je de berekening aanpast en de schaal X100 zet. Let daarbij ook op dat de ingang spanning aan de ADS1115 niet hoger wordt dan 5 volt. 
Gebruik in die situatie 2 weerstanden om de spanning te delen.

De touch zal ingezet gaan worden om de schaal aan te kunnen passen via een setup-menu voor meer dan 100 watt.

De reden dat er een ADS1115 (16bits) is ingezet als AD omzetter komt doordat de ESP32 AD omzetter een te klein bereik had die linear is. 800 t/m 2200 mv (12bits). Tot 150mv en na 2200 mv is het gedaan met het linear zijn. Ook kwam naar voren dat de AD van de ESP32 heel onstabiel is. Een extra condensator toegepast om hf te scheiden van de gelijkspanning werkte niet. Dat de ADS1115 wel stabiel is blijkt uit het feit dat er geen condensator aan de ingang is geplaast. DE ADS1115 is behoorlijk linear over een groot bereik. Dit is wat je terug ziet in de waarde van berekingen en de uitwerking op het display. Het is heel rustig en stabiel.

De formule die is toegepast voor de SWR berekening VSWR= 1+(Pref/Pfwd) /  1−(Pref/Pfwd)
In de prorgammering kun je zelf de schaal aanpassen en ijken als het nodig is.

Let op het ontwerp is getest met USB 5 volt. In de praktijk zal dit rond 4.5V zijn.  Als je een batterij wilt gebruiken van 3.7 volt zet er dan een omzetter naar 5 volt in. Mocht er na gebruik van een 5v module de waardes verlopen kun je deze zelf aanpassen in de code. 
Zal zelf een test uitvoeren om het verloop te controleren. Mocht dit zo zijn zal ik 2 codes neerzetten een voor USB 5v en een voor een batterij met 5 volt module. 
De laatste V9 versie heeft nu een relais die je kunt gebruiken om je eindtrap te beveiligen. Info staat in het script.
