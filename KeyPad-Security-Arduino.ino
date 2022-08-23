#include <Keypad.h>
#include <string.h>

String seccode = "1380AB";
byte rows[4] = {2,3,4,5};
byte columns[4] = {6,7,8,9};
char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
String code ="";
Keypad keypad = Keypad(makeKeymap(keys),rows,columns,4,4);
void setup() 
{
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  digitalWrite(11,LOW);
}

void loop()
{
  char select = keypad.waitForKey();
  code+=select;
  if(select ==  '#' || select == '*')
  {
    code = "";
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
  else
  {
  if(validation(code) && code.length() == seccode.length())
  {
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
  }
  else if(code.length() == seccode.length() && validation(code) == false)
  {
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
  }
  }
}
bool validation(String acode)
{
   
   if(acode == seccode)
   {
     return true;
   }
   else
     return false;
}
