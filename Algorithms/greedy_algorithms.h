#ifndef __GREEDY_ALGORITHMS__
#define __GREEDY_ALGORITHMS__
//----------------------------------------------------------------------------------
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

//----------------------------------------------------------------------------------
using Segment = std::pair<int, int>;
//----------------------------------------------------------------------------------
struct Item final {
	int weight;
	int value;
	Item(int V, int W):weight(W),value(V){}
};
//----------------------------------------------------------------------------------
class greedy_algorithms
{
public:
	// ��������� �� ���� ������ �������� (pair<������,�����>, �� ����� ������ ��������� ����� ������������ �������, 
	// ��� �������� ������ �� �������� �������� ���� �� ���� �� �����)
	static std::vector <int> get_covering_set(std::vector <Segment> segments);

	// ��������� �� ���� ����������� ������� � ��������, �� ������ ������������ ��������� (��������� ����� ������)
	static double get_max_knapsack_value(int capacity, std::vector <Item> items);

private:
	static bool intersection(Segment & first, Segment & second);

};
//----------------------------------------------------------------------------------
#endif	// __GREEDY_ALGORITHMS__
