#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <LiquidCrystal.h>

#define RMP 9
#define RMN 8
#define LMP 10
#define LMN 11
#define trig 6
#define echo 7

SoftwareSerial gsm(2, 3);
TinyGPS gps;
SoftwareSerial ss(4, 5);
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

int flag = 1;
String mob;
String latt,lon;
int get_no = 1;
int gps_got=1;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(RMP,OUTPUT);
  pinMode(RMN,OUTPUT);
  pinMode(LMP,OUTPUT);
  pinMode(LMN,OUTPUT);
  lcd.begin(16,2);
  lcd.print("Railway Track");
  lcd.setCursor(0,1);
  lcd.print("Detection Robot");
  delay(2000);
  gsm.begin(9600);
  Serial.println(F("Initializing All Modules"));
  Serial.println(F("Checking for GSM Module"));
  gsm_init();
  get_num();
  lcd.clear();
  lcd.home();
  lcd.print("GPS Initializing");
  ss.begin(9600);
  while(gps_got)get_gps();
  ss.end();
  delay(1000);
  Serial.println(F("Setup Completed"));
}

void loop() {
  lcd.clear();
  lcd.home();
  lcd.print("Robot Started");
  while(level()<5){
    analogWrite(RMP,200);
    digitalWrite(RMN,LOW);
    analogWrite(LMP,200);
    digitalWrite(LMN,LOW);
    delay(500);
  }
  analogWrite(RMP,0);
    digitalWrite(RMN,LOW);
    analogWrite(LMP,0);
    digitalWrite(LMN,LOW);
  lcd.clear();
  lcd.home();
  lcd.print("Fault Detected");
  sendmsg();
  lcd.clear();
  lcd.home();
  lcd.print("Robot stopped");
  lcd.setCursor(0,1);
  lcd.print("Reset Arduino");
  while(1);
}

int level()
{
  int duration, distance;
  digitalWrite (trig, HIGH);
  delay(50);
  digitalWrite (trig, LOW);
  duration=pulseIn(echo,HIGH);
  distance=(duration*0.034)/2;
  Serial.println(distance);
  return distance; 
}

void sendmsg()
{
  String cmd, getstr,loct;
  getstr = "Alert: Fault Detected at ";
  loct = "https://www.google.co.in/maps/place/";
  loct += latt+","+lon;
  cmd =  "AT+CMGS=\"";
  cmd += String(mob);
  cmd +="\"";
  cmd +="\r";
  gsm.println("AT+CMGF=1");   
  delay(1000); 
  gsm.println(cmd); 
  delay(1000);
  gsm.println(getstr); 
  gsm.println(loct);     
  delay(100);
  gsm.println((char)26);    
  delay(1000);
  Serial.println(F("sending msg..."));
  lcd.clear();
  lcd.home();
  lcd.print("Sending msg..");
  delay(3000);
}

void gsm_init()
{
  Serial.println(F("Finding Module.."));
  lcd.clear();
  lcd.home();
  lcd.print("Finding GSM");
  int at_flag=1;
  while(at_flag)
  {
    gsm.println("AT");
    while(gsm.available()>0)
    {
      if(gsm.find("OK"))
      at_flag=0;
      lcd.setCursor(0,1);
      lcd.print("Module Connected");
      response();
      delay(1000);
    }
    delay(1000);
  }
  Serial.println(F("Module Connected.."));
  delay(1000);
  Serial.println(F("Finding Network.."));
  lcd.clear();
  lcd.home();
  lcd.print("Finding Network");
  int net_flag=1;
  while(net_flag)
  {
    gsm.println("AT+CPIN?");
    while(gsm.available()>0)
    {
      if(gsm.find("+CPIN: READY"))
      net_flag=0;
      lcd.setCursor(0,1);
      lcd.print("Network found");
      response();
    }
    delay(1000);
  }
  Serial.println(F("Network Found.."));
  delay(1000);
}

void response()
{
  while(gsm.available()!=0)
  Serial.write(char (gsm.read()));
}

void showResponse(int waitTime)
{
    long t=millis();
    char c;
    while (t+waitTime>millis()){
      if (gsm.available()>0){
          c=gsm.read();
          Serial.print(c);
      }
    }               
}

void get_gps()
{
  while (ss.available() > 0)
  if (gps.encode(ss.read()))
  Serial.println(F("getting gps"));
  displayInfo();
}

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    latt = String(gps.location.lat(),6);
    Serial.print(latt);
    Serial.print(",");
    lon = String(gps.location.lng(),6);
    Serial.println(lon);
    gps_got=0;
  }
  else
  {
    Serial.println(F("INVALID"));
     delay(500);
  }
}

void get_num()
{
  String str;
  char ch;
  int i,j;
  gsm.println("AT\r");
  delay(800);
  gsm.println("AT+CMGF=1");    
  delay(1000);
  gsm.println("ATA\r");
  delay(800);
  gsm.println("AT+CLIP=1\r");
  delay(800);
  showResponse(2000);
  Serial.println("Waiting for Incoming Call");
  lcd.clear();
  lcd.home();
  lcd.print("Waiting for call");
  while(get_no)
  {
    while(!gsm.available());
    if(gsm.available()>15)
    {
    while(gsm.available()>0)
    {
       str += String(char (gsm.read()));
    }
       Serial.print("content: ");
       Serial.print(str); 
    if(j=str.indexOf('"'))    
    {
      for(i=j+4,j=0;j<10;i++,j++)
      {
        mob+=str[i];
      }
      mob[j]='\0'; 
      gsm.println("ATH\r");
      delay(1000);
      get_no=0;
      //Serial.println("got num");
    }
    }
  }
  Serial.print("Mobile No:");
  Serial.println(mob);
  lcd.setCursor(0,1);
  lcd.print(mob);
  delay(2000);
}
