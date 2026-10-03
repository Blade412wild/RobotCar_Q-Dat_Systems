#include <Arduino.h>
#include "Vector2.h"
#include "EventManager.h"
#include "CustomEvent.h"

CustomEvent TestEvent;
int result;
bool eventTestBool = false;

// forward declarations
int myFunction(int x, int y);
void HandleTestEvent(void);
void InvokeEvent();

void setup()
{
  Serial.begin(115200);
  delay(1000);

  InitEvent(&TestEvent);
  AddListener(&TestEvent, HandleTestEvent);

  InvokeEvent();
}

void loop()
{
  // Serial.println(result);
  delay(1000);
}

int myFunction(int x, int y)
{
  return x + y;
}

void HandleTestEvent(void)
{
  Serial.println("event Works");
}

void InvokeEvent()
{

  if (!eventTestBool)
  {
    Invoke(&TestEvent);
    eventTestBool = true;
  }
}
