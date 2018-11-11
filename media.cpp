#include "media.h"
using namespace std;

Media::Media(string title){
	this->setTitle(title);
	userScore = -1;
}
void Media::fillInfoByTitle(){
	srand(titleHash());
	setDuration(75 + rand()%125);
	IMDbRating = 1+rand()%10;
	setDescription("Something to watch anywhere, at any time, with anyone.");
}
string Media::getInfo(){
	string info = "\t";
	info.append(getTitle());
	info.append("\nIMDb rating:\t");
	info.append(to_string(getIMDbRating()));
	info.append("/10\n");
	if(userScore != -1){
		info.append("Your rating:\t");
		info.append(to_string(getUserScore()));
		info.append("/10\n");
	}
	info.append(additionalInfo());
	info.append("\nDescription:\t");
	info.append(getDescription());
	return info;
}
string Media::additionalInfo(){
	string info = "";
	info.append("Duration:\t");
	info.append(to_string(getDuration()));
	info.append(" minutes.");
	return info;
}
unsigned int Media::titleHash(){
	return hashFromString(getTitle());
}
string Media::getType(){
	return "Unknown";
}

unsigned int Media::hashFromString(string value){
	unsigned int u = 0;
	for(int x=0;x<value.length();x++){
		u+=(257+x)*(value[x]);
	}
	return u;
}
