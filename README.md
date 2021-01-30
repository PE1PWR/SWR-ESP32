# SWR-ESP32
SWR ESP32 TFT3.2
De software is vrij te gebruiken. Het is een SWR meter gebouwt met een ESP-32, ASD1115 en een tft 3.2 Touch. De touch staat wel in het schema maar is nog niet gebruikt in de programmering. Laatste versie is nu 3.0

Het script is geschreven voor voor een TFT 3.2 320 X 240 scherm. Als je een kleiner scherm gebruikt zal het beeld niet automatisch aangepast worden. Het is wel de bedoeling dat dit in de nieuwe versie wel mogelijk is.

Er zijn plannen om de ESP32 in te gaan zetten om de SWR te controleren en de eindtrap te beschermen. 100 watt is het maximum vermogen voor deze SWR uitvoering. Een hoger vermogen is mogelijk als je de berekening aanpast en de schaal X100 zet. Let daarbij ook op dat de ingang spanning aan de ADS1115 niet hoger wordt dan 5 volt. 
Gebruik in die situatie 2 weerstanden om de spanning te delen.

De touch zal ingezet gaan worden om de schaal aan te kunnen passen via een setup-menu voor meer dan 100 watt.

De reden dat ik een ADS1115 heb ikgezet als AD is dat de ESP32 AD een te klein bereik had die linear is. 800 t/m 2200 mv. Daarbij kwam ook naar voren dat de AD van de ESP32 heel onstabiel is. Ik heb een extra condensator toegapst om hf te scheiden van de gelijkspanning. Dit was echter niet voldoende. Dat de ADS1115 wel stabiel is moge blijken uit het feit dat er geen condensator aan de ingang is geplaast. Wat je meet zie je terug in de waarde van de berekingen.

De formule die is toegepast VSWR= 1+(Pref/Pfwd) /  1−(Pref/Pfwd)
In de prorgammering kun je zelf de schaal aanpassen en ijken.
