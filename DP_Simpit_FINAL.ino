
/* Daniel P - Simpit WIP Code
   This is a simple code, by a simple man, for a simple controller
   It controls x Buttons, Throttle, y Toggle switches
   If you are brand new, I suggest getting the Arduino starter kit
   and completing the following tutorials:
      . Code Structure: https://arduinogetstarted.com/tutorials/arduino-code-structure
      . Serial Monitor: https://arduinogetstarted.com/tutorials/arduino-serial-monitor
      . LED Blink: https://arduinogetstarted.com/tutorials/arduino-led-blink
      . Button: https://arduinogetstarted.com/tutorials/arduino-button
      . On-Off Switch: https://arduinogetstarted.com/tutorials/arduino-switch
      . Debounce: https://arduinogetstarted.com/tutorials/arduino-button-debounce
      . EZButton: https://arduinogetstarted.com/tutorials/arduino-button-library
      . Potentiometer: https://arduinogetstarted.com/tutorials/arduino-potentiometer

      They're super easy and quick, and should give you just enough knowledge to know what's going on below.

  The discord is here: https://discord.com/channels/775343611780399144
  The subreddit is here: https://www.reddit.com/r/Kerbalcontrollers 
  
  Here's a list of button codes for mapping to keyboard pressses:
  https://github.com/Simpit-team/KerbalSimpitRevamped/blob/main/KerbalSimpit/Contrib/InputSimulator/WindowsInput/Native/VirtualKeyCode.cs

// Credits:
 - Developers:
          - Rogor
 - Code I used parts of:
          - PeteWasHere
          - xKoney
          - Daniel Wareham
          - Coda
          - There may be more, if you think I've used some of your code, let me know and I'll add you
 - SAS Button logos - Matthew Peverill
 - Help on the Discord:
          - Aleopardstail
          - Hyratel
     
*/

// Include your librarys
#include <KerbalSimpit.h>  // Gives all the definitions that the simpit mod uses
#include <ezButton.h>      // Makes button programming easier

// Constants won't change. They're used here to
// link the arduino pins to your buttons and switches:
// Buttons
ezButton STAGE_PIN = A0;    
ezButton NEXTVESSEL_PIN = A14;  
ezButton MAP_PIN = 51;  
ezButton SAVE_PIN = 49;
ezButton LOAD_PIN = 47;
ezButton TIMEUP_PIN = 45; 
ezButton TIMEDOWN_PIN = 43; 
ezButton TIMECANCEL_PIN = 41; 
ezButton TIMEMNVR_PIN = 39; 
ezButton GRAB_PIN = 37; 
ezButton BOARD_PIN = 35; 
ezButton JET_PIN = 33;
ezButton LETGO_PIN = 31; 

// SAS Buttons
ezButton STABASS_PIN = 13;   
ezButton MANEUVER_PIN = 11;   
ezButton PROGRADE_PIN = 9; 
ezButton RETROGRADE_PIN = 7;  
ezButton NORMAL_PIN = 5;    
ezButton ANTINORMAL_PIN = 3;  
ezButton RADIALIN_PIN = 14; 
ezButton RADIALOUT_PIN = 16; 
ezButton TARGET_PIN = 18;  
ezButton ANTITARGET_PIN = 20; 

 // Action Groups - Switches
ezButton SAS_PIN = 52; // the number of the SAS Pin
ezButton RCS_PIN = 53; // the number of the RCS Pin
ezButton ANTENNA_PIN = A7; // the number of the Antenna Pin - CAG 6
ezButton GEAR_PIN = A6; // the number of the Gear Pin
ezButton BRAKES_PIN = A5; // the number of the Brakes Pin
ezButton LIGHTS_PIN = A4; // the number of the Lights Pin
ezButton SOLAR_PIN = A3; // the number of the Solar Pin - CAG 7
ezButton LADDER_PIN = A2; // the number of the Ladder Pin - CAG 8
ezButton CHUTES_PIN = A1; // the number of the Chutes Pin - CAG 9

 // CAG Action Groups
ezButton CAG1_PIN = 29; 
ezButton CAG2_PIN = 27; 
ezButton CAG3_PIN = 25; 
ezButton CAG4_PIN = 23; 

