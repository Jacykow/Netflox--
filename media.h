#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include "utility.h"
using namespace std;
class Media{
	private:
		string title;
		int length;
		int score;
		string description;
		int rating;
		unsigned int hashFromString(string value);
	public:
		Media(string name, bool fillInfo = true); //X
		void setTitle(string value){ title = value;}
		string getTitle(){ return title;}
		int getScore(){ return score;}
		int getLength(){ return length;}
		void setRating(int value){ rating = value;};
		unsigned int titleHash();
		//virtual...
		virtual void fillInfoByName(); //X
		virtual string getInfo(); //X
};
#endif
