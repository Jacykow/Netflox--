#include "movie.h"

void Movie::fillInfoByTitle(){
	Media::fillInfoByTitle();
	budget = 1+rand()%20;
	setDescription("A wonderful adventure of friendship and magic for the whole family.");
}
string Movie::additionalInfo(){
	string info = Media::additionalInfo();
	info.append("\nSPECTACLE:\t");
	int spectacle = getBudget() * 1000;
	if(spectacle > 9000){
		info.append("OVER 9000!!!!!!!!");
	}
	else{
		info.append(to_string(spectacle));
	}
	return info;
}
string Movie::getType(){
	return "Movie";
}
