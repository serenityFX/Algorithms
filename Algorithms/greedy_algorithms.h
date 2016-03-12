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
class greedy_algorithms
{
public:
	// Принимает на вход вектор отрезков (pair<начало,конец>, на выход выдает множество точек минимального размера, 
	// для которого каждый из отрезков содержит хотя бы ожну из точек)
	static std::vector <int> get_covering_set(std::vector <Segment> segments);

private:
	static bool intersection(Segment & first, Segment & second);

};
//----------------------------------------------------------------------------------
#endif	// __GREEDY_ALGORITHMS__
