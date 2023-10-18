/*
I expect this code to recieve and print a string of characters recieved over i2c
The next steps, provided this works are to:
- create a buffer in this code
- store the string in the buffer as it is recieved
- parse the string stored in the buffer into usable motor commands

very useful link:
https://admantium.com/blog/micro12_tutorial_i2c_connection/

By: Whit Whittall
*/

#include <Wire.h>

void setup() {
  Wire.begin(0x08);  // Set the Arduino as a slave with address 0x08
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);  // Do something in the loop if needed
}

void receiveEvent(int byteCount) {
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
}

