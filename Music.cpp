#include "Music.h"
using namespace std;
char* Music::getDuration(){
  return duration;
}

void Music::setDuration(char* newduration){
  strcpy(duration, newduration);
}

char* Music::getArtist(){
  return artist;
}

void Music::setArtist(char* newartist){
  strcpy(artist, newartist);
}

char* Music::getPublisher(){
  return publisher;
}

void Music::setPublisher(char* newpublisher){
  strcpy(publisher, newpublisher);
}