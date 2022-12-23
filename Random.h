#include <random>

class Random{
public:
	static void Init();
	///returns a random integer in range [from, to] 
	static int NextInt(int from, int to);
};