// LEDS
const int MAP_LED = 50;      // the number of the Map LED pin
const int SAVE_LED = 48;      // the number of the Quicksave pin
const int LOAD_LED = 46;      // the number of the Quickload pin
const int TIMEUP_LED = 44;      // the number of the Time Up pin
const int TIMEDOWN_LED = 42;      // the number of the Time Down pin
const int TIMECANCEL_LED = 40;      // the number of the Time Warp Cancel pin
const int TIMEMNVR_LED = 38;      // the number of the Time Warp to Next Manouevre pin
const int GRAB_LED = 36;      // the number of the Grab pin
const int BOARD_LED = 34;      // the number of the Board pin
const int JET_LED = 32;      // the number of the Jet pin
const int LETGO_LED = 30;      // the number of the Let Go pin
const int CAG1_LED = 28;      // the number of the Grab pin
const int CAG2_LED = 26;      // the number of the Board pin
const int CAG3_LED = 24;      // the number of the Jet pin
const int CAG4_LED = 22;      // the number of the Let Go pin

// SAS LEDs
const int STABASS_LED = 12;    // the number of the Stability Assist pin
const int MANEUVER_LED = 10;    // the number of the Maneuver pin
const int PROGRADE_LED = 8;   // the number of the Prograde pin
const int RETROGRADE_LED = 6;    // the number of the Retrograde pin
const int NORMAL_LED = 4;    // the number of the Normal pin
const int ANTINORMAL_LED = 2;    // the number of the AntiNormal pin
const int RADIALIN_LED = 15;    // the number of the Radial Out pin
const int RADIALOUT_LED = 17;    // the number of the Radial In pin
const int TARGET_LED = 19;    // the number of the Target pin
const int ANTITARGET_LED = 21;    // the number of the AntiTarget pin

// Throttle and Joysticks
const int THROTTLE_PIN = A8; // the pin used for controlling throttle
const int PITCH_PIN = A11; // the pin used for controlling pitch
const int ROLL_PIN = A13; // the pin used for controlling roll
const int YAW_PIN = A12;    // the pin used for controlling yaw
const int TRANSY_PIN = A9;    // the pin used for the X translation axis
const int TRANSX_PIN = A10;    // the pin used for the Y translation axis

// Deadzones for the Joysticks
const int deadRangeLow  = 505; // Range for pitch and Yaw
const int deadRangeHigh = 525; // Range for pitch and Yaw
const int deadRangeRollLow  = 505; // Range for pitch and Yaw
const int deadRangeRollHigh  = 525; // Range for pitch and Yaw

// Map the SAS Modes to the bit values recieved from parsing the SAS_MODE_INFO_MESSAGE channel
const int SASOff = 0x00;
const int StabAss = 0x01;
const int Maneuver = 0x02;
const int Prograde = 0x03;
const int Retrograde = 0x04;
const int Normal = 0x05;
const int AntiNormal = 0x06;
const int RadialIn = 0x07;
const int RadialOut = 0x08;
const int Target = 0x09;
const int AntiTarget = 0x0A;

// Create a space for the Joystick Value to go when it's disabled
bool JoystickValue = false;

// Variables for joysticks
int16_t pitch;
int16_t roll;
int16_t yaw;
int16_t X;
int16_t Y;

//Store the current action status, as recevied by simpit.
byte currentActionStatus = 0;
//Create a byte for the SAS Modes
byte currentSASMode;

// the following variables are unsigned long's because the time, measured
// in miliseconds, will quickly become a bigger number than can be stored
// in an int. CHECK IF I NEED THIS WITH EZBUTTONS
// Do not duplicate
unsigned long lastDebounceTime = 0;  // the last time the output pin
                                     // was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase
                                     // if the output flickers

// Declare a KerbalSimpit object that will
// communicate using the "Serial" device.
KerbalSimpit mySimpit(Serial);

