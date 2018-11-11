#include "mediacol.h"
using namespace std;

int main() {
	MediaCollection sc = MediaCollection("data.txt");
	sc.addRandomMedia(10);
	while(sc.menu());
	return 0;
}
