#define MAX_X 10
#define MAX_Y 10

/*
 *  This is the HackYSU 2017 Arduino Dungeon!
 *
*/


int buttonDefault = HIGH;
int buttonPressed = LOW;
bool insideWall = false;

// ----- Global Pin Number Definitions -----


// Row 1 of the LEDs

const int LED1_1R = 52;
const int LED1_1G = 53;
const int LED1_1B = 50;

const int LED1_2R = 45;
const int LED1_2G = 42;
const int LED1_2B = 43;

const int LED1_3R = 39;
const int LED1_3G = 36;
const int LED1_3B = 37;

const int LED1_4R = 8;
const int LED1_4G = 9;
const int LED1_4B = 10;


// Row 2 of the LEDs

const int LED2_1R = 51;
const int LED2_1G = 48;
const int LED2_1B = 49;

const int LED2_2R = 2;
const int LED2_2G = 3;
const int LED2_2B = 4;

const int LED2_3R = 5;
const int LED2_3G = 6;
const int LED2_3B = 7;

const int LED2_4R = 11;
const int LED2_4G = 12;
const int LED2_4B = 13;


// Row 3 of the LEDs

const int LED3_1R = 46;
const int LED3_1G = 47;
const int LED3_1B = 44;

const int LED3_2R = 40;
const int LED3_2G = 41;
const int LED3_2B = 38;

const int LED3_3R = 34;
const int LED3_3G = 35;
const int LED3_3B = 33;

const int LED3_4R = 32;
const int LED3_4G = 31;
const int LED3_4B = 30;

bool wonYet = false;

// Buttons

const int UP = 29;
const int LEFT = 28;
const int RIGHT = 26;
const int DOWN = 27;

int state[] = {buttonDefault, buttonDefault, buttonDefault, buttonDefault}; //up left right down

int currentX = 9;
int currentY = 9;
int x, y;

// ---------- Function Definitions ----------

