#include <stdio.h>
#include "EventManager.h"

void _Empty() { printf("Empty\n"); };

void AddListener(CustomEvent *eventPtr, void (*func)())
{
    if (eventPtr->ListenerCounter == MAX_LISTENERS)
    {
        printf("ListenersAreFull\n");
        return;
    }

    eventPtr->ListenerArray[eventPtr->ListenerCounter] = *func;
    eventPtr->ListenerCounter++;
}

void RemoveListener(CustomEvent *eventPtr, void (*func)())
{
    printf("\n-----Remove listener from array-----\n");

    if (eventPtr->ListenerCounter != 0)
    {
        int index = _GetIndex(eventPtr, *func);
        _RemoveListenerAtPoint(eventPtr, index);
    }
    else
    {
        Serial.printf("no event to remove\n");
    }
}

void Invoke(CustomEvent *eventPtr)
{
    //printf("\n\n---Invoke---\n");
    for (int i = 0; i < eventPtr->ListenerCounter; i++)
    {
        eventPtr->ListenerArray[i]();
    }
}

void InitEvent(CustomEvent *eventPtr)
{
    for (int i = 0; i < MAX_LISTENERS; i++)
    {
        eventPtr->ListenerArray[i] = _Empty;
    }
}

void ShowEventArray(CustomEvent *eventPtr)
{
    printf("\nshow all listeners\n");
    printf("size : %d \n", eventPtr->ListenerCounter);
    for (int i = 0; i < MAX_LISTENERS; i++)
    {
        printf("index : [%d] : ", i);
        eventPtr->ListenerArray[i]();
    }
}

int _GetIndex(CustomEvent *eventPtr, void (*func)())
{

    for (int i = 0; i < MAX_LISTENERS; i++)
    {
        if (eventPtr->ListenerArray[i] == *func)
        {
            printf("FOUND IT | i : %d\n", i);
            return i;
        }
    }
    
    return 0;
}

void _RemoveListenerAtPoint(CustomEvent *eventPtr, int index)
{
    eventPtr->ListenerArray[index] = _Empty;

    if (index < eventPtr->ListenerCounter)
        _UpdateListenerArray(eventPtr, index);
}

void _UpdateListenerArray(CustomEvent *eventPtr, int startIndex)
{
    printf("startIndex : %d, | counter : %d \n", startIndex, eventPtr->ListenerCounter);

    for (int i = startIndex; i < eventPtr->ListenerCounter; i++)
    {

        if (i == MAX_LISTENERS - 1)
        {
            printf("maxReached\n");
            eventPtr->ListenerArray[i] = _Empty;
            continue;
        }

        eventPtr->ListenerArray[i] = eventPtr->ListenerArray[i + 1];
    }

    // ListenerArray[MAX_LISTENERS] = Empty;

    eventPtr->ListenerCounter--;
}
