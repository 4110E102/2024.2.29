

/*
IRE: 紅外線接收器 1838B 38kHz
// http://www.righto.com/2010/11/testing-arduino-ir-remote-library.html
// https://github.com/Arduino-IRremote/Arduino-IRremote
After successful decoding, the IR data is contained in the IRData structure, available as IrReceiver.decodedIRData.

struct IRData {
    decode_type_t protocol;        // UNKNOWN, NEC, SONY, RC5, PULSE_DISTANCE, ...
    uint16_t address;              // Decoded address
    uint16_t command;              // Decoded command
    uint16_t extra;                // Used for Kaseikyo unknown vendor ID. Ticks used for decoding Distance protocol.
    uint16_t numberOfBits;         // Number of bits received for data (address + command + parity) - to determine protocol length if different length are possible.
    uint8_t flags;                 // IRDATA_FLAGS_IS_REPEAT, IRDATA_FLAGS_WAS_OVERFLOW etc. See IRDATA_FLAGS_* definitions
    IRRawDataType decodedRawData;    // Up to 32 (64 bit for 32 bit CPU architectures) bit decoded raw data, used for sendRaw functions.
    uint32_t decodedRawDataArray[RAW_DATA_ARRAY_SIZE]; // 32 bit decoded raw data, to be used for send function.
    irparams_struct *rawDataPtr; // Pointer of the raw timing data to be decoded. Mainly the data buffer filled by receiving ISR.
};
*/

#include <IRremote.hpp>
byte IR_RECEIVE_PIN = 2; // Signal Pin of IR receiver
IRRawDataType myRawData;// = 0x0;
uint16_t myCMDData;
//uint32_t myRawData;

void setup(){
    Serial.begin(115200);
    Serial.println();
    Serial.println("Enabling IR pin");
    // Start the receiver and if not 
    // 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.println(String() + "Ready to receive IR signals at pin " + IR_RECEIVE_PIN);
    Serial.println("Ready to receive IR signals of protocols: ");
    printActiveIRProtocols(&Serial);

    // infos for receive
    Serial.println("/n------Info for receive------");
    Serial.print(RECORD_GAP_MICROS);
    Serial.println(F(" us is the (minimum) gap, after which the start of a new IR packet is assumed"));
    Serial.print(MARK_EXCESS_MICROS);
    Serial.println(F(" us are subtracted from all marks and added to all spaces for decoding"));
}

void loop() {
    if (IrReceiver.decode()) {
        Serial.println();
        Serial.print(F("Decoded controller's protocol: "));
        Serial.println(getProtocolString(IrReceiver.decodedIRData.protocol));

        Serial.print(String() + "Decoded Raw Data: 0x" );
        myRawData = IrReceiver.decodedIRData.decodedRawData;
        Serial.println(myRawData, HEX); // Print "old" raw data
        
        Serial.print(String() + "Decoded Command Data: 0x" );
        myCMDData = IrReceiver.decodedIRData.command;
        Serial.println(myCMDData, HEX); // Print "old" raw data
        
        /* USE NEW 3.x FUNCTIONS */
        Serial.print("The complete received data: ");
        IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
        Serial.print("The statement required to send this data: ");
        IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data 
  
        auto control_type = IrReceiver.decodedIRData.protocol;
        Serial.println(String() + "Controller protocol: " + getProtocolString(control_type));
        auto control_address = IrReceiver.decodedIRData.address;
        Serial.print("IR data address: 0x");
        Serial.println(control_address, HEX);
  
        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
        } 
        
        IrReceiver.resume(); // Enable receiving of the next value
    }
  
    delay(1000);
}