void winAnimation(){ //flashes green three times, sprials in and out when completed maze
  int i; 
  // pin assignments for spiral 
  int spiralArray[23] = {53, 43, 39, 9, 13, 32, 35, 38, 46, 48, 4, 5, 4, 48, 46, 38, 35, 32, 13, 9, 39, 43, 53};
    //loop to blink green three times 

    digitalWrite(LED1_1R, LOW);
    digitalWrite(LED1_2R, LOW);
    digitalWrite(LED1_3R, LOW);
    digitalWrite(LED1_4R, LOW);
    digitalWrite(LED2_1R, LOW); 
    digitalWrite(LED2_2R, LOW); 
    digitalWrite(LED2_3R, LOW);
    digitalWrite(LED2_4R, LOW); 
    digitalWrite(LED3_1R, LOW);
    digitalWrite(LED3_2R, LOW);
    digitalWrite(LED3_3R, LOW);
    digitalWrite(LED3_4R, LOW);

    digitalWrite(LED1_1B, LOW);
    digitalWrite(LED1_2B, LOW);
    digitalWrite(LED1_3B, LOW);
    digitalWrite(LED1_4B, LOW);
    digitalWrite(LED2_1B, LOW); 
    digitalWrite(LED2_2B, LOW); 
    digitalWrite(LED2_3B, LOW);
    digitalWrite(LED2_4B, LOW); 
    digitalWrite(LED3_1B, LOW);
    digitalWrite(LED3_2B, LOW);
    digitalWrite(LED3_3B, LOW);
    digitalWrite(LED3_4B, LOW);

    digitalWrite(LED1_1G, LOW);
    digitalWrite(LED1_2G, LOW);
    digitalWrite(LED1_3G, LOW);
    digitalWrite(LED1_4G, LOW);
    digitalWrite(LED2_1G, LOW); 
    digitalWrite(LED2_2G, LOW); 
    digitalWrite(LED2_3G, LOW);
    digitalWrite(LED2_4G, LOW); 
    digitalWrite(LED3_1G, LOW);
    digitalWrite(LED3_2G, LOW);
    digitalWrite(LED3_3G, LOW);
    digitalWrite(LED3_4G, LOW);

    
    for(i =0; i <= 2; i++){

    digitalWrite(LED1_1G, LOW);
    digitalWrite(LED1_2G, LOW);
    digitalWrite(LED1_3G, LOW);
    digitalWrite(LED1_4G, LOW);
    digitalWrite(LED2_1G, LOW); 
    digitalWrite(LED2_2G, LOW); 
    digitalWrite(LED2_3G, LOW);
    digitalWrite(LED2_4G, LOW); 
    digitalWrite(LED3_1G, LOW);
    digitalWrite(LED3_2G, LOW);
    digitalWrite(LED3_3G, LOW);
    digitalWrite(LED3_4G, LOW);

    delay(500);
    
    digitalWrite(LED1_1G, HIGH);
    digitalWrite(LED1_2G, HIGH);
    digitalWrite(LED1_3G, HIGH);
    digitalWrite(LED1_4G, HIGH);
    digitalWrite(LED2_1G, HIGH); 
    digitalWrite(LED2_2G, HIGH); 
    digitalWrite(LED2_3G, HIGH);
    digitalWrite(LED2_4G, HIGH); 
    digitalWrite(LED3_1G, HIGH);
    digitalWrite(LED3_2G, HIGH);
    digitalWrite(LED3_3G, HIGH);
    digitalWrite(LED3_4G, HIGH);

    delay(500);
  }
    // reset LEDs 
    digitalWrite(LED1_1G, LOW);
    digitalWrite(LED1_2G, LOW);
    digitalWrite(LED1_3G, LOW);
    digitalWrite(LED1_4G, LOW);
    digitalWrite(LED2_1G, LOW); 
    digitalWrite(LED2_2G, LOW); 
    digitalWrite(LED2_3G, LOW);
    digitalWrite(LED2_4G, LOW); 
    digitalWrite(LED3_1G, LOW);
    digitalWrite(LED3_2G, LOW);
    digitalWrite(LED3_3G, LOW);
    digitalWrite(LED3_4G, LOW);
  
    // loop to spiral in and out alternating colors 
  for(i = 0; i < 23; i++) {
    
    digitalWrite(spiralArray[i], HIGH);

    delay(500);

    digitalWrite(spiralArray[i], LOW);
    
  }

 }

