 /*
 * The Circuit: 
 * Connect AUD to analog input 0
 * Connect GND to GND
 * Connect VCC to 3.3V (3.3V yields the best results)
 *  
 *  To adjust when the LED turns on based on audio input:
 *  Open up the serial com port (Top right hand corner of the Arduino IDE)
 *  It looks like a magnifying glass. Perform several experiments 
 *  clapping, snapping, blowing, door slamming, sample ing etc and see where the
 *  resting noise level is and where the loud noises are. Adjust the if statement
 *  according to your findings.
 *  
 *  You can also adjust how long you take samples for by updating the "SampleWindow"
 * 
 * This code has been adapted from the
 * Example Sound Level Sketch for the
 * Adafruit Microphone Amplifier
 * 
 */
 // See also https://learn.adafruit.com/adafruit-microphone-amplifier-breakout/measuring-sound-levels
 
// peak-to-peak level 
// Sample window width in mS (250 mS = 4Hz)
const int sampleWindow = 10; 

unsigned int sample ;
int ledPin = 9;

void setup() 
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
 unsigned long start= millis();  // Start of sample window
 unsigned int peakToPeak = 0;   // peak-to-peak level

 unsigned int signalMax = 0;
 unsigned int signalMin = 1024;

 // collect data for 250 miliseconds
 while (millis() - start < sampleWindow)
 {
    sample  = analogRead(0);
    if (sample  < 1024)  //This is the max of the 10-bit ADC so this loop will include all readings
    {
      if (sample  > signalMax)
      {
        signalMax = sample ;  // save just the max levels
      }
      else if (sample  < signalMin)
      {
        signalMin = sample ;  // save just the min levels
      }
    }
  }
  
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 3.3) / 1024;  // convert to volts
  
  Serial.println(volts);
         
}

