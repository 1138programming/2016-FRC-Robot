/*
 * Pneumatics.h
 *
 *  Created on: Feb 2, 2017
 *      Author: eeuser
 */

#ifndef SRC_SUBSYSTEMS_PNEUMATICS_H_
#define SRC_SUBSYSTEMS_PNEUMATICS_H_
#include "WPILib.h"
#include "Compressor.h"

class Pneumatics : public Subsystem {
private:
	Compressor* pCompressor;
	AnalogInput* pressureSensor;

public:
	Pneumatics();
//	virtual ~Pneumatics();

	void InitDefaultCommand();
};

#endif /* SRC_SUBSYSTEMS_PNEUMATICS_H_ */
