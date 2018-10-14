#include "series.h"
#include <string>
using namespace std;
string Series::getTitle(){
	return title;
}
void Series::setTitle(string value){
	title = value;
}
Series::Series(){
	title = "abc";
}

