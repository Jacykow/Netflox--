#ifndef ANIME_H
#define ANIME_H

#include "series.h"
using namespace std;

class Anime : public Series{
	private:
		float fillerDensity;
		string additionalInfo();
	public:
		float getFillerDensity(){ return fillerDensity;}
		Anime(string title) : Series(title){ }
		int getIMDbRating();
		void fillInfoByTitle();
		string getType();
};

#endif
