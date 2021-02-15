/*
 * RandomGenerator.h
 *
 *  Created on: Feb 15, 2021
 *      Author: lars
 */

#pragma once
#include "TimeVariant.h"
#include <functional>
#include <vector>
#include <random>
#include <chrono>

/**Random number generator.
 * Observes a clock and on each tick creates a new random number and performs the
 * registered actions.
 */
template<typename T,
typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr>	//Allow only arithmetic types
class RandomGenerator : TimeVariant{
public:
	/**Class constructor
	 * @param clock clock source
	 * @param min Random number lower bound
	 * @param max Random number upper bound
	 */
	RandomGenerator(IClockSource *clock, T min, T max) : TimeVariant(clock){
		_min = min;
		_max = max;
	}
	virtual ~RandomGenerator(){};
	/** Register a new action (lambda)
	 *
	 */
	void registerAction(std::function<void(T)> action){
		_actions.push_back(action);
	}
	/** Tick from clock
	 * Generate a random number and perform all actions with the new number
	 */
	void tick() override{
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::uniform_real_distribution<double> distribution(static_cast<double>(_min),static_cast<double>(_max));
		_value = static_cast<T>(distribution(generator));
		for(auto &action : _actions){
			action(_value);
		}

	}
private:
	std::vector<std::function<void(T)>> _actions;
	T _min;
	T _max;
	T _value;
};



