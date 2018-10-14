#ifndef SERIES_H
#define SERIES_H
#include <string>
using namespace std;
class Series{
	private:
		string title;
		int length;
		int score;
		string description;
	public:
		Series();
		void setTitle(string value);
		string getTitle();
};
#endif