// This setup code runs once when initialised
void setup() {
  // Open the serial connection.
  Serial.begin(115200);

  // Set up the LED'S as outputs. You need to do this or they'll be super dim
  pinMode(SAVE_LED, OUTPUT);
  pinMode(LOAD_LED, OUTPUT);
  pinMode(MAP_LED, OUTPUT);
  pinMode(TIMEUP_LED, OUTPUT);
  pinMode(TIMEDOWN_LED, OUTPUT);
  pinMode(TIMECANCEL_LED, OUTPUT);
  pinMode(TIMEMNVR_LED, OUTPUT);
  pinMode(LETGO_LED, OUTPUT);
  pinMode(JET_LED, OUTPUT);
  pinMode(BOARD_LED, OUTPUT);
  pinMode(GRAB_LED, OUTPUT);
  pinMode(CAG1_LED, OUTPUT);
  pinMode(CAG2_LED, OUTPUT);
  pinMode(CAG3_LED, OUTPUT);
  pinMode(CAG4_LED, OUTPUT);    

// SAS LED OUTPUTS
  pinMode(STABASS_LED, OUTPUT);
  pinMode( MANEUVER_LED, OUTPUT);
  pinMode(RETROGRADE_LED, OUTPUT);  
  pinMode(PROGRADE_LED, OUTPUT);  
  pinMode(NORMAL_LED, OUTPUT);
  pinMode(ANTINORMAL_LED, OUTPUT);
  pinMode(RADIALIN_LED, OUTPUT);
  pinMode(RADIALOUT_LED, OUTPUT);
  pinMode(TARGET_LED, OUTPUT);
  pinMode(ANTITARGET_LED, OUTPUT);

  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  // Set the debounce times to prevent chattering on the ezbutton pins. Do this for every button.
  // Buttons
  STAGE_PIN.setDebounceTime(50); // 
  NEXTVESSEL_PIN.setDebounceTime(50);
  MAP_PIN.setDebounceTime(50);
  SAS_PIN.setDebounceTime(50); 
  RCS_PIN.setDebounceTime(50); 
  ANTENNA_PIN.setDebounceTime(50); 
  BRAKES_PIN.setDebounceTime(50); 
  GEAR_PIN.setDebounceTime(50); // 
  LIGHTS_PIN.setDebounceTime(50); // 
  LADDER_PIN.setDebounceTime(50); // 
  SOLAR_PIN.setDebounceTime(50); // 
  CHUTES_PIN.setDebounceTime(50); // 
  TIMEUP_PIN.setDebounceTime(50); // 
  TIMEDOWN_PIN.setDebounceTime(50); // 
  TIMECANCEL_PIN.setDebounceTime(50); // 
  TIMEMNVR_PIN.setDebounceTime(50); // 
  SAVE_PIN.setDebounceTime(50); // 
  LOAD_PIN.setDebounceTime(50); // 
  LETGO_PIN.setDebounceTime(50); // 
  JET_PIN.setDebounceTime(50); // 
  BOARD_PIN.setDebounceTime(50); // 
  GRAB_PIN.setDebounceTime(50); // 
  CAG1_PIN.setDebounceTime(50); // 
  CAG2_PIN.setDebounceTime(50); // 
  CAG3_PIN.setDebounceTime(50); // 
  CAG4_PIN.setDebounceTime(50); // 

// SAS Buttons
  STABASS_PIN.setDebounceTime(50); // 
  MANEUVER_PIN.setDebounceTime(50); // 
  RETROGRADE_PIN.setDebounceTime(50); // 
  PROGRADE_PIN.setDebounceTime(50); // 
  NORMAL_PIN.setDebounceTime(50); // 
  ANTINORMAL_PIN.setDebounceTime(50); // 
  RADIALIN_PIN.setDebounceTime(50); // 
  RADIALOUT_PIN.setDebounceTime(50); // 
  TARGET_PIN.setDebounceTime(50); // 
  ANTITARGET_PIN.setDebounceTime(50); // 

  // This loop continually attempts to handshake with the plugin.
  // It will keep retrying until it gets a successful handshake.
  while (!mySimpit.init()) {
    delay(100);
  }
  // Turn off the built-in LED to indicate handshaking is complete.
digitalWrite(LED_BUILTIN, LOW);
  // Display a message in KSP to indicate handshaking is complete.
  mySimpit.printToKSP("Connected", PRINT_TO_SCREEN);
  // Sets our callback function. The KerbalSimpit library will
  // call this function every time a packet is received.
  mySimpit.inboundHandler(messageHandler);
  // Send a message to the plugin registering channels we need.
  // The plugin will now regularly send messages on these channels while the
  // flight scene is active in-game.
  mySimpit.registerChannel(ACTIONSTATUS_MESSAGE);
  mySimpit.registerChannel(SAS_MODE_INFO_MESSAGE);
}

