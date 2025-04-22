# Simulation of Digital Lock System with GSM

This project demonstrates a GSM-based digital security lock system designed for improved home and commercial security. It utilizes Arduino along with the Proteus 8 simulator to emulate a secure locking mechanism that operates through password authentication and sends SMS alerts in case of unauthorized access attempts.

## Overview

The system includes a 4x4 matrix keypad for input, LED indicators for status feedback, a servo motor to simulate door locking/unlocking, and a GSM module to send alert messages.

- If the correct password is entered, the door unlocks.
- After three incorrect password attempts, an SMS alert is sent to the registered phone number, and a red LED blinks to indicate a security breach.

## Published Work

This project was presented at **ICIECE-2021** and is titled:

**"Simulation of Digital Lock System with GSM"**  
Authors: Devyani Nandanwar, Debarjun Paul, Akhila Subbarao, Luxmi Kumre  
Department of Electronics and Communication Engineering,  
Maulana Azad National Institute of Technology, Bhopal, India

## Components Used

- Arduino UNO  
- 4x4 Matrix Keypad  
- Servo Motor  
- GSM Module (SIM800/SIM900)  
- LED Indicators (Red and Green)  
- LCD Display (16x2)  
- Resistors and jumper wires  
- Breadboard or PCB  
- Proteus 8 Simulator

## Key Features

- Password-based digital locking  
- GSM alert system after multiple failed attempts  
- Real-time feedback with LED and LCD display  
- Fully simulated using Proteus 8

## Functional Workflow

1. User inputs password via the keypad.
2. If the password is correct:
   - Green LED lights up.
   - Servo motor rotates to simulate door unlocking.
3. If the password is incorrect:
   - Red LED blinks.
   - After three failed attempts, GSM module sends an SMS alert to the owner.

## Setup and Simulation

### Requirements

- Proteus 8 Professional  
- Arduino IDE  
- Basic knowledge of embedded C and microcontrollers

### Steps to Run the Simulation

1. Open the `.pdsprj` file using Proteus 8.
2. Use Arduino IDE to compile the provided `.ino` file and generate the `.hex` file.
3. Load the `.hex` file into the Arduino component within Proteus.
4. Run the simulation and interact with the virtual keypad.

## Project Structure
GSM-based-Security-System/ ├── CircuitDesign/ │ └── DigitalLockSystem.pdsprj ├── ArduinoCode/ │ └── digital_lock.ino ├── Images/ │ └── CircuitDiagram.png ├── Publication/ │ └── Simulation_of_Digital_Lock_System_with_GSM.pdf └── README.md


## License

This project is distributed under the MIT License.


