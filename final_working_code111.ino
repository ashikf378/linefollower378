#define   inA         7
#define   inB         8
#define   inC         9
#define   inD         10
#define   enA         5
#define   enB         6

int leftBaseSpeed   = 140;
int rightBaseSpeed  = 140;
int maxSpeed        = 140;

char flag = 's';
int pos;
int I = 0;
const int NUM_SENSORS = 6; 
const int sensor_pins[NUM_SENSORS] = {A0, A1, A2, A3, A4,A5};
uint8_t s[NUM_SENSORS] = {0, 0, 0, 0, 0, 0};


int sensor; //this is to store final value after binary conversion
int sum = 0; //this is to store the count of detected sensor

// PID PARAMETERS

float kp            = 50;
float kd            = 30;
float ki            = 0;
int prevError = 0, error = 0;
float p, i = 0, d;

void setup() {
  for(int I = 0; I < NUM_SENSORS; I++) {
        pinMode(sensor_pins[I], INPUT);
  }
  wheelInit();
 
  otherInit();

  Serial.begin(9600);
}

void loop() {

  line_follow();
  lineFollow();
  reading();

}
void wheelInit()
{
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  //Setting Thewheel to zero speed
  digitalWrite(inA, HIGH);
  digitalWrite(inB, HIGH);
  digitalWrite(inC, HIGH);
  digitalWrite(inD, HIGH);
  for(int I = 0; I < NUM_SENSORS; I++) {
        pinMode(sensor_pins[I], INPUT);
}
}

void otherInit()
{
 
  prevError = 0;
  
}
