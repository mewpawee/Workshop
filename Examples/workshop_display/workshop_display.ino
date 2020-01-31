#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(1);
void setup() {
display.begin(SSD1306_SWITCHCAPVCC, 0x3c); 
display.clearDisplay(); 
display.drawPixel(127, 63, WHITE);
display.setCursor(0,0);
display.println("Hi All to");
display.println("heyAll");
display.println("www.ArduinoAll.com");
display.display();
}

void loop() {
  for(int i =0;i < 20;i++){
  display.setCursor(0,50);
  display.print(i);
  display.display();
  }
  display.clearDisplay();
}
