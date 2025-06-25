# Fall Detection System (Wearable IoT Device)

This project is a simple yet effective fall detection system using an **MPU 6050 accelerometer/gyroscope** and **NodeMCU**. It detects falls based on sudden acceleration changes and sends **real-time alerts** to the **Blynk App** on your smartphone.

## Features

- **Fall Detection**: Detects sudden motion changes indicating a fall.
- **Blynk Integration**: Sends instant notifications to your phone.
- **Customizable Thresholds**: Easily adjust sensitivity for different users.
- **Compact and Portable**: Ideal for wearable safety solutions.

---

## Components Used

| Component | Description |
|----------|-------------|
| NodeMCU  | WiFi-enabled microcontroller (ESP8266-based) |
| MPU 6050 | 3-axis accelerometer and gyroscope module |
| Blynk App | Mobile IoT app to receive alerts (Android/iOS) |

---

## Circuit Diagram & Connections

**MPU 6050:**

- VCC → 3.3V (NodeMCU)  
- GND → GND (NodeMCU)  
- SDA → D2 (GPIO 4 on NodeMCU)  
- SCL → D1 (GPIO 5 on NodeMCU)

---

## Installation & Setup

### 1. Hardware Setup
- Connect MPU 6050 to NodeMCU using the pins above.
- Ensure solid connections for reliable operation.

### 2. Software Requirements
Install the following via **Arduino IDE**:
- [Arduino IDE](https://www.arduino.cc/en/software)
- Blynk library (`Blynk`, `BlynkSimpleEsp8266`)
- MPU6050 library (`MPU6050_light`)

### 3. Blynk App Configuration
- Download **Blynk** (iOS/Android).
- Create a new project:
  - **Project Name**: Fall Detection  
  - **Device**: ESP8266  
  - **Connection Type**: WiFi  
- Add a **"Event Notification"** widget:
  - **Event Code**: `fall_detect`  
  - **Message**: `Fall detected! Check the person immediately.`  
- Copy the **Auth Token** from the Blynk app.

### 4. Configure the Code

- Open the provided code in **Arduino IDE**.
- Replace the placeholders in the code:
  - Replace `BLYNK_AUTH_TOKEN` with your **Blynk Auth Token**.
  - Replace `ssid` with your **WiFi network name**.
  - Replace `pass` with your **WiFi password**.

### 5. Upload the Code

- Connect the **NodeMCU** to your computer via USB.
- In Arduino IDE, select the correct board and port:
  - **Board**: NodeMCU 1.0 (ESP-12E Module)
  - **Port**: Choose the appropriate COM port
- Click **Upload** to flash the code onto the NodeMCU.

### 6. Test the System

- Power on the NodeMCU and wait for it to connect to WiFi.
- Open the **Serial Monitor** in Arduino IDE to view real-time logs.
- Simulate a fall (e.g., by jerking the **MPU 6050** module). If a fall is detected:
  - You will see a **"Fall detected!"** message in the Serial Monitor.
  - You will receive a **notification** on the Blynk app.

## Adjusting the Sensitivity

You can fine-tune the fall detection sensitivity by modifying the following variables in the code:

- `FALL_THRESHOLD`: Minimum acceleration change required to trigger a fall.  
  - *Lower values make the system more sensitive.*
- `FALL_DURATION`: Minimum duration (in milliseconds) of sustained acceleration change to register a fall.

## Troubleshooting

### 1. No WiFi Connection

- Ensure the SSID and password in the code are correct.
- Make sure the WiFi network is active and supports **2.4 GHz** (NodeMCU does not support 5 GHz).

### 2. MPU 6050 Not Detected

- Double-check the wiring between the MPU 6050 and NodeMCU.
- Make sure:
  - **SDA** is connected to **D2**
  - **SCL** is connected to **D1**

### 3. No Notifications from Blynk

- Confirm the **Blynk Auth Token** in the code matches your project.
- Ensure the event name in the Blynk app is set to `fall_detect`.

---

