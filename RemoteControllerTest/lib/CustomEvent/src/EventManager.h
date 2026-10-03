#ifndef EVENTMANAGER2_H
#define EVENTMANAGER2_H

#include <Arduino.h>
#include "CustomEvent.h"

//CustomEvent OnButtonPressLower;

// function declaration
// public
void InitEvent(CustomEvent *eventPtr); // initialize the event
void AddListener(CustomEvent *eventPtr, void (*func)()); // add a function that listens to the event 
void RemoveListener(CustomEvent *eventPtr, void (*func)()); // removes a fucntion that listens to the event
void Invoke(CustomEvent *eventPtr); // Invokes the event
void ShowEventArray(CustomEvent *eventPtr); 

// private
//"_" means don't use it outside this file"
void _RemoveListenerAtPoint(CustomEvent *eventPtr, int index);
void _UpdateListenerArray(CustomEvent *eventPtr, int startIndex);
int _GetIndex(CustomEvent *eventPtr, void (*func)());
void _Empty();

#endif

