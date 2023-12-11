constexpr int RED_PIN = 41;
constexpr int YELLOW_PIN = 40;
constexpr int GREEN_PIN = 39;
constexpr int SW_PIN = 42;

int Pins[] ={41,40,39};
int count;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(SW_PIN, INPUT_PULLUP);
  count = 0;
}


void loop() {
  while (digitalRead(SW_PIN) == 1){
    digitalWrite(Pins[count%3],1);
  }

  delay(10);
  printf("%d\n", count);
  while (digitalRead(SW_PIN) == 0){
    digitalWrite(Pins[count%3],0);
  }
  delay(10);
  count++;
}


