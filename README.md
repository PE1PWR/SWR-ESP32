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
