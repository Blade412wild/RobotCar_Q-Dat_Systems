#include <Arduino.h>
#include "Vector2.h"

int myFunction(int x, int y);


void setup()
{
  Serial.begin(115200);

  int result = myFunction(5, 7);
  //int buttomResult = ButtonTest(1,1);
  float Vector2Result =  testVector2(1.0f,2.0f);
  Serial.println(result);
}

void loop()
{
  delay(1000);
}

int myFunction(int x, int y)
{
  return x + y;
}

