#include "series.h"
#include "media.h"

void Series::fillInfoByTitle(){
	cout<<endl<<"HERE3"<<endl;
	Media::fillInfoByTitle();
	cout<<endl<<"HERE4"<<endl;
	seasons = 1 + (rand()%5) * (rand()%5);
	episodesPerSeason = 3 + (rand()%8) * (rand()%8);
	duration = 20 + rand()%60;
}
string Series::additionalInfo(){
	string info = "";
	info.append("Seasons:\t");
	info.append(to_string(seasons));
	info.append("\nEpisodes:\t");
	info.append(to_string(episodesPerSeason));
	info.append("\nSeasons:\t");
	info.append(to_string(duration));
	info.append("\nTotal minutes:\t");
	info.append(to_string(duration * episodesPerSeason * seasons));
	return info;
}
string Series::getType(){
	return "Series";
}
