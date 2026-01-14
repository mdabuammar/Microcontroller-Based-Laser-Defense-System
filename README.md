**Arduino Ultrasonic Radar System with Servo Tracking & Processing Visualization**

A microcontroller-based ultrasonic radar system that scans its surroundings using a rotating ultrasonic sensor, detects object distance and angle, and visualizes the data in real time using a radar-style graphical interface built with Processing.
The system also supports laser-assisted object pointing using a second servo motor.

**Project Overview**

This project demonstrates how embedded systems, sensors, actuators, and PC-side visualization can be integrated into a single real-time system.
The ultrasonic sensor continuously sweeps across a defined angular range using a servo motor. At each angle, the distance of nearby objects is measured and sent to a computer via serial communication. A Processing application reads this data and displays it as a live radar screen.
When an object is detected within a predefined range, a laser module can be activated and aligned toward the detected position.

**Key Features**

Real-time ultrasonic distance measurement
Servo-based angular scanning (15°–165°)
Live radar visualization using Processing
Serial communication between Arduino and PC
Laser-assisted object pointing
Modular and easily extendable design

**Hardware Components**
Component	Quantity
Arduino Uno	1
HC-SR04 Ultrasonic Sensor	1
Servo Motor (Ultrasonic Scan)	1
Servo Motor (Laser Alignment)	1
Laser Module	1
Breadboard	1
Jumper Wires	As required
USB Cable	1
**Pin Configuration (Arduino Uno)**
Component	Arduino Pin
Ultrasonic TRIG	D10
Ultrasonic ECHO	D11
Scan Servo	D13
Laser Servo	D4
Laser Module	D6
VCC	5V
GND	GND

Note: For stable servo operation, use an external 5V power supply with a common ground.

**Software Requirements**

Arduino IDE
Processing (v4.x recommended)
Processing Serial Library (processing.serial.*)

**Project Structure**
Arduino-Ultrasonic-Radar/
│
├── Arduino/
│   └── Arduino.ino
│
├── Processing/
│   └── processing.pde
│
├── images/
│   ├── hardware_setup.jpg
│   ├── circuit_diagram.png
│   └── radar_output.png
│
├── README.md
└── LICENSE

**How the System Works**

The servo motor rotates the ultrasonic sensor across a fixed angular range.
At each angle, the HC-SR04 measures distance to nearby objects.
Arduino sends angle and distance data over Serial in the format:
angle,distance.

The Processing application reads the serial data and:
Draws a rotating radar sweep
Displays detected objects as visual markers

When an object is within a predefined distance:
The laser module activates
The second servo aligns the laser toward the detected angle

**Setup & Execution**
Step 1: Upload Arduino Code
Open Arduino.ino in Arduino IDE
Select:
Board: Arduino Uno
Port: Correct COM port
Upload the code

**Step 2: Run Processing Visualization**

Open processing.pde in Processing
Update the serial port name:
myPort = new Serial(this, "COM6", 9600);

Run the sketch 

**Customization Options**
Detection distance threshold
Radar display range
Servo sweep angles
Laser activation conditions
These parameters can be adjusted directly in the Arduino and Processing code.

Safety Notice
The laser module is used only for demonstration purposes
Do not point the laser at eyes or reflective surfaces
Use low-power laser modules suitable for educational environments

**Contributors**
MD Abu Ammar
Evana Tanzim Rupa
Kashfia Hossain

**License**
This project is intended for educational and academic use.
You may reuse or modify it for learning purposes with proper attribution.

**Future Improvements**
Object tracking and prediction
Multiple sensor fusion
Wireless communication (Bluetooth / Wi-Fi)
Data logging and replay
AI-based object classification
