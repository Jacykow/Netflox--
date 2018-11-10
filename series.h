#ifndef SERIES_H
#define SERIES_H

#include <string>
#include "media.h"
using namespace std;

class Series : public Media{
	private:
		int seasons;
		int episodesPerSeason;
		string additionalInfo();
	public:
		explicit Series(string title, bool fillInfo = true) : Media(title, fillInfo) {	}
		int getSeasons(){ return seasons;}
		int getEpisodesPerSeason(){ return episodesPerSeason;}
		virtual void fillInfoByTitle() override;
		virtual string getType();
};
#endif
