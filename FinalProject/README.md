# Saturation Readme

### Functioning 
- The saturator.py file is very easy to function. At this point, it generates a sine wave, and asks for an integer 1 or 2 to determine the distortion algorithm. After you choose, a GUI will pop up with a volume slider, a quit button, and a start button. Simply press start a d you will get a distorted sine wave. 

- The saturator.c plugin isn't currently working but in theory it would if compiled. It would print out a list of your audio devices, and you would have to go into the code and type in the ID of the audio device you wanted to use. You'd run it again, and it would ask you for user input on what kind of distortion you wanted, 1 or 2, and it would then read any input into that audio device and output it to whatever speaker device you chose. 

- Both programs handle realtime audio, though the python file only currently runs the synthesized sine wave, as that was the program I was using to test the distortion algorithms. 