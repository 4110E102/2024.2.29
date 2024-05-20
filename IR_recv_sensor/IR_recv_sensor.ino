/*
 * 5-led control using infared manuly to move led array to right, left or both directions
IRE: 紅外線接收器 1838B 38kHz

  Must use IR_recv.ino to detect IR key setting buttons: 1. to right, 2. to left, 3. both
  library: https://github.com/Arduino-IRremote/Arduino-IRremote
*/

#include <IRremote.hpp>
byte IR_RECEIVE_PIN = 2; // Signal Pin of IR receiver 
//IRRawDataType IRRawData = 0x0;// 32 bits raw data

// declare sensor parameters?
const byte ledArrayPin[]={7, 8, 9, 10, 11, 12};
byte led_length = sizeof(ledArrayPin)/sizeof(byte);
 
byte direct, direct_t;        
byte j_led=0;

void setup(){
    Serial.begin(115200);
    Serial.println();
    Serial.println("Enabling IR pin");
    IrReceiver.begin(IR_RECEIVE_PIN); // Start the receiver
    Serial.println(String() + "Ready to receive IR signals at pin " + IR_RECEIVE_PIN);
    Serial.print(F("Ready to receive IR signals of protocols: "));
    printActiveIRProtocols(&Serial);
    
    Serial.println();
    Serial.println(String() + "initializing " + led_length + " LED..."); 
    for(byte i=0; i<led_length; i++)
        pinMode(ledArrayPin[i], OUTPUT); // to notify the led output 
}

void loop() {
    IRRawDataType IRRawData = 0x0;// 32 bits raw data
    uint16_t IRCMDData;

    for(byte i=0;i<led_length;i++){
        digitalWrite(ledArrayPin[i], LOW);  // 2 bits
    }
  
    // start IR sensor
    if (IrReceiver.decode()) { // check IR signal
        Serial.print(F("Decoded controller's protocol: "));
        Serial.println(getProtocolString(IrReceiver.decodedIRData.protocol));
        Serial.print(String() + "Decoded Raw Data: 0x" );
        IRRawData = IrReceiver.decodedIRData.decodedRawData;
        Serial.println(IRRawData, HEX); // Print "old" raw data

        Serial.print("The complete received data: ");
        IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
        Serial.print("The statement required to send this data: ");
        IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data

        Serial.print(String() + "Decoded Command Data: 0x" );
        IRCMDData = IrReceiver.decodedIRData.command;
        Serial.println(IRCMDData, HEX); // Print "old" raw data

        // IR control code
        if (IrReceiver.decodedIRData.protocol==UNKNOWN){
            Serial.println("The remote control device is no recognized.");
        } else if (IrReceiver.decodedIRData.protocol==NEC){
            
            if ((IRRawData==0xE916FF00) && (IRCMDData==0x16)){  // first key IR data
                direct = 0; 
                Serial.println("press 1st button >>");          
            } else if ((IRRawData==0xE619FF00) && (IRCMDData==0x19)){  // second key IR dat
                direct = 1;  
                Serial.println("press 2nd button >>");            
            } else if ((IRRawData==0xF20DFF00) && (IRCMDData==0xD)) { // third key IR data
                direct = 2;   
                direct_t = 0;
                j_led = 0; 
                Serial.println("press 3rd button >>");      
            } else {
              Serial.println("Not defined");
            }
        }
        IrReceiver.resume(); // Enable receiving of the next value
    }

    digitalWrite(ledArrayPin[j_led], HIGH);   
    delay(500);
    
    // sensors controlled by IR data
    switch (direct){
      case 0:  // 1: first --> last
          Serial.println(">>1st button is pressed");
          if(j_led==led_length-1){
              j_led = 0;
          } else{
            j_led++;
          }
          break;
      case 1:  // 2: last -- > first
          Serial.println(">>2nd button is pressed");
          if(j_led==0){
              j_led = led_length-1;
          } else{
            j_led--;
          }
          break;
      case 2: // 3: first <--> last
          Serial.println(">>3nd button is pressed");
          if(direct_t==0){
              if(j_led==led_length-1)
                direct_t=1;
              else
                 j_led++; 
          } else{
              if(j_led==0)
                  direct_t=0;
              else
                  j_led--;
          }
          break;
      default:
          Serial.println("Other button...");
          }     
          

    Serial.println(String() + "led direction: " + direct);
    Serial.println(String() + "flash @ " + j_led + " led");
    //delay(200); 
}
