//The Home Security System
//Team Members
//  Baranitharan B
//  Cibi P
//  Niyas Khan M
//Team Guide
//  Dr.charles.A(AP/ECE)
#include<ThingSpeak.h>
#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include<Servo.h>

unsigned long channel_num=1545534;
const char* ssID="Hari_animie";
const char* password="IiiamIiiam";
String REFID="554316";
String input;
String Command;
long int b5,c5;
//b5=0;
//c5=0; 
Servo drservo;
bool checkrefid;
int door = 2; //GPIO2-->D4
int vibration=4;//GPIO3->D2
int door_OC=D7;//GPIO-->D3
WiFiClient client;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
drservo.attach(door);
drservo.write(90);
pinMode(vibration,INPUT);
pinMode(door_OC,INPUT);
WiFi.begin(ssID,password);
Serial.print("connecting");
while (WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.print("Connected, IP address: ");
Serial.print(WiFi.localIP());
ThingSpeak.begin(client);
Serial.println("The Home Security System");
Serial.println("Enter your Command with REFID fist");
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(Serial.available()>0)
  //{
    input=String(ThingSpeak.readLongField(channel_num, 1,"00QD50X7HA9FWB02" ));
    input.trim();
    Serial.println("input=");
    Serial.print(input);
    checkrefid=checkREFID(input);
    if(checkrefid==true)
    {
      Serial.println("REFID Verified");
      Serial.println("recived command");
      Command=String(REFID+"09");
      //Serial.print(input);
      if(command_Check(input,Command))
      {
        drservo.write(0);
        Serial.println("Door lock opened");
       /* delay(10*1000);
        drservo.write(90);
        int evv1=ThingSpeak.writeField(channel_num,1,55576870,"UU5V6S2ASVKCIB4F");
        if(evv1!=200){
      Serial.println("data upload failed.. on numl");
      //vibbbb();*/
    }
    else if(command_Check(input,"55431621"))
    {
      drservo.write(90);
      Serial.println("Door Lock Closed");
      }
      else
      {
        //Serial.println(command);
        //Serial.println(input);
        Serial.println("command not identified");
      }
    }
    else
      Serial.println("REFID not matched");
  //}
 /* if(digitalRead(vibration)==HIGH)
  {
    Serial.println("vibration occured");
  }*/
  vibbbb();
  if(digitalRead(door_OC)==HIGH && c5!=936)
  {
    Serial.println("door is closed");
    int evv=ThingSpeak.writeField(channel_num,2,936,"UU5V6S2ASVKCIB4F");
    c5=936;
  }
  else if(digitalRead(door_OC)==LOW && c5!=110)
  {
    Serial.println("door is opened");
    int evv=ThingSpeak.writeField(channel_num,2,110,"UU5V6S2ASVKCIB4F");
    c5=110;
  }
}

void vibbbb()
{
  long v_meas=vpulse();
  delay(50);
  Serial.println(v_meas);
  if (v_meas<10000 && b5!=555)
  {
    int evv=ThingSpeak.writeField(channel_num,3,555,"UU5V6S2ASVKCIB4F");
    b5=555;
    if(evv!=200){
      Serial.println("data upload failed in low vibration..");
      Serial.println(evv);
      //vibbbb();
    }
    else
      Serial.println("data updated");
  }
  if (v_meas>10000 && v_meas<20000 && b5!=666)
  {
    int evv=ThingSpeak.writeField(channel_num,3,666,"UU5V6S2ASVKCIB4F");
    b5=666;
    if(evv!=200){
      Serial.println("data upload failed in medium vibration..");
      Serial.println(evv);
      
     // vibbbb();
    }
    else
      Serial.println("data updated");
  }
  if (v_meas>20000 && b5!=444)
  {
    int evv=ThingSpeak.writeField(channel_num,3,444,"UU5V6S2ASVKCIB4F");
    b5=444;
    if(evv!=200){
      Serial.println("data upload failed in high vibration..");
          Serial.println(evv);
          
      //vibbbb();
    }
    else
      Serial.println("data updated");
  }
}

long vpulse()
{
  delay(10);
  long v_meas=pulseIn(vibration,HIGH);
  return v_meas;
}
bool command_Check(String in1,String in2)
{
  int mismatch =0;
  if(in1.length()==in2.length())
  {
    for(int i=0; i<in2.length(); i++)
    {
      //Serial.println(String(i)+"->"+String(in1[i])+"="+String(in2[i]));
      if(in1[i]!=in2[i])
      {
        mismatch++;
      }
    }
  }
/*  else
  {
    //Serial.println(in1.length());
    //Serial.println(in2.length());
    //Serial.println("size not matched");
    return false;
  }*/
  if(mismatch==0)
    return true;
  else
  {
    Serial.println("mismatch="+String(mismatch));
    return false;}
}
bool checkREFID(String input1)
{
  int mismatch =0;
  for(int i=0; i<5; i++)
  {
    if(REFID[i]!=input1[i])
    {
      mismatch++;
    }
  }
    if(mismatch==0)
      return true;
    else
    {
      Serial.println("mismatch="+String(mismatch));
      return false;}
}
