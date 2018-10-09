#include <iostream>
#include "seriescol.h"
#include <vector>
using namespace std;

int main() {
	
	SeriesCol sc = SeriesCol();
	sc.AddB(3);
	cout<<sc.GetLast();
	
	return 0;
}
