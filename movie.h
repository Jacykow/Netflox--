#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"
using namespace std;

class Movie : public Media{
	private:
		string additionalInfo();
		int budget;
	public:
		int getBudget(){ return budget;}
		Movie(string title) : Media(title){ }
		void fillInfoByTitle();
		string getType();
};

#endif
