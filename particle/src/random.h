#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <random>

class Random {
public:
	static void Init()
	{
		Internal_getEngine().seed(std::random_device()());
	}

	static float Float()
	{
		static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
		return (float)s_Distribution(Internal_getEngine()) / (float)std::numeric_limits<uint_fast32_t>::max();
	}

private:
	static std::mt19937& Internal_getEngine()
	{
		static std::mt19937 s_RandomEngine;
		return s_RandomEngine;
	}
};

#endif