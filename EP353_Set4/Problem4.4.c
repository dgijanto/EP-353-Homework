#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

//Compile this code using:
//clang 02.SawtoothWave.c -o 02.SawtoothWave -lsndfile; ./02.SawtoothWave

#define kSampleRate 44100
#define kSec 1
#define kNumFrames (kSampleRate * kSec)
#define kNumChannels 2
#define kFormat (SF_FORMAT_WAV | SF_FORMAT_PCM_24)
#define kFileName "triangle.wav"

int main(){
  SNDFILE *sndFile;
  SF_INFO sfInfo;
  
  //Sound parameters
  float amplitude = 0.75;
  float frequency = 250.0;
  int numHarmonics = 31;

  //Create 2 channels worth buffer for holding audio data 
  float buffer[kNumChannels * kNumFrames];
  //Clear the buffer with zeros since we will be mixing multiple sine waves
  memset(buffer, 0, kNumChannels * kNumFrames * sizeof(float));

  //Initialize SF_INFO with 0s (memset is in string.h library)
  memset(&sfInfo, 0, sizeof(SF_INFO)); 

  //Set the format for the sound file to be saved
  sfInfo.samplerate = kSampleRate;
	sfInfo.frames = kNumFrames;
	sfInfo.channels = kNumChannels;
	sfInfo.format = kFormat;

   //Open the original sound file as read mode
  sndFile = sf_open(kFileName, SFM_WRITE, &sfInfo);
  if(!sndFile){
    printf ("Error : could not open file : %s\n", kFileName);
		puts(sf_strerror (NULL));
		return 1;
  }

  // Generate Triangle Wave
  for(int t = 0; t < kNumFrames; t++){
    for(int i = 1; i <= numHarmonics; i+=2){ 
      float sample;
      if ((i % 4 ) == 3){
        sample = -1 * (amplitude / i * sin(2.0 * M_PI * ((frequency * i)/kSampleRate) * t));
      }
      else{
        sample = amplitude / i * sin(2.0 * M_PI * ((frequency * i)/kSampleRate) * t);
      }
      for(int c = 0; c < kNumChannels; c++){
        buffer[kNumChannels * t + c] += sample;
      }
    }
  }
  
  //Write out the result
  sf_count_t count = sf_write_float(sndFile, buffer, sfInfo.channels * kNumFrames);

  //Make sure writing the file succeeded  
  if(count != sfInfo.channels * kNumFrames){
    puts(sf_strerror(sndFile));
  }

  //Close sound file and buffer
  sf_close(sndFile);
}