// Now we are going to program the behaviour for each button press
// This code runs continuously, monitoring the pins for input, and
// Reacting when an input is registered.
void loop() {
// Check for new serial messages.
mySimpit.update();

// Set EZButton to monitor the pins - Do this for every pin
// Just match it to the ezButton list above.
  // Buttons
  STAGE_PIN.loop(); // 
  NEXTVESSEL_PIN.loop(); // 
  MAP_PIN.loop(); // 
  SAS_PIN.loop(); // 
  RCS_PIN.loop(); // 
  BRAKES_PIN.loop(); // 
  GEAR_PIN.loop(); // 
  LIGHTS_PIN.loop(); // 
  ANTENNA_PIN.loop(); // 
  LADDER_PIN.loop(); // 
  SOLAR_PIN.loop(); // 
  CHUTES_PIN.loop(); // 
  TIMEUP_PIN.loop(); // 
  TIMEDOWN_PIN.loop(); // 
  TIMECANCEL_PIN.loop(); // 
  TIMEMNVR_PIN.loop(); // 
  SAVE_PIN.loop(); // 
  LOAD_PIN.loop(); // 
  LETGO_PIN.loop(); // 
  JET_PIN.loop(); // 
  BOARD_PIN.loop(); // 
  GRAB_PIN.loop(); // 
  CAG1_PIN.loop(); // 
  CAG2_PIN.loop(); // 
  CAG3_PIN.loop(); // 
  CAG4_PIN.loop(); // 
  
// SAS Buttons
  STABASS_PIN.loop(); // 
  MANEUVER_PIN.loop(); // 
  RETROGRADE_PIN.loop(); // 
  PROGRADE_PIN.loop(); // 
  NORMAL_PIN.loop(); // 
  ANTINORMAL_PIN.loop(); // 
  RADIALIN_PIN.loop(); // 
  RADIALOUT_PIN.loop(); // 
  TARGET_PIN.loop(); // 
  ANTITARGET_PIN.loop(); // 
 
// Now we tell our buttons what to do

  // STAGING
     if(STAGE_PIN.isPressed()){
      mySimpit.activateAction(STAGE_ACTION);
      }

  // SAS MODES

     if(STABASS_PIN.isPressed()){
      mySimpit.setSASMode(AP_STABILITYASSIST);
      }

     if(MANEUVER_PIN.isPressed()){
      mySimpit.setSASMode(AP_MANEUVER);
      }
     
     if(RETROGRADE_PIN.isPressed()){
      mySimpit.setSASMode(AP_RETROGRADE);
      }

     if(PROGRADE_PIN.isPressed()){
      mySimpit.setSASMode(AP_PROGRADE);
      }

     if(NORMAL_PIN.isPressed()){
      mySimpit.setSASMode(AP_NORMAL);
      }

     if(ANTINORMAL_PIN.isPressed()){
      mySimpit.setSASMode(AP_ANTINORMAL);
      }

     if(RADIALIN_PIN.isPressed()){
      mySimpit.setSASMode(AP_RADIALIN);
      }

     if(RADIALOUT_PIN.isPressed()){
      mySimpit.setSASMode(AP_RADIALOUT);
      }

     if(TARGET_PIN.isPressed()){
      mySimpit.setSASMode(AP_TARGET);
      }

     if(ANTITARGET_PIN.isPressed()){
      mySimpit.setSASMode(AP_ANTITARGET);
        mySimpit.printToKSP("Antitarget mode", PRINT_TO_SCREEN);
      }


  // TIMEWARP
    // TIME WARP UP - YES
     if(TIMEUP_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0xBE);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(TIMEUP_LED, HIGH);
  } 
     if(TIMEUP_PIN.isReleased()){
      digitalWrite(TIMEUP_LED, LOW);
      }

    // TIME WARP DOWN
     if(TIMEDOWN_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0xBC);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(TIMEDOWN_LED, HIGH);
  } 
     if(TIMEDOWN_PIN.isReleased()){
      digitalWrite(TIMEDOWN_LED, LOW);
      }
   
    // TIME WARP CANCEL
     if(TIMECANCEL_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0xBF);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(TIMECANCEL_LED, HIGH);
  } 
     if(TIMECANCEL_PIN.isReleased()){
      digitalWrite(TIMECANCEL_LED, LOW);
      }

   // TIME WARP TO NEXT MANEUVER
     if(TIMEMNVR_PIN.isPressed()){
        timewarpMessage timewarp;
        timewarp.command = TIMEWARP_NEXT_MANEUVER;
        mySimpit.send(TIMEWARP_MESSAGE, timewarp);
        digitalWrite(TIMEMNVR_LED, HIGH);
  }  
     if(TIMEMNVR_PIN.isReleased()){
      digitalWrite(TIMEMNVR_LED, LOW);
      mySimpit.printToKSP("End Warp to Maneuver!");
      }
      
