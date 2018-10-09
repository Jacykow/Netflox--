#include "seriescol.h"
int SeriesCol::GetLast(){
	return b[b.size()-1];
}
void SeriesCol::AddB(int value){
	b.push_back(value);
}
