#include "romcom.h"

void Romcom::fillInfoByTitle(){
	Series::fillInfoByTitle();
	loveTriangles = 1+rand()%10;
	setDescription("The same plot as in every romcom ever. What did you expect?");
}
string Romcom::additionalInfo(){
	string info = Series::additionalInfo();
	info.append("\nPlot logic:\t");
	info.append(to_string(5-loveTriangles/2));
	info.append("/10");
	return info;
}
string Romcom::getType(){
	return "Romcom";
}
