// Global Variables & Objects
int railPos;
int channel1LastState = digitalRead(12);
int stateChannel1;
int stateChannel2;

// Constants

const int c1 = 0; // Starting position
const int c2 = 200;
const int c3 = 400;
const int c4 = 600;
const int c5 = 800;
const int c6 = 1000;

// Setup function

void setup() {

  pinMode(12, INPUT); // Channel 1
  pinMode(13, INPUT); // Channel 2

  // Motors

  pinMode(10, OUTPUT); // High, LEFT
  pinMode(9, OUTPUT); // High, RIGHT


  // Initalize lastStatusChannel1;


  Serial.begin(9600);

}

/* Method to get the current rail position of the mono-claw */

int currentrailPos() {

  stateChannel1 = digitalRead(12);
  stateChannel2 = digitalRead(13);

  if (stateChannel1 != channel1LastState) {
    if (stateChannel1 != stateChannel2) {
      railPos++;
    } else {
      railPos--;
    }

  }


  channel1LastState = stateChannel1;
  return railPos;
}


/* Method to tell the monoclaw where to go, (select a column from the console) *DEPRECATED* */

int ColumnSelect() {
  Serial.println("Enter the column in format: c[int]");
  while (Serial.available() == 0) {};
  int column = Serial.parseInt();


  // Take current rail position, determine if the specified rail position is either left or right

  if (column == 1) {
    return c1;
  }
  else if (column == 2) {
    return c2;
  }
  else if (column == 3) {
    return c3;
  }
  else if (column == 4) {
    return c4;
  }
  else if (column == 5) {
    return c5;
  }
  else if (column == 6) {
    return c6;
  }


}

/* Loop method */

void loop() {


  // Take inputs from channels, determine if a move has occured






  // The columns are about 200~ position units apart.

  int chosenColumn = ColumnSelect();
  Serial.print("Chosen Column ");
  Serial.println(chosenColumn);
  Serial.println(currentrailPos());

  if (chosenColumn >= railPos) {
    for (railPos = currentrailPos(); chosenColumn >= railPos  ; railPos = currentrailPos()) {



      Serial.println(currentrailPos());

      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);


    }
  }
  else if (chosenColumn <= railPos) {
    for (railPos = currentrailPos(); chosenColumn <= railPos  ; railPos = currentrailPos()) {



      Serial.println(currentrailPos());
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);


    }
  }


  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  /*
    for (int i = millis(); i >= 30000 ;) {
    randomSeed(millis());
    int chosenColumn = random(1, 6);


    if (chosenColumn >= railPos) {
      for (railPos = currentrailPos(); chosenColumn >= railPos  ; railPos = currentrailPos()) {




        digitalWrite(10, HIGH);
        digitalWrite(9, LOW);


      }
    }
    else if (chosenColumn <= railPos) {
      for (railPos = currentrailPos(); chosenColumn <= railPos  ; railPos = currentrailPos()) {



        digitalWrite(10, LOW);
        digitalWrite(9, HIGH);


      }
    }




    }
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
  */
}
