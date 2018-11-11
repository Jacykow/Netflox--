#ifndef DRAMA_H
#define DRAMA_H

#include "series.h"
using namespace std;

class Drama : public Series{
	private:
		int plotTwists;
		bool fundedByNetflox;
		string additionalInfo();
	public:
		int getPlotTwists(){ return plotTwists;}
		bool isFundedByNetflox(){ return fundedByNetflox;}
		Drama(string title) : Series(title){ }
		void fillInfoByTitle();
		string getType();
};

#endif