void deathAnimation(){ //outside ring blinks red. center two fade 

    int pwmPower = 255;

    digitalWrite(LED1_1R, LOW);
    digitalWrite(LED1_2R, LOW);
    digitalWrite(LED1_3R, LOW);
    digitalWrite(LED1_4R, LOW);
    digitalWrite(LED2_1R, LOW); 
    digitalWrite(LED2_2R, LOW); 
    digitalWrite(LED2_3R, LOW);
    digitalWrite(LED2_4R, LOW); 
    digitalWrite(LED3_1R, LOW);
    digitalWrite(LED3_2R, LOW);
    digitalWrite(LED3_3R, LOW);
    digitalWrite(LED3_4R, LOW);

    digitalWrite(LED1_1B, LOW);
    digitalWrite(LED1_2B, LOW);
    digitalWrite(LED1_3B, LOW);
    digitalWrite(LED1_4B, LOW);
    digitalWrite(LED2_1B, LOW); 
    digitalWrite(LED2_2B, LOW); 
    digitalWrite(LED2_3B, LOW);
    digitalWrite(LED2_4B, LOW); 
    digitalWrite(LED3_1B, LOW);
    digitalWrite(LED3_2B, LOW);
    digitalWrite(LED3_3B, LOW);
    digitalWrite(LED3_4B, LOW);

    digitalWrite(LED1_1G, LOW);
    digitalWrite(LED1_2G, LOW);
    digitalWrite(LED1_3G, LOW);
    digitalWrite(LED1_4G, LOW);
    digitalWrite(LED2_1G, LOW); 
    digitalWrite(LED2_2G, LOW); 
    digitalWrite(LED2_3G, LOW);
    digitalWrite(LED2_4G, LOW); 
    digitalWrite(LED3_1G, LOW);
    digitalWrite(LED3_2G, LOW);
    digitalWrite(LED3_3G, LOW);
    digitalWrite(LED3_4G, LOW);



  while(pwmPower>=0){

    delay(500);
    
    digitalWrite(LED1_1R, LOW);
    digitalWrite(LED1_2R, LOW);
    digitalWrite(LED1_3R, LOW);
    digitalWrite(LED1_4R, LOW);
    digitalWrite(LED2_1R, LOW); 
    //digitalWrite(LED2_2R, LOW); skip center green LEDs
    //digitalWrite(LED2_3R, LOW);
    digitalWrite(LED2_4R, LOW); 
    digitalWrite(LED3_1R, LOW);
    digitalWrite(LED3_2R, LOW);
    digitalWrite(LED3_3R, LOW);
    digitalWrite(LED3_4R, LOW);

    delay(500);
    
    digitalWrite(LED1_1R, HIGH);
    digitalWrite(LED1_2R, HIGH);
    digitalWrite(LED1_3R, HIGH);
    digitalWrite(LED1_4R, HIGH);
    digitalWrite(LED2_1R, HIGH); 
    //digitalWrite(LED2_2R, HIGH); 
    //digitalWrite(LED2_3R, HIGH);
    digitalWrite(LED2_4R, HIGH); 
    digitalWrite(LED3_1R, HIGH);
    digitalWrite(LED3_2R, HIGH);
    digitalWrite(LED3_3R, HIGH);
    digitalWrite(LED3_4R, HIGH);
   
    analogWrite(LED2_2G, pwmPower);
    analogWrite(LED2_3G, pwmPower);

    pwmPower = pwmPower - 60 ;
  }

  digitalWrite(LED2_2G, LOW);
  digitalWrite(LED2_3G, LOW);
}

void ledBlink(){ //LEDs blink when move to different room than current room

    digitalWrite(LED1_1R, LOW);
    digitalWrite(LED1_2R, LOW);
    digitalWrite(LED1_3R, LOW);
    digitalWrite(LED1_4R, LOW);
    digitalWrite(LED2_1R, LOW); 
    digitalWrite(LED2_2R, LOW); 
    digitalWrite(LED2_3R, LOW);
    digitalWrite(LED2_4R, LOW); 
    digitalWrite(LED3_1R, LOW);
    digitalWrite(LED3_2R, LOW);
    digitalWrite(LED3_3R, LOW);
    digitalWrite(LED3_4R, LOW);

    digitalWrite(LED1_1G, LOW);
    digitalWrite(LED1_2G, LOW);
    digitalWrite(LED1_3G, LOW);
    digitalWrite(LED1_4G, LOW);
    digitalWrite(LED2_1G, LOW); 
    digitalWrite(LED2_2G, LOW); 
    digitalWrite(LED2_3G, LOW);
    digitalWrite(LED2_4G, LOW); 
    digitalWrite(LED3_1G, LOW);
    digitalWrite(LED3_2G, LOW);
    digitalWrite(LED3_3G, LOW);
    digitalWrite(LED3_4G, LOW);

    digitalWrite(LED1_1B, LOW);
    digitalWrite(LED1_2B, LOW);
    digitalWrite(LED1_3B, LOW);
    digitalWrite(LED1_4B, LOW);
    digitalWrite(LED2_1B, LOW); 
    digitalWrite(LED2_2B, LOW); 
    digitalWrite(LED2_3B, LOW);
    digitalWrite(LED2_4B, LOW); 
    digitalWrite(LED3_1B, LOW);
    digitalWrite(LED3_2B, LOW);
    digitalWrite(LED3_3B, LOW);
    digitalWrite(LED3_4B, LOW);

    delay(500);
}


