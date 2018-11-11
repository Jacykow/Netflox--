#ifndef SERIES_H
#define SERIES_H

#include "media.h"
using namespace std;

class Series : public Media{
	private:
		int seasons;
		int episodesPerSeason;
	protected:
		virtual string additionalInfo();
	public:
		Series(string title) : Media(title){ }
		int getSeasons(){ return seasons;}
		int getEpisodesPerSeason(){ return episodesPerSeason;}
		
		virtual void fillInfoByTitle();
		virtual string getType();
};
#endif
