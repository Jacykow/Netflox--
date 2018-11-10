#include "mediacol.h"
using namespace std;
MediaCollection::MediaCollection(string file){
	fileName = file;
}
bool MediaCollection::menu(){
	cout<<"   MENU"<<endl;
	cout<<"(1) Show all."<<endl;
	cout<<"(2) Add."<<endl;
	cout<<"(3) Remove."<<endl;
	cout<<"(4) Rate."<<endl;
	cout<<"(5) Show Details."<<endl;
	cout<<"(6) Show Recommendations."<<endl;
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
		case 3:
			removeWithUser();
			break;
		case 4:
			rateWithUser();
			break;
		case 5:
			showDetailsWithUser();
			break;
		case 6:
			showRecommendations();
			break;
		default:
			exitWithMessage("Out of range :(");
			break;
	}
	return true;
}



void MediaCollection::showAll(){
	system("cls");
	for(int x=0;x<this->size();x++){
		cout<<"("<<x+1<<")"<<this->at(x)->getType()<<"\t"<<this->at(x)->getTitle()<<"\t HASH: "<<this->at(x)->titleHash()<<endl;
	}
}
void MediaCollection::addWithUser(){
	string title = getFromInput<string>("Enter the title: ");
	cout<<"What king of media is "<<title<<"?"<<endl;
	cout<<"(1) No idea"<<endl;
	cout<<"(0) Return"<<endl;
	switch(getFromInput<int>("Pick one: ")){
		case 1:
			this->add(new Media(title));
			break;
		case 0:
			exitWithMessage("Going back to the menu...");
			return;
		default:
			exitWithMessage("Out of range :(");
			return;
	}
	cout<<endl<<"We found this in our database and added it to your list."<<endl;
	cout<<this->back()->getInfo()<<endl;
	exitWithMessage("");
}
void MediaCollection::removeWithUser(){
	int index = getFromInput<int>("Enter the corresponding number: ");
	if(index == 0){
		exitWithMessage("Going back to the menu...");
		return;
	}
	if(index < 0 || index > this->size()){
		exitWithMessage("Out of range :(");
		return;
	}
	cout<<"Removing "<<this->at(index-1)->getTitle()<<endl;
	delete(this->at(index-1));
	this->erase(this->begin() + (index-1));
	exitWithMessage("");
}
void MediaCollection::rateWithUser(){
	int index = getFromInput<int>("Enter the corresponding number: ");
	if(index == 0){
		exitWithMessage("Going back to the menu...");
		return;
	}
	if(index < 0 || index > this->size()){
		exitWithMessage("Out of range :(");
		return;
	}
	int rating = getFromInput<int>("Enter Your rating on a 1-10 scale: ");
	if(rating == 0){
		exitWithMessage("Going back to the menu...");
		return;
	}
	if(rating < 1 || rating > 10){
		exitWithMessage("Out of range :(");
		return;
	}
	this->at(index-1)->setRating(rating);
	cout<<"Rated "<<this->at(index-1)->getTitle()<<" at "<<rating<<"/10";
	exitWithMessage("");
}
void MediaCollection::showDetailsWithUser(){
	int index = getFromInput<int>("Enter the corresponding number: ");
	if(index == 0){
		exitWithMessage("Going back to the menu...");
		return;
	}
	if(index < 0 || index > this->size()){
		exitWithMessage("Out of range :(");
		return;
	}
	cout<<this->at(index-1)->getInfo();
	exitWithMessage("");
}
void MediaCollection::showRecommendations(){
	addRandomMedia(5);
	exitWithMessage("There is a new season of Galactic Encounters! Watch it now!");
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
		string title = "Galactic Encounters Season ";
		title.append(to_string(t));
		title.append(" Episode ");
		title.append(to_string(x+1));
		switch((t+x)%5+1){
			case 1:
				this->add(new Media(title));
				break;
			case 2:
				this->add(new Series(title));
				break;
			case 3:
				this->add(new Media(title));
				break;
			case 4:
				this->add(new Media(title));
				break;
			case 5:
				this->add(new Media(title));
				break;
		}
	}
}
void MediaCollection::exitWithMessage(string message){
	cout<<message<<endl;
	system("pause");
	system("cls");
}

// Wiem, ¿e to ewidentnie powinno byæ w jakimœ namespace Utility, ale po 3 godzinach walki ze œrodowiskiem
// odpuœci³em sobie to marzenie - bêdzie w wersji 2.0 :)
template<class T>
T MediaCollection::getFromInput(string text){
	T out;
	cout<<text;
	cin>>out;
	return out;
}
