# Momentum
The 2016 2017 Robot for Team 1138

# Diagnostic Lights
What all the lights on the roboRIO, Talon, PDB, and Radio (Bridge) mean

## RoboRIO
### RoboRIO Power
- **Green** - Power is good.
- **Red Solid** - Fault condition. One or more user voltage rails are in short-citruit or overcurrent condition. Check user rails.
- **Red Flashing** - Input voltage is too high (> 16 V) and all outputs are disabled. Check user rails.
- **Yellow Solid** - Brownout condition. The 6 V user rail and outputs are disabled.

### RoboRIO Status
On while the controller is booting, then should turn off
- **2 blinks** - Software error, reimage roboRIO
- **3 blinks**- Safe Mode, restart roboRIO, reimage if not resolved
- **4 blinks** - Software crashed twice without reboting, reboot roboRIO, reimage if not resolved
- **Constant flash or stays solid on** - Unrecoverable error. Contact NI.

### RoboRIO Radio
- **Off** - No connection detected
- **Yellow Blinking** - Booting as access point. Radio is enable and access point is being constructed.
- **Yellow Solid** - Access point active. Radio is enabled and in access point mode.
- **Green Blinking** - Booting as bridge. Radio is enable and bridging is in progress.
- **Green Solid** - Bridge active. Radio is enabled and has bridge configured with SSID settings.
- **Red** - Reserved.

### RoboRIO Comm
- **Off** - No communication
- **Red Solid** - Communication with DS, but no user code
- **Red Blinking** - Driver station has E-Stopped the robot
- **Green Solid** - Good communication with DS, active
- **Yellow** - Reserved

### RoboRIO Mode
- **Off** - Outputs disabled (robot in Disabled, brown-out, etc.)
- **Yellow** - Autonomous Enabled
- **Green** - Teleop Enabled
- **Red** - Test Enabled or outputs unknown/undetermined

### RoboRIO RSL (Safety)
- **Solid** - Robot On and Disabled
- **Blinking** - Robot On and Enabled
- **Off** - Robot Off, roboRIO not powered, or RSL not wired properly

## Talon
### Talon Status
- **Flashing Red/Green** - Calibration Mode
- **Blinking Green** - Successful Calibration
- **Blinkng Red** - Failed Calibration

### Talon Blink Codes During Normal Operation
- **Both Blinking Green** - Forward throttle is applied. Blink rate is proportional to Duty Cycle.
- **Both Blinking Red** - Reverse throttle is applied. Blink rate is proportional to Duty Cycle.
- **No Lights** - No Power applied
- **Orange Alternate LEDs** - CAN bus detected, robot disabled
- **Slow Red Alternate LEDs** - CAN bus/PWM not detected
- **Fast Red Alternate LEDs** - Fault detected
- **Red/Orange Alternate LEDs** - Damaged Hardware
- **Red LEDs Strobe M+** - Forward Limit Switch or Forward Soft Limit
- **Red LEDs Strobe M-** - Reverse Limit Switch or Reverse Soft Limit
- **Green/Orange LED1** - In Boot-loader mode

### Talon B/C CAL Blink Codes
- **Solid Red** - Brake Mode
- **Off** - Coast Mode

## PDP
### PDP Fault Table
- **Green** - Robot Enabled/Disabled
- **Orange** - Sticky Fault
- **Red** - No CAM Comm

### PDP Special States Table
- **Red/Orange** - Damaged Hardware
- **Green/Orange** - Bootloader Mode
- **None** - No Power/Incorrect Polarity

## Radio
### Radio Power
- **Blinking blue** - Device is booting
- **Solid blue** - Boot has completed

### Radio Ethernet
- **Solid blue** - Cable is plugged in to each port
- **Blinking blue** - Traffic

### Radio WiFi
- **No Color** - Speed test (dashboard checkin) has not been run
- **Red Solid** - Speed to the gateway is below 1Mbps
- **Yellow Solid** - Speed to the gateway is above 1Mbps and below 2.5Mbps
- **Green Blink**- speed to the gateway is above 2.5Mbps
- **Red Blink** - node is in lonely mode (the radio assumes it is on the wrong WiFi channel)
- **Yellow Blink** - node is in orphan mode