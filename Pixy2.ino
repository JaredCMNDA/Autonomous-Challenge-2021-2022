
// Libraries

#include <Pixy2.h>

// Init

Pixy2 pixy; // Pixy object

// Variables

int y_threshold = 100;
int x1 = 15;
int x2 = 52;
int x3 = 96;
int x4 = 141;
int x5 = 189;
int x6 = 233;
int x7 = 280;
int I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12;
int index[] = {I1, I2, I3, I4, I5, I6, I7, I8, I9, I10, I11, I12}; // Index
int count1, count2, count3; // Counting number of blocks for each sig


void setup() {
  Serial.begin(9600);
  pixy.init();
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


  getObjects();
  Serial.println("\n\n\n\n");
  errCheck();
  delay(20000);


}

void getObjects() {
  pixy.ccc.getBlocks();
  for (int i = 0; i < pixy.ccc.numBlocks; i++) {
    sortObject(pixy.ccc.blocks[i]);
  }
}

void errCheck() {
  for (int i = 0; i <= 11; i++) {
    if (index[i] == 1) {
      count1 = count1 + 1;
    } else if (index[i] > 1) {
      count2 = count2 + 1;
    } else if (index[i] == 0) {
      count3 = count3 + 1;
    }
  }


  if (count1 < 4 || count2 < 4 || count3 < 4) {
    Serial.println("Pixy err -> Less than 4 blocks for one of the signatures -- Refreshing");
    getObjects();
  } else {
    Serial.println("Index has been updated");
    for (int i = 0; i <= 11; i++) {
      Serial.print(index[i]);
      Serial.print(", ");
    }
  }
}

void sortObject(Block object) {
  int signature = object.m_signature;
  int x = object.m_x;
  Serial.print("(");
  Serial.print(x);
  Serial.print(",");
  Serial.print(object.m_y);
  Serial.print("),");

  if (signature == 1) {
    // Gold

    if (object.m_y < y_threshold) {
      // Upper Row

      if (x > x1 && x < x2) {
        // I1
        index[0] = 1;

      } else if (x > x2 && x < x3) {
        // I2
        index[1] = 1;

      } else if (x > x3 && x < x4) {
        // I3
        index[2] = 1;

      } else if (x > x4 && x < x5) {
        // I4
        index[3] = 1;

      } else if (x > x5 && x < x6) {
        // I5
        index[4] = 1;

      } else if (x > x6 && x < x7) {
        // I6
        index[5] = 1;

      }

    } else {
      // Lower Row


      if (x > x1 && x < x2) {
        // I7
        index[6] = 1;

      } else if (x > x2 && x < x3) {
        // I8
        index[7] = 1;

      } else if (x > x3 && x < x4) {
        // I9
        index[8] = 1;

      } else if (x > x4 && x < x5) {
        // I10
        index[9] = 1;

      } else if (x > x5 && x < x6) {
        // I11
        index[10] = 1;

      } else if (x > x6 && x < x7) {
        // I12
        index[11] = 1;

      }

    }

  }
  //
  //
  //
  else if (signature > 1) {
    // Anything else

    if (object.m_y < y_threshold) {
      // Upper Row

      if (x > x1 && x < x2) {
        // I1
        index[0] = 2;

      } else if (x > x2 && x < x3) {
        // I2
        index[1] = 2;

      } else if (x > x3 && x < x4) {
        // I3
        index[2] = 2;

      } else if (x > x4 && x < x5) {
        // I4
        index[3] = 2;

      } else if (x > x5 && x < x6) {
        // I5
        index[4] = 2;

      } else if (x > x6 && x < x7) {
        // I6
        index[5] = 2;

      }

    } else {
      // Lower Row

      if (x > x1 && x < x2) {
        // I7
        index[6] = 2;

      } else if (x > x2 && x < x3) {
        // I8
        index[7] = 2;

      } else if (x > x3 && x < x4) {
        // I9
        index[8] = 2;

      } else if (x > x4 && x < x5) {
        // I10
        index[9] = 2;

      } else if (x > x5 && x < x6) {
        // I11
        index[10] = 2;

      } else if (x > x6 && x < x7) {
        // I12
        index[11] = 2;

      }

    }

  }






}
