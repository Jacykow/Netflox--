#include "mediacol.h"
using namespace std;

int main() {
	MediaCollection sc = MediaCollection("data.txt");
	while(sc.menu());
	return 0;
}
