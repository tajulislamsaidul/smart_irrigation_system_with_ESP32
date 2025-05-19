---

# 🌿 Smart Irrigation System with ESP32

This project demonstrates a **smart irrigation system** built using the **ESP32 development board**, integrated with **Blynk IoT platform**, a **soil moisture sensor**, **LCD display**, **relay module**, and a **mini water pump**. It allows real-time monitoring and control of watering through both web and mobile interfaces.

## 📷 System Overview

 ![Image Alt](https://github.com/tajulislamsaidul/smart_irrigation_system_with_ESP32/blob/282b65ee19618addebe99b4ae2a28cbb4c49c6e9/photo_6149782698856661942_y.jpg)
 ![Image Alt](image_url)
---

## 📦 Components Used

* ESP32 DevKit V4
* Soil Moisture Sensor
* LCD Screen with I2C Module
* Single-channel Relay Module
* Mini Water Pump & Pipe
* Breadboard
* Jumper Wires
* Blynk Cloud Dashboard (Web & Mobile)

---

## 🛠️ Step-by-Step Assembly Instructions

### 🔌 Hardware Setup

1. **Install ESP32 board on the breadboard.**
2. **Power Lines Setup:**

   * ESP32 `Vin` → Breadboard `+`
   * ESP32 `GND` → Breadboard `-`
3. **Connect Soil Moisture Sensor:**

   * VCC → Breadboard `+`
   * GND → Breadboard `-`
   * AO → ESP32 `Pin 33`
4. **Connect I2C LCD Display:**

   * GND → Breadboard `-`
   * VCC → Breadboard `+`
   * SDA → ESP32 `Pin 21`
   * SCL → ESP32 `Pin 22`
5. **Connect Relay Module:**

   * VCC → ESP32 `3.3V`
   * GND → Breadboard `-`
   * IN → ESP32 `Pin 4`
   * COM → Breadboard `+`
   * NO → Water Pump `+`
   * Water Pump `-` → Breadboard `-`
6. **Power Supply:**

   * Connected USB to the ESP32 for power supply to the stable relay and pump operation.

---

### 📱 Blynk Web Dashboard Configuration

1. Go to [Blynk Cloud](https://blynk.cloud), sign up or log in.
2. Create a **new template** named `smartirrigationnsystem`.
3. Under **Datastreams**, add:

   * **Soil moisture value**: `V0`, Min: `0`, Max: `100`
   * **Water pump**: `V1`, Min: `0`, Max: `1`
4. Create a **Web Dashboard**:

   * Add **Gauge Widget** for `V0`
   * Add **Button Widget** for `V1`
5. Link widgets to their corresponding datastreams.
6. Create a new **Device** and assign it the template.

---

### 📲 Blynk Mobile App Setup

1. Install the **Blynk IoT App** from the App Store/Google Play.
2. Log in with your Blynk credentials.
3. Select the previously created template.
4. Add:

   * **Button Widget** linked to `V1`
   * **Gauge Widget** linked to `V0`
5. Customize the UI as needed.

---

## 💻 Programming the ESP32

1. Connect ESP32 to your PC using a USB cable.
2. Open `Arduino IDE`.
3. Install the **ESP32 board support** and required libraries.
4. Copy and paste the code from [`smart_irrigation_systemwith_ESP32.ino`](./smart_irrigation_systemwith_ESP32.ino).
5. Replace with your:

   * **WiFi SSID**
   * **WiFi Password**
   * **Blynk Auth Token**
6. Select the correct **Board** (`ESP32 Dev Module`) and **Port**.
7. Upload the sketch.

---

## ✅ Features

* 🌱 **Soil Moisture Monitoring**
* 💧 **Auto and Manual Pump Control**
* 📊 **Real-time Data Display (Web & Mobile)**
* 📱 **Remote Access with Blynk Cloud**
* 🔌 **Relay-based Pump Activation**

---

## 🧠 Future Improvements

* Add **DHT11/DHT22** for temperature/humidity sensing.
* Integrate **rain detection** module.
* Use **deep sleep** mode for power saving.

---

## 📃 License

This project is open-source under the MIT License.

---