void lightLED(int LEDSelect, int r, int g, int b){
  if (LEDSelect == 11){
    digitalWrite(LED1_1R, r);
    digitalWrite(LED1_1G, g);
    digitalWrite(LED1_1B, b);
  }
  else if (LEDSelect == 12){
    digitalWrite(LED1_2R, r);
    digitalWrite(LED1_2G, g);
    digitalWrite(LED1_2B, b);
  }
  else if (LEDSelect == 13){
    digitalWrite(LED1_3R, r);
    digitalWrite(LED1_3G, g);
    digitalWrite(LED1_3B, b);
  }
  else if (LEDSelect == 14){
    digitalWrite(LED1_4R, r);
    digitalWrite(LED1_4G, g);
    digitalWrite(LED1_4B, b);
  }
  else if (LEDSelect == 21){
    digitalWrite(LED2_1R, r);
    digitalWrite(LED2_1G, g);
    digitalWrite(LED2_1B, b);
  }
  else if (LEDSelect == 22){
    digitalWrite(LED2_2R, r);
    digitalWrite(LED2_2G, g);
    digitalWrite(LED2_2B, b);
  }
  else if (LEDSelect == 23){
    digitalWrite(LED2_3R, r);
    digitalWrite(LED2_3G, g);
    digitalWrite(LED2_3B, b);
  }
  else if (LEDSelect == 24){
    digitalWrite(LED2_4R, r);
    digitalWrite(LED2_4G, g);
    digitalWrite(LED2_4B, b);
  }
  else if (LEDSelect == 31){
    digitalWrite(LED3_1R, r);
    digitalWrite(LED3_1G, g);
    digitalWrite(LED3_1B, b);
  }
  else if (LEDSelect == 32){
    digitalWrite(LED3_2R, r);
    digitalWrite(LED3_2G, g);
    digitalWrite(LED3_2B, b);
  }
  else if (LEDSelect == 33){
    digitalWrite(LED3_3R, r);
    digitalWrite(LED3_3G, g);
    digitalWrite(LED3_3B, b);
  }
  else if (LEDSelect == 34){
    digitalWrite(LED3_4R, r);
    digitalWrite(LED3_4G, g);
    digitalWrite(LED3_4B, b);
  }
}

//MAP ARRAY
unsigned int location[MAX_Y][MAX_X] = {

  {18,16,6,6,13,6,6,8,18,4},
  {18,18,18,18,5,18,18,9,6,14},
  {18,10,6,6,14,18,18,18,18,5},
  {18,5,18,18,9,6,16,18,18,5},
  {3,7,18,18,18,18,18,18,18,5},
  {18,18,10,6,6,6,6,8,18,5},
  {18,18,5,18,18,18,18,9,6,14},
  {16,18,12,13,13,8,18,18,18,5},
  {12,6,11,15,15,11,6,16,18,5},
  {17,18,18,9,7,18,18,18,18,1}};

// Starting room: top only is open
void room1(){
  insideWall = false;
  lightLED(11, HIGH, LOW, HIGH);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, HIGH, LOW, HIGH);
  lightLED(21, HIGH, LOW, HIGH);
  lightLED(24, HIGH, LOW, HIGH);
  lightLED(31, HIGH, LOW, HIGH);
  lightLED(32, HIGH, LOW, HIGH);
  lightLED(33, HIGH, LOW, HIGH);
  lightLED(34, HIGH, LOW, HIGH);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// Only left side is open
void room2(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, HIGH);
  lightLED(13, LOW, LOW, HIGH);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, LOW);
  lightLED(24, LOW, LOW, HIGH);
  lightLED(31, LOW, LOW, LOW);
  lightLED(32, LOW, LOW, HIGH);
  lightLED(33, LOW, LOW, HIGH);
  lightLED(34, LOW, LOW, HIGH);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// Only right side is open
