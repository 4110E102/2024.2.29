/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/
const byte ledPin[]={2,3,9,10,11,12};
byte led_length = sizeof(ledPin)/sizeof(ledPin[0]);
byte j=0;
byte direct=0;

void setup(){
    for(int i=0;i<led_length;i++)
        pinMode(ledPin[i],OUTPUT);
        }
    
void loop() {
    for(int i=0;i<led_length;i++){
        digitalWrite(ledPin[i],LOW);
    }
    digitalWrite(ledPin[j],HIGH);
    delay(200);

  if(direct==0){

    if(j==led_length-1)
        direct=1;
    else
    j++;
  } else {
    if(j==0)
        direct=1;
    else
        j--;
  }
}
