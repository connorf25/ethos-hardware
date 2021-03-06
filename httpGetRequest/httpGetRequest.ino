/*
 LG01  HTTP Client

 This example for the LG01 shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to the Arduino
 website and download a version of the logo as ASCII text.

 created by Tom igoe
 May 2013
 modified by Dragino
 May 2017


 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/HttpClient

 */

#include <Bridge.h>
#include <HttpClient.h>
#define BAUDRATE 115200

/*
 * Simple Sketch
 */
void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  Bridge.begin(BAUDRATE);
  digitalWrite(A2, HIGH);

  Console.begin();

  while (!Console); // wait for a serial connection
  digitalWrite(A2, LOW);
  Console.println("Ready to Go!");
}

void loop() {
  // Initialize the client library
  HttpClient client;

  // Make a HTTP request:
  Console.println("Sending Request...");

  /*
   * If wanting to use POST, will need to transfer
   * data to linux first via bridge/serial, and then use a
   * python script
   */
  client.get("10.130.1.216:3000");

  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    Console.print(c);
  }
  // Console.flush();

  delay(5000);
}
