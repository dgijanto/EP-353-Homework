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

  float buffer[sfInfo.frames];

  sf_count_t readcount = sf_read_float(inFile, buffer, sfInfo.frames);
  for(int i = 0; i < sfInfo.frames; i++){
    buffer[i] = buffer[i] * -1;
  }

   outFile = sf_open("sineInverted.wav", SFM_WRITE, &sfInfo);

  if(!outFile){	
    printf ("Error : could not open file : sineInverted.wav");
    puts (sf_strerror(NULL));
    return 1;
  }

  sf_write_float(outFile, buffer, readcount);

  sf_close(inFile);
  sf_close(outFile);

}