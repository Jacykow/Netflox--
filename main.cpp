#include "mediacol.h"
using namespace std;

int main() {
	MediaCollection sc = MediaCollection("data.txt");
	sc.showAlerts();
	while(sc.menu());
	return 0;
}
