# 🚗 Arduino Obstacle Avoiding Robot Car

A complete Arduino-based obstacle avoiding robot car using **2 IR sensors** and **L298N motor driver**.  
This project is designed for beginners who want to understand sensing, decision logic, and motor control from scratch.

---

## 🔧 Components Used

- Arduino Uno  
- L298N Motor Driver  
- 2x IR Sensors  
- 4x DC Gear Motors  
- 3S Lithium Battery  
- Jumper Wires  

---

## 🔌 Pin Connections

| Component | Arduino Pin |
|------------|------------|
| IN1 | 8 |
| IN2 | 9 |
| IN3 | 10 |
| IN4 | 11 |
| ENA | 5 (PWM) |
| ENB | 6 (PWM) |
| IR Left | 2 |
| IR Right | 3 |

> ⚠️ Note: Make sure all grounds (Arduino, Motor Driver, Battery, IR Sensors) are connected together (Common Ground).

---

## ⚙️ How It Works

The robot uses **2 IR sensors** to detect obstacles.

### 🧠 Decision Logic:

- Both clear → Move Forward  
- Left detects obstacle → Turn Right  
- Right detects obstacle → Turn Left  
- Both detect obstacle → Reverse  

The decision logic runs continuously inside the Arduino loop, allowing real-time reaction.

---

## 📂 Files Included

- `obstacle_avoider.ino` – Complete working Arduino code  
- `wiring-diagram.png` – Exact wiring diagram used in the project  

---

## 🧱 Mechanical Design

You can view the complete 3D mechanical layout of this robot here:

🔗 https://www.tinkercad.com/things/6SZ6rdJAexD-ir-sensor

---

## 🎥 YouTube Tutorial

Watch the full build video here:

▶️ https://youtu.be/nvVCJ8mCtR8

---

## 🚀 Future Improvements

Some possible upgrades:

- Replace IR with Ultrasonic sensor  
- Add Bluetooth control  
- Upgrade to ESP32 WiFi control  
- Add speed smoothing and non-blocking logic  

---

## 📜 License

This project is open-source and free to use for educational purposes.
