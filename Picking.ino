//Picking state machine
void picking() {
  switch (state) {

    //Rotate the arm until an object is found
    case SPIN_TO_FIND:
      movetoObject();
      state = COLOR_CHECK;
      break;

    //After an object has been found, it checks the object color
    case COLOR_CHECK:
      tcs.getRawData(&r, &g, &b, &c);
      color_check(r, g, b);
      state = PICKUP_POSITION;
      delay(1000);
      break;

    //Put the arm in the angles needed to pick the object
    case PICKUP_POSITION:
      pickupPosition();
      state = PICKUP_OBJECT;
      delay(1000);
      break;

    //Closes the gripper so that the object can be picked up
    case PICKUP_OBJECT:
      grabObject();
      state = SPIN_POSITION;
      delay(500);
      break;

    //Put the arm in a confortable spinning position
    case SPIN_POSITION:
      findPosition();
      state = SPIN_TO_BIN;
      delay(1000);
      break;

    //Spins the arm until it reaches the bin
    case SPIN_TO_BIN:
      movetoBin();
      state = RELEASE_OBJECT;
      delay(1000);
      break;

    //Open the gripper so that the object falls in the bin
    case RELEASE_OBJECT:
      releaseObject();
      startPosition();
      state = FIND_POSITION;
      delay(1000);
      break;


    //Put the arm in the search position
    case FIND_POSITION :
      findPosition();
      state = SPIN_TO_FIND;
      delay(1000);
      break;

  }
}
