#include "anime.h"

void Anime::fillInfoByTitle(){
	Series::fillInfoByTitle();
	fillerDensity = (0.5f+rand()%100000) / (100000.0f);
	setDescription("THEIR EYES ARE FAKE!");
}
string Anime::additionalInfo(){
	string info = Series::additionalInfo();
	info.append("\nTime wasted:\t");
	int w = (getDuration() * getEpisodesPerSeason() * getSeasons())/60 * getFillerDensity();
	info.append(to_string(w));
	return info;
}
string Anime::getType(){
	return "Anime";
}
int Anime::getIMDbRating(){
	return max(Series::getIMDbRating()-3, 1);
}
