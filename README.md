<h1>Automotive-Parameter-Monitoring-Using-CAN🚗</h1>

**📌 Project Overview**

Modern automobiles contain several Electronic Control Units (ECUs) that communicate through the CAN Bus instead of individual point-to-point wiring. This project simulates such an automotive network by implementing three independent CAN nodes connected through a common CAN bus.

Each node performs a dedicated task:   

Main Node – Controls the overall system, monitors temperature, receives fuel level data, and controls vehicle indicators.   
Fuel Node – Reads fuel level using ADC and transmits fuel information.   
Indicator Node – Receives turn indicator commands and displays LED scrolling patterns.   

All nodes communicate through the CAN protocol using the on-chip CAN controller of LPC2129 and the MCP2551 CAN transceiver.   

**🎯 Objectives**  

| Objective             | Description                                   |  
| --------------------- | --------------------------------------------- |  
| 🚗 CAN Communication  | Learn Controller Area Network protocol        |  
| 🔄 Multi-node System  | Implement communication between multiple ECUs |  
| 🌡 Sensor Interface   | Read engine temperature using DS18B20         |  
| ⛽ Fuel Monitoring     | Measure fuel level using ADC                  |  
| 💡 Indicator Control  | Control left/right indicators through CAN     |  
| 📺 Dashboard Display  | Display vehicle parameters on LCD             |  
| 🔌 Distributed System | Understand automotive embedded architecture   |  


**🏗️ System Architecture**  

                 +--------------------------------+  
                 |          MAIN NODE             |  
                 |--------------------------------|  
                 | LPC2129                        |  
                 | DS18B20 Temperature Sensor     |  
                 | 16x2 LCD                       |  
                 | Left & Right Switches          |  
                 +---------------+----------------+  
                                 |  
                           MCP2551 CAN  
                                 |  
      ========================= CAN BUS =========================  
                                 |  
            +---------------------------+--------------------+  
            |                                             |  
      +-------------+                                 +---------------+  
      | Fuel Node   |                                 | Indicator Node|  
      |-------------|                                 |---------------|  
      | LPC2129     |                                 | LPC2129       |  
      | ADC         |                                 | LEDs          |  
      | Fuel Sensor |                                 | LED Patterns  |  
      +-------------+                                 +---------------+  
  
**🧰 Hardware Components**

| Component                   | Quantity | Purpose                        |  
| --------------------------- | -------: | ------------------------------ |  
| LPC2129 ARM7 MCU            |        3 | Main controller for each node  |  
| MCP2551 CAN Transceiver     |        3 | CAN physical layer             |  
| DS18B20 Temperature Sensor  |        1 | Engine temperature measurement |  
| Potentiometer (Fuel Sensor) |        1 | Fuel level simulation          |  
| 16×2 LCD                    |        1 | Display temperature & fuel     |  
| Push Buttons                |        2 | Left & Right indicator control |  
| LEDs                        |        8 | Indicator simulation           |  
| 120Ω Resistors              |        2 | CAN bus termination            |  
| Crystal Oscillator          |        3 | MCU clock generation           |  
| 5V/3.3V Supply              |        1 | Power source                   |  


**💻 Software Requirements**  

| Software       | Purpose                       |  
| -------------- | ----------------------------- |  
| Keil µVision 5 | Code Development              |  
| Embedded C     | Programming Language          |  
| Flash Magic    | Program Download              |  
| Proteus        | Circuit Simulation (Optional) |  


**CAN Network Topology**

          120Ω                               120Ω  
        Termination                       Termination  
  
CANH ============================================== CANH  
  
CANL ============================================== CANL  

          MAIN NODE  
               │  
          FUEL NODE  
               │  
      INDICATOR NODE  

CAN is terminated with 120Ω resistors at both ends to eliminate signal reflections.  

<img width="680" height="503" alt="WhatsApp Image 2026-07-16 at 4 38 21 PM" src="https://github.com/user-attachments/assets/c0113445-d179-4d86-84d0-2a5bbaff9207" />


**🚘 Main Node**  

| Function                  | Description                        |  
| ------------------------- | ---------------------------------- |  
| 🌡 Temperature Monitoring | Reads engine temperature           |  
| 📺 LCD Display            | Displays temperature & fuel level  |  
| 📩 CAN Receiver           | Receives fuel level from Fuel Node |  
| 🚦 Indicator Control      | Reads switch status                |  
| 📤 CAN Transmitter        | Sends indicator commands           |  
| 🧠 Network Controller     | Coordinates all CAN communication  |  


main node work flow  

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

**⛽Fuel Node**

| Function         | Description                    |  
| ---------------- | ------------------------------ |  
| Fuel Measurement | Reads analog fuel level        |  
| ADC Conversion   | Converts analog to digital     |  
| CAN Transmission | Sends fuel percentage          |  
| Periodic Update  | Continuously updates Main Node |  

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

**💡Indicator Node**  
| Function        | Description                |  
| --------------- | -------------------------- |  
| CAN Receiver    | Receives indicator command |  
| LED Control     | Drives LEDs                |  
| Left Animation  | Right → Left scrolling     |  
| Right Animation | Left → Right scrolling     |  
  


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
 
  

<img width="680" height="440" alt="WhatsApp Image 2026-07-15 at 4 09 29 PM (1)" src="https://github.com/user-attachments/assets/2894d723-c507-41a1-8bb8-7b3faebe8bcf" />


**📊Project Workflow**    

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

**⭐Key Features**

| Feature                     | Description                    |  
| --------------------------- | ------------------------------ |  
| Multi-node CAN Architecture | Three independent controllers  |  
| Real-time Monitoring        | Live vehicle parameter display |  
| Fuel Level Monitoring       | ADC based                      |  
| Temperature Monitoring      | DS18B20 based                  |  
| Indicator Control           | CAN controlled                 |  
| Distributed Processing      | Multiple ECUs                  |  
| Modular Design              | Easy to expand                 |  
| Reliable Communication      | CAN Error Detection            |  


**🚀Advantages**  

| Benefit                 | Description                         |  
| ----------------------- | ----------------------------------- |  
| High Reliability        | Robust CAN communication            |  
| Reduced Wiring          | Single CAN network                  |  
| Fault Tolerance         | CAN Error Detection                 |  
| Real-time Communication | Fast data transfer                  |  
| Expandable              | Easy to add new nodes               |  
| Priority Arbitration    | Critical messages transmitted first |  
   

**🚙Applications**

| Application           |  
| --------------------- |  
| Passenger Vehicles    |  
| Electric Vehicles     |  
| Agricultural Machines |  
| Heavy Trucks          |  
| Industrial Automation |  
| Marine Systems        |  
| Smart Transportation  |  
| Automotive Education  |  


**📁Project Folder Structure**     

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

 **📺 Output**

| Module       | Output                                   |  
| ------------ | ---------------------------------------- |  
| Main Node    | Displays engine temperature              |  
| Fuel Node    | Sends fuel percentage continuously       |  
| Main Node    | Receives and displays fuel level         |  
| Left Switch  | LEDs scroll Right → Left                 |  
| Right Switch | LEDs scroll Left → Right                 |  
| CAN Bus      | Reliable communication between all nodes |  


<img width="504" height="200" alt="WhatsApp Image 2026-07-15 at 4 06 34 PM" src="https://github.com/user-attachments/assets/5b510585-ced7-4972-bec4-744b1d1ad098" />





**👨‍💻Author**  
*Rahul Rapelli*
