#include "drama.h"

void Drama::fillInfoByTitle(){
	Series::fillInfoByTitle();
	plotTwists = 1+rand()%10;
	fundedByNetflox = rand()%2;
	setDescription("The plot holes never end.");
}
string Drama::additionalInfo(){
	string info = Series::additionalInfo();
	info.append("\nPlot logic:\t");
	info.append(to_string((isFundedByNetflox() ? 5 : 8)-getPlotTwists()/2));
	info.append("/10");
	return info;
}
string Drama::getType(){
	return "Drama";
}
