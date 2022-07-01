// whoops, spelled receiver wrong

// setup() runs once, when the device is first turned on.
SYSTEM_MODE(AUTOMATIC);
// #define FIRSTARGON
#define SECONDARGON
void setup()
{
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(D7, OUTPUT);
  pinMode(D6, INPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  // The core of your code will likely live here.
  #ifdef FIRSTARGON
  if (Serial.available() > 0)
  {
    char value = Serial.read();
    if (value == '1')
    {
      Serial1.write('O');
    }
    else if (value == '0')
    {
      Serial1.write('F');
    }
    else if (value == '?')
    {
      Serial1.write('G');
      delay(100ms);
      Serial.println();
      Serial.write(Serial1.read());
      Serial.println();
    }
  }
  #endif
  #ifdef SECONDARGON
  if (Serial1.available() > 0)
  {
    char value = Serial1.read();
    Serial.write(value);
    if (value == 'O')
    {
      digitalWrite(D7, HIGH);
    }
    else if (value == 'F')
    {
      digitalWrite(D7, LOW);
    }

    else if (value == 'G')
    {
      Serial1.print(digitalRead(D6));
    }
  }
  #endif
}