#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Media{
	private:
		string title;
		int score;
		string description;
		int rating;
		unsigned int hashFromString(string value);
		virtual string additionalInfo();
	protected:
		int duration;
	public:
		Media(string title, bool fillInfo = true); //X
		void setTitle(string value){ title = value;}
		string getTitle(){ return title;}
		int getScore(){ return score;}
		int getDuration(){ return duration;}
		void setRating(int value){ rating = value;};
		unsigned int titleHash();
		string getInfo();
		//virtual...
		virtual void fillInfoByTitle();
		virtual string getType();
};
#endif
