#include <iostream>
#include "seriescol.h"
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	SeriesCol sc = SeriesCol();
	sc.AddB(3);
	cout<<sc.GetLast();
	
	return 0;
}
