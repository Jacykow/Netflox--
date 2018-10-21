#ifndef MEDIA_H
#define MEDIA_H
#include <string>
using namespace std;
class Media{
	private:
		string title;
		int length;
		int score;
		string description;
	public:
		Media();
		void setTitle(string value);
		string getTitle();
};
#endif
