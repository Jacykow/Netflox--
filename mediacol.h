#ifndef MEDIACOL_H
#define MEDIACOL_H

#include <vector>
#include <fstream>
#include <iostream>
#include <new>
#include <time.h>
#include "media.h"
#include "series.h"
#include "romcom.h"
#include "drama.h"
#include "anime.h"
#include "ppvshow.h"
#include "movie.h"
using namespace std;

class MediaCollection : public vector<Media*>{
	private:
		string fileName;
		template<class T>
		T getFromInput(string text);
		void addWithUser();
		void removeWithUser();
		void rateWithUser();
		void showDetailsWithUser();
		void showRecommendations();
		void exitWithMessage(string message);
	public:
		MediaCollection(string file);
		~MediaCollection();
		bool menu();
		void add(Media* s);
		void operator+=(Media* s);
		void showAll();
		void addRandomMedia(int amount);
		void load();
		void save();
};
#endif

