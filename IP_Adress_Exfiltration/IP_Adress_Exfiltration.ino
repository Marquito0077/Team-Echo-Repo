  //PROGRAM DEVELOPED BY ANTHONY L. ALVAREZ 
#include "DigiKeyboard.h";  //For Digispark

void setup() {
  //empty
}
void loop() {

  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("https://www.whatismyip.com/");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(70, MOD_GUI_LEFT); //For full screenshot
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("File Explorer");
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(43); //Tab Key Stroke
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.print("Home\\Screenshots");
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(43);
  DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
  //FOR TESTING PURPOSES 
  DigiKeyboard.sendKeyStroke(0,MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("Word");
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(600);
  DigiKeyboard.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT);




  for(;;){ /*empty*/ }
}