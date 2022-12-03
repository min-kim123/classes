#ifndef MOVIE_H
#define MOVIE_H
#include "Media.h"
using namespace std;
class Movie: public Media {
 public:
  char duration[80];
  int rating;
  char director[80];

  char* getDuration();
  void setDuration(char newduration[80]);
  float getRating();
  void setRating(float newrating);
  char* getDirector();
  void setDirector(char newdirector[80]);
};
#endif