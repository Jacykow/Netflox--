#include "mediacol.h"
using namespace std;
MediaCollection::MediaCollection(string file){
	fileName = file;
}
bool MediaCollection::menu(){
	system("cls");
	cout<<"\tMENU"<<endl;
	cout<<"(1) Show all media."<<endl;
	cout<<"(2) Add media."<<endl;
	cout<<"(0) Exit."<<endl;
	switch(getFromInput<int>("Pick an option: ")){
		case 0:
			return false;
			break;
		case 1:
			showAll();
			break;
		case 2:
			addWithUser();
			break;
		default:
			cout<<"Invalid number!"<<endl;
			break;
	}
	system("pause");
	return true;
}



void MediaCollection::showAll(){
	for(int x=0;x<this->size();x++){
		cout<<"("<<x+1<<")\t"<<this->at(x)->getTitle()<<"\t HASH: "<<this->at(x)->titleHash()<<endl;
	}
	int o = getFromInput<int>("(0) Return\n\nPick a number from the list to get the full descpription. Enter a negative number to remove the correspoding media from the list.\n");
	if(o == 0){
		cout<<"Going back to the menu..."<<endl;;
		return;
	}
	if(abs(o)-1 > this->size()){
		cout<<o<<" Out of range :("<<endl;
		return;
	}
	if(o < 0) {
		o=abs(o);
		cout<<"Removing "<<this->at(o-1)->getTitle()<<endl;
		delete(this->at(o-1));
		this->erase(this->begin() + (o-1));
	}
	else {
		cout<<this->at(o-1)->getInfo()<<endl;
	}
}
void MediaCollection::addWithUser(){
	
}


void MediaCollection::add(Media* s){
	this->push_back(s);
}
void MediaCollection::operator+=(Media* s){
	add(s);
}
void MediaCollection::addRandomMedia(int amount){
	srand(time(NULL));
	int t = 1+rand()%100000;
	for(int x=0;x<amount;x++){
		string name = "Galactic Encounters Season ";
		name.append(to_string(t));
		name.append(" Episode ");
		name.append(to_string(x+1));
		switch((t+x)%5+1){
			case 1:
				this->add(new Media(name));
				break;
			case 2:
				this->add(new Media(name));
				break;
			case 3:
				this->add(new Media(name));
				break;
			case 4:
				this->add(new Media(name));
				break;
			case 5:
				this->add(new Media(name));
				break;
		}
	}
}

// Wiem, ¿e to ewidentnie powinno byæ w jakimœ namespace Utility, ale po 3 godzinach walki ze œrodowiskiem
// odpuœci³em sobie to marzenie - bêdzie w wersji 2.0 :)
template<class T>
T MediaCollection::getFromInput(string text){
	T out;
	cout<<text;
	cin>>out;
	system("cls");
	return out;
}
int abs(int a){
	return a<0 ? -a : a;
}
