// 4x4 buttons
// See http://www.devicemart.co.kr/1290708
// based on http://www.hardcopyworld.com/ngine/aduino/index.php/archives/2756

const int numRows= 4;
const int numCols= 4;
 
int pinRows[numRows] = {2, 3, 4, 5};
int pinCols[numCols] = {6, 7, 8, 9};
 
void setup() {
    Serial.begin(9600);    // init Serial communication
    
    // initialize row pins as INPUT_PULLUP
    for(int i=0; i<numRows; i++) {
        pinMode(pinRows[i], INPUT_PULLUP);
    }
    
    // initialize column pins as OUTPUT
    for(int j=0; j<numCols; j++) {
        pinMode(pinCols[j], OUTPUT);
        digitalWrite(pinCols[j], HIGH);    // set initial output as HIGH
    }
}


void loop() {
    // Check input
    for(int j=0; j<numCols; j++) {
        digitalWrite(pinCols[j], LOW);    // set as LOW to check button press
        for(int i=0; i<numRows; i++) {
            if( digitalRead(pinRows[i]) == LOW ) {    // check input. LOW is pressed
                Serial.print("Pressed row=");
                Serial.print(i);
                Serial.print(", column=");
                Serial.println(j);
            }
        }
        digitalWrite(pinCols[j], HIGH);    // set as default (HIGH)
    }
    delay(500);
}
