#include "series.h"

void Series::fillInfoByTitle(){
	Media::fillInfoByTitle();
	seasons = 1 + (rand()%5) * (rand()%5);
	episodesPerSeason = 3 + (rand()%8) * (rand()%8);
	setDuration(20 + rand()%60);
	setDescription("The sci-fi medium-budget psychology-horror of the week.");
}
string Series::additionalInfo(){
	string info = "";
	info.append("Seasons:\t");
	info.append(to_string(seasons));
	info.append("\nAvg. Episodes:\t");
	info.append(to_string(episodesPerSeason));
	info.append("\nAvg. Minutes:\t");
	info.append(to_string(getDuration()));
	info.append("\nTotal time:\t");
	info.append(to_string((getDuration() * getEpisodesPerSeason() * getSeasons())/60));
	info.append(" hours");
	return info;
}
string Series::getType(){
	return "Series";
}
