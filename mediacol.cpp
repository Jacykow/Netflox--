#include "mediacol.h"
using namespace std;

MediaCollection::MediaCollection(string file){
	fileName = file;
	load();
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
	try{
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
	}
	catch(string message){
		exitWithMessage(message);
	}
	
	return true;
}
MediaCollection::~MediaCollection(){
	save();
}
void MediaCollection::showAlerts(){
	bool found = false;
	for(int x=0;x<this->size();x++){
		if(this->at(x)->getType()=="PPVShow" && dynamic_cast<PPVShow*>(this->at(x))->isLiveSoon()){
			if(!found){
				cout<<"The following shows from your list will start soon:\n";
				found = true;
			}
			cout<<"- "<<this->at(x)->getTitle()<<endl;
		}
	}
	if(!found){
		cout<<"None of your shows are starting soon. Maybe add some more?\n";
	}
	else{
		cout<<endl;
	}
}

void MediaCollection::showAll(){
	system("cls");
	for(int x=0;x<this->size();x++){
		cout<<"("<<x+1<<")"<<this->at(x)->getType()<<"\t"<<this->at(x)->getTitle()<<endl;
		//<<"\tHASH: "<<this->at(x)->titleHash()
	}
}
void MediaCollection::addWithUser(){
	cout<<"Enter the title: ";
	string title;
	getline(cin,title);
	getline(cin,title);
	cout<<"What king of media is "<<title<<"?"<<endl;
	cout<<"(1) No idea"<<endl;
	cout<<"(2) Some series"<<endl;
	cout<<"(3) Romantic comedy"<<endl;
	cout<<"(4) Drama"<<endl;
	cout<<"(5) Anime"<<endl;
	cout<<"(6) Movie"<<endl;
	cout<<"(7) PPV show"<<endl;
	cout<<"(0) Return"<<endl;
	switch(getFromInput<int>("Pick one: ")){
		case 1:
			this->add(new Media(title));
			break;
		case 2:
			this->add(new Series(title));
			break;
		case 3:
			this->add(new Romcom(title));
			break;
		case 4:
			this->add(new Drama(title));
			break;
		case 5:
			this->add(new Anime(title));
			break;
		case 6:
			this->add(new Movie(title));
			break;
		case 7:
			this->add(new PPVShow(title));
			break;
		case 0:
			exitWithMessage("Going back to the menu...");
			return;
		default:
			exitWithMessage("Out of range :(");
			return;
	}
	save();
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
		throw("Out of range :(");
		return;
	}
	cout<<"Removing "<<this->at(index-1)->getTitle()<<endl;
	delete(this->at(index-1));
	this->erase(this->begin() + (index-1));
	save();
	exitWithMessage("");
}
void MediaCollection::rateWithUser(){
	int index = getFromInput<int>("Enter the corresponding number: ");
	if(index == 0){
		exitWithMessage("Going back to the menu...");
		return;
	}
	if(index < 0 || index > this->size()){
		throw("Out of range :(");
		return;
	}
	int userScore = getFromInput<int>("Enter Your userScore on a 1-10 scale: ");
	if(userScore == 0){
		exitWithMessage("Going back to the menu...");
		return;
	}
	if(userScore < 1 || userScore > 10){
		throw("Out of range :(");
		return;
	}
	this->at(index-1)->setUserScore(userScore);
	save();
	cout<<"Rated "<<this->at(index-1)->getTitle()<<" at "<<userScore<<"/10";
	exitWithMessage("");
}
void MediaCollection::showDetailsWithUser(){
	int index = getFromInput<int>("Enter the corresponding number: ");
	if(index == 0){
		exitWithMessage("Going back to the menu...");
		return;
	}
	if(index < 0 || index > this->size()){
		throw("Out of range :(");
		return;
	}
	cout<<this->at(index-1)->getInfo();
	exitWithMessage("");
}
void MediaCollection::showRecommendations(){
	addRandomMedia(5);
	exitWithMessage("There is a new season of Galactic Encounters! Watch it now!");
}

void MediaCollection::exitWithMessage(string message){
	cout<<message<<endl;
	system("pause");
	system("cls");
}
void MediaCollection::add(Media* s){
	s->fillInfoByTitle();
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
		switch((t+x)%7+1){
			case 1:
				this->add(new Media(title));
				break;
			case 2:
				this->add(new Series(title));
				break;
			case 3:
				this->add(new Romcom(title));
				break;
			case 4:
				this->add(new Drama(title));
				break;
			case 5:
				this->add(new Anime(title));
				break;
			case 6:
				this->add(new PPVShow(title));
				break;
			case 7:
				this->add(new Movie(title));
				break;
		}
	}
}

void MediaCollection::save(){
	ofstream file;
	file.open(fileName);
	Media* m;
	for(int x=0;x<this->size();x++){
		m=this->at(x);
		file<<m->getType()<<endl;
		file<<m->getTitle()<<endl;
		file<<m->getUserScore()<<endl;
	}
	file.close();
}
void MediaCollection::load(){
	ifstream file;
	file.open(fileName);
	string line, title;
	int score;
	while(getline(file,line)){
		getline(file,title);
		if(line == "Unknown"){
			this->add(new Media(title));
		}
		else if(line == "Series"){
			this->add(new Series(title));
		}
		else if(line == "Romcom"){
			this->add(new Romcom(title));
		}
		else if(line == "Drama"){
			this->add(new Drama(title));
		}
		else if(line == "Anime"){
			this->add(new Anime(title));
		}
		else if(line == "PPVShow"){
			this->add(new PPVShow(title));
		}
		else if(line == "Movie"){
			this->add(new Movie(title));
		}
		else{
			return;
		}
		file>>score;
		getline(file,line);
		this->back()->setUserScore(score);
	}
	file.close();
}

// Ewidentnie powinno to byæ w jakimœ namespace Utility, ale po 2 godzinach walki ze œrodowiskiem
// odpuœci³em sobie to marzenie - bêdzie w wersji 2.0 :)
template<class T>
T MediaCollection::getFromInput(string text){
	T out;
	cout<<text;
	cin>>out;
	return out;
}
