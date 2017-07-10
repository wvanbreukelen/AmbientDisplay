// Analog photonic sensor pin
const int sensor = A7;

// Allowed error between readings. Used to prevent screen flickering by changing the brightness leves continuously.
const int allowedError = 15;

// Number of times to check light level each read cycle.
const int times = 15;

// Previous value.
int prev = 0;

// Calculate average light level.
int calculateAverage(const int &times)
{
  int count = 0;
  
  for (int i = 0; i < times; ++i)
  {
    count += analogRead(sensor);
    delay(200);
  }

  return (count / times);
}

// Calculate brightness level for the monitor.
int calculateBrightness(const int &val)
{
  int b = (-0.09 * val) + 100;

  if (b > 100)
    return 100;

  if (b < 0)
    return 0;

  return b;
}

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);

  // Take a base reading
  prev = calculateAverage(times);
  
  delay(100);
  Serial.write(calculateBrightness(prev));
  delay(3000);
}

void loop()
{
  int val = calculateAverage(times);
  int diff = prev - val;
  
  if (abs(diff) > allowedError)
  {
    prev = val;
    Serial.write(calculateBrightness(val));
  }
  
  delay(3500);
}
