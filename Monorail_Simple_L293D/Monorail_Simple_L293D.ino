void setup() {
  // Jared McIntyre
  // Motor Pins

  int motorRight = 10;
  int motorLeft = 11;

  // Column Distance (In MS)




  // Button Initialization & Declaration
  pinMode(A0, INPUT_PULLUP); // Change Direction
  pinMode(A1, INPUT_PULLUP); // Off/on toggle



  Serial.begin(9600); // Begin 9600 baud
}

String Direction = "";

int distance = 2300;

void loop() {
  // put your main code here, to run repeatedly:

  /*
    Serial.println("Enter the direction.");
    while (Serial.available() == 0) {}
    Direction = Serial.readString();
    Serial.print("Chosen direction: ");
    Serial.println(Direction);

    if (Direction == "right") {
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
    }
    else if (Direction == "left") {
      digitalWrite(11, HIGH);
      digitalWrite(10, LOW);
    }
    else if (Direction == "stop") {
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
    }
  */


  // Move left for a period of int Distance, stop, then continue to the next column (int Distnace)

  // Stop and wait

    delay(distance);

    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);

    delay(distance);

    digitalWrite(11, LOW);
    digitalWrite(10, LOW);



}
