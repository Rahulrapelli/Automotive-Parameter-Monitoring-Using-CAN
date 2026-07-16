**Automotive-Parameter-Monitoring-Using-CAN**

**📌 Project Overview**

Modern automobiles contain several Electronic Control Units (ECUs) that communicate through the CAN Bus instead of individual point-to-point wiring. This project simulates such an automotive network by implementing three independent CAN nodes connected through a common CAN bus.

Each node performs a dedicated task:   

Main Node – Controls the overall system, monitors temperature, receives fuel level data, and controls vehicle indicators.   
Fuel Node – Reads fuel level using ADC and transmits fuel information.   
Indicator Node – Receives turn indicator commands and displays LED scrolling patterns.   

All nodes communicate through the CAN protocol using the on-chip CAN controller of LPC2129 and the MCP2551 CAN transceiver.   

**🎯 Objectives**  

Learn CAN Bus communication.  
Understand distributed embedded systems.  
Implement multi-node communication.  
Interface sensors with LPC2129.  
Develop real-time automotive applications.  
Reduce wiring complexity using CAN.  

**🏗️ System Architecture**  

                +------------------------+  
                |      MAIN NODE         |  
                |------------------------|  
                | LPC2129               |  
                | LCD                   |  
                | DS18B20               |  
                | Left Switch           |  
                | Right Switch          |  
                +-----------+-----------+  
                            |  
                      MCP2551 Transceiver  
                            |  
====================== CAN BUS ======================  
        |                                  |  
        |                                  |  
+-------+-------+                  +-------+--------+  
|   FUEL NODE   |                  | INDICATOR NODE |  
|---------------|                  |----------------|  
| LPC2129       |                  | LPC2129        |  
| ADC           |                  | 8 LEDs         |  
| Fuel Sensor   |                  | Indicator LEDs |  
+---------------+                  +----------------+  

**🧰 Hardware Components**

Component	Quantity	Purpose  
LPC2129 ARM7 MCU	3	Main Controller for each node  
MCP2551 CAN Transceiver	3	CAN Physical Layer  
DS18B20 Temperature Sensor	1	Engine Temperature  
Potentiometer/Fuel Sensor	1	Fuel Level Measurement  
16x2 LCD	1	Display Temperature & Fuel  
Push Buttons	2	Left & Right Indicators  
LEDs	8	Indicator Simulation  
120Ω Resistors	2	CAN Bus Termination  
Crystal Oscillator	3	MCU Clock  
Power Supply	5V/3.3V	System Power  

**💻 Software Requirements**  

Software	Purpose  
Keil uVision 5	Program Development  
Embedded C	Programming Language  
Flash Magic	Program Download  
Proteus (Optional)	Simulation  
Communication Protocol  
Protocol	Usage  
CAN	Node Communication  
One Wire	DS18B20 Temperature Sensor  
ADC	Fuel Sensor Reading  
GPIO	LEDs, LCD, Switches 

**CAN Network Topology**

120Ω                               120Ω  
RT                                    RT  

CANH ----------------------------------------- CANH  

CANL ----------------------------------------- CANL  

        MAIN  
          |  
        FUEL  
          |  
     INDICATOR  

CAN is terminated with 120Ω resistors at both ends to eliminate signal reflections.  

<img width="680" height="503" alt="WhatsApp Image 2026-07-16 at 4 38 21 PM" src="https://github.com/user-attachments/assets/c0113445-d179-4d86-84d0-2a5bbaff9207" />


**1️⃣ Main Node**  

Responsibilities  
Reads Engine Temperature  
Displays Temperature on LCD  
Receives Fuel Level  
Reads Left Indicator Switch  
Reads Right Indicator Switch  
Sends Indicator Commands  
Coordinates CAN Network  
Connected Peripherals  
Peripheral	Interface  
LCD	GPIO  
DS18B20	One Wire  
Left Switch	External Interrupt  
Right Switch	External Interrupt  
MCP2551	CAN  
Main Node Working  
Temperature Monitoring  

The DS18B20 continuously measures engine temperature.  

DS18B20  
     ↓  
LPC2129  
     ↓  
LCD Display  
Fuel Display  

