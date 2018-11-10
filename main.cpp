#include "mediacol.h"
using namespace std;

int main() {
	MediaCollection sc = MediaCollection("data.txt");
	sc.addRandomMedia(5);
	while(sc.menu());
	return 0;
}