void room3(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, HIGH);
  lightLED(13, LOW, LOW, HIGH);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, HIGH);
  lightLED(24, LOW, LOW, LOW);
  lightLED(31, LOW, LOW, HIGH);
  lightLED(32, LOW, LOW, HIGH);
  lightLED(33, LOW, LOW, HIGH);
  lightLED(34, LOW, LOW, LOW);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// Only bottom open
void room4(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, HIGH);
  lightLED(13, LOW, LOW, HIGH);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, HIGH);
  lightLED(24, LOW, LOW, HIGH);
  lightLED(31, LOW, LOW, HIGH);
  lightLED(32, LOW, LOW, LOW);
  lightLED(33, LOW, LOW, LOW);
  lightLED(34, LOW, LOW, HIGH);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}


// 2 sides open: top & bottom
void room5(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, HIGH);
  lightLED(24, LOW, LOW, HIGH);
  lightLED(31, LOW, LOW, HIGH);
  lightLED(32, LOW, LOW, LOW);
  lightLED(33, LOW, LOW, LOW);
  lightLED(34, LOW, LOW, HIGH);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 2 sides open: Left & right
void room6(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, HIGH);
  lightLED(13, LOW, LOW, HIGH);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, LOW);
  lightLED(24, LOW, LOW, LOW);
  lightLED(31, LOW, LOW, LOW);
  lightLED(32, LOW, LOW, HIGH);
  lightLED(33, LOW, LOW, HIGH);
  lightLED(34, LOW, LOW, LOW);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 2 sides open: Left & top
void room7(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, LOW);
  lightLED(24, LOW, LOW, HIGH);
  lightLED(31, LOW, LOW, LOW);
  lightLED(32, LOW, LOW, HIGH);
  lightLED(33, LOW, LOW, HIGH);
  lightLED(34, LOW, LOW, HIGH);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 2 sides open: Left & bottom
void room8(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, HIGH);
  lightLED(13, LOW, LOW, HIGH);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, LOW);
  lightLED(24, LOW, LOW, HIGH);
  lightLED(31, LOW, LOW, LOW);
  lightLED(32, LOW, LOW, LOW);
  lightLED(33, LOW, LOW, LOW);
  lightLED(34, LOW, LOW, HIGH);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 2 sides open: Right & top
void room9(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, HIGH);
  lightLED(24, LOW, LOW, LOW);
  lightLED(31, LOW, LOW, HIGH);
  lightLED(32, LOW, LOW, HIGH);
  lightLED(33, LOW, LOW, HIGH);
  lightLED(34, LOW, LOW, LOW);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 2 sides open: Right & bottom
void room10(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, HIGH);
  lightLED(13, LOW, LOW, HIGH);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, HIGH);
  lightLED(24, LOW, LOW, LOW);
  lightLED(31, LOW, LOW, HIGH);
  lightLED(32, LOW, LOW, LOW);
  lightLED(33, LOW, LOW, LOW);
  lightLED(34, LOW, LOW, LOW);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 3 sides open: Left, top, & right
void room11(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, LOW);
  lightLED(24, LOW, LOW, LOW);
  lightLED(31, LOW, LOW, LOW);
  lightLED(32, LOW, LOW, HIGH);
  lightLED(33, LOW, LOW, HIGH);
  lightLED(34, LOW, LOW, LOW);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 3 sides open: Top, right, & bottom
void room12(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, HIGH);
  lightLED(24, LOW, LOW, LOW);
  lightLED(31, LOW, LOW, HIGH);
  lightLED(32, LOW, LOW, LOW);
  lightLED(33, LOW, LOW, LOW);
  lightLED(34, LOW, LOW, LOW);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 3 sides open: Right, bottom, & left
void room13(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, HIGH);
  lightLED(13, LOW, LOW, HIGH);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, LOW);
  lightLED(24, LOW, LOW, LOW);
  lightLED(31, LOW, LOW, LOW);
  lightLED(32, LOW, LOW, LOW);
  lightLED(33, LOW, LOW, LOW);
  lightLED(34, LOW, LOW, LOW);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// 3 sides open: Bottom, left, & top
