#ifndef __SORT__
#define __SORT__
//----------------------------------------------------------------------------------
#include <memory>
//----------------------------------------------------------------------------------
class Sort
{
public:
	static void mergeSort(int *mass, int start, int end);
	static void mergeSortWithInsertCount(int *mass, int start, int end,long &insert);

private:
	static void merge(int *mass, int start, int middle, int end);
	static void mergeWithInsertCount(int *mass, int start, int middle, int end, long &insert);

};
//----------------------------------------------------------------------------------
#endif // __SORT__

