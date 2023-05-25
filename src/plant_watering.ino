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