#include "media.h"
using namespace std;

Media::Media(string title, bool fillInfo){
	this->title = title;
	rating = -1;
	if(fillInfo){
		cout<<endl<<"HERE1"<<endl;
		fillInfoByTitle();
	}
}
void Media::fillInfoByTitle(){
	srand(titleHash());
	cout<<endl<<"HERE2"<<endl;
	duration = 75 + rand()%125;
	score = 1+rand()%10;
	description = "Something to watch anywhere, at any time, with anyone.";
}
string Media::getInfo(){
	string info = "\t";
	info.append(title);
	info.append("\nGlobal Rating:\t");
	info.append(to_string(score));
	info.append("/10\n");
	if(rating != -1){
		info.append("Your Rating:\t");
		info.append(to_string(rating));
		info.append("/10\n");
	}
	info.append(additionalInfo());
	info.append("\nDescription:\t");
	info.append(description);
	return info;
}
string Media::additionalInfo(){
	string info = "";
	info.append("Duration:\t");
	info.append(to_string(duration));
	info.append(" minutes.");
	return info;
}
unsigned int Media::titleHash(){
	return hashFromString(title);
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
