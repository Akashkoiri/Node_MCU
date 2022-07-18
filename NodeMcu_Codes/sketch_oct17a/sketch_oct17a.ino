#include <ESP8266WiFi.h>

WiFiClient client;                                 //diffine client variable
WiFiServer server(80);                        //define server variable

void setup() {
  Serial.begin(9600);
  WiFi.softAP("NodeMCU", "0987654321");                //NodeMCU is creating it's own wifi
  Serial.println();                                    // after the println line anything prints from a new line in serial moniter
  Serial.println("NodeMCU is started");  
  Serial.print(WiFi.softAPIP());                 //(WiFi.softAPlIP) used for checking network's IP address
  server.begin();                                      //server concept starts from here
  pinMode(LED_BUILTIN,OUTPUT);                    //defining the led
}
void loop() {
  client = server.available();                   //initialising that "client" is equal to "server.avilable()" //server.available() == 0
   if(client == 1)                                       //checking is any request has been come to the server
   {
       String request = client.readStringUntil('\n');           //reading the request sent by the client until the line ends & saving it on the string variable called request
        Serial.println(request);                                                //printing that request
        request.trim();                    //triming and saving only the main request other than garbage values

      if(request == "GET /ledon HTTP/1.1")    //checking that request by the user is similiar to this line
        {
            digitalWrite(LED_BUILTIN, LOW); //turning the LED on
        }
        if(request == "GET /ledoff HTTP/1.1")   //checking that request by the user is similiar to this line
        {
            digitalWrite(LED_BUILTIN,HIGH); //turning the LED off
        }
    }
    client.println("HTTP/1.1 200 OK");    
  client.println("Content-Type: text/html"); //This three line must be included before writing the code for printing the webpage on localserver
  client.println("");       
  client.println("<!Doctype html>");        
  client.println("<html>");         
  client.println("<head>");         
  client.println("<title>NodeMCU Controll page</title>");   
  client.println("</head>");          //write every line of code of that webpage in "client.println()" Function in the loop for controlling the device
  client.println("<a href=\"/ledon\"\"><button>ON</button></a>"); 
  client.println("<a href=\"/ledoff\"\"><button>OFF</button></a>"); 
  client.println("</body>");          
  client.println("</html>");
}