void room14(){
  insideWall = false;
  lightLED(11, LOW, LOW, LOW);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, LOW);
  lightLED(24, LOW, LOW, HIGH);
  lightLED(31, LOW, LOW, LOW);
  lightLED(32, LOW, LOW, LOW);
  lightLED(33, LOW, LOW, LOW);
  lightLED(34, LOW, LOW, HIGH);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

// All 4 sides open
void room15(){
  insideWall = false;
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, LOW);
  lightLED(24, LOW, LOW, LOW);
  lightLED(31, LOW, LOW, LOW);
  lightLED(32, LOW, LOW, LOW);
  lightLED(33, LOW, LOW, LOW);
  lightLED(34, LOW, LOW, LOW);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
}

//death room
void room16(){
  deathAnimation();
  Serial.println("You died bitch");
}
//end room
void room17(){
  winAnimation();
  wonYet = true;
  insideWall = false;
}
void room18(){
  insideWall = true;
}
//top open not starting room
void room19(){
  lightLED(11, LOW, LOW, HIGH);
  lightLED(12, LOW, LOW, LOW);
  lightLED(13, LOW, LOW, LOW);
  lightLED(14, LOW, LOW, HIGH);
  lightLED(21, LOW, LOW, HIGH);
  lightLED(24, LOW, LOW, HIGH);
  lightLED(31, LOW, LOW, HIGH);
  lightLED(32, LOW, LOW, HIGH);
  lightLED(33, LOW, LOW, HIGH);
  lightLED(34, LOW, LOW, HIGH);
  //set player LEDs green
  lightLED(22, LOW, HIGH, LOW);
  lightLED(23, LOW, HIGH, LOW);
  insideWall = false;
}

// Enables one to
void roomSelect(int sel){
  if (sel == 1)
    room1();
  else if (sel == 2)
    room2();
  else if (sel == 3)
    room3();
  else if (sel == 4)
    room4();
  else if (sel == 5)
    room5();
  else if (sel == 6)
    room6();
  else if (sel == 7)
    room7();
  else if (sel == 8)
    room8();
  else if (sel == 9)
    room9();
  else if (sel == 10)
    room10();
  else if (sel == 11)
    room11();
  else if (sel == 12)
    room12();
  else if (sel == 13)
    room13();
  else if (sel == 14)
    room14();
  else if (sel == 15)
    room15();
  else if (sel == 16)
    room16();
  else if (sel == 17)
    room17();
  else if (sel == 18)
    room18();
  else if (sel == 19)
    room19();
        
}

int upMove(int currentY){
  int ymove = currentY;
  if (0 < ymove <= 9)
  {
    ymove--;
    return ymove;
  }
  else
    return -1;
}

int downMove(int currentY){
  int ymove = currentY;
  if (0 <= ymove < 9)
  {
    ymove++;
    return ymove;
  }
  else
    return -1;
}

int leftMove(int currentX){
  int xmove = currentX;
  if (0 < xmove <= 9)
  {
    xmove--;
    return xmove;
  }
  else
    return -1;
}

int rightMove(int currentX){
  int xmove = currentX;
  if (0 <= xmove < 9)
  {
    xmove++;
    return xmove;
  }
  else
    return -1;
}

//  ---------------- VOID SETUP --------------------------------


void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to the HackYSU 2017 Arduino Dungeon!");

  // Row 1 of the Output LEDs

  pinMode(LED1_1R, OUTPUT);
  pinMode(LED1_1G, OUTPUT);
  pinMode(LED1_1B, OUTPUT);

  pinMode(LED1_2R, OUTPUT);
  pinMode(LED1_2G, OUTPUT);
  pinMode(LED1_2B, OUTPUT);

  pinMode(LED1_3R, OUTPUT);
  pinMode(LED1_3G, OUTPUT);
  pinMode(LED1_3B, OUTPUT);

  pinMode(LED1_4R, OUTPUT);
  pinMode(LED1_4G, OUTPUT);
  pinMode(LED1_4B, OUTPUT);


