#ifndef PPVSHOW_H
#define PPVSHOW_H

#include "media.h"
using namespace std;

class PPVShow : public Media{
	private:
		string additionalInfo();
	public:
		PPVShow(string title) : Media(title){ }
		void fillInfoByTitle();
		string getType();
};

#endif
