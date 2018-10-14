#include "SeriesCollection.h"
#include <iostream>
using namespace std;
SeriesCollection::SeriesCollection(){
	series.clear(); 
}
void SeriesCollection::show(){
	for(int x=0;x<series.size();x++){
		cout<<x+1<<". "<<series[x].getTitle()<<endl;
	}
}
void SeriesCollection::Add(Series s){
	series.push_back(s);
}
void SeriesCollection::operator+=(Series s){
	Add(s);
}
