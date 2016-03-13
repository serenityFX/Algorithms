#include "Sort.h"
//----------------------------------------------------------------------------------
void Sort::mergeSort(int *mass, int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		mergeSort(mass, start,middle);
		mergeSort(mass, middle + 1, end);
		merge(mass, start, middle, end);
	}
}
//----------------------------------------------------------------------------------
void Sort::mergeSortWithInsertCount(int *mass, int start, int end,long &insert)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		mergeSortWithInsertCount(mass, start, middle,insert);
		mergeSortWithInsertCount(mass, middle + 1, end, insert);
		mergeWithInsertCount(mass, start, middle, end,insert);
	}
}
//----------------------------------------------------------------------------------
void Sort::merge(int *mass, int start, int middle, int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;

	int *L = new int[n1+1];
	int *R = new int[n2+1];

	for (int i = 1; i <= n1; ++i) L[i-1] = mass[start + i -1];
	for (int j = 1; j <= n2; ++j) R[j-1] = mass[middle + j];

	int i = 0, j = 0;
	for (int k = start; k <= end; ++k)
	{
		if (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				mass[k] = L[i];
				i++;
			}
			else
			{
				mass[k] = R[j];
				j++;
			}
		}
		else if (i<n1) {
			mass[k] = L[i];
			i++;
		}
		else {
			mass[k] = R[j];
			j++;
		}
		
	}

	delete[] L;
	delete[] R;
}
//----------------------------------------------------------------------------------
void Sort::mergeWithInsertCount(int *mass, int start, int middle, int end, long &insert)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;

	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];

	for (int i = 1; i <= n1; ++i) L[i - 1] = mass[start + i - 1];
	for (int j = 1; j <= n2; ++j) R[j - 1] = mass[middle + j];

	int i = 0, j = 0;
	for (int k = start; k <= end; ++k)
	{
		if (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				mass[k] = L[i];
				i++;
			}
			else
			{
				mass[k] = R[j];
				insert += (n1 - i);
				j++;
			}
		}
		else if (i<n1) {
			mass[k] = L[i];
			i++;
		}
		else {
			mass[k] = R[j];
			j++;
		}

	}

	delete[] L;
	delete[] R;
}
//----------------------------------------------------------------------------------




