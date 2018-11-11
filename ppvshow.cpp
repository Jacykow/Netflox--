#include "ppvshow.h"

void PPVShow::fillInfoByTitle(){
	Media::fillInfoByTitle();
	popularity = 1+rand()%10;
	setDescription("Watch now or wait a month to watch for free!");
}
string PPVShow::additionalInfo(){
	string info = Media::additionalInfo();
	info.append("\nCost:\t");
	info.append(to_string(getPopularity() * getDuration() / 10));
	info.append(".");
	info.append(to_string(getPopularity() * getDuration() % 10));
	info.append("9 PLN");
	return info;
}
string PPVShow::getType(){
	return "PPVShow";
}
