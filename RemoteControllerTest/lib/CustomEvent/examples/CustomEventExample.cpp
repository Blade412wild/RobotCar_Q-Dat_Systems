#include <Arduino.h>
#include "EventManager.h"
#include "CustomEvent.h"

CustomEvent TestEvent;

// forward declarations
void HandleTestEvent(void);

void setup()
{
  Serial.begin(115200);

  InitEvent(&TestEvent); // initliaze 
  AddListener(&TestEvent, HandleTestEvent); // add a function to the event 

  Invoke(&TestEvent); //invokes event
}

void loop()
{

}

void HandleTestEvent(void)
{
  Serial.println("event Works");
}



