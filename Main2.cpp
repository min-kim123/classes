#include <string.h>
#include <iostream>
#include <vector>
#include "Videogame.h"
#include "Music.h"
#include "Movie.h"
#include <cstring>
#include "Media.h"
using namespace std;


void print(Media *aa) {
  if (aa->type == 0){//video game
            VideoGame* childNew = static_cast<VideoGame*>(aa);
            cout << "------------------------" << endl;
            cout << "|Video Game|" << endl;
            cout << "Title: " << childNew->getTitle() << endl;
            cout << "Rating: " << childNew->getRating() << endl;
            cout << "Year: " << childNew->getYear() << endl;
            cout << "Publisher: " << childNew->getPublisher() << endl;
        }
        else if(aa->type == 1){//music
            Music* childNew = static_cast<Music*>(aa);
            cout << "------------------------" << endl;
            cout << "|Music|" << endl;
            cout << "Title: " << childNew->getTitle() << endl;
            cout << "Artist: " << childNew->getArtist() << endl;
            cout << "Year: " << childNew->getYear() << endl;
            cout << "Publisher: " << childNew->getPublisher() << endl;
            cout << "Duration: " << childNew->getDuration() << endl;
        }
        else if (aa->type ==2){//movie
            Movie* childNew = static_cast<Movie*>(aa);
            cout << "------------------------" << endl;
            cout << "|Movie|"<< endl;
            cout << "Title: " << childNew->getTitle() << endl;
            cout << "Director: " << childNew->getDirector() << endl;
            cout << "Year: " << childNew->getYear() << endl;
            cout << "Rating: " << childNew->getRating() << endl;
            cout << "Duration: " << childNew->getDuration() << endl;
        }
}
void search(vector <Media*> & pmedia) {//search media database- if multiple objects match, all are listed
  VideoGame videogame;
  Movie movie;
  Music music;
  char toy[10];//title or year
  char title[80];
  int year;
  Media *child; //pointer to media

  cout << "Are you searching the Title or the Year? (TITLE, YEAR): " << endl;
  cin >> toy;
  cin.ignore();
  if (strcmp(toy, "TITLE") == 0) {
    cout << "Enter the title: ";
    cin.getline(title, 80);
    for(vector<Media*>::iterator it = pmedia.begin(); it != pmedia.end(); it++){
      child = (Media*)(*it); // cast parent to child
      if (!strcmp(child->getTitle(), title)){
        print(child);
      }
    cout << "------------------------" << endl;
    }
  }
  // user chose year
  else if (strcmp(toy, "YEAR") == 0) {
    cout << "Enter the year: ";
    cin >> year;
    cin.ignore();
    for(vector<Media*>::iterator it = pmedia.begin(); it != pmedia.end();it++){
      child = (Media*)(*it);
      if (child->getYear()==year){
        print(child);
      }
    }
    cout << "------------------------" << endl;
  }
}
void add(vector <Media*> & pmedia) {//ADD MEDIA
  char add_input[30];

  //ask what kind of media user wants to add, then go inside whatever if statement matches with input
  cout << "What kind of media would you like to add? (VIDEO GAME, MUSIC, MOVIE): " << endl;
  cin.getline(add_input,30);
  if (strcmp(add_input, "VIDEO GAME") == 0) {//ADD VIDEO GAME
    VideoGame* videogame = new VideoGame;
    int vgYear;
    float vgRating;
    char vgTitle[80];
    char vgPublisher[80];

    videogame->type=0;
    //video game title
    cout << "Video Game Title: " << endl;
    cin.getline(vgTitle, 80);
    videogame->setTitle(vgTitle);
    //video game year
    cout << "Video Game Year: " << endl;
    cin >> vgYear;
    videogame->setYear(vgYear);
    cin.ignore();  // Get rid of new line character
    //video game publisher
    cout << "Video Game Publisher: " << endl;
    cin.getline(vgPublisher, 80);
    videogame->setPublisher(vgPublisher);
    //video game rating
    cout << "Video Game Rating (scale of 1 to 5: 1-worst 5-awesome): " << endl;
    cin >> vgRating;
    cin.ignore();
    videogame->setRating(vgRating);
    pmedia.push_back(videogame);
  }

  else if (strcmp(add_input, "MUSIC") == 0) {//ADD MUSIC
    Music* music = new Music;
    int musicYear;
    char musicTitle[80];
    char musicDuration[80];
    char musicArtist[80];
    char musicPublisher[80];
    music->type = 1;

    cout << "Music Title: " << endl;
    cin.getline(musicTitle, 80);
    music->setTitle(musicTitle);
    cout << "Music Artist: " << endl;
    cin.getline(musicArtist, 80);
    music->setArtist(musicArtist);
    cout << "Music Year: " << endl;
    cin >> musicYear;
    music->setYear(musicYear);
    cin.ignore();  // Get rid of new line character
    cout << "Music Duration (x:xx): " << endl;
    cin >> musicDuration;
    cin.ignore();
    music->setDuration(musicDuration);
    cout << "Music Publisher: " << endl;
    cin.getline(musicPublisher, 80);
    music->setPublisher(musicPublisher);
    pmedia.push_back(music);
  }

  else if (strcmp(add_input, "MOVIE") == 0) {//ADD MOVIE
    Movie* movie = new Movie;
    int movieYear;
    int movieRating;
    char movieDuration[80];
    char movieTitle [10];
    char movieDirector[10];

    movie->type = 2;
    cout << "Movie Title: " << endl;
    cin.getline(movieTitle, 80);
    movie->setTitle(movieTitle);
    cout << "Movie Director: " << endl;
    cin.getline(movieDirector, 80);
    movie->setDirector(movieDirector);
    cout << "Movie Year: " << endl;
    cin >> movieYear;
    cin.ignore();  // Get rid of new line character
    movie->setYear(movieYear);
    cout << "Movie Duration (x:xx): " << endl;
    cin.getline(movieDuration, 80);
    movie->setDuration(movieDuration);
    cout << "Movie Rating (scale of 1 to 5: 1-worst 5-awesome): " << endl;
    cin >> movieRating;
    cin.ignore();
    movie->setRating(movieRating);
    pmedia.push_back(movie);
  }
}
void delet(vector <Media*> &pmedia) {
  VideoGame videogame;
  Movie movie;
  Music music;

  int year;
  char title[80];
  char toy[80];

  Media* child; 
  int input2;//
  char yon; //y/n char input to confirm deletion

  cout << "Do you have the title or year of the media to delete?  (TITLE, YEAR): " << endl;
  cin.getline(toy, 80);
  if (strcmp(toy, "TITLE") == 0) {//search for title and output
    input2 = 0;//save for later when confirming deleton
    cout << "Title: ";
    cin.getline(title, sizeof(title));
    for(vector<Media*>::iterator it = pmedia.begin(); it != pmedia.end();it++){
      child = (Media*)(*it);
      if (!strcmp(child->getTitle(), title)){
        print(child);
      }
    cout << "------------------------" << endl;
    }
  }
  // user chose year
  else if (strcmp(toy, "YEAR") == 0) {//search for year and output
    input2 = 1;//save for later when confirming deletion
    cout << "Year: ";
    cin >> year;
    cin.ignore();
    for(vector<Media*>::iterator it = pmedia.begin(); it != pmedia.end();it++){
      child = (Media*)(*it);
      if (child->getYear()==year){
        print(child);
      }
    }
    cout << "------------------------" << endl;
  }
  
  // user confirmation for deletion
  cout << "Would you like to delete? (y, n)";
  cin >> yon;
  cin.ignore();
  if (yon == 'y'){//deletes
    if (input2 == 1){ // if user previously entered a year it goes here
      for(vector<Media*>::iterator it = pmedia.begin(); it != pmedia.end();it++){//loop through Media vector
        child = (Media*)(*it);
        if(child->getYear()==year){//if the same year is found, it is deleted
            delete *it; 
            pmedia.erase(it--); // remove vector
        }
      }
    }
    else if(input2 == 0){ // if user previously entered a title it goes here
      for(vector<Media*>::iterator it = pmedia.begin(); it != pmedia.end();it++){//loop through Media vector
        child = (Media*)(*it);
        if(!strcmp(child->getTitle(), title)) {//if the same title is found, it is deleted
          delete *it; 
          pmedia.erase(it--); // remove vector 
        }
      }
    }
    cout << "Deleted" << endl;
  }
  else if (yon == 'n') {//does not delete
      cout << "Not deleted" << endl;
  }
}

int main () {
  vector <Media*> pmedia; 
  bool cont = true;
  char input[30];

  while (cont == true) {
    cout << "Do you want to add, search, delete, or quit? (ADD, SEARCH, DELETE, QUIT): ";
    cin.getline(input, 30);
    if (strcmp(input, "ADD") == 0) {//if input = "ADD" it adds a media element
      add(pmedia);
    }
    else if (strcmp(input, "SEARCH") == 0) {//if input = "SEARCH" it searches for media elements
      search(pmedia);
    }
    else if (strcmp(input, "DELETE") == 0) {//if input = "DELETE" it deletes media elements
      delet(pmedia);
    }
    else if (strcmp(input, "QUIT") == 0) {//quit
      cont = false;
    }
  }
  return 0;
}