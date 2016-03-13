#ifndef __GREEDY_ALGORITHMS__
#define __GREEDY_ALGORITHMS__
//----------------------------------------------------------------------------------
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <string>


//----------------------------------------------------------------------------------
using Segment = std::pair<int, int>;
//----------------------------------------------------------------------------------
struct Item final {
	int weight;
	int value;
	Item(int V, int W):weight(W),value(V){}
};
//----------------------------------------------------------------------------------
struct Freq
{
	std::string symbol;
	int frequency;

	bool operator<(const Freq &other) const
	{
		return std::tie(frequency, symbol) > std::tie(other.frequency, other.symbol);
	}
};
//----------------------------------------------------------------------------------
class greedy_algorithms
{
public:
	//Accepts a vector of segments(pair<start, end>) on the output produces a set of points the minimum size 
	// for which each segment contains at least one of the points
	static std::vector <int> get_covering_set(std::vector <Segment> segments);

	// Takes as input the capacity of the backpack and items on exit maximum value(items can be split)
	static double get_max_knapsack_value(int capacity, std::vector <Item> items);

	static std::unordered_map<char, std::string>	HuffmanEncode(const std::string &input);
	static std::string								HuffmanDecode(std::unordered_map<std::string,char> input, std::string inpText);

private:
	static bool intersection(Segment & first, Segment & second);

};
//----------------------------------------------------------------------------------
#endif	// __GREEDY_ALGORITHMS__
