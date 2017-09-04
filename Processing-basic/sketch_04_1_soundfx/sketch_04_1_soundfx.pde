// based on
// http://freeartbureau.org/fab_activity/processing-for-kids-part-2/
import ddf.minim.*;
 
Minim minim;
 
AudioSample fx1;
AudioSample fx2;
AudioSample fx3;
 
void setup() {
    size (300, 300);
    minim = new Minim(this);
    fx1 = minim.loadSample("se_jump.wav");
    fx2 = minim.loadSample("Synth_bl-xk-95_hifi.wav");
    fx3 = minim.loadSample("Synth_bl-xk-90_hifi.wav");
    rectMode(CENTER);
}
 
void draw() {
    background(0);
}
 
void keyPressed() {
    if ( key == 'a' ) {
            
        fx1.trigger();
     }
    if ( key == 's' ) {
            
        fx2.trigger();
     }
    if ( key == 'd' ) {
        
        fx3.trigger();
     }
}
 
void stop() {
  // always close Minim audio classes when you are done with them
    fx1.close();
    fx2.close();
    fx3.close();
    
    minim.stop();
    super.stop();
}