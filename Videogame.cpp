#include "Videogame.h"
using namespace std;
float VideoGame::getRating(){
  return rating;
}

void VideoGame::setRating(float newrating){
  rating = newrating;
}

char* VideoGame::getPublisher(){
  return publisher;
}

void VideoGame::setPublisher(char* newpublisher){
  strcpy(publisher, newpublisher);
}