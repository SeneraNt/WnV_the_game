#include "Random.h"
//Modyfied from here: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c

static std::mt19937 sEngine;

void Random::Init()
{
	std::random_device dev;
	sEngine = std::mt19937(dev());
}

int Random::NextInt(int from, int to)
{
	std::uniform_int_distribution<std::mt19937::result_type> dist(from, to);
	return dist(sEngine);
}
