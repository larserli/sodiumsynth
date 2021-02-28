/*
 * MeanTrigger.h
 *
 *  Created on: Feb 28, 2021
 *      Author: lars
 */

#pragma once
#include "IAudioModule.h"
#include "ClockObserver.h"
#include "IClockSource.h"
#include <functional>
#include <vector>

/** Trigger based on rolling average
 * 
 * This module maintains a rolling average over a window. 
 * If the mean value exceeds a treshold, an action is raised, if defined. 
 * Another action is raised when the mean drops below the threshold. 
 * It is possible to define a hysteresis to avoid repeated actions when the level is close
 * to the treshold. 
 */
class MeanTrigger : public ClockObserver
{
public:
	/** Class constructor
	 * @param clock Master clock
	 */
	MeanTrigger(IClockSource *clock);
	~MeanTrigger();
	/** Is the trigger active?
	 * @returns true if the trigger is active
	 */
	bool isActive();
	/** Update function 
	 */
	void tick() override;
	/** Set treshold value 
	 * @param level treshold 
	 * @param hysteresis hysteresis
	 */
	void setLevel(float level, float hysteresis);
	/** Assign input (source)
	 * @param source 
	 */
	void setSource(IAudioModule *source);
	/** Assign an action to be raised when the level rises above the treshold. 
	 * @param action function object
	 */
	void setActionOn(std::function<void(void)> action);
	/** Assign an action to be raised when the level drops below the treshold. 
	 * @param action function object 
	 */
	void setActionOff(std::function<void(void)> action);
private:
	//Master clock
	IClockSource *m_clock;

	IAudioModule *m_source;
	//Rolling average
	double m_mean;
	//Buffer
	std::vector<float> m_samples;

	size_t m_current_sample;

	size_t m_bufferSize;

	bool m_active;
	//Trigger level
	float m_trigger;
	//Trigger hysteresis
	float m_hyst;
	//Called when the average value exceeds the trigger value + hysteresis
	std::function<void(void)> m_triggerOn;
	//Called when the average value exceeds the trigger value - hysteresis
	std::function<void(void)> m_triggerOff;
};