Receives fuel percentage from Fuel Node.  

Fuel Node  
      ↓  
CAN Bus  
      ↓  
Main Node  
      ↓  
LCD  
Indicator Control  
Switch Pressed  
      ↓  
Main Node  
      ↓  
CAN Message  
      ↓  
Indicator Node  
      ↓  
LED Animation

**2️⃣ Fuel Node**

Responsibilities  
Reads Analog Fuel Sensor  
Converts Analog Voltage to Digital  
Calculates Fuel Percentage  
Sends Fuel Data over CAN  
Connected Hardware  
Peripheral	Interface  
Fuel Sensor	ADC  
MCP2551	CAN  
Working  
Fuel Sensor  
      ↓  
ADC  
      ↓  
LPC2129  
      ↓  
CAN Message  
      ↓  
Main Node  
Fuel Percentage Calculation  

**3️⃣ Indicator Node**  

Responsibilities  
Receives Indicator Command  
Controls LEDs  
Displays Left Animation  
Displays Right Animation  
LED Operation 
Animation moves  
Right → Left  
Right Indicator  
Animation moves  
Left → Right  

**CAN Communication Flow** 

Fuel Sensor  
     ↓  
Fuel Node  
     ↓  
CAN Frame  
     ↓  
Main Node  
     ↓  
LCD  
Left Switch  
      ↓  
Main Node  
      ↓  
CAN Frame  
      ↓  
Indicator Node  
      ↓  
LED Animation  
 
**Project Workflow**    

<img width="680" height="440" alt="WhatsApp Image 2026-07-15 at 4 09 29 PM (1)" src="https://github.com/user-attachments/assets/2894d723-c507-41a1-8bb8-7b3faebe8bcf" />

Power ON  
↓  
Initialize LCD  
↓  
Initialize CAN  
↓  
Initialize DS18B20  
↓  
Initialize ADC  
↓  
Wait for CAN Messages  
↓  
Read Sensors  
↓  
Send CAN Frames  
↓  
Receive Frames  
↓  
Display Results  
↓  
Repeat Forever

**Key Features**

Multi-node CAN network architecture  
Real-time sensor monitoring  
Fuel level measurement using ADC  
Digital temperature measurement using DS18B20    
CAN-based indicator control  
Distributed processing using three LPC2129 controllers  
16×2 LCD for real-time monitoring  
Reliable communication with CAN error detection  
Low wiring complexity compared to point-to-point communication  
Modular and scalable design  

**Advantages**  

High communication reliability  
Fault-tolerant network  
Fast real-time data transfer  
Reduced wiring harness  
Easy addition of new ECU nodes  
Supports priority-based message transmission  
Suitable for automotive applications   

**Applications**

Passenger vehicles  
Electric vehicles (EVs)  
Agricultural machinery  
Heavy-duty trucks  
Industrial automation  
Marine control systems  
Smart transportation systems  
Automotive ECU development and education

**Project Folder Structure**     

Automotive-CAN-Bus-System/  
│  
├── Main_Node/  
│   ├── main.c  
│   ├── can.c  
│   ├── lcd.c  
│   ├── ds18b20.c  
│   ├── interrupt.c  
│   └── include/  
│  
├── Fuel_Node/  
│   ├── main.c  
│   ├── adc.c  
│   ├── can.c  
│   └── include /  
│  
├── Indicator_Node/  
│   ├── main.c  
│   ├── led.c  
│   ├── can.c  
│   └── include /  
│  
├── README.md  
└── LICENSE  

 **Output**

LCD displays engine temperature in real time.    
Fuel node continuously measures and sends fuel percentage to the main node.  
Main node receives and displays the fuel level on the LCD.  
Pressing the Left Indicator switch causes LEDs on the Indicator Node to scroll from right to left.  
Pressing the Right Indicator switch causes LEDs to scroll from left to right.  
All communication occurs over the CAN bus, with reliable message transmission between nodes.  

<img width="504" height="200" alt="WhatsApp Image 2026-07-15 at 4 06 34 PM" src="https://github.com/user-attachments/assets/5b510585-ced7-4972-bec4-744b1d1ad098" />


