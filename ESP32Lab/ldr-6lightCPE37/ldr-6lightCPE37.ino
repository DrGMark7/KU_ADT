constexpr int ANALOG_PIN = 4;

constexpr int PWM_FREQ = 5000;
constexpr int PWM_RES = 10;
constexpr int RED_CHANNEL = 0;
constexpr int YELLOW_CHANNEL = 1;
constexpr int GREEN_CHANNEL = 2;

constexpr int RED = 41;
constexpr int YELLOW = 40;
constexpr int GREEN = 39;

void setupPwm(int channel, int pin) {
  ledcSetup(channel, PWM_FREQ, PWM_RES);
  ledcAttachPin(pin, channel);
}

void setLed(int redValue, int yellowValue, int greenValue) {
  ledcWrite(RED_CHANNEL, redValue);
  ledcWrite(YELLOW_CHANNEL, yellowValue);
  ledcWrite(GREEN_CHANNEL, greenValue);
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  analogSetAttenuation(ADC_11db);

  setupPwm(RED_CHANNEL, RED);
  setupPwm(YELLOW_CHANNEL, YELLOW);
  setupPwm(GREEN_CHANNEL, GREEN);
}

void loop() {
  int sensorValue = analogRead(ANALOG_PIN);
  printf("%d\n", sensorValue);

  if (400 < sensorValue && sensorValue < 830) {
    setLed(0, 0, 1023);
  } else if (830 < sensorValue && sensorValue < 1260) {
    setLed(0, 0, 511);
  } else if (1260 < sensorValue && sensorValue < 1690) {
    setLed(0, 1023, 0);
  } else if (1690 < sensorValue && sensorValue < 2120) {
    setLed(0, 511, 0);
  } else if (2120 < sensorValue && sensorValue < 2550) {
    setLed(1023, 0, 0);
  } else if (2550 < sensorValue && sensorValue < 2980) {
    setLed(511, 0, 0);
  }

  delay(50);
}
