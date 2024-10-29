
#include <Keyboard.h>
#include <Mouse.h>

// delay (1000 = 1 sec)
const int time = 10;
const int time_click = 500;

// Mouse
const int move_mouse = 20;

// JoyStick
const int VRx = A1;
const int VRy = A0;
const int VLx = A3;
const int VLy = A2;
const int SWR = 2;
const int SWL = 3;

// KeyBoard
const char Up = 'w';
const char Down = 's';
const char Lift = 'a';
const char Right = 'd';

const char R_A = 'e';
const char R_B = 'f';
const char R_C = 'z';
const char R_D = 'x';

const char L_A = 'l';
const char L_B = 'k';
const char L_C = 'o';
const char L_D = 'i';

// Button
const int B_RA = 2;
const int B_RB = 3;
const int B_RC = 4;
const int B_RD = 5;

const int B_LA = 6;
const int B_LB = 7;
const int B_LC = 8;
const int B_LD = 9;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  Mouse.begin();

  pinMode(SWR, INPUT_PULLUP);
  pinMode(SWL, INPUT_PULLUP);

  pinMode(B_RA, INPUT_PULLUP);
  pinMode(B_RB, INPUT_PULLUP);
  pinMode(B_RC, INPUT_PULLUP);
  pinMode(B_RD, INPUT_PULLUP);

  pinMode(B_LA, INPUT_PULLUP);
  pinMode(B_LB, INPUT_PULLUP);
  pinMode(B_LC, INPUT_PULLUP);
  pinMode(B_LD, INPUT_PULLUP);
}

void loop() {

  int Button_RA = digitalRead(B_RA);
  int Button_RB = digitalRead(B_RB);
  int Button_RC = digitalRead(B_RC);
  int Button_RD = digitalRead(B_RD);

  int Button_LA = digitalRead(B_LA);
  int Button_LB = digitalRead(B_LB);
  int Button_LC = digitalRead(B_LC);
  int Button_LD = digitalRead(B_LD);

  int xValueR = analogRead(VRx);
  int yValueR = analogRead(VRy);
  int xValueL = analogRead(VLx);
  int yValueL = analogRead(VLy);

  if (xValueR < 400) {
    Keyboard.write(Lift);
    delay(time);
  } else if (xValueR > 600) {
    Keyboard.write(Right);
    delay(time);
  }
  if (yValueR < 400) {
    Keyboard.write(Down);
    delay(time);
  } else if (yValueR > 600) {
    Keyboard.write(Up);
    delay(time);
  }

  if (xValueL < 400) {
    Mouse.move(-move_mouse, 0);
    delay(time);
  } else if (xValueL > 600) {
    Mouse.move(move_mouse, 0);
    delay(time);
  }
  if (yValueL < 400) {
    Mouse.move(0, move_mouse);
    delay(time);
  } else if (yValueL > 600) {
    Mouse.move(0, -move_mouse);
    delay(time);
  }

  if (Button_RA == 0) {
    Keyboard.write(R_A);
    delay(time_click);
  }
  if (Button_RB == 0) {
    Keyboard.write(R_B);
    delay(time_click);
  }
  if (Button_RC == 0) {
    Keyboard.write(R_C);
    delay(time_click);
  }
  if (Button_RD == 0) {
    Keyboard.write(R_D);
    delay(time_click);
  }
  if (Button_RA == 0) {
    Keyboard.write(R_A);
    delay(time_click);
  }
  if (Button_LA == 0) {
    Keyboard.write(L_A);
    delay(time_click);
  }
  if (Button_LB == 0) {
    Keyboard.write(L_B);
    delay(time_click);
  }
  if (Button_LC == 0) {
    Keyboard.write(L_C);
    delay(time_click);
  }
  if (Button_LD == 0) {
    Keyboard.write(L_D);
    delay(time_click);
  }
}
