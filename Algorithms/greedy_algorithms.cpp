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
//----------------------------------------------------------------------------------
std::unordered_map<char, std::string> greedy_algorithms::HuffmanEncode(const std::string &input)
{
	std::unordered_map<char, int> inpFreq;
	for (auto in : input) inpFreq[in]++;

	std::vector<Freq> freq;
	for (auto f : inpFreq) freq.push_back({std::string(1,f.first),f.second});

	if (freq.size() == 1)
	{
		std::unordered_map<char, std::string> result;
		result[freq[0].symbol[0]] = "0";
		return std::move(result);
	}

	std::priority_queue<Freq> q(freq.begin(),freq.end());
	std::unordered_map<char, std::string> result;

	while (q.size() >= 2)
	{
		auto first = q.top();
		q.pop();
		auto second = q.top();
		q.pop();
	
		for (auto c : first.symbol) result[c] = "0" + result[c];
		for (auto c : second.symbol) result[c] = "1" + result[c];
	
		q.push({first.symbol + second.symbol, first.frequency + second.frequency});
	}

	return result;
}
//----------------------------------------------------------------------------------
std::string greedy_algorithms::HuffmanDecode(std::unordered_map<std::string,char> input, std::string inpText)
{
	std::string result;

	auto i = inpText.begin();
	std::string value;
	while (i != inpText.end())
	{
		value += *i;
		auto j = input.find(value);
		if (j != input.end())
		{
			result += input[value];
			value.clear();
		}
		++i;
	}

	return result;
}
//----------------------------------------------------------------------------------