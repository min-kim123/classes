#include <string.h>
#include "Media.h"
#include <iostream>
using namespace std;

int Media::getYear(){
  return year;
}

void Media::setYear(int newyear){
  year = newyear;
}

char* Media::getTitle(){
  return title;
}

void Media::setTitle(char* newtitle){
  strcpy(title, newtitle);
}
