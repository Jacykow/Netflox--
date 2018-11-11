#ifndef ROMCOM_H
#define ROMCOM_H

#include "series.h"
using namespace std;

class Romcom : public Series{
	private:
		int loveTriangles;
		string additionalInfo();
	public:
		Romcom(string title) : Series(title){ }
		int getLoveTriangles(){	return loveTriangles;}
		void fillInfoByTitle();
		string getType();
};

#endif
