#ifndef PROXYRANDOM_H
#define PROXYRANDOM_H

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

class ProxyRandom
{
	//Pseudo random number generator
	boost::mt19937 _prng;

	//Singleton pointer

	static ProxyRandom * _singleInstance;


private:

	//default constructor, uses a time-dependent seed
	ProxyRandom();



	//Constructor with explicit seed
	//@param seed the seed to initialize the prng
	ProxyRandom(unsigned int seed);


	//Singleton get
	static ProxyRandom *get();

	int getUniformlyDistributedRandomBetween(unsigned int min, unsigned int max);
};





#endif
