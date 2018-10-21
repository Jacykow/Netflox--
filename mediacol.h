//Media collection
#ifndef MEDIACOL_H
#define MEDIACOL_H
#include <vector>
#include "media.h"
using namespace std;
class MediaCollection : public vector<Media*>{
	private:
		string fileName;
		void load();
		void save();
	public:
		MediaCollection(string file);
		bool showOptions();
		void addSeries(Media* s);
		void operator+=(Media* s);
		void removeSeries(string name);
		void operator-=(string name);
		void showAll();
		void showStats();
		void showRecommendations(int amount);
};
#endif

