void driving() {
  
  /*if (FMRS_1 == 1 && FRS_1 == 1)
  {
    switch (juncounter) {
      case 0:
        turn_Left();
        delay(400);
        juncounter = 1;
        juncounter2 = 2;
        clockStart2();
        clockStart();
        break;

      case 1:
        if (clockCheck3() == true) {
          move_Forward();
          delay(200);
          juncounter = 2;
          clockStart2();
        }
        break;

      case 2:
        if (clockCheck3() == true) {
          turn_Right();
          delay(500);
          move_Forward();
          delay(700);
          stop_Movement();
          delay(2000);
          turn_Right();
          delay(500);
          //STATE = PICKING;
          juncounter = 3;
          clockStart2();
        }
        break;

      case 3:
        move_Forward();
        delay(400);
        juncounter = 4;
        clockStart2();
        break;

      case 4:
        if (clockCheck4() == true) {
          turn_Right();
          delay(500);
          move_Forward();
          delay(800);
          stop_Movement();
          delay(2000);
          //STATE = PICKING;
          juncounter = 5;
          juncounter2 = 3;
        }
        break;

      case 5:
        move_Forward();
        delay(100);
        juncounter = 6;
    }
  }
  //If both left sensors detect
  if (FMLS_1 == 1 && FLS_1 == 1)
  {
    switch (juncounter2) {
      case 1:
        turn_Left();
        delay(400);
        juncounter2 = 2;
        juncounter = 1;
        clockStart();
        clockStart2();
        break;

      case 2:
        if (clockCheck() == true) {
          move_Forward();
          delay(200);
          stop_Movement();
          delay(2000);
          juncounter = 5;
          juncounter2 = 3;
          clockStart();
        }
        break;

      case 3:
        if (clockCheck() == true) {
          digitalWrite(50, HIGH);
          turn_Left();
          delay(1000);
          juncounter2 = 4;
          clockStart();
        }
        break;

      case 4:
        if (clockCheck() == true) {
          digitalWrite(50, LOW);
          move_Forward();
          delay(400);
          juncounter2 = 5;
        }
        break;

      case 5:
        digitalWrite(50, HIGH);
        move_Forward();
        delay(700);
        stop_Movement();
        //STATE = DROP;
        juncounter2 = 1;
        digitalWrite(50, LOW);
        break;
    }
  }
  *///If central and left sensors detect
  else if (FCS_1 == 1 && FLS_1 == 1)
  {
    turn_Left();
  }
  //If middle left and right sensors detect right has priority
  if (FRS_1 == 1 && FLS_1 == 1)
  {
    move_Forward();
  }
  //If right sensor detect
  else if (FRS_1 == 1)
  {
    turn_Right();
    delay(50);
  }
  //If left sensor detect
  else if (FLS_1 == 1)
  {
    turn_Left();
    delay(50);
  }
  //If central sensor detect
  else if (FCS_1 == 1)
  {
    move_Forward();
  }
}


