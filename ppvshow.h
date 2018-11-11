#ifndef PPVSHOW_H
#define PPVSHOW_H

#include "media.h"
using namespace std;

class PPVShow : public Media{
	private:
		int popularity;
		string additionalInfo();
	public:
		int getPopularity(){ return popularity;}
		PPVShow(string title) : Media(title){ }
		void fillInfoByTitle();
		string getType();
};

#endif
