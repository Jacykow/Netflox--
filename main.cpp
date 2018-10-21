#include <iostream>
#include "mediacol.h"
#include <new>
using namespace std;

int main() {
	
	Media* s = new Media();
	
	MediaCollection sc = MediaCollection("data.txt");
	sc+=s;
	sc.showAll();
	
	
	return 0;
}
