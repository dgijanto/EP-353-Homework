#include <stdio.h>
#include <string.h>
#include <portaudio.h>

//Compile with:
//clang 00.Template.c -o 00.Template -lportaudio
//Run with:
//./00.Template

//------------------------------------------------------------------------------------
//Constants
#define kInputDeviceIndex 0 //Built-in input
#define kOutputDeviceIndex 1 //Built-in output
#define kNumFramesPerBuffer 512
#define kSamplingRate 44100.0
#define kNumChannels 2
#define kGain 5
//------------------------------------------------------------------------------------
// TODO: Define your struct here

//------------------------------------------------------------------------------------
//Function prototypes
int initPortAudio();
int closePortAudio();
void printPaDevices();
void process(float *buffer, unsigned long numFrames, void *userData);
//------------------------------------------------------------------------------------
//Audio render callback function
int renderCallback(
  const void *input,
  void *output,
  unsigned long frameCount,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData,
  int uInput
);
//------------------------------------------------------------------------------------
int main(){
  PaStream *pStream = NULL; //For port audio streaming
	PaStreamParameters inputParameters; //Parameters for input of a stream
  PaStreamParameters outputParameters; //Parameters for output of a stream

  //TODO: Initialize your struct for audio processing here. 

  //Initialize port audio
  if(initPortAudio()) return 1;

  //Print available audio devices
  printPaDevices();

  //Configure port audio input streaming setup
  memset(&inputParameters, 0, sizeof(PaStreamParameters));
  inputParameters.channelCount = kNumChannels;
	inputParameters.device = kInputDeviceIndex;
	inputParameters.sampleFormat = paFloat32;
	inputParameters.suggestedLatency = 0.0;
  
  //Configure port audio output streaming setup
  memset(&outputParameters, 0, sizeof(PaStreamParameters));
  outputParameters.channelCount = kNumChannels;
	outputParameters.device = kOutputDeviceIndex;
	outputParameters.sampleFormat = paFloat32;
	outputParameters.suggestedLatency = 0.0;

  //Open port audio streaming
  PaError error = Pa_OpenStream(
    &pStream,
    &inputParameters, //input
    &outputParameters, //output
    kSamplingRate,
    kNumFramesPerBuffer, //frames per buffer
    paNoFlag,
    renderCallback,
    NULL 
  );

  //Check for error in opening port audio streaming
  if(error != paNoError){
    printf("Error: Failed to open port audio stream. %s\n",Pa_GetErrorText(error));
    closePortAudio();
    return 1;
  }

  //Start port audio streaming
  error = Pa_StartStream(pStream);
  if(error != paNoError){
    printf("Error: Failed to start port audio stream. %s\n",Pa_GetErrorText(error));
  }
  else {
    printf("Rendering audio... Press enter to stop streaming audio\n");
    getchar();
    error = Pa_StopStream(pStream);
    if(error != paNoError){
      printf("Error: Failed to stop port audio stream. %s", Pa_GetErrorText(error));
    }
  }

  //Close port audio streaming
  if(closePortAudio()) return 1;
}
//------------------------------------------------------------------------------------
void process(float *buffer, unsigned long numFrames, void *userData){

  printf("Which Type of Waveshape Would you like? 1 or 2?");
  int uInput;
  scanf("%i", &uInput);

  for(unsigned long n = 0; n < numFrames; n += kNumChannels){
    for(int c=0; c < kNumChannels; c++){
      float in = buffer[n+c];
      // Apply Gain
      in = buffer[n+c] * kGain;
      switch (uInput){
        case 1 :
          if (in > 1){
            buffer[n+c] = in + ((in * in * in)/3);
          }
          else if (in < -1){
            buffer[n+c] = in + ((in * in * in)/3);
          }
        break;

        case 2 :
          if (in > 1){
            buffer[n+c] = 1;
          }
          else if (in < -1){
            buffer[n+c] = in + -1;
          }
      }
    }
  }
}
//------------------------------------------------------------------------------------
int renderCallback(
  const void *input,
  void *output,
  unsigned long frameCount,
  const PaStreamCallbackTimeInfo* timeInfo,
  PaStreamCallbackFlags statusFlags,
  void *userData

){
  float *inBuffer = (float *) input;
  float *outBuffer = (float *) output;
  unsigned long numFrames = frameCount * kNumChannels;

  //Samples are interleaved so increment by two with kNumChannels
  for(unsigned long n=0; n < numFrames; n+=kNumChannels){//iterate over samples in channels
    for(int c=0;c<kNumChannels;c++){//Iterate over number of channels
      outBuffer[n+c] = inBuffer[n+c]; //Copy input to output
    }
  }

  process(outBuffer, numFrames, userData);

  return 0;
}
//------------------------------------------------------------------------------------
int initPortAudio(){ //Initialize Port Audio
  PaError error = Pa_Initialize();
  if(error != paNoError){
    printf("Error: Pa_Initialize() failed with %s\n", Pa_GetErrorText(error));
    return 1;
  }
  return 0;
}
//------------------------------------------------------------------------------------
int closePortAudio(){ //Terminate Port Audio
  PaError error = Pa_Terminate();
  if(error != paNoError){
    printf("Error: Pa_Terminate() failed with %s\n",Pa_GetErrorText(error));
    return 1;
  }
  return 0;
}
//------------------------------------------------------------------------------------
void printPaDevices(){
  //Get number of port audio devices available
  PaDeviceIndex numDevices = Pa_GetDeviceCount(); 
  PaDeviceIndex curDeviceID;

  const PaDeviceInfo *pDeviceInfo; 
  const PaHostApiInfo *pHostApiInfo;

  //Iterate over each device and print out information about them
  for(curDeviceID = 0; curDeviceID < numDevices; curDeviceID++){
    pDeviceInfo = Pa_GetDeviceInfo(curDeviceID);
    pHostApiInfo = Pa_GetHostApiInfo(pDeviceInfo->hostApi);
    printf("--------------------------------------------\n");
    printf("ID: %d, Name: %s, ", curDeviceID, pDeviceInfo->name);
    printf("API name: %s\n", pHostApiInfo->name);
    printf("Max output channels: %d\t", pDeviceInfo->maxOutputChannels);
    printf("Max input channels: %d\n\n", pDeviceInfo->maxInputChannels);
  }
}