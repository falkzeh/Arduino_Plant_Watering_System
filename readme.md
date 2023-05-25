# Arduino Plant Watering System

## Project Description

This project is an automated plant watering system designed for people like me who keep letting their plants die. It uses an Arduino UNO, moisture sensors, pumps, and a relay to provide a timely and accurate watering schedule for up to four plants. It aims to solve the problem of over watering or under watering, which are common issues in plant care.

---

## Features

- **Automatic Watering**: The system waters the plants automatically when the soil moisture levels fall below a certain threshold.
- **Moisture Level Monitoring**: The system consistently monitors the moisture level in the soil and adjusts the watering schedule accordingly.
- **Supports up to 4 Plants**: The system has the capability to water and monitor up to four plants simultaneously.

---

## Hardware Requirements

- Arduino UNO
- Soil Moisture Sensors (4x)
- Water Pumps (4x)
- Relay Module (4-channel)
- Breadboard
- Jumper Wires (assorted male-to-male, female-to-female, male-to-female)
- Hose (length depends on how far your plants are away from the water source)

---

## Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)

---

## Installation Guide

**Installing the Software**

Download and install the Arduino IDE from **[the official website](https://www.arduino.cc/en/Main/Software)**.

**Setting Up the Hardware:**

Connect the moisture sensors, pumps, and relay module to the Arduino UNO using the breadboard and jumper wires.

| Humidity Sensor | Arduino | Sensor |
| --- | --- | --- |
| Humidity Sensor 1 | A0 | AOUT |
| Humidity Sensor 1 | 5V | VCC |
| Humidity Sensor 1 | GND | GND |
| Humidity Sensor 2 | A1 | AOUT |
| Humidity Sensor 2 | 5V | VCC |
| Humidity Sensor 2 | GND | GND |
| Humidity Sensor 3 | A2 | AOUT |
| Humidity Sensor 3 | 5V | VCC |
| Humidity Sensor 3 | GND | GND |
| Humidity Sensor 4 | A3 | AOUT |
| Humidity Sensor 4 | 5V | VCC |
| Humidity Sensor 4 | GND | GND |

| Arduino | Four-Channel Relay |
| --- | --- |
| VCC | VIN |
| GND | GND |
| D2 | IN1 |
| D3 | IN2 |
| D4 | IN4 |
| D5 | IN5 |

I’m using the 5V output of the Arduino to power the sensors as well as the pumps. My super chaotic setup looks like this:

![IMG_20230523_205513333~2.jpg](screenshots/setup.jpg)

**Connecting the Hardware and Software:**

Upload the project code to the Arduino UNO via the Arduino IDE:

```cpp
const int NUM_SENSORS = 4;
int outputPins[NUM_SENSORS] = {2, 3, 4, 5};
int inputPins[NUM_SENSORS] = {A0, A1, A2, A3};
float values[NUM_SENSORS] = {0, 0, 0, 0};

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < NUM_SENSORS; i++) {
    pinMode(outputPins[i], OUTPUT);
    pinMode(inputPins[i], INPUT);
    digitalWrite(outputPins[i], HIGH);
  }
  delay(5);
}

void loop() {
  for(int i = 0; i < NUM_SENSORS; i++) {
    Serial.print("MOISTURE LEVEL ");
		Serial.print(i);
		Serial.print(" : ");
    values[i] = analogRead(inputPins[i]);
    Serial.println(values[i]);

    if(values[i] > 750) {
      digitalWrite(outputPins[i], LOW);
    } else {
      digitalWrite(outputPins[i], HIGH);
    }
  }

  Serial.println();
  delay(500);
}
```

---

## Usage

Once everything is set up, the system will start monitoring the moisture level of the soil for each plant. When the moisture level falls below a certain threshold, the respective pump will activate, watering the plant. The system runs continuously, ensuring your plants receive the optimal amount of water.

If you check your Serial Monitor, you should see outputs like this:

```bash
MOISTURE LEVEL 0 : 587
MOISTURE LEVEL 1 : 549
MOISTURE LEVEL 2 : 390
MOISTURE LEVEL 3 : 522
```
