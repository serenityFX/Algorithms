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