// Save & Load

  // Save - YES
     if(SAVE_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0x74);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(SAVE_LED, HIGH);
  } 
     if(SAVE_PIN.isReleased()){
      digitalWrite(SAVE_LED, LOW);
      }
      
  // Load - Mapped to F6
     if(LOAD_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0x75, KEY_DOWN_MOD);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(LOAD_LED, HIGH);
  } 
     if(LOAD_PIN.isReleased()){
      keyboardEmulatorMessage keyMsg(0x75, KEY_UP_MOD);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(LOAD_LED, LOW);
      }
      
  // MAP
  if(MAP_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0x4D);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(MAP_LED, HIGH);
  } 
  if(MAP_PIN.isReleased()){
      digitalWrite(MAP_LED, LOW);
      }

  // CHANGE VESSEL
    // Next Vessel
  if(NEXTVESSEL_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0xDD);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
  } 


  // EVA Controls

    // Grab
    
  if(GRAB_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0x46);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(GRAB_LED, HIGH);
  } 
  if(GRAB_PIN.isReleased()){
      digitalWrite(GRAB_LED, LOW);
      }

    // Board
    
  if(BOARD_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0x42);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(BOARD_LED, HIGH);
  } 
  if(BOARD_PIN.isReleased()){
      digitalWrite(BOARD_LED, LOW);
      }

    // Jet

  if(JET_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0x52);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(JET_LED, HIGH);
  } 
  if(JET_PIN.isReleased()){
      digitalWrite(JET_LED, LOW);
      }

    // Let Go

  if(LETGO_PIN.isPressed()){
      keyboardEmulatorMessage keyMsg(0x20);
      mySimpit.send(KEYBOARD_EMULATOR,keyMsg);
      digitalWrite(LETGO_LED, HIGH);
  } 
  if(LETGO_PIN.isReleased()){
      digitalWrite(LETGO_LED, LOW);
      }
     

// And now our switches
// With these we need to do actions for each flick