// Row 2 of the Output LEDs

  pinMode(LED2_1R, OUTPUT);
  pinMode(LED2_1G, OUTPUT);
  pinMode(LED2_1B, OUTPUT);

  pinMode(LED2_2R, OUTPUT);
  pinMode(LED2_2G, OUTPUT);
  pinMode(LED2_2B, OUTPUT);

  pinMode(LED2_3R, OUTPUT);
  pinMode(LED2_3G, OUTPUT);
  pinMode(LED2_3B, OUTPUT);

  pinMode(LED2_4R, OUTPUT);
  pinMode(LED2_4G, OUTPUT);
  pinMode(LED2_4B, OUTPUT);


// Row 3 of Output LEDs

    // 1st LED of the 3rd Row
  pinMode(LED3_1R, OUTPUT);
  pinMode(LED3_1G, OUTPUT);
  pinMode(LED3_1B, OUTPUT);

  pinMode(LED3_2R, OUTPUT);
  pinMode(LED3_2G, OUTPUT);
  pinMode(LED3_2B, OUTPUT);

  pinMode(LED3_3R, OUTPUT);
  pinMode(LED3_3G, OUTPUT);
  pinMode(LED3_3B, OUTPUT);

  pinMode(LED3_4R, OUTPUT);
  pinMode(LED3_4G, OUTPUT);
  pinMode(LED3_4B, OUTPUT);


// Buttons

  pinMode(UP, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(DOWN, INPUT);

  digitalWrite(UP, buttonDefault);
  digitalWrite(LEFT, buttonDefault);
  digitalWrite(RIGHT, buttonDefault);
  digitalWrite(DOWN, buttonDefault);
}
int moveCounter = 0;

void loop(){

if (moveCounter == 0) //if first move put in room1 and print intro
{
  room1();
  Serial.println("You're in a dungeon! Quick! Use the arrow push buttons to escape!");
}

while(wonYet == false){

  //reset state array
  for (int i = 0; i < 4; i++)
  {
    state[i] = buttonDefault;
  }

  while (state[0] == buttonDefault && state[1] == buttonDefault && state[2] == buttonDefault && state[3] == buttonDefault){
    state[0] = digitalRead(UP);
    state[1] = digitalRead(LEFT);
    state[2] = digitalRead(RIGHT);
    state[3] = digitalRead(DOWN);
  }
  //determine move
  if (state[0] == buttonPressed) //move up
  {
    y = upMove(currentY);
      currentY = y;
  }

  else if (state[1] == buttonPressed) //move left 
  {
    x = leftMove(currentX);
      currentX = x;
  }

  else if (state[2] == buttonPressed) //move right
  {
    x = rightMove(currentX);
      currentX = x;
  }

  else if (state[3] == buttonPressed) //move down
  {
    y = downMove(currentY);
      currentY = y;
  }

  if(currentX <= -1 || currentY <= -1 || currentX > 9 || currentY > 9){
    Serial.println("You fell off the edge and were teleported back to the beginning. Good luck!");
    currentX = 9;
    currentY = 9;
    ledBlink();
    roomSelect(location[currentY][currentX]);
  }
  
  else if ((-1 < currentX < 9) && ( -1 < currentY < 9))
  {
    ledBlink();
    roomSelect(location[currentY][currentX]);
      if(insideWall == true){
        Serial.println("You walked into a wall bro.... BACK TO THE BEGINNING");
        currentX = 9;
        currentY = 9;
        ledBlink();
        roomSelect(location[currentY][currentX]);
      }
  }

  moveCounter++;
  delay(250);
}

if (wonYet == true)
{
  Serial.println("YOU WON");
  winAnimation();
}

}

