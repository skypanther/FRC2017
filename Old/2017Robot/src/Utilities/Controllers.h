#ifndef SRC_UTILITIES_CONTROLLERS_H_
#define SRC_UTILITIES_CONTROLLERS_H_

#include "WPILib.h"
#include "CANTalon.h"
#include "AHRS.h"

enum ShotSelection {hopper, gearFar, gearCenter, loadingZone};

class Controllers {
private:
	Joystick *driveJoystick;
	Joystick *armJoystick;
	Joystick *buttonBox1;
	Joystick *buttonBox2;

	CANTalon *leftDrive1;
	CANTalon *leftDrive2;
	CANTalon *leftDrive3;
	CANTalon *rightDrive1;
	CANTalon *rightDrive2;
	CANTalon *rightDrive3;
	DoubleSolenoid *shiftSol;

	CANTalon *gearActuator;
	Solenoid *gearClamp;

	CANTalon *intakeMotor;
	CANTalon *intakeMotor2;
	DoubleSolenoid *intakeSol;
	DoubleSolenoid *releaseSol;

	CANTalon *turretMotor;

	CANTalon *shooterWheel;
	CANTalon *hoodMotor;

	CANTalon *carouselMotor;
	CANTalon *feederMotor;

	AHRS *navX;

	ShotSelection selectedShot;

	int driveSubsystemIndex;
	int gearSubsystemIndex;
	int intakeSubsystemIndex;
	int visionSubsystemIndex;
	int turretSubsystemIndex;
	int shooterSubsystemIndex;
	int feederSubsystemIndex;

public:
	Controllers();
	~Controllers();

	Joystick* getDriveJoystick();
	Joystick* getArmJoystick();
	Joystick* getButtonBox1();
	Joystick* getButtonBox2();

	CANTalon* getLeftDrive1();
	CANTalon* getLeftDrive2();
	CANTalon* getLeftDrive3();
	CANTalon* getRightDrive1();
	CANTalon* getRightDrive2();
	CANTalon* getRightDrive3();
	DoubleSolenoid* getShiftSol();

	CANTalon* getGearActuator();
	Solenoid* getGearClamp();

	CANTalon* getIntakeMotor();
	CANTalon* getIntakeMotor2();
	DoubleSolenoid* getIntakeSol();
	DoubleSolenoid* getReleaseSol();

	CANTalon* getTurretMotor();

	CANTalon* getShooterWheel();
	CANTalon* getHoodMotor();

	CANTalon* getCarouselMotor();
	CANTalon* getFeederMotor();

	AHRS*	getNavX();

	int getDriveSubsystemIndex();
	int getGearSubsystemIndex();
	int getIntakeSubsystemIndex();
	int getVisionSubsystemIndex();
	int getTurretSubsystemIndex();
	int getShooterSubsystemIndex();
	int getFeederSubsystemIndex();
	ShotSelection getSelectedShot();

	void setDriveSubsystemIndex(int i);
	void setGearSubsystemIndex(int i);
	void setIntakeSubsystemIndex(int i);
	void setVisionSubsystemIndex(int i);
	void setTurretSubsystemIndex(int i);
	void setShooterSubsystemIndex(int i);
	void setFeederSubsystemIndex(int i);
	void setSelectedShot(ShotSelection selectedShot);
};

#endif /* SRC_UTILITIES_CONTROLLERS_H_ */
