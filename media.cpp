#include "media.h"
using namespace std;

Media::Media(string name, bool fillInfo){
	title = name;
	rating = -1;
	if(fillInfo){
		fillInfoByName();
	}
}
void Media::fillInfoByName(){
	srand(titleHash());
	length = 400 + rand()%400;
	score = rand()%11;
	description = "Something to watch anywhere, at any time, with anyone.";
}
string Media::getInfo(){
	string info = "\t";
	info.append(title);
	info.append("\nDuration:\t");
	info.append(to_string(length));
	info.append(" minutes\nRating:  \t");
	info.append(to_string(score));
	info.append(" / 10\nDescription:\t");
	info.append(description);
	return info;
}
unsigned int Media::titleHash(){
	return hashFromString(title);
}

unsigned int Media::hashFromString(string value){
	unsigned int u = 0;
	for(int x=0;x<value.length();x++){
		u+=(257+x)*(value[x]);
	}
	return u;
}
