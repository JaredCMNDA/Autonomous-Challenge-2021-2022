void setup() {
  // put your setup code here, to run once:


  pinMode(12, INPUT);
  pinMode(13, INPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);

}

int currentPos = 0;
int setPos;
int aState;
int aLastState = digitalRead(12);

void loop() {
  // put your main code here, to run repeatedly:


   aState = digitalRead(12); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(13) != aState) { 
       currentPos ++;
     } else {
       currentPos --;
     }
     Serial.print("Position: ");
     Serial.println(currentPos);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
 }


  
