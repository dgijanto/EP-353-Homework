#include <math.h>
#include <stdio.h>

int main(){
   
   // Assigning Char midiNote
    char midiNote = 60;
    // Calculating  the Frequency using MIDI Note 
    float frequency; 
    frequency = pow(2,(((float)midiNote)-69)/12)*440;

    // Printing result to terminal
    printf("The frequency of the MIDI note number %i is %lf.\n",midiNote, frequency);

}