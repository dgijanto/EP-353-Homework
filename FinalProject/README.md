# LMSC-261/EP-353 Final Proposal
# Ableton Saturator Clone

## Summary
My project will be coding and implementing a VST3 plugin in JUCE, roughly modeled on the Ableton saturation plugin.

### Details
My program will act as a waveshaping tool featuring several different 
shapes to choose from. It will feature a drive knob to allow the user determine exactly how much distortion they choose to have. It will potentially feature some filter tools used to shape the distorted sound slightly, if there is ample time to do it, but priority number 1 is getting the waveshaping tools done. 

I am planning on using this project for both LMSC-261 and EP-353, so am taking a two pronged approach to the code on this project. I am first going to implement a processor in python using a python audio library (not sure which one yet) that will allow me to implement the math for the desired waveshapes, and so I can tweak it to my desired sounds. I will then implement it in C/C++ for realtime audio, hopefully in a VST3 plugin form through JUCE. Depending on time, I may end up implementing it with a library in C/C++ instead. 

### Minimum Accomplishment
At the minimum, I will have implemented some sort of waveshaper/distortion plugin, prototyped the math in python and implemented in C/C++. It will likely have limited waveshapes, and no filters, but will still handle realtime audio.

### Aspired Accomplishment
What I hope to do, is have this program implemented in VST3 form with JUCE, having a UI with Sliders, and potentially a graph of the waveshape for visualization, as well as 

### Maximum Accomplishment
The best outcome for this project would be a fully featured saturator, with all the features of the ableton saturator, excluding the waveshaper option as one of the dropdown selections. 

### Steps
- Research Math and DSP Techniques for Distortion
- Research and select an audio handling library for python
- Implement file-based audio processing in Python, through the use of one function to handle the recording of the sound to a new audio file, with several different waveshapes to choose from
- Compare ableton audio and my audio and tweak math to receive similar results (look into Ableton source code?)
- Research and learn more of JUCE, I have a very very basic knowladge, but will likely need to get more deeply into it to do this project in this time limit. 
- Implement the audio based processing, file based, in C++
- Implement the UI and and JUCE processing portion in JUCE. 
