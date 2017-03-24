/*
 * ShooterCam.h
 *
 *  Created on: Feb 2, 2017
 *      Author: eeuser
 */

#include <CameraServer.h>
#include "WPILib.h"
#include "Commands/Subsystem.h"

#ifndef SRC_SUBSYSTEMS_SHOOTERCAM_H_
#define SRC_SUBSYSTEMS_SHOOTERCAM_H_

class ShooterCam {
public:
	ShooterCam();
	void openCamera();
	virtual ~ShooterCam();

};

#endif /* SRC_SUBSYSTEMS_SHOOTERCAM_H_ */
