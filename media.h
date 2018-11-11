#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Media{
	private:
		string title;
		int IMDbRating;
		int userScore;
		unsigned int hashFromString(string value);
		string description;
		int duration;
	protected:
		setDuration(int value){ duration = value;}
		setDescription(string value){ description = value;}
		
		virtual string additionalInfo();
	public:
		Media(string title);
		void setTitle(string value){ title = value;}
		string getTitle(){ return title;}
		int getIMDbRating(){ return IMDbRating;}
		int getDuration(){ return duration;}
		void setUserScore(int value){ userScore = value;}
		int getUserScore(){	return userScore;}
		unsigned int titleHash();
		string getInfo();
		string getDescription(){ return description;}
		
		virtual void fillInfoByTitle();
		virtual string getType();
};
#endif
