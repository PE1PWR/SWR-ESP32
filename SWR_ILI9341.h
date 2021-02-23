

#define SMOOTH_FONT
#define TFT_CLK 18
#define TFT_MISO 23
#define TFT_MOSI 19
#define TFT_DC 2
#define TFT_CS 4
#define TFT_RST 15    // Chip select for TFT screen
#define PB_PIN = 13
#define LED_PIN = 26
#define SPI_READ_FREQUENCY  40000000
#define SPI_FREQUENCY  80000000 
//#define SPI_TOUCH_FREQUENCY  2500000

#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts
#define number_of_readings 200 // Number of readings to hold in an array
#define major_graduations 0.1  // number_of_readings / 10 to set the scale graduations
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);// TFT 3.2 scherm