// ACTION GROUPS
  // SAS Toggle

  if(SAS_PIN.isPressed()){
    mySimpit.printToKSP("Activate SAS!");
    mySimpit.activateAction(SAS_ACTION);
  }
  if(SAS_PIN.isReleased()){
    mySimpit.printToKSP("Deactivate SAS!");
    mySimpit.deactivateAction(SAS_ACTION);
  }

   // RCS Toggle

  if(RCS_PIN.isPressed()){
     mySimpit.printToKSP("Activate RCS!");
     mySimpit.activateAction(RCS_ACTION);
  }
  if(RCS_PIN.isReleased()){
     mySimpit.printToKSP("Deactivate RCS!");
     mySimpit.deactivateAction(RCS_ACTION);
  }
  
   // Brakes Toggle

  if(BRAKES_PIN.isPressed()){
    mySimpit.printToKSP("Activate Brakes!");
    mySimpit.activateAction(BRAKES_ACTION);
  }
  if(BRAKES_PIN.isReleased()){
    mySimpit.printToKSP("Deactivate Brakes!");
    mySimpit.deactivateAction(BRAKES_ACTION);
  }

    // Gear Toggle
  
  if(GEAR_PIN.isPressed()){
     mySimpit.printToKSP("Activate Gear!");
     mySimpit.activateAction(GEAR_ACTION);
  }
  if(GEAR_PIN.isReleased()){
     mySimpit.printToKSP("Deactivate GEAR!");
     mySimpit.deactivateAction(GEAR_ACTION);
  }

    // Lights Toggle - YES

  if(LIGHTS_PIN.isPressed()){
     mySimpit.printToKSP("Activate Lights!");
     mySimpit.activateAction(LIGHT_ACTION);
  }
  if(LIGHTS_PIN.isReleased()){
     mySimpit.printToKSP("Deactivate Lights!");
     mySimpit.deactivateAction(LIGHT_ACTION);
  }

 
 // CUSTOM ACTION GROUPS

   // Custom Action Group A1
   if(CAG1_PIN.isPressed()){
    mySimpit.activateCAG(1);
    digitalWrite(CAG1_LED, HIGH);
  }
   if(CAG1_PIN.isReleased()){
    mySimpit.deactivateCAG(1);
    digitalWrite(CAG1_LED, LOW);
  }
  
   // Custom Action Group A2
   if(CAG2_PIN.isPressed()){
    mySimpit.activateCAG(2);
    digitalWrite(CAG2_LED, HIGH);
  }
   if(CAG2_PIN.isReleased()){
    mySimpit.deactivateCAG(2);
    digitalWrite(CAG2_LED, LOW);
  }
  
    // Custom Action Group A3
   if(CAG3_PIN.isPressed()){
    mySimpit.activateCAG(3);
    digitalWrite(CAG3_LED, HIGH);
  }
   if(CAG3_PIN.isReleased()){
    mySimpit.deactivateCAG(3);
    digitalWrite(CAG3_LED, LOW);
  }

     // Custom Action Group A4
   if(CAG4_PIN.isPressed()){
    mySimpit.activateCAG(4);
    digitalWrite(CAG4_LED, HIGH);
  }
   if(CAG4_PIN.isReleased()){
    mySimpit.deactivateCAG(4);
    digitalWrite(CAG4_LED, LOW);
  }
  
   // Antenna Toggle - Custom Group 6
   if(ANTENNA_PIN.isPressed()){
    mySimpit.printToKSP("Activate Antenna!");
    mySimpit.activateCAG(6);
  }
   if(ANTENNA_PIN.isReleased()){
    mySimpit.printToKSP("Deactivate Antenna!");
    mySimpit.deactivateCAG(6);
  }

  // Solar Toggle - Custom Group 7
  if(SOLAR_PIN.isPressed()){
    mySimpit.printToKSP("Activate Solar!");
    mySimpit.activateCAG(7);
  }
  if(SOLAR_PIN.isReleased()){
    mySimpit.printToKSP("Deactivate Solar!");
    mySimpit.deactivateCAG(7);
  }

  // Ladder Toggle - Custom Group 8
  if(LADDER_PIN.isPressed()){
    mySimpit.printToKSP("Activate Ladders!");
    mySimpit.activateCAG(8);
  }
  if(LADDER_PIN.isReleased()){
    mySimpit.printToKSP("Deactivate Ladder!");
    mySimpit.deactivateCAG(8);
  }

  // Chutes Toggle - Custom Group 9
  if(CHUTES_PIN.isPressed()){
    mySimpit.printToKSP("Activate Chutes!");
    mySimpit.activateCAG(9);
  }
  if(CHUTES_PIN.isReleased()){
    mySimpit.printToKSP("Deactivate Chutes!");
    mySimpit.deactivateCAG(9);
  }
  
// THROTTLE
  // Send at each loop a message to control the throttle and the pitch/roll axis.
 
  throttleMessage throttle_msg;
  
  // Read the value of the potentiometer
  int reading = analogRead(THROTTLE_PIN);
  // Convert it in KerbalSimpit Range
  throttle_msg.throttle = map(reading, 25, 2000, 0, INT16_MAX);
  // Send the message
  mySimpit.send(THROTTLE_MESSAGE, throttle_msg);
  
  //Rotation
  // Send at each loop a message to control the throttle and the pitch/roll axis.
