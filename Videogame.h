#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Media.h"
using namespace std;

class VideoGame: public Media {
 public:
  float rating;
  char publisher[80];
  float getRating();
  void setRating(float inRating);
  char* getPublisher();
  void setPublisher(char inPublisher[80]);
};
#endif