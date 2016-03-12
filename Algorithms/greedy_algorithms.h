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
	// Принимает на вход вектор отрезков (pair<начало,конец>, на выход выдает множество точек минимального размера, 
	// для которого каждый из отрезков содержит хотя бы одну из точек)
	static std::vector <int> get_covering_set(std::vector <Segment> segments);

	// Принимает на вход вместимость рюкзака и предметы, на выходе максимальная стоимость (приедметы можно делить)
	static double get_max_knapsack_value(int capacity, std::vector <Item> items);

private:
	static bool intersection(Segment & first, Segment & second);

};
//----------------------------------------------------------------------------------
#endif	// __GREEDY_ALGORITHMS__
