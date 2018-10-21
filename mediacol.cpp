#include "mediacol.h"
#include <iostream>
using namespace std;
MediaCollection::MediaCollection(string file){
	fileName = file;
}
void MediaCollection::showAll(){
	for(int x=0;x<this->size();x++){
		cout<<x+1<<". "<<this->at(x)->getTitle()<<endl;
	}
}
void MediaCollection::addSeries(Media* s){
	this->push_back(s);
}
void MediaCollection::operator+=(Media* s){
	addSeries(s);
}
