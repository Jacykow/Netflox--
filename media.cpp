#include "media.h"
#include <string>
using namespace std;
string Media::getTitle(){
	return "kappa";
}
void Media::setTitle(string value){
	title = value;
}
Media::Media(){
	title = "abc";
}