if (JoystickValue == true){
rotationMessage rot_msg;
  // Read the values of the potentiometers
  int reading_pitch = analogRead(PITCH_PIN);
  int reading_roll = analogRead(ROLL_PIN);
  int reading_yaw = analogRead(YAW_PIN);
  // Check if they are in the deadzone, if not, set the values to a KSP Figure
    // Pitch
  {if (reading_pitch < deadRangeLow)
   pitch = map(reading_pitch, 0, deadRangeLow, INT16_MIN, 0);
  else if (reading_pitch > deadRangeHigh)
    pitch = map(reading_pitch, deadRangeHigh , 1023, 0, INT16_MAX);
  else
    pitch = 0;}
    // Roll
{if (reading_roll < deadRangeRollLow)
 roll = map(reading_roll, 0, deadRangeRollLow, INT16_MIN, 0);
 else if (reading_roll > deadRangeRollHigh)
roll = map(reading_roll, deadRangeRollHigh , 1023, 0, INT16_MAX);
else
  roll = 0;}
    // Yaw
  {if (reading_yaw < deadRangeLow)
   yaw = map(reading_yaw, 0, deadRangeLow, INT16_MIN, 0);
  else if (reading_yaw > deadRangeHigh)
   yaw = map(reading_yaw, deadRangeHigh , 1023, 0, INT16_MAX);
  else
   yaw = 0;}
// Put those values in the message
 rot_msg.setPitch(pitch);
 rot_msg.setRoll(roll);
 rot_msg.setYaw(yaw);
 // rot_msg.setRoll(roll);
  // Send the message
  mySimpit.send(ROTATION_MESSAGE, rot_msg);
}
  // Translation
  // Send at each loop a message to control the tranlation.
  translationMessage trn_msg;
  // Read the values of the potentiometers
  int reading_transX = analogRead(TRANSX_PIN);
  int reading_transY = analogRead(TRANSY_PIN);

  // Check if they are in the deadzone, if not, set the values to a KSP Figure
    // X Axis
  {if (reading_transX < deadRangeLow)
    X = map(reading_transX, 0, deadRangeLow, INT16_MAX, 0);
  else if (reading_transX > deadRangeHigh)
    X = map(reading_transX, deadRangeHigh , 1023, 0, INT16_MIN);
  else
    X = 0;}
    // Y Axis
    
  {if (reading_transY < deadRangeLow)
    Y = map(reading_transY, 0, deadRangeLow, INT16_MAX, 0);
  else if (reading_transY > deadRangeHigh)
    Y = map(reading_transY, deadRangeHigh , 1023, 0, INT16_MIN);
  else
    Y = 0;}
    
  // Put those values in the message
  trn_msg.setX(X);
  trn_msg.setY(Y);
  // Send the message
  mySimpit.send(TRANSLATION_MESSAGE, trn_msg);
  
  }

void messageHandler(byte messageType, byte msg[], byte msgSize) {
  switch(messageType) {
  case ACTIONSTATUS_MESSAGE:
    // Checking if the message is the size we expect is a very basic
    // way to confirm if the message was received properly.
    if (msgSize == 1) {
      currentActionStatus = msg[0];
      //Let the LED_BUILIN match the current SAS state
      if(currentActionStatus & SAS_ACTION){
        digitalWrite(LED_BUILTIN, HIGH);
      } else {
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
    break;
    case SAS_MODE_INFO_MESSAGE:
        if (msgSize == sizeof(SASInfoMessage)) {
          SASInfoMessage sasMessage = parseSASInfoMessage(msg);
          switch (sasMessage.currentSASMode) {
            case AP_STABILITYASSIST:
              currentSASMode = StabAss;
              digitalWrite(STABASS_LED, HIGH);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW);
              JoystickValue = true;     
              break;
            case AP_MANEUVER:
              currentSASMode = Maneuver;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, HIGH);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);  
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW); 
              JoystickValue = false;     
              break;
            case AP_PROGRADE:
              currentSASMode = Prograde;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, HIGH);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW);
              JoystickValue = false;  
              break;
            case AP_RETROGRADE:
              currentSASMode = Retrograde;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, HIGH);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW);
              JoystickValue = false;     
              break;
            case AP_NORMAL:
              currentSASMode = Normal;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, HIGH);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW);    
              JoystickValue = false;     
             break;
            case AP_ANTINORMAL:
              currentSASMode = AntiNormal;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, HIGH);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW);  
              JoystickValue = false;     
              break;
            case AP_RADIALIN:
              currentSASMode = RadialIn;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, HIGH);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW);    
              JoystickValue = false;     
              break;
            case AP_RADIALOUT:
              currentSASMode = RadialOut;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, HIGH);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW);    
              JoystickValue = false;     
              break;
            case AP_TARGET:
              currentSASMode = Target;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, HIGH);     
              digitalWrite(ANTITARGET_LED, LOW);   
              JoystickValue = false;     
            
              break;
            case AP_ANTITARGET:
              currentSASMode = AntiTarget;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, HIGH);    
              JoystickValue = false;                
              break;
            default:
              currentSASMode = SASOff;
              digitalWrite(STABASS_LED, LOW);
              digitalWrite(MANEUVER_LED, LOW);
              digitalWrite(PROGRADE_LED, LOW);
              digitalWrite(RETROGRADE_LED, LOW);      
              digitalWrite(NORMAL_LED, LOW);
              digitalWrite(ANTINORMAL_LED, LOW);
              digitalWrite(RADIALIN_LED, LOW);     
              digitalWrite(RADIALOUT_LED, LOW);
              digitalWrite(TARGET_LED, LOW);     
              digitalWrite(ANTITARGET_LED, LOW);
              JoystickValue = true;                    
              break;
          };

       } 
      default:
        break;
}  
}
