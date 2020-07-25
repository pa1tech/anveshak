#include <Ethernet.h>
#include <SPI.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 0, 9 };

byte server[] = { 192, 168, 0, 2}; 
int port = 8000;

EthernetClient client;

void setup()
{
  Ethernet.begin(mac, ip);

  pinMode(31,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(35,OUTPUT);
  
  //Serial.begin(9600);
  //Serial.println("Connecting..");
  while(!client.connect(server,port))
  {
    //Serial.println("Connecting...");
  }
  //Serial.println("Connected :)");
}

void loop()
{
  if(client.available())
  {
    char c = client.read();
    switch(c)
    {
      case '0':
      digitalWrite(31,HIGH);
      digitalWrite(33,LOW);
      digitalWrite(35,LOW);
      break;

      case '1':
      digitalWrite(31,LOW);
      digitalWrite(33,HIGH);
      digitalWrite(35,LOW);
      break;

      case '2':
      digitalWrite(31,LOW);
      digitalWrite(33,LOW);
      digitalWrite(35,HIGH);
      break;
      
    }
    //Serial.println(c);
  }
  else
  {
    if(!client.connected())
    {
      client.stop();
      //Serial.println("Connecting...");
      client.connect(server,port);
    }
  }
}
