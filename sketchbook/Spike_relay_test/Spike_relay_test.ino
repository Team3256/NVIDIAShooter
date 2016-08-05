
//ticking bomb test for spike relay
// When 
int a;
void setup(){
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 a = 1000;
}

void loop(){
  
  
  if (a > 100){
    a-= 50;
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW); 
    delay(a);          
    digitalWrite(9, LOW); 
    digitalWrite(10, HIGH); 
    delay(a);
  }
  else if (a < 100 && a > 10){
    a-= 5;
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW); 
    delay(a);          
    digitalWrite(9, LOW); 
    digitalWrite(10, HIGH); 
    delay(a);
  }
  else{
    digitalWrite(9, LOW); 
    digitalWrite(10, LOW); 
  }
}
