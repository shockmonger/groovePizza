#include <Bounce.h>
int triggerPins1[8] = {0,1,2,3,4,5,6,7};  //Innermost layer, clockwise from 12
int triggerPins2[8] = {16,17,18,20,9,10,11,12}; //Outer layer, clockwise from 12
int tempo = 120;    //intitialize to 120bpm
int eighthMs;
int layer1NoteNumber = 48;    //C3
int layer2NoteNumber = 50;    //D3
int channel = 1;              
int beats = 8;
  
 
 void setup(){    //set pins to pullup mode
pinMode(0, INPUT_PULLUP);    //Layer 1, 12 o clock
pinMode(1, INPUT_PULLUP);
pinMode(2, INPUT_PULLUP); 
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);    
pinMode(16, INPUT_PULLUP);    //layer 2, 12 o clock
pinMode(17, INPUT_PULLUP);
pinMode(18, INPUT_PULLUP);
pinMode(20, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
pinMode(12, INPUT_PULLUP);

}
void loop(){
 
   for (int i = 0; i < beats; i++){
    //start by clearing al note ons
    usbMIDI.sendNoteOn(layer1NoteNumber, 0, channel); 
    usbMIDI.sendNoteOn(layer2NoteNumber, 0, channel);
    
   //pin 19 is connected to a cap sensor which serves as the mute button 
   if (touchRead(19) < 3000){  //if the mute button is not being pressed
  
   //if the present pin sees ground, meaning that something is closing circuit
  
  
   if (digitalRead(triggerPins1[i]) == LOW){
    usbMIDI.sendNoteOn(layer1NoteNumber, 127, channel);  //send the note
    }
    //if not, check to see if note's cap trigger was pressed (pin 22)
    else if(touchRead(22)>3000){
      usbMIDI.sendNoteOn(layer1NoteNumber, 127, channel);
    }
    
   //same as above for outer layer... check if pin sees ground
   if (digitalRead(triggerPins2[i]) == LOW){
    usbMIDI.sendNoteOn(layer2NoteNumber, 127, channel);
    }
    //otherwise check cap trigger, pin 23
    else if(touchRead(23)>3000){
      usbMIDI.sendNoteOn(layer2NoteNumber, 127, channel);
    }
   }
   //tempo range is approx 120 to 250
    tempo = analogRead(14) / 8 + 120;
    int swing = analogRead(15);
    //convert knob reading to ms value
    //the lower the coefficient (now 12), the more drastic the swing
    int swingMs = swing/tempo*12;  
    eighthMs = 30000/tempo;    //convert bpm to ms, becomes 8th note
    if (i%2 != 0)             
    delay (eighthMs - swingMs);  //subtract the swing time from 'ands'
    else
    delay (eighthMs + swingMs);  //add swing time to downbeats 
 }
 }
 
