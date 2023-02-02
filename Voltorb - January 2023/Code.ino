// C++ code
// IEEE UVCE PES
// VOLTORB JAN 2023
void setup()
{
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  
  pinMode(3,INPUT);
  pinMode(2,INPUT);
  Serial.println("IEEE UVCE PES");
}

void loop(){
  while(digitalRead(2)){ // WHILE MODE IS AUTO
    Serial.println("AUTO MODE");
    //YELLOW
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    delay(500);
    
    //RIGHT
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    delay(5000);
    
    //YELLOW
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    delay(500);
    
    //LEFT
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    delay(5000);
  }// auto mode end
  
  while(!digitalRead(2)){
    Serial.println("MANUAL");
    //YELLOW
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    delay(500);
    
    while(digitalRead(3) && !digitalRead(2)){ // if left
      Serial.println("LEFT MANUAL");
        //LEFT
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
    }
    
    //YELLOW
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    delay(500);
    
    while(!digitalRead(3)&& !digitalRead(2)){ //if right
      //RIGHT
        Serial.println("RIGHT MANUAL");
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
      
    }
    
  }
  
}

