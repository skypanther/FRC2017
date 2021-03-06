/*
 * AutoHopperBlue.h
 *
 *  Created on: Mar 14, 2017
 *      Author: roberthilton
 */

#ifndef SRC_AUTONOMOUS_BLUE_AUTOHOPPERBLUE_H_
#define SRC_AUTONOMOUS_BLUE_AUTOHOPPERBLUE_H_

#include <Utilities/CustomAction.h>
#include <Actions/VisionTurretControlAction.h>
#include <Subsystems/DriveBaseSubsystem.h>
#include <Subsystems/ShooterSubsystem.h>
#include <Subsystems/TurretSubsystem.h>
#include <Subsystems/BallFeederSubsystem.h>
#include <Subsystems/IntakeSubsystem.h>

#define AUTO_HOPPER_BLUE_TARGETING_TIMEOUT_MS 500

class AutoHopperBlue: public CustomAction {
public:
	AutoHopperBlue(Controllers *robotControllers, vector<CustomSubsystem*> *subsystemVector)
	:CustomAction(robotControllers, subsystemVector){
		ds = &DriverStation::GetInstance();
		driveBaseSubsystem = dynamic_cast<DriveBaseSubsystem*>(subsystemVector->at(robotControllers->getDriveSubsystemIndex()));
		shooterSubsystem = dynamic_cast<ShooterSubsystem*>(subsystemVector->at(robotControllers->getShooterSubsystemIndex()));
		turretSubsystem = dynamic_cast<TurretSubsystem*>(subsystemVector->at(robotControllers->getTurretSubsystemIndex()));
		ballFeederSubsystem = dynamic_cast<BallFeederSubsystem*>(subsystemVector->at(robotControllers->getFeederSubsystemIndex()));
		intakeSubsystem = dynamic_cast<IntakeSubsystem*>(subsystemVector->at(robotControllers->getIntakeSubsystemIndex()));
		visionTurretControlAction = new VisionTurretControlAction(robotControllers, subsystemVector);
	}
	~AutoHopperBlue() {}

	void start() override {
		this_thread::sleep_for(chrono::milliseconds(250));
		driveBaseSubsystem->setGear(false);
		intakeSubsystem->setIntakePosition(true);
		turretSubsystem->selectShot(ShotSelection::hopper);
		//driveBaseSubsystem->changeControlMode(CANSpeedController::kMotionProfile);
		//driveBaseSubsystem->processMotionProfile(getVectorFromLeftProfile(), getVectorFromRightProfile());
		shooterSubsystem->selectShot(ShotSelection::hopper);

		double avgPosTmp = 0;


		driveBaseSubsystem->setDriveSpeed(1, -1);

		do {
			avgPosTmp = driveBaseSubsystem->getAveragePosition();
			this_thread::sleep_for(chrono::milliseconds(10));
		} while (avgPosTmp < 34 && ds->IsAutonomous());

		driveBaseSubsystem->setDriveSpeed(-0.75, -0.75);

		avgPosTmp = 0;

		do {
			avgPosTmp = abs(robotControllers->getNavX()->GetYaw());
			this_thread::sleep_for(chrono::milliseconds(10));
		} while (avgPosTmp < TURN_ANGLE_ONE_RED && ds->IsAutonomous());
		driveBaseSubsystem->setDriveSpeed(0, 0);
		this_thread::sleep_for(chrono::milliseconds(100));
		driveBaseSubsystem->setPosition(0);
		this_thread::sleep_for(chrono::milliseconds(30));

		driveBaseSubsystem->setDriveSpeed(1, -1);

		avgPosTmp = 0;

		do {
			avgPosTmp = driveBaseSubsystem->getAveragePosition();
			cout << "average pos: " << avgPosTmp << endl;
			this_thread::sleep_for(chrono::milliseconds(10));
		} while (avgPosTmp < 14 && ds->IsAutonomous());

		driveBaseSubsystem->setDriveSpeed(0, 0);
		visionTurretControlAction->start();
		timeoutStart = Timer::GetFPGATimestamp();
		while (!visionTurretControlAction->isOnTarget() && timeoutElapsedTimeMS < AUTO_HOPPER_BLUE_TARGETING_TIMEOUT_MS) {
			this_thread::sleep_for(chrono::milliseconds(25));
			timeoutEnd = Timer::GetFPGATimestamp();
			timeoutElapsedTimeMS = (int)((timeoutEnd - timeoutStart) * 1000);
		}

		//delete visionTurretControlAction;
		//visionTurretControlAction = nullptr;

		ballFeederSubsystem->setFeederOn();

		this_thread::sleep_for(chrono::milliseconds(1000));

		timeoutStart = Timer::GetFPGATimestamp();
		while (ds->IsAutonomous()&&ds->IsEnabled()) {

			timeoutEnd = Timer::GetFPGATimestamp();
			if ((timeoutEnd - timeoutStart) > 2.5) {
				timeoutStart = Timer::GetFPGATimestamp();
				intakeSubsystem->setIntakePosition(false);
				this_thread::sleep_for(chrono::milliseconds(100));
				intakeSubsystem->setIntakeSpeed(1);
				this_thread::sleep_for(chrono::milliseconds(250));
				intakeSubsystem->setIntakeSpeed(0);
				intakeSubsystem->setIntakePosition(true);
			}
		}
		intakeSubsystem->setIntakePosition(true);
		visionTurretControlAction->stop();
		//ballFeederSubsystem->setFeederOff();

	};

	void stop() override {

	};

protected:
	void run() override {};

private:
	DriverStation *ds;

	DriveBaseSubsystem *driveBaseSubsystem;
	ShooterSubsystem *shooterSubsystem;
	TurretSubsystem *turretSubsystem;
	BallFeederSubsystem *ballFeederSubsystem;
	IntakeSubsystem *intakeSubsystem;

	VisionTurretControlAction *visionTurretControlAction;
};

#endif /* SRC_AUTONOMOUS_BLUE_AUTOHOPPERBLUE_H_ */
