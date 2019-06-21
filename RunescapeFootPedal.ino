/*
   RuneScape Foot Pedal
   For Leonardo and Due boards only. Controls mouse clicks from 
   a pushbutton on an Arduino Leonardo, Micro or Due.
   
   Hardware:
   * 1 x pushbutton attached to D6
   * 1 x 10k resistor
*/

#include "Mouse.h"

// set pin number for the button
const int mouseButton = 6;

int responseDelay = 1; // response delay of the mouse, in ms

void setup() {
   // initialise the button input
   pinMode(mouseButton, INPUT);
   
   // initialise mouse control
   Mouse.begin();
}

void loop() {
   // read the button state
   int clickState = digitalRead(mouseButton);

   // if the mouse button is pressed
   if (clickState == HIGH) {
      // if the mouse is not pressed, press it
      if (!Mouse.isPressed(MOUSE_LEFT)) {
         Mouse.press(MOUSE_LEFT);
      }
   } else { // else the mouse button is not pressed
      // if the mouse is pressed, release it
      if (Mouse.isPressed(MOUSE_LEFT)) {
         Mouse.release(MOUSE_LEFT);
      }
   }
   
   // a slight delay
   delay(responseDelay);
}
