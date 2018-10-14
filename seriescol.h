//Series collection
#ifndef SERIESCOL_H
#define SERIESCOL_H
#include <vector>
#include "series.h"
using namespace std;
class SeriesCollection : vector<Series>{
	private:
		string fileName;
		void load();
		void save();
	public:
		SeriesCollection(string file);
		bool showOptions();
		void addSeries(Series s);
		void operator+=(Series s);
		void removeSeries(string name);
		void operator-=(string name);
		void showAll();
		void showStats();
		void showRecommendations(int amount);
};
#endif

