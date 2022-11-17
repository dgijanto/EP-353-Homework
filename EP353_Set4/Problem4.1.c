#include <stdio.h>
#include <string.h>
#include <sndfile.h>

#define frames5 (sfInfo.frames * 5)

int main(){

  SNDFILE *inFile = NULL, *outFile = NULL;
  SF_INFO sfInfo;

  memset(&sfInfo, 0, sizeof(SF_INFO));

  inFile = sf_open("sine.wav", SFM_READ, &sfInfo);

  if(!inFile){
    printf ("Error : could not open file : sine.wav\n");
    puts (sf_strerror (NULL));
    return 1;
  }

  if(!sf_format_check(&sfInfo)){	
    sf_close(inFile);
    printf("Invalid encoding\n");
    return 1;
  }

  float buffer[frames5];

  // writing new file
  int *frames = 0; 
  float buffer_2[sfInfo.frames * 5];

  for(int i = 0; i < 5; i++){
    buffer_2[(*frames)] = sf_read_float(inFile, buffer, sfInfo.frames);
    frames += sfInfo.frames;
    sf_seek(inFile,0,SEEK_SET);
  }
  sf_count_t readcount = (long long) buffer_2;
  sfInfo.frames = (sfInfo.frames * 5);
  outFile = sf_open("sine5.wav", SFM_WRITE, &sfInfo);

  if(!outFile){	
    printf ("Error : could not open file : sine5.wav");
    puts (sf_strerror(NULL));
    return 1;
  }

  sf_write_float(outFile, buffer, readcount);

  sf_close(inFile);
  sf_close(outFile);

}