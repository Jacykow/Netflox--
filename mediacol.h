#ifndef MEDIACOL_H
#define MEDIACOL_H
#include <vector>
#include "media.h"
#include <iostream>
#include <new>
#include <time.h>
using namespace std;
class MediaCollection : public vector<Media*>{
	private:
		string fileName;
		void load();
		void save();
		template<class T>
		T getFromInput(string text);
		void addWithUser();
	public:
		MediaCollection(string file);
		bool menu();
		void add(Media* s);
		void operator+=(Media* s);
		void showAll(); //X
		void showRecommendations(int amount);
		void addRandomMedia(int amount);
};
#endif

