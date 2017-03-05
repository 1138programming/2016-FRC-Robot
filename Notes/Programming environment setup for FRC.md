Go to \Program Files and delete eclipse

Delete legends from wherever it is on the laptop

Open control panel
Select Programs and Features and uninstall the following:
a. Adblock
b. Android Studio
c. FRC Toolchain
d. FRC Radio Config Util 16.2
e. Java 32 bit if exists
f. Java 64 bit if is exists
g. HERO SDK
Reboot the Laptop

Install Java www.java.com

Instructions from WPLIB -> https://wpilib.screenstepslive.com/s/4485/m/13809/l/599681-installing-eclipse-c-java
Download and install HERO SDK
	http://www.ctr-electronics.com/hro.html#product_tabs_technical_resources
		CTRE Toolsuite Installer 4.4.1.9-nonadmin (.zip)
	move the c:\ folder into your workspace folder - c:\Users\eeuser\workspace
Download and install the C++ Toolchains
	download the toolchains (Windows Installer)
	open an admin command window
	change to users\eeuser\downloads
	msiexec /i FRC-2017-Windows-Toolchain-(Version).msi
	move the c:\frc folder into your workspace folder - c:\Users\eeuser\workspace
Download eclipse IDE for C++ Developers Windows 32 bit -> https://eclipse.org/downloads/packages/release/Mars/2
Extract eclipse to \Program Files
Launch eclipse and create the default workspace
Go to Help->Check for Updates
Skip to the Configuring eclipse section of WPLIB 
Enable the General->Workspace->Save automatically before build option
Enable the Install/Update->Automatic Updates->Look for updates each time Eclipse is started option
Installing the development plugins - Option 1: Online Install and follow the instructions.

In eclipse window->preferences->wpilib->team number set to 1138


Download Legends from Github and import it into you eclipse workspace.

Install GitHub for eclipse
