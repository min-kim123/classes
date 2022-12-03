#ifndef MEDIA_H
#define MEDIA_H
#include <string.h>
using namespace std;

class Media {
 public:
  char title[80];
  int year;
  int type; // indicate child type if parent pointer is pointing to a child object
  int getYear();
  void setYear(int newyear);
  char* getTitle();
  void setTitle(char newtitle[80]);
};

#endif