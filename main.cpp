#include <iostream>
#include "SeriesCollection.h"
//#include "series.h"
using namespace std;

int main() {
	
	Series s = Series();
	
	SeriesCollection sc = SeriesCollection();
	sc+=s;
	sc.show();
	
	
	return 0;
}
