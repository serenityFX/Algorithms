#include "greedy_algorithms.h"
//----------------------------------------------------------------------------------
std::vector <int> greedy_algorithms::get_covering_set(std::vector <Segment> segments)
{
	std::sort(segments.begin(), segments.end(), [](const Segment &left, const Segment &right){return left.first < right.first; });

	
	std::vector<int> points;
	 
	while (segments.size() > 1)
	{
		auto start = segments.begin();
		auto stop = segments.begin() + 1;
		std::set<int> group;
		group.insert(start->first);		
		while (intersection(*start, *stop))
		{
			group.insert(stop->first);
			start->second = std::min(start->second, stop->second);
			stop++;			
			if (stop == segments.end()) break;
		}
		auto p = group.end();
		points.push_back(*(--p));

		segments.erase(start, stop);
	}

	if (!segments.empty()) points.push_back(segments[0].first);
	return std::move(points);
}
//----------------------------------------------------------------------------------
bool greedy_algorithms::intersection(Segment & first, Segment & second)
{
	if (second.first >= first.first && second.first <= first.second ||
		second.second >= first.first && second.second <= first.second)
		return true;
	return false;
}
//----------------------------------------------------------------------------------
double greedy_algorithms::get_max_knapsack_value(int capacity, std::vector <Item> items) 
{
	double value = 0.0;

	std::sort(items.begin(), items.end(), [](const Item &left, const Item &right)
	{
		return	(static_cast<double>(left.value) / static_cast<double>(left.weight)) >
				(static_cast<double>(right.value) / static_cast<double>(right.weight));
	} );


	// take items while there is empty space in knapsack
	for (auto &item : items) {
		if (capacity > item.weight) {
			// can take full item and continue
			capacity -= item.weight;
			value += item.value;
		}
		else {
			value += item.value * (static_cast <double>(capacity) / item.weight);
			break;
		}
	}

	return value;
}