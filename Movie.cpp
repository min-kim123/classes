#include "Movie.h"
using namespace std;
float Movie::getRating(){
  return rating;
}

void Movie::setRating(float newrating){
  rating = newrating;
}

char* Movie::getDuration(){
  return duration;
}

void Movie::setDuration(char* newduration){
  strcpy(duration, newduration);
}

char* Movie::getDirector(){
  return director;
}

void Movie::setDirector(char* newdirector){
  strcpy(director, newdirector);
}