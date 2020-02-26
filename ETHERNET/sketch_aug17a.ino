#include<SPI.h>
#include<Ethernet2.h>
byte mac[] ={0x90,0xA2,0xDA,0x0F,0xFE,0x10};
IPAddress ip(192,168,1,227);
IPAddress subnet(255,255,255,0);
IPAddress gateway(192,168,1,1);
EthernetServer  server(80);

void setup() {
  Ethernet.begin(mac,ip,gateway,subnet);
  server.begin();
}

void loop() {
  EthernetClient client = server.available();
  if(client){
    while(client.connected()){
      if(client.available()){
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type;text/html");
        client.println();
        
        client.println("<!doctype html>");
        client.println("<html><head>");
        client.println("<title></title>");
        client.println("</head><body>");
        client.print("<img src=");
        client.print("https://i.imgur.com/I2uLJO2.png");
        client.print("/>");
        client.println("</body></html>");
        break;
      }
    }
    delay(1);
    client.stop();
  }
}
