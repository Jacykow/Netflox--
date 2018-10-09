//Series collection
#ifndef SERIESCOL_H
#define SERIESCOL_H
#include <vector>
using namespace std;
class SeriesCol{
	private:
		vector<int> b;
	public:
		void AddB(int b);
		int GetLast();
};

#endif

