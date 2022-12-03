#ifndef MUSIC_H
#define MUSIC_H
#include "Media.h"
using namespace std;
class Music: public Media {
 public:
 char duration[80];
  char publisher[10];
  char artist[10];

  char* getDuration();
  void setDuration(char newduration[80]);
  char* getPublisher();
  void setPublisher(char newpublisher[80]);
  char* getArtist();
  void setArtist(char newartist[80]);
};
#endif