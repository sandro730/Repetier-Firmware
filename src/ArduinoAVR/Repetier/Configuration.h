/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/**************** READ FIRST ************************

   This configuration file was created with the configuration tool. For that
   reason, it does not contain the same informations as the original Configuration.h file.
   It misses the comments and unused parts. Open this file file in the config tool
   to see and change the data. You can also upload it to newer/older versions. The system
   will silently add new options, so compilation continues to work.

   This file is optimized for version 1.0.3dev
   generator: http://www.repetier.com/firmware/dev/

   If you are in doubt which named functions use which pins on your board, please check the
   pins.h for the used name->pin assignments and your board documentation to verify it is
   as you expect.

*/

<<<<<<< HEAD

// BASIC SETTINGS: select your board type, thermistor type, axis scaling, and endstop configuration

/** Number of extruders. Maximum 6 extruders. */
#define NUM_EXTRUDER 1

/** Set to 1 if all extruder motors go to 1 nozzle that mixes your colors. */
#define MIXING_EXTRUDER 0

//// The following define selects which electronics board you have. Please choose the one that matches your setup
// Gen3 PLUS for RepRap Motherboard V1.2 = 21
// MEGA/RAMPS up to 1.2       = 3
// RAMPS 1.3/RAMPS 1.4        = 33
// Azteeg X3                  = 34
// Azteeg X3 Pro              = 35
// MPX3  (mainly RAMPS compatible) = 38
// Ultimaker Shield 1.5.7     = 37
// Gen6                       = 5
// Gen6 deluxe                = 51
// Sanguinololu up to 1.1     = 6
// Sanguinololu 1.2 and above = 62
// 3Drag/Velleman K8200       = 66 (experimental)
// Open Motion Controller     = 91
// Melzi board                = 63  // Define REPRAPPRO_HUXLEY if you have one for correct HEATER_1_PIN assignment!
// Azteeg X1                  = 65
// 3Drag/Velleman K8200 (experimental) = 66
// Gen7 1.1 till 1.3.x        = 7
// Gen7 1.4.1 and later       = 71
// Sethi 3D_1                 = 72
// Teensylu (at90usb)         = 8 // requires Teensyduino
// Printrboard (at90usb)      = 9 // requires Teensyduino
// Printrboard Ref. F or newer= 92 // requires Teensyduino
// Foltyn 3D Master           = 12
// MegaTronics 1.0            = 70
// Megatronics 2.0            = 701
// Megatronics 3.0            = 703 // Thermistors predefined not thermocouples
// Minitronics 1.0            = 702
// RUMBA                      = 80  // Get it from reprapdiscount
// FELIXprinters              = 101
// Rambo                      = 301
// PiBot for Repetier V1.0-1.3= 314
// PiBot for Repetier V1.4    = 315
// PiBot Controller V2.0      = 316
// Sanguish Beta              = 501
// Unique One rev. A          = 88
// SAV MK1                    = 89
// MJRice Pica Rev B          = 183
// MJRice Pica Rev C          = 184
// Zonestar ZRIB 2.1          = 39
// User layout defined in userpins.h = 999

// Configuration.h for my printer 3D.
// Modify only file Configuration.h for to branch MyMaster
// To maintain a configuration that is aligned with repetier/Repetier-Firmware

#define MOTHERBOARD 33

=======
#define NUM_EXTRUDER 4
#define MOTHERBOARD 35
>>>>>>> refs/heads/master
#include "pins.h"

// ################## EDIT THESE SETTINGS MANUALLY ################

// ################ END MANUAL SETTINGS ##########################

#define HOST_RESCUE 1
#undef FAN_BOARD_PIN
#define FAN_BOARD_PIN ORIG_FAN_PIN
#define BOARD_FAN_SPEED 255
#define BOARD_FAN_MIN_SPEED 0
#define FAN_THERMO_PIN -1
#define FAN_THERMO_MIN_PWM 128
#define FAN_THERMO_MAX_PWM 255
#define FAN_THERMO_MIN_TEMP 45
#define FAN_THERMO_MAX_TEMP 60
#define FAN_THERMO_THERMISTOR_PIN -1
#define FAN_THERMO_THERMISTOR_TYPE 1

//#define EXTERNALSERIAL  use Arduino serial library instead of build in. Requires more ram, has only 63 byte input buffer.
// Uncomment the following line if you are using Arduino compatible firmware made for Arduino version earlier then 1.0
// If it is incompatible you will get compiler errors about write functions not being compatible!
//#define COMPAT_PRE1
#define BLUETOOTH_SERIAL  -1
#define BLUETOOTH_BAUD  115200
#define MIXING_EXTRUDER 0

<<<<<<< HEAD
/* Define the type of axis movements needed for your printer. The typical case
is a full cartesian system where x, y and z moves are handled by separate motors.

0 = full cartesian system, xyz have separate motors.
1 = z axis + xy H-gantry (x_motor = x+y, y_motor = x-y)
2 = z axis + xy H-gantry (x_motor = x+y, y_motor = y-x)
3 = Delta printers (Rostock, Kossel, RostockMax, Cerberus, etc)
4 = Tuga printer (Scott-Russell mechanism)
5 = Bipod system (not implemented)
8 = y axis + xz H-gantry (x_motor = x+z, z_motor = x-z)
9 = y axis + xz H-gantry (x_motor = x+z, z_motor = z-x)
Cases 1, 2, 8 and 9 cover all needed xy and xz H gantry systems. If you get results mirrored etc. you can swap motor connections for x and y.
If a motor turns in the wrong direction change INVERT_X_DIR or INVERT_Y_DIR.
*/
// SB #define DRIVE_SYSTEM 0
#define DRIVE_SYSTEM 3
/*
  Normal core xy implementation needs 2 virtual steps for a motor step to guarantee
  that every tiny move gets maximum one step regardless of direction. This can cost
  some speed, so alternatively you can activate the FAST_COREXYZ by uncommenting
  the define. This solves the core movements as nonlinear movements like done for
  deltas but without the complicated transformations. Since transformations are still
  linear you can reduce delta computations per second to 10 and also use 10 
  subsegments instead of 20 to reduce memory usage.
*/
//#define FAST_COREXYZ

/* You can write some GCODE to be executed on startup. Use this e.g. to set some 
pins. Separate multiple GCODEs with \n
*/
//#define STARTUP_GCODE ""

// ##########################################################################################
// ##                               Calibration                                            ##
// ##########################################################################################

/** Drive settings for the Delta printers
*/
#if DRIVE_SYSTEM == DELTA
    // ***************************************************
    // *** These parameter are only for Delta printers ***
    // ***************************************************

/** \brief Delta drive type: 0 - belts and pulleys, 1 - filament drive */
#define DELTA_DRIVE_TYPE 0

#if DELTA_DRIVE_TYPE == 0
/** \brief Pitch in mm of drive belt. GT2 = 2mm */
#define BELT_PITCH 2
/** \brief Number of teeth on X, Y and Z tower pulleys */
// SB #define PULLEY_TEETH 20
// SB 2017/01/06 Corretto con 100.
#define PULLEY_TEETH 16
#define PULLEY_CIRCUMFERENCE (BELT_PITCH * PULLEY_TEETH)
#elif DELTA_DRIVE_TYPE == 1
/** \brief Filament pulley diameter in millimeters */
#define PULLEY_DIAMETER 10
#define PULLEY_CIRCUMFERENCE (PULLEY_DIAMETER * 3.1415927)
#endif

/** \brief Steps per rotation of stepper motor */
#define STEPS_PER_ROTATION 200

/** \brief Micro stepping rate of X, Y and Y tower stepper drivers */
#define MICRO_STEPS 16

// Calculations
#define AXIS_STEPS_PER_MM ((float)(MICRO_STEPS * STEPS_PER_ROTATION) / PULLEY_CIRCUMFERENCE)
// SB Provato con comparatore AXIS_STEPS_PER_MM 01.0095 o 101.0101
// SB 2017/01/06 Corretto con 100.
#define XAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM
#define YAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM
#define ZAXIS_STEPS_PER_MM AXIS_STEPS_PER_MM
#else
// *******************************************************
// *** These parameter are for all other printer types ***
// *******************************************************

/** Drive settings for printers with cartesian drive systems */
/** \brief Number of steps for a 1mm move in x direction.
For xy gantry use 2*belt moved!
Overridden if EEPROM activated. */
#define XAXIS_STEPS_PER_MM 98.425196
/** \brief Number of steps for a 1mm move in y direction.
For xy gantry use 2*belt moved!
Overridden if EEPROM activated.*/
#define YAXIS_STEPS_PER_MM 98.425196
/** \brief Number of steps for a 1mm move in z direction  Overridden if EEPROM activated.*/
#define ZAXIS_STEPS_PER_MM 2560
#endif

// ##########################################################################################
// ##                           Extruder configuration                                     ##
// ##########################################################################################

// You can use either PWM (pulse width modulation) or PDM (pulse density modulation) for
// extruders or coolers. PDM will give more signal changes per second, so on average it gives
// the cleaner signal. The only advantage of PWM is giving signals at a fixed rate and never more
// then PWM.
#define PDM_FOR_EXTRUDER 1
#define PDM_FOR_COOLER 1

// The firmware checks if the heater and sensor got decoupled, which is dangerous. Since it will never reach target
// temperature, the heater will stay on for every which can burn your printer or house.
// As an additional barrier to your smoke detectors (I hope you have one above your printer) we now
// do some more checks to detect if something got wrong.

// If the temp. is on hold target, it may not sway more then this degrees celsius, or we mark
// sensor as defect.
#define DECOUPLING_TEST_MAX_HOLD_VARIANCE 20
// Minimum temp. rise we expect after the set duration of full heating is over.
// Always keep a good safety margin to get no false positives. If your period is e.g. 10 seconds
// because at startup you already need 7 seconds until heater starts to rise temp. for sensor
// then you have 3 seconds of increased heating to reach 1°C.
#define DECOUPLING_TEST_MIN_TEMP_RISE 1
// Set to 1 if you want firmware to kill print on decouple
#define KILL_IF_SENSOR_DEFECT 0
// for each extruder, fan will stay on until extruder temperature is below this value
=======
#define DRIVE_SYSTEM 0
#define XAXIS_STEPS_PER_MM 72.72
#define YAXIS_STEPS_PER_MM 72.72
#define ZAXIS_STEPS_PER_MM 520
>>>>>>> refs/heads/master
#define EXTRUDER_FAN_COOL_TEMP 50
#define PDM_FOR_EXTRUDER 0
#define PDM_FOR_COOLER 0
#define DECOUPLING_TEST_MAX_HOLD_VARIANCE 20
#define DECOUPLING_TEST_MIN_TEMP_RISE 1
#define KILL_IF_SENSOR_DEFECT 1
#define RETRACT_ON_PAUSE 4
#define PAUSE_START_COMMANDS ""
#define PAUSE_END_COMMANDS ""
#define SHARED_EXTRUDER_HEATER 0
#define EXT0_X_OFFSET 0
#define EXT0_Y_OFFSET 0
#define EXT0_Z_OFFSET 0
<<<<<<< HEAD
// for skeinforge 40 and later, steps to pull the plastic 1 mm inside the extruder, not out.  Overridden if EEPROM activated.
// SB #define EXT0_STEPS_PER_MM 413 //385
#define EXT0_STEPS_PER_MM 776
// What type of sensor is used?
// 0 is no thermistor/temperature control
// 1 is 100k thermistor (Epcos B57560G0107F000 - RepRap-Fab.org and many other)
// 2 is 200k thermistor
// 3 is mendel-parts thermistor (EPCOS G550)
// 4 is 10k thermistor
// 8 is ATC Semitec 104GT-2
// 12 is 100k RS thermistor 198-961
// 13 is PT100 for E3D/Ultimaker
// 14 is 100K NTC 3950
// 15 DYZE DESIGN 500°C Thermistor
// 16 is B3 innovations 500°C sensor
// 5 is userdefined thermistor table 0
// 6 is userdefined thermistor table 1
// 7 is userdefined thermistor table 2
// 50 is userdefined thermistor table 0 for PTC thermistors
// 51 is userdefined thermistor table 0 for PTC thermistors
// 52 is userdefined thermistor table 0 for PTC thermistors
// 60 is AD8494, AD8495, AD8496 or AD8497 (5mV/degC and 1/4 the price of AD595 but only MSOT_08 package)
// 61 is AD8494, AD8495, AD8496 or AD8497 (5mV/degC and 1.25 Vref offset like adafruit breakout)
// 97 Generic thermistor table 1
// 98 Generic thermistor table 2
// 99 Generic thermistor table 3
// 100 is AD595
// 101 is MAX6675
// 102 is MAX31855
// SB #define EXT0_TEMPSENSOR_TYPE 1
#define EXT0_TEMPSENSOR_TYPE 14
// Analog input pin for reading temperatures or pin enabling SS for MAX6675
=======
#define EXT0_STEPS_PER_MM 255
#define EXT0_TEMPSENSOR_TYPE 5
>>>>>>> refs/heads/master
#define EXT0_TEMPSENSOR_PIN TEMP_0_PIN
#define EXT0_HEATER_PIN HEATER_0_PIN
<<<<<<< HEAD
#define EXT0_STEP_PIN E0_STEP_PIN
#define EXT0_DIR_PIN E0_DIR_PIN
// set to false/true for normal / inverse direction
// SB  #define EXT0_INVERSE true
#define EXT0_INVERSE false
#define EXT0_ENABLE_PIN E0_ENABLE_PIN
// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define EXT0_ENABLE_ON 0
/* Set to 1 to mirror motor. Pins for mirrored motor are below */
=======
#define EXT0_STEP_PIN ORIG_E0_STEP_PIN
#define EXT0_DIR_PIN ORIG_E0_DIR_PIN
#define EXT0_INVERSE 1
#define EXT0_ENABLE_PIN ORIG_E0_ENABLE_PIN
#define EXT0_ENABLE_ON 1
>>>>>>> refs/heads/master
#define EXT0_MIRROR_STEPPER 0
<<<<<<< HEAD
#define EXT0_STEP2_PIN E0_STEP_PIN
#define EXT0_DIR2_PIN E0_DIR_PIN
#define EXT0_INVERSE2 false
#define EXT0_ENABLE2_PIN E0_ENABLE_PIN
// The following speed settings are for skeinforge 40+ where e is the
// length of filament pulled inside the heater. For repsnap or older
// skeinforge use higher values.
//  Overridden if EEPROM activated.
// SB #define EXT0_MAX_FEEDRATE 30
#define EXT0_MAX_FEEDRATE 80
// Feedrate from halted extruder in mm/s
//  Overridden if EEPROM activated.
#define EXT0_MAX_START_FEEDRATE 10
// Acceleration in mm/s^2
//  Overridden if EEPROM activated.
// SB #define EXT0_MAX_ACCELERATION 4000
#define EXT0_MAX_ACCELERATION 1000
/** Type of heat manager for this extruder.
- 0 = Simply switch on/off if temperature is reached. Works always.
- 1 = PID Temperature control. Is better but needs good PID values. Defaults are a good start for most extruder.
- 3 = Dead-time control. PID_P becomes dead-time in seconds.
 Overridden if EEPROM activated.
*/
=======
#define EXT0_STEP2_PIN ORIG_E0_STEP_PIN
#define EXT0_DIR2_PIN ORIG_E0_DIR_PIN
#define EXT0_INVERSE2 0
#define EXT0_ENABLE2_PIN ORIG_E0_ENABLE_PIN
#define EXT0_MAX_FEEDRATE 50
#define EXT0_MAX_START_FEEDRATE 20
#define EXT0_MAX_ACCELERATION 5000
>>>>>>> refs/heads/master
#define EXT0_HEAT_MANAGER 1
#define EXT0_PREHEAT_TEMP 190
<<<<<<< HEAD
// SB // =========================== Configuration for second extruder ========================
// SB #define EXT1_X_OFFSET 0
// SB #define EXT1_Y_OFFSET 0
// SB #define EXT1_Z_OFFSET 0
// SB // for skeinforge 40 and later, steps to pull the plastic 1 mm inside the extruder, not out.  Overridden if EEPROM activated.
// SB #define EXT1_STEPS_PER_MM 373
// SB // What type of sensor is used?
// SB // 0 is no thermistor/temperature control
// SB // 1 is 100k thermistor (Epcos B57560G0107F000 - RepRap-Fab.org and many other)
// SB // 2 is 200k thermistor
// SB // 3 is mendel-parts thermistor (EPCOS G550)
// SB // 4 is 10k thermistor
// SB // 5 is userdefined thermistor table 0
// SB // 6 is userdefined thermistor table 1
// SB // 7 is userdefined thermistor table 2
// SB // 8 is ATC Semitec 104GT-2
// SB // 50 is userdefined thermistor table 0 for PTC thermistors
// SB // 51 is userdefined thermistor table 0 for PTC thermistors
// SB // 52 is userdefined thermistor table 0 for PTC thermistors
// SB // 60 is AD8494, AD8495, AD8496 or AD8497 (5mV/degC and 1/4 the price of AD595 but only MSOT_08 package)
// SB // 61 is AD8494, AD8495, AD8496 or AD8497 (5mV/degC and 1.25 Vref offset like adafruit breakout)
// SB // 97 Generic thermistor table 1
// SB // 98 Generic thermistor table 2
// SB // 99 Generic thermistor table 3
// SB // 100 is AD595
// SB // 101 is MAX6675
// SB #define EXT1_TEMPSENSOR_TYPE 3
// SB // Analog input pin for reading temperatures or pin enabling SS for MAX6675
// SB #define EXT1_TEMPSENSOR_PIN TEMP_2_PIN
// SB // Which pin enables the heater
// SB #define EXT1_HEATER_PIN HEATER_2_PIN
// SB #define EXT1_STEP_PIN E1_STEP_PIN
// SB #define EXT1_DIR_PIN E1_DIR_PIN
// SB // set to 0/1 for normal / inverse direction
// SB #define EXT1_INVERSE false
// SB #define EXT1_ENABLE_PIN E1_ENABLE_PIN
// SB // For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
// SB #define EXT1_ENABLE_ON false
// SB /* Set to 1 to mirror motor. Pins for mirrored motor are below */
// SB #define EXT1_MIRROR_STEPPER 0
// SB #define EXT1_STEP2_PIN E0_STEP_PIN
// SB #define EXT1_DIR2_PIN E0_DIR_PIN
// SB #define EXT1_INVERSE2 false
// SB #define EXT1_ENABLE2_PIN E0_ENABLE_PIN
// SB // The following speed settings are for skeinforge 40+ where e is the
// SB // length of filament pulled inside the heater. For repsnap or older
// SB // skeinforge use heigher values.
// SB //  Overridden if EEPROM activated.
// SB #define EXT1_MAX_FEEDRATE 25
// SB // Feedrate from halted extruder in mm/s
// SB //  Overridden if EEPROM activated.
// SB #define EXT1_MAX_START_FEEDRATE 12
// SB // Acceleration in mm/s^2
// SB //  Overridden if EEPROM activated.
// SB #define EXT1_MAX_ACCELERATION 10000
// SB /** Type of heat manager for this extruder.
// SB - 0 = Simply switch on/off if temperature is reached. Works always.
// SB - 1 = PID Temperature control. Is better but needs good PID values. Defaults are a good start for most extruder.
// SB  Overridden if EEPROM activated.
// SB */
// SB #define EXT1_HEAT_MANAGER 1
// SB /** Wait x seconds, after reaching target temperature. Only used for M109.  Overridden if EEPROM activated. */
// SB #define EXT1_WATCHPERIOD 1
// SB 
// SB /** \brief The maximum value, I-gain can contribute to the output.
// SB 
// SB A good value is slightly higher then the output needed for your temperature.
// SB Values for starts:
// SB 130 => PLA for temperatures from 170-180 deg C
// SB 180 => ABS for temperatures around 240 deg C
// SB 
// SB The precise values may differ for different nozzle/resistor combination.
// SB  Overridden if EEPROM activated.
// SB */
// SB #define EXT1_PID_INTEGRAL_DRIVE_MAX 130
// SB /** \brief lower value for integral part
// SB 
// SB The I state should converge to the exact heater output needed for the target temperature.
// SB To prevent a long deviation from the target zone, this value limits the lower value.
// SB A good start is 30 lower then the optimal value. You need to leave room for cooling.
// SB  Overridden if EEPROM activated.
// SB */
// SB #define EXT1_PID_INTEGRAL_DRIVE_MIN 60
// SB /** P-gain.  Overridden if EEPROM activated. */
// SB #define EXT1_PID_PGAIN_OR_DEAD_TIME   24
// SB /** I-gain.  Overridden if EEPROM activated.
// SB */
// SB #define EXT1_PID_I   0.88
// SB /** D-gain.  Overridden if EEPROM activated.*/
// SB #define EXT1_PID_D 200
// SB // maximum time the heater is can be switched on. Max = 255.  Overridden if EEPROM activated.
// SB #define EXT1_PID_MAX 255
// SB /** \brief Faktor for the advance algorithm. 0 disables the algorithm.  Overridden if EEPROM activated.
// SB K is the factor for the quadratic term, which is normally disabled in newer versions. If you want to use
// SB the quadratic factor make sure ENABLE_QUADRATIC_ADVANCE is defined.
// SB L is the linear factor and seems to be working better then the quadratic dependency.
// SB */
// SB #define EXT1_ADVANCE_K 0.0f
// SB #define EXT1_ADVANCE_L 0.0f
// SB /* Motor steps to remove backlash for advance algorithm. These are the steps
// SB needed to move the motor cog in reverse direction until it hits the driving
// SB cog. Direct drive extruder need 0. */
// SB #define EXT1_ADVANCE_BACKLASH_STEPS 0
// SB 
// SB #define EXT1_WAIT_RETRACT_TEMP 	150
// SB #define EXT1_WAIT_RETRACT_UNITS	0
// SB #define EXT1_SELECT_COMMANDS "M117 Extruder 2"
// SB #define EXT1_DESELECT_COMMANDS ""
// SB /** The extruder cooler is a fan to cool the extruder when it is heating. If you turn the etxruder on, the fan goes on. */
// SB #define EXT1_EXTRUDER_COOLER_PIN -1
// SB /** PWM speed for the cooler fan. 0=off 255=full speed */
// SB #define EXT1_EXTRUDER_COOLER_SPEED 255
// SB /** Time in ms between a heater action and test of success. Must be more then time between turning heater on and first temp. rise! 
// SB  * 0 will disable decoupling test */
// SB #define EXT1_DECOUPLE_TEST_PERIOD 18000
// SB /** Pin which toggles regularly during extrusion allowing jam control. -1 = disabled */
// SB #define EXT1_JAM_PIN -1
// SB /** Pull-up resistor for jam pin? */
// SB #define EXT1_JAM_PULLUP false
// SB #define EXT1_PREHEAT_TEMP 190
=======
#define EXT0_WATCHPERIOD 1
#define EXT0_PID_INTEGRAL_DRIVE_MAX 255
#define EXT0_PID_INTEGRAL_DRIVE_MIN 40
#define EXT0_PID_PGAIN_OR_DEAD_TIME 8.94
#define EXT0_PID_I 0.51
#define EXT0_PID_D 20
#define EXT0_PID_MAX 255
#define EXT0_ADVANCE_K 0
#define EXT0_ADVANCE_L 0
#define EXT0_ADVANCE_BACKLASH_STEPS 0
#define EXT0_WAIT_RETRACT_TEMP 150
#define EXT0_WAIT_RETRACT_UNITS 0
#define EXT0_SELECT_COMMANDS ""
#define EXT0_DESELECT_COMMANDS ""
#define EXT0_EXTRUDER_COOLER_PIN -1
#define EXT0_EXTRUDER_COOLER_SPEED 255
#define EXT0_DECOUPLE_TEST_PERIOD 30000
#define EXT0_JAM_PIN -1
#define EXT0_JAM_PULLUP 0
#define EXT1_X_OFFSET 0
#define EXT1_Y_OFFSET 0
#define EXT1_Z_OFFSET 0
#define EXT1_STEPS_PER_MM 257
#define EXT1_TEMPSENSOR_TYPE 5
#define EXT1_TEMPSENSOR_PIN TEMP_2_PIN
#define EXT1_HEATER_PIN HEATER_2_PIN
#define EXT1_STEP_PIN ORIG_E1_STEP_PIN
#define EXT1_DIR_PIN ORIG_E1_DIR_PIN
#define EXT1_INVERSE 1
#define EXT1_ENABLE_PIN ORIG_E1_ENABLE_PIN
#define EXT1_ENABLE_ON 1
#define EXT1_MIRROR_STEPPER 0
#define EXT1_STEP2_PIN ORIG_E1_STEP_PIN
#define EXT1_DIR2_PIN ORIG_E1_DIR_PIN
#define EXT1_INVERSE2 0
#define EXT1_ENABLE2_PIN ORIG_E1_ENABLE_PIN
#define EXT1_MAX_FEEDRATE 100
#define EXT1_MAX_START_FEEDRATE 40
#define EXT1_MAX_ACCELERATION 5000
#define EXT1_HEAT_MANAGER 1
#define EXT1_PREHEAT_TEMP 190
#define EXT1_WATCHPERIOD 1
#define EXT1_PID_INTEGRAL_DRIVE_MAX 255
#define EXT1_PID_INTEGRAL_DRIVE_MIN 40
#define EXT1_PID_PGAIN_OR_DEAD_TIME 8.94
#define EXT1_PID_I 0.51
#define EXT1_PID_D 20
#define EXT1_PID_MAX 255
#define EXT1_ADVANCE_K 0
#define EXT1_ADVANCE_L 0
#define EXT1_ADVANCE_BACKLASH_STEPS 0
#define EXT1_WAIT_RETRACT_TEMP 150
#define EXT1_WAIT_RETRACT_UNITS 0
#define EXT1_SELECT_COMMANDS ""
#define EXT1_DESELECT_COMMANDS ""
#define EXT1_EXTRUDER_COOLER_PIN -1
#define EXT1_EXTRUDER_COOLER_SPEED 255
#define EXT1_DECOUPLE_TEST_PERIOD 30000
#define EXT1_JAM_PIN -1
#define EXT1_JAM_PULLUP 0
#define EXT2_X_OFFSET 0
#define EXT2_Y_OFFSET 0
#define EXT2_Z_OFFSET 0
#define EXT2_STEPS_PER_MM 257
#define EXT2_TEMPSENSOR_TYPE 5
#define EXT2_TEMPSENSOR_PIN TEMP_3_PIN
#define EXT2_HEATER_PIN HEATER_3_PIN
#define EXT2_STEP_PIN ORIG_E2_STEP_PIN
#define EXT2_DIR_PIN ORIG_E2_DIR_PIN
#define EXT2_INVERSE 1
#define EXT2_ENABLE_PIN ORIG_E2_ENABLE_PIN
#define EXT2_ENABLE_ON 1
#define EXT2_MIRROR_STEPPER 0
#define EXT2_STEP2_PIN ORIG_E2_STEP_PIN
#define EXT2_DIR2_PIN ORIG_E2_DIR_PIN
#define EXT2_INVERSE2 0
#define EXT2_ENABLE2_PIN ORIG_E2_ENABLE_PIN
#define EXT2_MAX_FEEDRATE 100
#define EXT2_MAX_START_FEEDRATE 40
#define EXT2_MAX_ACCELERATION 5000
#define EXT2_HEAT_MANAGER 1
#define EXT2_PREHEAT_TEMP 190
#define EXT2_WATCHPERIOD 1
#define EXT2_PID_INTEGRAL_DRIVE_MAX 255
#define EXT2_PID_INTEGRAL_DRIVE_MIN 40
#define EXT2_PID_PGAIN_OR_DEAD_TIME 8.94
#define EXT2_PID_I 0.51
#define EXT2_PID_D 20
#define EXT2_PID_MAX 255
#define EXT2_ADVANCE_K 0
#define EXT2_ADVANCE_L 0
#define EXT2_ADVANCE_BACKLASH_STEPS 0
#define EXT2_WAIT_RETRACT_TEMP 150
#define EXT2_WAIT_RETRACT_UNITS 0
#define EXT2_SELECT_COMMANDS ""
#define EXT2_DESELECT_COMMANDS ""
#define EXT2_EXTRUDER_COOLER_PIN -1
#define EXT2_EXTRUDER_COOLER_SPEED 255
#define EXT2_DECOUPLE_TEST_PERIOD 30000
#define EXT2_JAM_PIN -1
#define EXT2_JAM_PULLUP 0
#define EXT3_X_OFFSET 0
#define EXT3_Y_OFFSET 0
#define EXT3_Z_OFFSET 0
#define EXT3_STEPS_PER_MM 257
#define EXT3_TEMPSENSOR_TYPE 5
#define EXT3_TEMPSENSOR_PIN TEMP_4_PIN
#define EXT3_HEATER_PIN HEATER_4_PIN
#define EXT3_STEP_PIN ORIG_E3_STEP_PIN
#define EXT3_DIR_PIN ORIG_E3_DIR_PIN
#define EXT3_INVERSE 1
#define EXT3_ENABLE_PIN ORIG_E3_ENABLE_PIN
#define EXT3_ENABLE_ON 1
#define EXT3_MIRROR_STEPPER 0
#define EXT3_STEP2_PIN ORIG_E3_STEP_PIN
#define EXT3_DIR2_PIN ORIG_E3_DIR_PIN
#define EXT3_INVERSE2 0
#define EXT3_ENABLE2_PIN ORIG_E3_ENABLE_PIN
#define EXT3_MAX_FEEDRATE 100
#define EXT3_MAX_START_FEEDRATE 40
#define EXT3_MAX_ACCELERATION 5000
#define EXT3_HEAT_MANAGER 1
#define EXT3_PREHEAT_TEMP 190
#define EXT3_WATCHPERIOD 1
#define EXT3_PID_INTEGRAL_DRIVE_MAX 255
#define EXT3_PID_INTEGRAL_DRIVE_MIN 40
#define EXT3_PID_PGAIN_OR_DEAD_TIME 8.94
#define EXT3_PID_I 0.51
#define EXT3_PID_D 20
#define EXT3_PID_MAX 255
#define EXT3_ADVANCE_K 0
#define EXT3_ADVANCE_L 0
#define EXT3_ADVANCE_BACKLASH_STEPS 0
#define EXT3_WAIT_RETRACT_TEMP 150
#define EXT3_WAIT_RETRACT_UNITS 0
#define EXT3_SELECT_COMMANDS ""
#define EXT3_DESELECT_COMMANDS ""
#define EXT3_EXTRUDER_COOLER_PIN -1
#define EXT3_EXTRUDER_COOLER_SPEED 255
#define EXT3_DECOUPLE_TEST_PERIOD 30000
#define EXT3_JAM_PIN -1
#define EXT3_JAM_PULLUP 0
>>>>>>> refs/heads/master

#define FEATURE_RETRACTION 1
<<<<<<< HEAD
/** auto-retract converts pure extrusion moves into retractions. Beware that
 simple extrusion e.g. over Repetier-Host will then not work! */
// SB #define AUTORETRACT_ENABLED 0
#define AUTORETRACT_ENABLED 1
// SB #define RETRACTION_LENGTH 3
#define RETRACTION_LENGTH 2.5
#define RETRACTION_LONG_LENGTH 13
// SB #define RETRACTION_SPEED 40
#define RETRACTION_SPEED 60
// SB #define RETRACTION_Z_LIFT 0
=======
#define AUTORETRACT_ENABLED 0
#define RETRACTION_LENGTH 2.5
#define RETRACTION_LONG_LENGTH 2.5
#define RETRACTION_SPEED 50
>>>>>>> refs/heads/master
#define RETRACTION_Z_LIFT 0
#define RETRACTION_UNDO_EXTRA_LENGTH 0
#define RETRACTION_UNDO_EXTRA_LONG_LENGTH 0
#define RETRACTION_UNDO_SPEED 40
#define FILAMENTCHANGE_X_POS 0
#define FILAMENTCHANGE_Y_POS 0
#define FILAMENTCHANGE_Z_ADD  2
#define FILAMENTCHANGE_REHOME 1
#define FILAMENTCHANGE_SHORTRETRACT 5
#define FILAMENTCHANGE_LONGRETRACT 50
#define JAM_METHOD 1
#define JAM_STEPS 220
#define JAM_SLOWDOWN_STEPS 320
#define JAM_SLOWDOWN_TO 70
#define JAM_ERROR_STEPS 500
#define JAM_MIN_STEPS 10
#define JAM_ACTION 1

#define RETRACT_DURING_HEATUP true
#define PID_CONTROL_RANGE 20
#define SKIP_M109_IF_WITHIN 2
#define SCALE_PID_TO_MAX 0
<<<<<<< HEAD


#define HEATER_PWM_SPEED 1 // How fast ist pwm signal 0 = 15.25Hz, 1 = 30.51Hz, 2 = 61.03Hz, 3 = 122.06Hz

/** Temperature range for target temperature to hold in M109 command. 5 means +/-5 degC

Uncomment define to force the temperature into the range for given watch period.
*/
//#define TEMP_HYSTERESIS 5

/** Userdefined thermistor table

There are many different thermistors, which can be combined with different resistors. This result
in unpredictable number of tables. As a resolution, the user can define one table here, that can
be used as type 5 for thermistor type in extruder/heated bed definition. Make sure, the number of entries
matches the value in NUM_TEMPS_USERTHERMISTOR0. If you span definition over multiple lines, make sure to end
each line, except the last, with a backslash. The table format is {{adc1,temp1},{adc2,temp2}...} with
increasing adc values. For more informations, read
http://hydraraptor.blogspot.com/2007/10/measuring-temperature-easy-way.html

If you have a sprinter temperature table, you have to multiply the first value with 4 and the second with 8.
This firmware works with increased precision, so the value reads go from 0 to 4095 and the temperature is
temperature*8.

If you have a PTC thermistor instead of a NTC thermistor, keep the adc values increasing and use thermistor types 50-52 instead of 5-7!
*/
/** Number of entries in the user thermistor table 0. Set to 0 to disable it. */
// SB #define NUM_TEMPS_USERTHERMISTOR0 28
#define NUM_TEMPS_USERTHERMISTOR0 0
#define USER_THERMISTORTABLE0  {\
  {1*4,864*8},{21*4,300*8},{25*4,290*8},{29*4,280*8},{33*4,270*8},{39*4,260*8},{46*4,250*8},{54*4,240*8},{64*4,230*8},{75*4,220*8},\
  {90*4,210*8},{107*4,200*8},{128*4,190*8},{154*4,180*8},{184*4,170*8},{221*4,160*8},{265*4,150*8},{316*4,140*8},{375*4,130*8},\
  {441*4,120*8},{513*4,110*8},{588*4,100*8},{734*4,80*8},{856*4,60*8},{938*4,40*8},{986*4,20*8},{1008*4,0*8},{1018*4,-20*8}	}

/** Number of entries in the user thermistor table 1. Set to 0 to disable it. */
=======
#define TEMP_HYSTERESIS 0
#define EXTRUDE_MAXLENGTH 160
#define NUM_TEMPS_USERTHERMISTOR0 29
#define USER_THERMISTORTABLE0 {{0,8000},{69,2280},{79,2200},{92,2120},{107,2040},{125,1960},{146,1886},{172,1810},{204,1736},{243,1661},{291,1586},{350,1511},{422,1437},{512,1362},{622,1287},{756,1212},{919,1138},{1345,988},{3139,539},{3388,464},{3591,390},{3749,314},{3866,240},{3949,160},{4005,80},{4041,0},{4064,-80},{4086,-240},{4093,-400}}
>>>>>>> refs/heads/master
#define NUM_TEMPS_USERTHERMISTOR1 0
#define USER_THERMISTORTABLE1 {}
#define NUM_TEMPS_USERTHERMISTOR2 0
#define USER_THERMISTORTABLE2 {}
#define GENERIC_THERM_VREF 5
#define GENERIC_THERM_NUM_ENTRIES 33
#define TEMP_GAIN 1
#define HEATER_PWM_SPEED 0
#define COOLER_PWM_SPEED 0

// ############# Heated bed configuration ########################

<<<<<<< HEAD
/** \brief Set true if you have a heated bed connected to your board, false if not */
// SB #define HAVE_HEATED_BED 1
#define HAVE_HEATED_BED 0

#define HEATED_BED_MAX_TEMP 115
/** Skip M190 wait, if heated bed is already within x degrees. Fixed numbers only, 0 = off. */
#define SKIP_M190_IF_WITHIN 3

// Select type of your heated bed. It's the same as for EXT0_TEMPSENSOR_TYPE
// set to 0 if you don't have a heated bed
#define HEATED_BED_SENSOR_TYPE 1
/** Analog pin of analog sensor to read temperature of heated bed.  */
#define HEATED_BED_SENSOR_PIN TEMP_1_PIN
/** \brief Pin to enable heater for bed. */
#define HEATED_BED_HEATER_PIN HEATER_1_PIN
// How often the temperature of the heated bed is set (msec)
#define HEATED_BED_SET_INTERVAL 5000

/**
Heat manager for heated bed:
0 = Bang Bang, fast update
1 = PID controlled
2 = Bang Bang, limited check every HEATED_BED_SET_INTERVAL. Use this with relay-driven beds to save life time
3 = dead time control
*/
#define HEATED_BED_HEAT_MANAGER 1
/** \brief The maximum value, I-gain can contribute to the output.
The precise values may differ for different nozzle/resistor combination.
 Overridden if EEPROM activated.
*/
#define HEATED_BED_PID_INTEGRAL_DRIVE_MAX 255
/** \brief lower value for integral part

The I state should converge to the exact heater output needed for the target temperature.
To prevent a long deviation from the target zone, this value limits the lower value.
A good start is 30 lower then the optimal value. You need to leave room for cooling.
 Overridden if EEPROM activated.
*/
#define HEATED_BED_PID_INTEGRAL_DRIVE_MIN 80
/** P-gain.  Overridden if EEPROM activated. */
#define HEATED_BED_PID_PGAIN_OR_DEAD_TIME   196
/** I-gain  Overridden if EEPROM activated.*/
#define HEATED_BED_PID_IGAIN   33.02
/** Dgain.  Overridden if EEPROM activated.*/
#define HEATED_BED_PID_DGAIN 290
// maximum time the heater can be switched on. Max = 255.  Overridden if EEPROM activated.
#define HEATED_BED_PID_MAX 255
// Time to see a temp. change when fully heating. Consider that beds at higher temp. need longer to rise and cold
// beds need some time to get the temp. to the sensor. Time is in milliseconds! Set 0 to disable
#define HEATED_BED_DECOUPLE_TEST_PERIOD 300000

// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
// SB #define MAXTEMP 260
#define MAXTEMP 270

=======
#define HAVE_HEATED_BED 1
>>>>>>> refs/heads/master
#define HEATED_BED_PREHEAT_TEMP 55
<<<<<<< HEAD

/** Extreme values to detect defect thermistors. */
// SB #define MIN_DEFECT_TEMPERATURE -10
#define MIN_DEFECT_TEMPERATURE 10
=======
#define HEATED_BED_MAX_TEMP 120
#define SKIP_M190_IF_WITHIN 3
#define HEATED_BED_SENSOR_TYPE 8
#define HEATED_BED_SENSOR_PIN TEMP_1_PIN
#define HEATED_BED_HEATER_PIN HEATER_1_PIN
#define HEATED_BED_SET_INTERVAL 5000
#define HEATED_BED_HEAT_MANAGER 1
#define HEATED_BED_PID_INTEGRAL_DRIVE_MAX 255
#define HEATED_BED_PID_INTEGRAL_DRIVE_MIN 80
#define HEATED_BED_PID_PGAIN_OR_DEAD_TIME   196
#define HEATED_BED_PID_IGAIN   33
#define HEATED_BED_PID_DGAIN 290
#define HEATED_BED_PID_MAX 255
#define HEATED_BED_DECOUPLE_TEST_PERIOD 300000
#define MIN_EXTRUDER_TEMP 150
#define MAXTEMP 280
#define MIN_DEFECT_TEMPERATURE -10
>>>>>>> refs/heads/master
#define MAX_DEFECT_TEMPERATURE 300
#define MILLISECONDS_PREHEAT_TIME 30000

// ##########################################################################################
// ##                             Laser configuration                                      ##
// ##########################################################################################

/*
If the firmware is in laser mode, it can control a laser output to cut or engrave materials.
Please use this feature only if you know about safety and required protection. Lasers are
dangerous and can hurt or make you blind!!!

The default laser driver only supports laser on and off. Here you control the intensity with
your feedrate. For exchangeable diode lasers this is normally enough. If you need more control
you can set the intensity in a range 0-255 with a custom extension to the driver. See driver.h
and comments on how to extend the functions non invasive with our event system.

If you have a laser - powder system you will like your E override. If moves contain a
increasing extruder position it will laser that move. With this trick you can
use existing fdm slicers to laser the output. Laser width is extrusion width.

Other tools may use M3 and M5 to enable/disable laser. Here G1/G2/G3 moves have laser enabled
and G0 moves have it disables.

In any case, laser only enables while moving. At the end of a move it gets
automatically disabled.
*/

#define SUPPORT_LASER 0
#define LASER_PIN -1
#define LASER_ON_HIGH 1
#define LASER_WARMUP_TIME 0
#define LASER_PWM_MAX 255
#define LASER_WATT 2

// ##                              CNC configuration                                       ##

/*
If the firmware is in CNC mode, it can control a mill with M3/M4/M5. It works
similar to laser mode, but mill keeps enabled during G0 moves and it allows
setting rpm (only with event extension that supports this) and milling direction.
It also can add a delay to wait for spindle to run on full speed.
*/

#define SUPPORT_CNC 0
#define CNC_WAIT_ON_ENABLE 300
#define CNC_WAIT_ON_DISABLE 0
#define CNC_ENABLE_PIN -1
#define CNC_ENABLE_WITH 1
#define CNC_DIRECTION_PIN -1
#define CNC_DIRECTION_CW 1
#define CNC_PWM_MAX 255
#define CNC_RPM_MAX 8000
#define CNC_SAFE_Z 150

#define DEFAULT_PRINTER_MODE 0

// ################ Endstop configuration #####################

<<<<<<< HEAD
/* By default all endstops are pulled up to HIGH. You need a pull-up if you
use a mechanical endstop connected with GND. Set value to false for no pull-up
on this endstop.
*/
#define ENDSTOP_PULLUP_X_MIN false
#define ENDSTOP_PULLUP_Y_MIN false
#define ENDSTOP_PULLUP_Z_MIN false
// SB #define ENDSTOP_PULLUP_X_MAX true
#define ENDSTOP_PULLUP_X_MAX false
// SB #define ENDSTOP_PULLUP_Y_MAX true
#define ENDSTOP_PULLUP_Y_MAX false
#define ENDSTOP_PULLUP_Z_MAX false

//set to true to invert the logic of the endstops
=======
#define MULTI_ZENDSTOP_HOMING 0
#define ENDSTOP_PULLUP_X_MIN true
>>>>>>> refs/heads/master
#define ENDSTOP_X_MIN_INVERTING true
<<<<<<< HEAD
#define ENDSTOP_Y_MIN_INVERTING true
#define ENDSTOP_Z_MIN_INVERTING true
// SB #define ENDSTOP_X_MAX_INVERTING false
#define ENDSTOP_X_MAX_INVERTING true
// SB #define ENDSTOP_Y_MAX_INVERTING false
#define ENDSTOP_Y_MAX_INVERTING true
#define ENDSTOP_Z_MAX_INVERTING true

// Set the values true where you have a hardware endstop. The Pin number is taken from pins.h.

// SB #define MIN_HARDWARE_ENDSTOP_X true
#define MIN_HARDWARE_ENDSTOP_X false
// SB #define MIN_HARDWARE_ENDSTOP_Y true
#define MIN_HARDWARE_ENDSTOP_Y false
#define MIN_HARDWARE_ENDSTOP_Z false
// SB #define MAX_HARDWARE_ENDSTOP_X false
#define MAX_HARDWARE_ENDSTOP_X true
// SB #define MAX_HARDWARE_ENDSTOP_Y false
#define MAX_HARDWARE_ENDSTOP_Y true
=======
#define MIN_HARDWARE_ENDSTOP_X true
#define ENDSTOP_PULLUP_Y_MIN true
#define ENDSTOP_Y_MIN_INVERTING true
#define MIN_HARDWARE_ENDSTOP_Y true
#define ENDSTOP_PULLUP_Z_MIN true
#define ENDSTOP_Z_MIN_INVERTING true
#define MIN_HARDWARE_ENDSTOP_Z true
#define ENDSTOP_PULLUP_Z2_MINMAX true
#define ENDSTOP_Z2_MINMAX_INVERTING false
#define MINMAX_HARDWARE_ENDSTOP_Z2 false
#define ENDSTOP_PULLUP_X_MAX true
#define ENDSTOP_X_MAX_INVERTING true
#define MAX_HARDWARE_ENDSTOP_X true
#define ENDSTOP_PULLUP_Y_MAX true
#define ENDSTOP_Y_MAX_INVERTING true
#define MAX_HARDWARE_ENDSTOP_Y true
#define ENDSTOP_PULLUP_Z_MAX true
#define ENDSTOP_Z_MAX_INVERTING true
>>>>>>> refs/heads/master
#define MAX_HARDWARE_ENDSTOP_Z true
#define ENDSTOP_PULLUP_X2_MIN true
#define ENDSTOP_PULLUP_Y2_MIN true
#define ENDSTOP_PULLUP_Z2_MINMAX true
#define ENDSTOP_PULLUP_X2_MAX true
#define ENDSTOP_PULLUP_Y2_MAX true
#define ENDSTOP_X2_MIN_INVERTING false
#define ENDSTOP_Y2_MIN_INVERTING false
#define ENDSTOP_X2_MAX_INVERTING false
#define ENDSTOP_Y2_MAX_INVERTING false
#define MIN_HARDWARE_ENDSTOP_X2 false
#define MIN_HARDWARE_ENDSTOP_Y2 false
#define MAX_HARDWARE_ENDSTOP_X2 false
#define MAX_HARDWARE_ENDSTOP_Y2 false
#define X2_MIN_PIN -1
#define X2_MAX_PIN -1
#define Y2_MIN_PIN -1
#define Y2_MAX_PIN -1
#define Z2_MINMAX_PIN -1


<<<<<<< HEAD


//// ADVANCED SETTINGS - to tweak parameters
=======
>>>>>>> refs/heads/master

<<<<<<< HEAD
// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0

// Disables axis when it's not being used.
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false
#define DISABLE_E false
/* If you want to keep z motor running on stepper timeout, remove comments below.
  This may be useful if your z bed moves when motors are disabled. Will still
  turn z off when heaters get also disabled. 
*/
//#define PREVENT_Z_DISABLE_ON_STEPPER_TIMEOUT

// Inverting motor direction. Only in case of pure cartesian printers, this
// is also the axis you invert!
// SB #define INVERT_X_DIR 1
#define INVERT_X_DIR false
#define INVERT_X2_DIR 1
// SB #define INVERT_Y_DIR 1
#define INVERT_Y_DIR false
#define INVERT_Y2_DIR 1
// SB #define INVERT_Z_DIR 1
#define INVERT_Z_DIR false
#define INVERT_Z2_DIR 1
#define INVERT_Z3_DIR 1
#define INVERT_Z4_DIR 1

//// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
// SB #define X_HOME_DIR -1
#define X_HOME_DIR 1
// SB #define Y_HOME_DIR -1
#define Y_HOME_DIR 1
#define Z_HOME_DIR 1

// Delta robot radius endstop
=======
>>>>>>> refs/heads/master
#define max_software_endstop_r true

#define min_software_endstop_x false
#define min_software_endstop_y false
#define min_software_endstop_z false
<<<<<<< HEAD

//If true, axis won't move to coordinates greater than the defined lengths below.
#define max_software_endstop_x true
#define max_software_endstop_y true
// SB #define max_software_endstop_z false
#define max_software_endstop_z true

// If during homing the endstop is reached, ho many mm should the printer move back for the second try
#define ENDSTOP_X_BACK_MOVE 5
#define ENDSTOP_Y_BACK_MOVE 5
// SB #define ENDSTOP_Z_BACK_MOVE 2
#define ENDSTOP_Z_BACK_MOVE 5

// For higher precision you can reduce the speed for the second test on the endstop
// during homing operation. The homing speed is divided by the value. 1 = same speed, 2 = half speed
#define ENDSTOP_X_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_Y_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_Z_RETEST_REDUCTION_FACTOR 2

// When you have several endstops in one circuit you need to disable it after homing by moving a
// small amount back. This is also the case with H-belt systems.
// SB #define ENDSTOP_X_BACK_ON_HOME 1
#define ENDSTOP_X_BACK_ON_HOME 5
// SB #define ENDSTOP_Y_BACK_ON_HOME 1
#define ENDSTOP_Y_BACK_ON_HOME 5
// SB #define ENDSTOP_Z_BACK_ON_HOME 0
#define ENDSTOP_Z_BACK_ON_HOME 5
// If you do z min homing, you might want to rise extruder a bit after homing so it does not heat
// touching your bed.
#define Z_UP_AFTER_HOME 0
// You can disable endstop checking for print moves. This is needed, if you get sometimes
// false signals from your endstops. If your endstops don't give false signals, you
// can set it on for safety.
// SB #define ALWAYS_CHECK_ENDSTOPS 1
#define ALWAYS_CHECK_ENDSTOPS true
=======
#define max_software_endstop_x false
#define max_software_endstop_y false
#define max_software_endstop_z false
#define DOOR_PIN -1
#define DOOR_PULLUP 1
#define DOOR_INVERTING 1
#define ENDSTOP_X_BACK_MOVE 6
#define ENDSTOP_Y_BACK_MOVE 6
#define ENDSTOP_Z_BACK_MOVE 6
#define ENDSTOP_X_RETEST_REDUCTION_FACTOR 3
#define ENDSTOP_Y_RETEST_REDUCTION_FACTOR 3
#define ENDSTOP_Z_RETEST_REDUCTION_FACTOR 6
#define ENDSTOP_X_BACK_ON_HOME 1
#define ENDSTOP_Y_BACK_ON_HOME 1
#define ENDSTOP_Z_BACK_ON_HOME 0
#define ALWAYS_CHECK_ENDSTOPS 1
#define MOVE_X_WHEN_HOMED 0
#define MOVE_Y_WHEN_HOMED 0
#define MOVE_Z_WHEN_HOMED 0
>>>>>>> refs/heads/master

<<<<<<< HEAD
// maximum positions in mm - only fixed numbers!
// For delta robot Z_MAX_LENGTH is the maximum travel of the towers and should be set to the distance between the hotend
// and the platform when the printer is at its home position.
// If EEPROM is enabled these values will be overridden with the values in the EEPROM
// SB #define X_MAX_LENGTH 165
#define X_MAX_LENGTH 135
// SB #define Y_MAX_LENGTH 175
#define Y_MAX_LENGTH 135
// SB #define Z_MAX_LENGTH 116.820
#define Z_MAX_LENGTH 323

// Coordinates for the minimum axis. Can also be negative if you want to have the bed start at 0 and the printer can go to the left side
// of the bed. Maximum coordinate is given by adding the above X_MAX_LENGTH values.
=======
// ################# XYZ movements ###################

#define X_ENABLE_ON 1
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 1
#define DISABLE_X 0
#define DISABLE_Y 0
#define DISABLE_Z 0
#define DISABLE_E 0
#define PREVENT_Z_DISABLE_ON_STEPPER_TIMEOUT
#define INVERT_X_DIR 0
#define INVERT_X2_DIR 0
#define INVERT_Y_DIR 1
#define INVERT_Y2_DIR 0
#define INVERT_Z_DIR 0
#define INVERT_Z2_DIR 0
#define INVERT_Z3_DIR 0
#define INVERT_Z4_DIR 0
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1
#define X_MAX_LENGTH 418
#define Y_MAX_LENGTH 240
#define Z_MAX_LENGTH 210
>>>>>>> refs/heads/master
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define PARK_POSITION_X 0
#define PARK_POSITION_Y 10
#define PARK_POSITION_Z_RAISE 10


#define DISTORTION_CORRECTION 0
#define DISTORTION_CORRECTION_POINTS 5
#define DISTORTION_LIMIT_TO 2
#define DISTORTION_CORRECTION_R 100
#define DISTORTION_PERMANENT 1
#define DISTORTION_UPDATE_FREQUENCY 15
#define DISTORTION_START_DEGRADE 0.5
#define DISTORTION_END_HEIGHT 1
#define DISTORTION_EXTRAPOLATE_CORNERS 0
#define DISTORTION_XMIN 10
#define DISTORTION_YMIN 10
#define DISTORTION_XMAX 190
#define DISTORTION_YMAX 190

// ##########################################################################################
// ##                           Movement settings                                          ##
// ##########################################################################################

<<<<<<< HEAD
// Microstep setting (Only functional when stepper driver microstep pins are connected to MCU. Currently only works for RAMBO boards
// SB #define MICROSTEP_MODES {8,8,8,8,8} // [1,2,4,8,16]
#define MICROSTEP_MODES {16,16,16,16,16} // [1,2,4,8,16]
=======
#define FEATURE_BABYSTEPPING 1
#define BABYSTEP_MULTIPLICATOR 1
>>>>>>> refs/heads/master

#define DELTA_SEGMENTS_PER_SECOND_PRINT 180 // Move accurate setting for print moves
#define DELTA_SEGMENTS_PER_SECOND_MOVE 70 // Less accurate setting for other moves
<<<<<<< HEAD

// Delta settings
#if DRIVE_SYSTEM==DELTA
/** \brief Delta rod length (mm)
*/
// SB #define DELTA_DIAGONAL_ROD 345 // mm
// SB Calcolato con foglio My_Calibration_Calculus.xlsx 372,7397399511
#define DELTA_DIAGONAL_ROD 372.74 // mm


/*  =========== Parameter essential for delta calibration ===================

            C, Y-Axis
            |                        |___| CARRIAGE_HORIZONTAL_OFFSET (recommend set it to 0)
            |                        |   \------------------------------------------
            |_________ X-axis        |    \                                        |
           / \                       |     \  DELTA_DIAGONAL_ROD (length)    Each move this Rod Height
          /   \                             \                                 is calculated
         /     \                             \    Carriage is at printer center!   |
         A      B                             \_____/--------------------------------
                                              |--| END_EFFECTOR_HORIZONTAL_OFFSET (recommend set it to 0)
                                         |----| ROD_RADIUS (Horizontal rod pivot to pivot measure)
                                     |-----------| PRINTER_RADIUS (recommend set it to ROD_RADIUS)

    Column angles are measured from X-axis counterclockwise
    "Standard" positions: alpha_A = 210, alpha_B = 330, alpha_C = 90
*/

/** \brief column positions - change only to correct build imperfections! */
#define DELTA_ALPHA_A 210
#define DELTA_ALPHA_B 330
#define DELTA_ALPHA_C 90

/** Correct radius by this value for each column. Perfect builds have 0 everywhere. */
#define DELTA_RADIUS_CORRECTION_A 0
#define DELTA_RADIUS_CORRECTION_B 0
#define DELTA_RADIUS_CORRECTION_C 0

/** Correction of the default diagonal size. Value gets added.*/
#define DELTA_DIAGONAL_CORRECTION_A 0
#define DELTA_DIAGONAL_CORRECTION_B 0
#define DELTA_DIAGONAL_CORRECTION_C 0

/** Max. radius (mm) the printer should be able to reach. */
// Se è troppo piccolo ed eseguo il comdnao G30 per eseguire un sondaggio di con z-probbre
// hotend va verso l'alto e va in errore il comando di controllo del piano G30.
// SB #define DELTA_MAX_RADIUS 200
#define DELTA_MAX_RADIUS 160

// Margin (mm) to avoid above tower minimum (xMin xMinsteps)
// If your printer can put its carriage low enough the rod is horizontal without hitting the floor
// set this to zero. Otherwise, measure how high the carriage is from horizontal rod
// Also, movement speeds are 10x to 20x cartesian speeds at tower bottom.
// You may need to leave a few mm for safety.
// Hitting floor at high speed can damage your printer (motors, drives, etc)
// THIS MAY NEED UPDATING IF THE HOT END HEIGHT CHANGES!
#define DELTA_FLOOR_SAFETY_MARGIN_MM 15

/** \brief Horizontal offset of the universal joints on the end effector (moving platform).
*/
#define END_EFFECTOR_HORIZONTAL_OFFSET 0

/** \brief Horizontal offset of the universal joints on the vertical carriages.
*/
#define CARRIAGE_HORIZONTAL_OFFSET 0

/** \brief Printer radius in mm,
  measured from the center of the print area to the vertical smooth tower.
  Alternately set this to the pivot to pivot horizontal rod distance, when head is at (0,0)
*/
// SB #define PRINTER_RADIUS 124
// SB #define PRINTER_RADIUS (CARRIAGE_HORIZONTAL_OFFSET + MY_ROD_RADIUS + END_EFFECTOR_HORIZONTAL_OFFSET )
// SB #define PRINTER_RADIUS 187.123
#define PRINTER_RADIUS 187.255

/** 1 for more precise delta moves. 0 for faster computation.
Needs a bit more computation time. */
=======
>>>>>>> refs/heads/master
#define EXACT_DELTA_MOVES 1

// Delta settings
#define DELTA_HOME_ON_POWER 0

<<<<<<< HEAD
/** To allow software correction of misaligned endstops, you can set the correction in steps here. If you have EEPROM enabled
you can also change the values online and autoleveling will store the results here. */
// SB #define DELTA_X_ENDSTOP_OFFSET_STEPS 0
// SB #define DELTA_X_ENDSTOP_OFFSET_STEPS 54
#define DELTA_X_ENDSTOP_OFFSET_STEPS 0
// SB #define DELTA_Y_ENDSTOP_OFFSET_STEPS 0
// SB #define DELTA_Y_ENDSTOP_OFFSET_STEPS 55
#define DELTA_Y_ENDSTOP_OFFSET_STEPS 0
// SB #define DELTA_Z_ENDSTOP_OFFSET_STEPS 0
#define DELTA_Z_ENDSTOP_OFFSET_STEPS 0

#endif
#if DRIVE_SYSTEM==TUGA
// ========== Tuga special settings =============
/* Radius of the long arm in mm. */
#define DELTA_DIAGONAL_ROD 240
#endif

/** \brief Number of delta moves in each line. Moves that exceed this figure will be split into multiple lines.
Increasing this figure can use a lot of memory since 7 bytes * size of line buffer * MAX_SELTA_SEGMENTS_PER_LINE
will be allocated for the delta buffer.
PrintLine PrintLine::lines[PRINTLINE_CACHE_SIZE (default 16?)];
Printline is about 200 bytes + 7 * DELTASEGMENTS_PER_PRINTLINE
or 16 * (200 + (7*22=154) = 354) = 5664 bytes! !1
min is 5 * (200 + (7*10=70) =270) = 1350
 This leaves ~1K free RAM on an Arduino which has only 8k
Mega. Used only for nonlinear systems like delta or tuga. */
#define DELTASEGMENTS_PER_PRINTLINE 22

/** After x seconds of inactivity, the stepper motors are disabled.
    Set to 0 to leave them enabled.
    This helps cooling the Stepper motors between two print jobs.
    Overridden if EEPROM activated.
*/
#define STEPPER_INACTIVE_TIME 360
/** After x seconds of inactivity, the system will go down as far it can.
    It will at least disable all stepper motors and heaters. If the board has
    a power pin, it will be disabled, too.
    Set value to 0 for disabled.
    Overridden if EEPROM activated.
*/
=======
#define DELTASEGMENTS_PER_PRINTLINE 24
#define STEPPER_INACTIVE_TIME 360L
>>>>>>> refs/heads/master
#define MAX_INACTIVE_TIME 0L
#define MAX_FEEDRATE_X 200
#define MAX_FEEDRATE_Y 200
<<<<<<< HEAD
// SB #define MAX_FEEDRATE_Z 5
#define MAX_FEEDRATE_Z 200

/** Home position speed in mm/s. Overridden if EEPROM activated. */
// SB #define HOMING_FEEDRATE_X 80
#define HOMING_FEEDRATE_X 30
// SB #define HOMING_FEEDRATE_Y 80
#define HOMING_FEEDRATE_Y 30
// SB #define HOMING_FEEDRATE_Z 3
#define HOMING_FEEDRATE_Z 30

/** Set order of axis homing. Use HOME_ORDER_XYZ and replace XYZ with your order. 
 * If you measure Z with your extruder tip you need a hot extruder to get right measurement. In this
 * case set HOME_ORDER_ZXYTZ and also define ZHOME_HEAT_HEIGHT and ZHOME_MIN_TEMPERATURE. It will do
 * first a z home to get some reference, then raise to ZHOME_HEAT_HEIGHT do xy homing and then after
 * heating to minimum ZHOME_MIN_TEMPERATURE will z home again for correct height.   
 * */
#define HOMING_ORDER HOME_ORDER_ZXY
/*
  Raise Z before homing z axis
  0 = no
  1 = if z min is triggered
  2 = always
  This is for printers with z probe used as z min. For homing the probe must be
  at a minimum height for some endstop types, so raising it before will help
  to make sure this is guaranteed. 
*/
=======
#define MAX_FEEDRATE_Z 80
#define HOMING_FEEDRATE_X 40
#define HOMING_FEEDRATE_Y 40
#define HOMING_FEEDRATE_Z 40
#define HOMING_ORDER HOME_ORDER_XYZ
>>>>>>> refs/heads/master
#define ZHOME_PRE_RAISE 0
#define ZHOME_PRE_RAISE_DISTANCE 10
#define RAISE_Z_ON_TOOLCHANGE 0
#define ZHOME_MIN_TEMPERATURE 0
#define ZHOME_HEAT_ALL 1
#define ZHOME_HEAT_HEIGHT 20
#define ZHOME_X_POS 999999
#define ZHOME_Y_POS 999999
#define ENABLE_BACKLASH_COMPENSATION 1
#define X_BACKLASH 0
#define Y_BACKLASH 0
#define Z_BACKLASH 0
#define RAMP_ACCELERATION 1
#define STEPPER_HIGH_DELAY 0
#define DIRECTION_DELAY 0
#define STEP_DOUBLER_FREQUENCY 12000
#define ALLOW_QUADSTEPPING 1
<<<<<<< HEAD
/** If you reach STEP_DOUBLER_FREQUENCY the firmware will do 2 or 4 steps with nearly no delay. That can be too fast
for some printers causing an early stall.

*/
#define DOUBLE_STEP_DELAY 0 // time in microseconds

/** If the firmware is busy, it will send a busy signal to host signaling that
 everything is fine and it only takes a bit longer to finish. That way the 
 host can keep timeout short so in case of communication errors the resulting
 blobs are much smaller. Set to 0 to disable it. */
#define KEEP_ALIVE_INTERVAL 2000
//// Acceleration settings

/** \brief X, Y, Z max acceleration in mm/s^2 for printing moves or retracts. Make sure your printer can go that high!
 Overridden if EEPROM activated.
*/
// SB #define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X 1000
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X 1500
// SB #define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1000
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1500
// SB #define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z 100
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z 1500

/** \brief X, Y, Z max acceleration in mm/s^2 for travel moves.  Overridden if EEPROM activated.*/
// SB #define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X 2000
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X 1500
// SB #define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y 2000
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1500
// SB #define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z 100
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z 1500

/** If you print on a moving bed, it can become more shaky the higher and bigger
 your print gets. Therefore it might be helpfull to reduce acceleration with
 increasing print height. You can define here how acceleration should change.
 You set ACCELERATION_FACTOR_TOP to the factor in percent for the top position
 of your printer. Acceleration will then be modified linear over height.
 INTERPOLATE_ACCELERATION_WITH_Z sets, which accelerations get changed:
 0 = do not interpolate at all
 1 = interpolate x and y acceleration
 2 = interpolate z acceleration
 3 = interpolate x,y and z acceleration
  */
=======
#define DOUBLE_STEP_DELAY 1 // time in microseconds
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X 1000
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1000
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z 50
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X 1000
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1000
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z 50
>>>>>>> refs/heads/master
#define INTERPOLATE_ACCELERATION_WITH_Z 0
#define ACCELERATION_FACTOR_TOP 100
#define MAX_JERK 25
#define MAX_ZJERK 0.3
#define PRINTLINE_CACHE_SIZE 24
#define MOVE_CACHE_LOW 10
#define LOW_TICKS_PER_MOVE 250000
<<<<<<< HEAD

// ##########################################################################################
// ##                           Extruder control                                           ##
// ##########################################################################################


/* \brief Minimum temperature for extruder operation

This is a safety value. If your extruder temperature is below this temperature, no
extruder steps are executed. This is to prevent your extruder to move unless the filament
is at least molten. After having some complains that the extruder does not work, I leave
it 0 as default.
*/

#define MIN_EXTRUDER_TEMP 160

/** \brief Enable advance algorithm.

Without a correct adjusted advance algorithm, you get blobs at points, where acceleration changes. The
effect increases with speed and acceleration difference. Using the advance method decreases this effect.
For more informations, read the wiki.
*/
#define USE_ADVANCE 1

/** \brief enables quadratic component.

Set 1 to allow, 0 disallow a quadratic advance dependency. Linear is the dominant value, so no real need
to activate the quadratic term. Only adds lots of computations and storage usage. */
#define ENABLE_QUADRATIC_ADVANCE 0


// ##########################################################################################
// ##                           Communication configuration                                ##
// ##########################################################################################

//// AD595 THERMOCOUPLE SUPPORT UNTESTED... USE WITH CAUTION!!!!

/** \brief Communication speed.

- 250000 : Fastest with error rate of 0% with 16 or 32 MHz - update wiring_serial.c in your board files. See boards/readme.txt
- 115200 : Fast, but may produce communication errors on quite regular basis, Error rate -3,5%
- 76800 : Best setting for Arduino with 16 MHz, Error rate 0,2% page 198 AVR1284 Manual. Result: Faster communication then 115200
- 57600 : Should produce nearly no errors, on my gen 6 it's faster than 115200 because there are no errors slowing down the connection
- 38600

 Overridden if EEPROM activated.
*/
//#define BAUDRATE 76800
#define BAUDRATE 115200
//#define BAUDRATE 250000

/**
Some boards like Gen7 have a power on pin, to enable the ATX power supply. If this is defined,
the power will be turned on without the need to call M80 if initially started.
*/
#define ENABLE_POWER_ON_STARTUP 1

/**
If you use an ATX power supply you need the power pin to work non inverting. For some special
boards you might need to make it inverting.
*/
#define POWER_INVERTING 0

/** Automatically enable power when temperatures or moves/homing is used. Set only to 1 if
 *you have a power unit controlled by PS_ON_PIN! */
#define AUTOMATIC_POWERUP 0

/** What shall the printer do, when it receives an M112 emergency stop signal?
 0 = Disable heaters/motors, wait forever until someone presses reset.
 1 = restart by resetting the AVR controller. The USB connection will not reset if managed by a different chip!
*/
#define KILL_METHOD 1

/** Appends the line number after every ok send, to acknowledge the received command. Uncomment for plain ok ACK if your host has problems with this */
#define ACK_WITH_LINENUMBER 1
/** Communication errors can swallow part of the ok, which tells the host software to send
the next command. Not receiving it will cause your printer to stop. Sending this string every
second, if our queue is empty should prevent this. Comment it, if you don't want this feature. */
// SB #define WAITING_IDENTIFIER "wait"

/** \brief Sets time for echo debug

You can set M111 1 which enables ECHO of commands sent. This define specifies the position,
when it will be executed. In the original FiveD software, echo is done after receiving the
command. With checksum you know, how it looks from the sending string. With this define
uncommented, you will see the last command executed. To be more specific: It is written after
execution. This helps tracking errors, because there may be 8 or more commands in the queue
and it is elsewise difficult to know, what your reprap is currently doing.
*/
#define ECHO_ON_EXECUTE 1

/** \brief EEPROM storage mode

Set the EEPROM_MODE to 0 if you always want to use the settings in this configuration file. If not,
set it to a value not stored in the first EEPROM-byte used. If you later want to overwrite your current
EEPROM settings with configuration defaults, just select an other value. On the first call to epr_init()
it will detect a mismatch of the first byte and copy default values into EEPROM. If the first byte
matches, the stored values are used to overwrite the settings.

IMPORTANT: With mode <>0 some changes in Configuration.h are not set any more, as they are
           taken from the EEPROM.
*/
// SB #define EEPROM_MODE 2
#define EEPROM_MODE 2
// SB E' obbligatorio abilitare eeprom per utilizzare DISTORTION_CORRECTION

/**************** duplicate motor driver ***************

If you have unused extruder steppers free, you could use it to drive the second or third z motor
instead of driving them with a single stepper. The same works for the other axis if needed.
*/

#define FEATURE_TWO_XSTEPPER 0
#define X2_STEP_PIN   E1_STEP_PIN
#define X2_DIR_PIN    E1_DIR_PIN
#define X2_ENABLE_PIN E1_ENABLE_PIN

/* Dual x axis mean having a printer with x motors and each controls one
extruder position. In that case you can also have different resolutions for the
2 motors. */
=======
#define EXTRUDER_SWITCH_XY_SPEED 100
>>>>>>> refs/heads/master
#define DUAL_X_AXIS 0
#define DUAL_X_RESOLUTION 0
#define X2AXIS_STEPS_PER_MM 100
#define FEATURE_TWO_XSTEPPER 0
#define X2_STEP_PIN   ORIG_E1_STEP_PIN
#define X2_DIR_PIN    ORIG_E1_DIR_PIN
#define X2_ENABLE_PIN ORIG_E1_ENABLE_PIN
#define FEATURE_TWO_YSTEPPER 0
#define Y2_STEP_PIN   ORIG_E1_STEP_PIN
#define Y2_DIR_PIN    ORIG_E1_DIR_PIN
#define Y2_ENABLE_PIN ORIG_E1_ENABLE_PIN
#define FEATURE_TWO_ZSTEPPER 0
#define Z2_STEP_PIN   ORIG_E1_STEP_PIN
#define Z2_DIR_PIN    ORIG_E1_DIR_PIN
#define Z2_ENABLE_PIN ORIG_E1_ENABLE_PIN
#define FEATURE_THREE_ZSTEPPER 0
#define Z3_STEP_PIN   ORIG_E2_STEP_PIN
#define Z3_DIR_PIN    ORIG_E2_DIR_PIN
#define Z3_ENABLE_PIN ORIG_E2_ENABLE_PIN
#define FEATURE_FOUR_ZSTEPPER 0
#define Z4_STEP_PIN   ORIG_E3_STEP_PIN
#define Z4_DIR_PIN    ORIG_E3_DIR_PIN
#define Z4_ENABLE_PIN ORIG_E3_ENABLE_PIN
#define FEATURE_DITTO_PRINTING 1
#define USE_ADVANCE 1
#define ENABLE_QUADRATIC_ADVANCE 0


// ################# Misc. settings ##################

#define BAUDRATE 250000
#define ENABLE_POWER_ON_STARTUP 1
#define POWER_INVERTING 0
#define AUTOMATIC_POWERUP 0
#define KILL_METHOD 1
#define EMERGENCY_PARSER 1
#define ACK_WITH_LINENUMBER 1
#define KEEP_ALIVE_INTERVAL 2000
#define WAITING_IDENTIFIER "wait"
#define ECHO_ON_EXECUTE 1
#define EEPROM_MODE 1
#undef PS_ON_PIN
#define PS_ON_PIN -1
#define JSON_OUTPUT 1

/* ======== Servos =======
Control the servos with
M340 P<servoId> S<pulseInUS>   / ServoID = 0..3  pulseInUs = 500..2500
Servos are controlled by a pulse width normally between 500 and 2500 with 1500ms in center position. 0 turns servo off.
WARNING: Servos can draw a considerable amount of current. Make sure your system can handle this or you may risk your hardware!
*/
#define FEATURE_SERVO 0
#define SERVO0_PIN 11
#define SERVO1_PIN -1
#define SERVO2_PIN -1
#define SERVO3_PIN -1
#define SERVO0_NEUTRAL_POS  -1
#define SERVO1_NEUTRAL_POS  -1
#define SERVO2_NEUTRAL_POS  -1
#define SERVO3_NEUTRAL_POS  -1
#define UI_SERVO_CONTROL 0
#define FAN_KICKSTART_TIME  200
#define MAX_FAN_PWM 255

        #define FEATURE_WATCHDOG 1

// #################### Z-Probing #####################

#define Z_PROBE_Z_OFFSET 0
#define Z_PROBE_Z_OFFSET_MODE 0
#define UI_BED_COATING 0
#define FEATURE_Z_PROBE 0
#define EXTRUDER_IS_Z_PROBE 0
#define Z_PROBE_DISABLE_HEATERS 0
<<<<<<< HEAD
// SB #define Z_PROBE_PIN 63
#define Z_PROBE_PIN ORIG_Y_MIN_PIN
// SB #define Z_PROBE_PULLUP 1
#define Z_PROBE_PULLUP true
// SB #define Z_PROBE_ON_HIGH 1
#define Z_PROBE_ON_HIGH true
// SB #define Z_PROBE_X_OFFSET 0
#define Z_PROBE_X_OFFSET 6.0
// SB #define Z_PROBE_Y_OFFSET 0
#define Z_PROBE_Y_OFFSET 23.5
// SB #define Z_PROBE_BED_DISTANCE 5.0 // Higher than max bed level distance error in mm
#define Z_PROBE_BED_DISTANCE 20.0

// Waits for a signal to start. Valid signals are probe hit and ok button.
// This is needful if you have the probe trigger by hand.
// SB #define Z_PROBE_WAIT_BEFORE_TEST 0
#define Z_PROBE_WAIT_BEFORE_TEST false
/** Speed of z-axis in mm/s when probing */
// SB #define Z_PROBE_SPEED 2
#define Z_PROBE_SPEED 10
/** Delay before going down. Needed for piezo endstops to reload safely. */
#define Z_PROBE_DELAY 0
// SB #define Z_PROBE_XY_SPEED 150
#define Z_PROBE_XY_SPEED 1000
// SB #define Z_PROBE_SWITCHING_DISTANCE 1.5 // Distance to safely switch off probe after it was activated
#define Z_PROBE_SWITCHING_DISTANCE 2
// SB #define Z_PROBE_REPETITIONS 5 // Repetitions for probing at one point.
#define Z_PROBE_REPETITIONS 3
/** Distance between nozzle and bed when probe triggers. */
// SB #define Z_PROBE_HEIGHT 39.91
// SB #define Z_PROBE_HEIGHT 10.69
#define Z_PROBE_HEIGHT 15.446
/** These scripts are run before resp. after the z-probe is done. Add here code to activate/deactivate probe if needed. */
=======
#define Z_PROBE_BED_DISTANCE 10
#define Z_PROBE_PIN -1
#define Z_PROBE_PULLUP 0
#define Z_PROBE_ON_HIGH 0
#define Z_PROBE_X_OFFSET 0
#define Z_PROBE_Y_OFFSET 0
#define Z_PROBE_WAIT_BEFORE_TEST 0
#define Z_PROBE_SPEED 2
#define Z_PROBE_XY_SPEED 150
#define Z_PROBE_SWITCHING_DISTANCE 1
#define Z_PROBE_REPETITIONS 1
#define Z_PROBE_USE_MEDIAN 0
#define Z_PROBE_HEIGHT 40
#define Z_PROBE_DELAY 0
>>>>>>> refs/heads/master
#define Z_PROBE_START_SCRIPT ""
#define Z_PROBE_FINISHED_SCRIPT ""
<<<<<<< HEAD
/* SB - Esempio Codice GCode per disarmare il Probe meccanico */
// SB #define Z_PROBE_FINISHED_SCRIPT "G0 X-79 Y124 Z50\nG0 X-79 Y124 Z19.5\nG0 X-79 Y124 Z50\nG0 X0 Y0 Z100"
/** Set 1 if you need a hot extruder for good probe results. Normally only required if nozzle is probe. */
=======
#define Z_PROBE_RUN_AFTER_EVERY_PROBE ""
>>>>>>> refs/heads/master
#define Z_PROBE_REQUIRES_HEATING 0
#define Z_PROBE_MIN_TEMPERATURE 150
<<<<<<< HEAD

/*
Define how we measure the bed rotation. 
All methods need at least 3 points to define the bed rotation correctly. The quality we get comes
from the selection of the right points and method.

BED_LEVELING_METHOD 0
This method measures at the 3 probe points and creates a plane through these points. If you have
a really planar bed this gives the optimum result. The 3 points must not be in one line and have
a long distance to increase numerical stability.

BED_LEVELING_METHOD 1
This measures a grid. Probe point 1 is the origin and points 2 and 3 span a grid. We measure
BED_LEVELING_GRID_SIZE points in each direction and compute a regression plane through all
points. This gives a good overall plane if you have small bumps measuring inaccuracies.

BED_LEVELING_METHOD 2
Bending correcting 4 point measurement. This is for cantilevered beds that have the rotation axis
not at the side but inside the bed. Here we can assume no bending on the axis and a symmetric
bending to both sides of the axis. So probe points 2 and 3 build the symmetric axis and
point 1 is mirrored to 1m across the axis. Using the symmetry we then remove the bending
from 1 and use that as plane.
*/
// SB #define BED_LEVELING_METHOD 0
=======
#define FEATURE_AUTOLEVEL 0
#define FEATURE_SOFTWARE_LEVELING 0
#define Z_PROBE_X1 20
#define Z_PROBE_Y1 20
#define Z_PROBE_X2 160
#define Z_PROBE_Y2 20
#define Z_PROBE_X3 100
#define Z_PROBE_Y3 160
>>>>>>> refs/heads/master
#define BED_LEVELING_METHOD 0
#define BED_CORRECTION_METHOD 0
#define BED_LEVELING_GRID_SIZE 5
#define BED_LEVELING_REPETITIONS 5
#define BED_MOTOR_1_X 0
#define BED_MOTOR_1_Y 0
#define BED_MOTOR_2_X 200
#define BED_MOTOR_2_Y 0
#define BED_MOTOR_3_X 100
#define BED_MOTOR_3_Y 200
<<<<<<< HEAD

/* Autoleveling allows it to z-probe 3 points to compute the inclination and compensates the error for the print.
   This feature requires a working z-probe and you should have z-endstop at the top not at the bottom.
   The same 3 points are used for the G29 command.
*/
// SB #define FEATURE_AUTOLEVEL 0
// SB #define Z_PROBE_X1 100
// SB #define Z_PROBE_Y1 20
// SB #define Z_PROBE_X2 160
// SB #define Z_PROBE_Y2 170
// SB #define Z_PROBE_X3 20
// SB #define Z_PROBE_Y3 170

// SB Valori per un raggio di 135
#define FEATURE_AUTOLEVEL true
#define Z_PROBE_X1 -116.913
#define Z_PROBE_Y1 -67.5
#define Z_PROBE_X2 116.913
#define Z_PROBE_Y2 -67.5
#define Z_PROBE_X3 0
#define Z_PROBE_Y3 135
/* Bending correction adds a value to a measured z-probe value. This may be
  required when the z probe needs some force to trigger and this bends the
  bed down. Currently the correction values A/B/C correspond to z probe
  positions 1/2/3. In later versions a bending correction algorithm might be
  introduced to give it other meanings.*/
=======
>>>>>>> refs/heads/master
#define BENDING_CORRECTION_A 0
#define BENDING_CORRECTION_B 0
#define BENDING_CORRECTION_C 0
<<<<<<< HEAD

/* DISTORTION_CORRECTION compensates the distortion caused by mechanical imprecisions of nonlinear (i.e. DELTA) printers
 * assumes that the floor is plain (i.e. glass plate)
 *     and that it is perpendicular to the towers
 *     and that the (0,0) is in center
 * requires z-probe
 * G33 measures the Z offset in matrix NxN points (due to nature of the delta printer, the corners are extrapolated instead of measured)
 * and compensate the distortion
 * more points means better compensation, but consumes more memory and takes more time
 * DISTORTION_CORRECTION_R is the distance of last row or column from center
 * SB requires #define EEPROM_MODE 1 or 2
 */

// SB #define DISTORTION_CORRECTION         1
#define DISTORTION_CORRECTION         1
// SB #define DISTORTION_CORRECTION_POINTS  5
#define DISTORTION_CORRECTION_POINTS  9
/** Max. distortion value to enter. Used to prevent dangerous errors with big values. */
#define DISTORTION_LIMIT_TO 2
/* For delta printers you simply define the measured radius around origin */
// SB #define DISTORTION_CORRECTION_R       80
#define DISTORTION_CORRECTION_R       112
/* For all others you define the correction rectangle by setting the min/max coordinates. Make sure the the probe can reach all points! */
// SB #define DISTORTION_XMIN 10
#define DISTORTION_XMIN -135
// SB #define DISTORTION_YMIN 10
#define DISTORTION_YMIN -135
// SB #define DISTORTION_XMAX 190
#define DISTORTION_XMAX 135
// SB #define DISTORTION_YMAX 190
#define DISTORTION_YMAX 135

/** Uses EEPROM instead of ram. Allows bigger matrix (up to 22x22) without any ram cost.
  Especially on arm based systems with cached EEPROM it is good, on AVR it has a small
  performance penalty.
*/
#define DISTORTION_PERMANENT          1
/** Correction computation is not a cheap operation and changes are only small. So it
is not necessary to update it for every sub-line computed. For example lets take DELTA_SEGMENTS_PER_SECOND_PRINT = 150
and fastest print speed 100 mm/s. So we have a maximum segment length of 100/150 = 0.66 mm.
Now lats say our point field is 200 x 200 mm with 9 x 9 points. So between 2 points we have
200 / (9-1) = 25 mm. So we need at least 25 / 0.66 = 37 lines to move to the next measuring
point. So updating correction every 15 calls gives us at least 2 updates between the
measured points.
NOTE: Explicit z changes will always trigger an update!
*/
#define DISTORTION_UPDATE_FREQUENCY   15
/** z distortion degrades to 0 from this height on. You should start after the first layer to get
best bonding with surface. */
#define DISTORTION_START_DEGRADE 0.5
/** z distortion correction gets down to 0 at this height. */
#define DISTORTION_END_HEIGHT 1.5
/** If your corners measurement points are not measurable with given radius, you can
set this to 1. It then omits the outer measurement points allowing a larger correction area.*/
// SB // #define DISTORTION_EXTRAPOLATE_CORNERS 0
// SB // It then set to 2 the outer measurement points to external radius.
// SB // #define DISTORTION_EXTRAPOLATE_CORNERS 2
#define DISTORTION_EXTRAPOLATE_CORNERS 1


/* If your printer is not exactly square but is more like a parallelogram, you can
use this to compensate the effect of printing squares like parallelograms. Set the
parameter to then tangents of the deviation from 90° when you print a square object.
E.g. if you angle is 91° enter tan(1) = 0.017. If error doubles you have the wrong sign.
Always hard to say since the other angle is 89° in this case!
*/
=======
>>>>>>> refs/heads/master
#define FEATURE_AXISCOMP 0
#define AXISCOMP_TANXY 0
#define AXISCOMP_TANYZ 0
#define AXISCOMP_TANXZ 0

#ifndef SDSUPPORT  // Some boards have sd support on board. These define the values already in pins.h
#define SDSUPPORT 1
#undef SDCARDDETECT
#define SDCARDDETECT ORIG_SDCARDDETECT
#undef SDCARDDETECTINVERTED
#define SDCARDDETECTINVERTED 0
#endif
#define SD_EXTENDED_DIR 1 /** Show extended directory including file length. Don't use this with Pronterface! */
#define SD_RUN_ON_STOP ""
#define SD_STOP_HEATER_AND_MOTORS_ON_STOP 1
#define ARC_SUPPORT 1
#define FEATURE_MEMORY_POSITION 1
#define FEATURE_CHECKSUM_FORCED 0
#define FEATURE_FAN_CONTROL 1
#define FEATURE_FAN2_CONTROL 0
#define FEATURE_CONTROLLER 21
#define ADC_KEYPAD_PIN -1
#define LANGUAGE_EN_ACTIVE 1
#define LANGUAGE_DE_ACTIVE 1
#define LANGUAGE_NL_ACTIVE 0
#define LANGUAGE_PT_ACTIVE 1
#define LANGUAGE_IT_ACTIVE 1
#define LANGUAGE_ES_ACTIVE 1
#define LANGUAGE_FI_ACTIVE 0
#define LANGUAGE_SE_ACTIVE 0
#define LANGUAGE_FR_ACTIVE 1
#define LANGUAGE_CZ_ACTIVE 0
#define LANGUAGE_PL_ACTIVE 0
#define LANGUAGE_TR_ACTIVE 0
#define LANGUAGE_RU_ACTIVE 0
#define UI_PRINTER_NAME "Stacker 500"
#define UI_PRINTER_COMPANY "Stacker LLC"
#define UI_PAGES_DURATION 4000
#define UI_SPEEDDEPENDENT_POSITIONING 0
#define UI_DISABLE_AUTO_PAGESWITCH 1
#define UI_AUTORETURN_TO_MENU_AFTER 30000
#define FEATURE_UI_KEYS 0
#define UI_ENCODER_SPEED 1
#define UI_REVERSE_ENCODER 0
#define UI_KEY_BOUNCETIME 10
#define UI_KEY_FIRST_REPEAT 500
#define UI_KEY_REDUCE_REPEAT 50
#define UI_KEY_MIN_REPEAT 50
#define FEATURE_BEEPER 1
#define CASE_LIGHTS_PIN -1
#define CASE_LIGHT_DEFAULT_ON 1
<<<<<<< HEAD

/** Set to false to disable SD support: */
#ifndef SDSUPPORT  // Some boards have SD support on board. These define the values already in pins.h
#define SDSUPPORT false
// Uncomment to enable or change card detection pin. With card detection the card is mounted on insertion.
#undef SDCARDDETECT
#define SDCARDDETECT -1
// Change to true if you get a inserted message on removal.
#define SDCARDDETECTINVERTED false
#endif
/** Show extended directory including file length. Don't use this with Pronterface! */
#define SD_EXTENDED_DIR 1
/** The GCODEs in this line get executed, when you stop a SD print before it was ended.
Separate commands by \n */
#define SD_RUN_ON_STOP ""
/** Disable motors and heaters when print was stopped. */
#define SD_STOP_HEATER_AND_MOTORS_ON_STOP 1

// If you want support for G2/G3 arc commands set to true, otherwise false.
#define ARC_SUPPORT 1

/** You can store the current position with M401 and go back to it with M402.
   This works only if feature is set to true. */
#define FEATURE_MEMORY_POSITION 1

/** If a checksum is sent, all future commands must also contain a checksum. Increases reliability especially for binary protocol. */
#define FEATURE_CHECKSUM_FORCED 0

/** Should support for fan control be compiled in. If you enable this make sure
the FAN pin is not the same as for your second extruder. RAMPS e.g. has FAN_PIN in 9 which
is also used for the heater if you have 2 extruders connected. */
#define FEATURE_FAN_CONTROL 1

/* You can have a second fan controlled by adding P1 to M106/M107 command. */
// SB #define FEATURE_FAN2_CONTROL 0
#define FEATURE_FAN2_CONTROL true
//#define FAN2_PIN ORIG_FAN2_PIN
#define FAN2_PIN 6

/* By setting FAN_BOARD_PIN to a pin number you get a board cooler. That fan 
goes on as soon as moves occur. Mainly to prevent overheating of stepper drivers. */
// SB //#undef FAN_BOARD_PIN
// SB //#define FAN_BOARD_PIN ORIG_FAN_PIN
#undef FAN_BOARD_PIN
#define FAN_BOARD_PIN 11
/** Speed of board fan when on. 0 = off, 255 = max */
// SB #define BOARD_FAN_SPEED 255
#define BOARD_FAN_SPEED 255
/* Speed when no cooling is required. Normally 0 but if you need slightly cooling
it can be set here */
#define BOARD_FAN_MIN_SPEED 0
/* You can have one additional fan controlled by a temperature. You can set
   set at which temperature it should turn on and at which it should reach max. speed.
*/
#define FAN_THERMO_PIN -1
#define FAN_THERMO_MIN_PWM 128
#define FAN_THERMO_MAX_PWM 255
#define FAN_THERMO_MIN_TEMP 45
#define FAN_THERMO_MAX_TEMP 60
// Analog pin number or channel for due boards
#define FAN_THERMO_THERMISTOR_PIN -1
#define FAN_THERMO_THERMISTOR_TYPE 1

/** The door pin is to detect a door opening. This will prevent new command
 from serial or sd card getting executed. It will not stop immediately. Instead
 it lets the move buffer run empty so closing the door allows continuing the print.
 The exact behavior might change in the future.
  */
 
#define DOOR_PIN -1
#define DOOR_PULLUP 1
#define DOOR_INVERTING 1

/** Adds support for ESP8266 Duet web interface, PanelDue and probably some other things. 
 * This essentially adds command M36/M408 and extends M20.
 * Since it requires some memory do not enable it unless you have such a display!
 *  */
#define FEATURE_JSON 0

/** For displays and keys there are too many permutations to handle them all in once.
For the most common available combinations you can set the controller type here, so
you don't need to configure uicong.h at all. Controller settings > 1 disable usage
of uiconfig.h

0 or NO_CONTROLLER = no display
1 or UICONFIG_CONTROLLER = Manual definition of display and keys parameter in uiconfig.h

The following settings override uiconfig.h!
2 or CONTROLLER_SMARTRAMPS = Smartcontroller from reprapdiscount on a RAMPS or RUMBA board
3 or CONTROLLER_ADAFRUIT = Adafruit RGB controller
4 or CONTROLLER_FOLTYN = Foltyn 3DMaster with display attached
5 or CONTROLLER_VIKI = ViKi LCD - Check pin configuration in ui.h for feature controller 5!!! sd card disabled by default!
6 or CONTROLLER_MEGATRONIC = ReprapWorld Keypad / LCD, predefined pins for Megatronics v2.0 and RAMPS 1.4. Please check if you have used the defined pin layout in ui.h.
7 or CONTROLLER_RADDS = RADDS Extension Port
8 or CONTROLLER_PIBOT20X4 = PiBot Display/Controller extension with 20x4 character display
9 or CONTROLLER_PIBOT16X2 = PiBot Display/Controller extension with 16x2 character display
10 or CONTROLLER_GADGETS3D_SHIELD = Gadgets3D shield on RAMPS 1.4, see http://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
11 or CONTROLLER_REPRAPDISCOUNT_GLCD = RepRapDiscount Full Graphic Smart Controller
12 or CONTROLLER_FELIX = FELIXPrinters Controller
13 or CONTROLLER_RAMBO = SeeMeCNC Display on Rambo (ORION)
14 or CONTROLLER_OPENHARDWARE_LCD2004 = OpenHardware.co.za LCD2004 V2014
15 or CONTROLLER_SANGUINOLOLU_PANELOLU2 = Sanguinololu + Panelolu2
16 or CONTROLLER_GAMEDUINO2 (in development)
17 or CONTROLLER_MIREGLI 17
18 or CONTROLLER_GATE_3NOVATICA Gate Controller from 3Novatica
21 or CONTROLLER_VIKI2 Panucatt VIKI2 graphic lcd
24 or CONTROLLER_ZONESTAR = Zonestar P802M with LCD 20x4 and 5 ADC button keypad
25 or CONTROLLER_ORCABOTXXLPRO2 
26 or CONTROLLER_AZSMZ_12864 
405 or CONTROLLER_FELIX_DUE Felix LCD für due based board
27 or CONTROLLER_REPRAPWORLD_GLCD = ReprapWorld Graphical LCD
*/

#define FEATURE_CONTROLLER NO_CONTROLLER

/* You can have one keypad connected via single analog pin as seen on
 some printers with Melzi V2.0 board, 20x4 LCD and 5 buttons keypad. This must be
 the analog pin number! */
#define ADC_KEYPAD_PIN -1

/**
Select the languages to use. On first startup user can select
the language from a menu with activated languages. In Configuration->Language
the language can be switched any time. 
On 8 bit processors do not active all or you run out of text memory (64kb)
and strange errors occur. 8-9 languages normally work.
*/
#define LANGUAGE_EN_ACTIVE 1 // English
#define LANGUAGE_DE_ACTIVE 1 // German
#define LANGUAGE_NL_ACTIVE 0 // Dutch
#define LANGUAGE_PT_ACTIVE 1 // Brazilian Portuguese
#define LANGUAGE_IT_ACTIVE 1 // Italian
#define LANGUAGE_ES_ACTIVE 1 // Spanish
#define LANGUAGE_FI_ACTIVE 0 // Finnish
#define LANGUAGE_SE_ACTIVE 0 // Swedish
#define LANGUAGE_FR_ACTIVE 1 // French
#define LANGUAGE_CZ_ACTIVE 0 // Czech
#define LANGUAGE_PL_ACTIVE 1 // Polish
#define LANGUAGE_TR_ACTIVE 1 // Turkish

/* Some displays loose their settings from time to time. Try uncommenting the
auto-repair function if this is the case. It is not supported for all display
types. It creates a minimal flicker from time to time and also slows down
computations, so do not enable it if your display works stable!
*/
//#define TRY_AUTOREPAIR_LCD_ERRORS

// This is line 2 of the status display at startup. Change to your like.
#define UI_PRINTER_NAME "MyPrinter"
#define UI_PRINTER_COMPANY "Self Made"


/** For graphic displays you can have a fixed top line. It can also contain
 * dynamic modifiers. Do not define it if you want full 6 rows of data */
//#define UI_HEAD "E1:%e0/%E0 E2:%e1/%E1 B:%eb/%Eb"

/** How many ms should a single page be shown, until it is switched to the next one.*/
#define UI_PAGES_DURATION 4000

/** Delay of start screen in milliseconds */
=======
>>>>>>> refs/heads/master
#define UI_START_SCREEN_DELAY 1000
#define UI_DYNAMIC_ENCODER_SPEED 1
        /**
Beeper sound definitions for short beeps during key actions
and longer beeps for important actions.
Parameter is delay in microseconds and the secons is the number of repetitions.
Values must be in range 1..255
*/
#define BEEPER_SHORT_SEQUENCE 2,2
#define BEEPER_LONG_SEQUENCE 8,8
#define UI_SET_MIN_HEATED_BED_TEMP  30
#define UI_SET_MAX_HEATED_BED_TEMP 120
#define UI_SET_MIN_EXTRUDER_TEMP   170
#define UI_SET_MAX_EXTRUDER_TEMP   280
#define UI_SET_EXTRUDER_FEEDRATE 2
#define UI_SET_EXTRUDER_RETRACT_DISTANCE 3


#define NUM_MOTOR_DRIVERS 0

#define DEBUG_ECHO_ASCII


#define MACHINE_TYPE "STACKER"
#define ALTERNATIVE_JERK
#define REDUCE_ON_SMALL_SEGMENTS
#define MAX_JERK_DISTANCE 0.8 
#define ZHOME_WAIT_UNSWING 500
#define BIG_OUTPUT_BUFFER // allows complete temperature line as output
#define CUSTOM_LOGO
#define LOGO_WIDTH 128
#define LOGO_HEIGHT 13
#define LOGO_BITMAP const unsigned char logo[] PROGMEM = {\
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\
0x0F, 0xFF, 0xF3, 0xFF, 0xF9, 0xFF, 0xFE, 0x7F, 0xFF, 0x9E, 0x0F, 0x87, 0xFF, 0xF7, 0xFF, 0xFC,\
0x1F, 0xFF, 0xF3, 0xFF, 0xF3, 0xFF, 0xFC, 0xFF, 0xFF, 0x3C, 0x1F, 0x07, 0xFF, 0xE7, 0xFF, 0xF8,\
0x1F, 0xFF, 0xE7, 0xFF, 0xF3, 0xFF, 0xFC, 0xFF, 0xFF, 0x3C, 0x3E, 0x0F, 0xFF, 0xEF, 0xFF, 0xF8,\
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00,\
0x38, 0x00, 0x00, 0x3C, 0x07, 0x80, 0x79, 0xE0, 0x00, 0x78, 0x00, 0x0E, 0x00, 0x0F, 0x00, 0xF8,\
0x3F, 0xFF, 0x80, 0x3C, 0x07, 0x3F, 0xF9, 0xE0, 0x00, 0x7B, 0xF8, 0x1F, 0xFF, 0x8F, 0x01, 0xF0,\
0x3F, 0xFF, 0xC0, 0x78, 0x0F, 0x7F, 0xF9, 0xC0, 0x00, 0x73, 0xF8, 0x1F, 0xFF, 0x8E, 0x7F, 0xE0,\
0x00, 0x03, 0xC0, 0x78, 0x0E, 0x00, 0x73, 0xC0, 0x00, 0xF0, 0x7C, 0x1E, 0x00, 0x1E, 0xFF, 0xC0,\
0x00, 0x03, 0xC0, 0x70, 0x0E, 0x00, 0xF3, 0xC0, 0x00, 0xF0, 0x3E, 0x3C, 0x00, 0x1E, 0xFF, 0xC0,\
0x7F, 0xFF, 0x80, 0xF0, 0x1E, 0x00, 0xF3, 0xFF, 0xFC, 0xF0, 0x1E, 0x3F, 0xFF, 0x9C, 0x07, 0xC0,\
0xFF, 0xFF, 0x00, 0xF0, 0x1E, 0x01, 0xE7, 0xFF, 0xFD, 0xE0, 0x1F, 0x3F, 0xFF, 0xBC, 0x03, 0xE0,\
0xFF, 0xFE, 0x01, 0xE0, 0x3E, 0x01, 0xE7, 0xFF, 0xF9, 0xE0, 0x0F, 0xBF, 0xFF, 0x3C, 0x01, 0xF0\
};

#if 0
Informations:

Extruder temperatures use a user defined table for ATC 104GT sensor. Here a adjustment to
real temperatures in nozzle is included. So in deviation to original temperature table these
temperatures are used:
-50 - 30: Original T
30-260: T-(T-30)*15/230
260-300: T-15

New table stops now at 285°C so max. settable temperature is 280°C
#endif

#endif

/* Below you will find the configuration string, that created this Configuration.h

========== Start configuration string ==========
{
    "editMode": 2,
    "processor": 0,
    "baudrate": 250000,
    "bluetoothSerial": -1,
    "bluetoothBaudrate": 115200,
    "xStepsPerMM": 72.72,
    "yStepsPerMM": 72.72,
    "zStepsPerMM": 520,
    "xInvert": "0",
    "x2Invert": 0,
    "xInvertEnable": "1",
    "eepromMode": 1,
    "yInvert": "1",
    "y2Invert": 0,
    "yInvertEnable": 0,
    "zInvert": "0",
    "z2Invert": 0,
    "z3Invert": 0,
    "z4Invert": 0,
    "zInvertEnable": "1",
    "extruder": [
        {
            "id": 0,
            "heatManager": 1,
            "pidDriveMin": 40,
            "pidDriveMax": 255,
            "pidMax": 255,
            "sensorType": 5,
            "sensorPin": "TEMP_0_PIN",
            "heaterPin": "HEATER_0_PIN",
            "maxFeedrate": 50,
            "startFeedrate": 20,
            "invert": "1",
            "invertEnable": "1",
            "acceleration": 5000,
            "watchPeriod": 1,
            "pidP": 8.94,
            "pidI": 0.51,
            "pidD": 20,
            "advanceK": 0,
            "advanceL": 0,
            "waitRetractTemp": 150,
            "waitRetractUnits": 0,
            "waitRetract": 0,
            "stepsPerMM": 255,
            "coolerPin": -1,
            "coolerSpeed": 255,
            "selectCommands": "",
            "deselectCommands": "",
            "xOffset": 0,
            "yOffset": 0,
            "zOffset": 0,
            "xOffsetSteps": 0,
            "yOffsetSteps": 0,
            "zOffsetSteps": 0,
            "stepper": {
                "name": "Extruder 0",
                "step": "ORIG_E0_STEP_PIN",
                "dir": "ORIG_E0_DIR_PIN",
                "enable": "ORIG_E0_ENABLE_PIN"
            },
            "advanceBacklashSteps": 0,
            "decoupleTestPeriod": 30,
            "jamPin": -1,
            "jamPullup": "0",
            "mirror": "0",
            "invert2": "0",
            "stepper2": {
                "name": "Extruder 0",
                "step": "ORIG_E0_STEP_PIN",
                "dir": "ORIG_E0_DIR_PIN",
                "enable": "ORIG_E0_ENABLE_PIN"
            },
            "preheat": 190
        },
        {
            "id": 1,
            "heatManager": 1,
            "pidDriveMin": 40,
            "pidDriveMax": 255,
            "pidMax": 255,
            "sensorType": 5,
            "sensorPin": "TEMP_2_PIN",
            "heaterPin": "HEATER_2_PIN",
            "maxFeedrate": 100,
            "startFeedrate": 40,
            "invert": "1",
            "invertEnable": "1",
            "acceleration": 5000,
            "watchPeriod": 1,
            "pidP": 8.94,
            "pidI": 0.51,
            "pidD": 20,
            "advanceK": 0,
            "advanceL": 0,
            "waitRetractTemp": 150,
            "waitRetractUnits": 0,
            "waitRetract": 0,
            "stepsPerMM": 257,
            "coolerPin": -1,
            "coolerSpeed": 255,
            "selectCommands": "",
            "deselectCommands": "",
            "xOffset": 0,
            "yOffset": 0,
            "zOffset": 0,
            "xOffsetSteps": 0,
            "yOffsetSteps": 0,
            "zOffsetSteps": 0,
            "stepper": {
                "name": "Extruder 1",
                "step": "ORIG_E1_STEP_PIN",
                "dir": "ORIG_E1_DIR_PIN",
                "enable": "ORIG_E1_ENABLE_PIN"
            },
            "advanceBacklashSteps": 0,
            "decoupleTestPeriod": 30,
            "jamPin": -1,
            "jamPullup": "0",
            "mirror": "0",
            "invert2": "0",
            "stepper2": {
                "name": "Extruder 1",
                "step": "ORIG_E1_STEP_PIN",
                "dir": "ORIG_E1_DIR_PIN",
                "enable": "ORIG_E1_ENABLE_PIN"
            },
            "preheat": 190
        },
        {
            "id": 2,
            "heatManager": 1,
            "pidDriveMin": 40,
            "pidDriveMax": 255,
            "pidMax": 255,
            "sensorType": 5,
            "sensorPin": "TEMP_3_PIN",
            "heaterPin": "HEATER_3_PIN",
            "maxFeedrate": 100,
            "startFeedrate": 40,
            "invert": "1",
            "invertEnable": "1",
            "acceleration": 5000,
            "watchPeriod": 1,
            "pidP": 8.94,
            "pidI": 0.51,
            "pidD": 20,
            "advanceK": 0,
            "advanceL": 0,
            "waitRetractTemp": 150,
            "waitRetractUnits": 0,
            "waitRetract": 0,
            "stepsPerMM": 257,
            "coolerPin": -1,
            "coolerSpeed": 255,
            "selectCommands": "",
            "deselectCommands": "",
            "xOffset": 0,
            "yOffset": 0,
            "zOffset": 0,
            "xOffsetSteps": 0,
            "yOffsetSteps": 0,
            "zOffsetSteps": 0,
            "stepper": {
                "name": "Extruder 2",
                "step": "ORIG_E2_STEP_PIN",
                "dir": "ORIG_E2_DIR_PIN",
                "enable": "ORIG_E2_ENABLE_PIN"
            },
            "advanceBacklashSteps": 0,
            "decoupleTestPeriod": 30,
            "jamPin": -1,
            "jamPullup": "0",
            "mirror": "0",
            "invert2": "0",
            "stepper2": {
                "name": "Extruder 2",
                "step": "ORIG_E2_STEP_PIN",
                "dir": "ORIG_E2_DIR_PIN",
                "enable": "ORIG_E2_ENABLE_PIN"
            },
            "preheat": 190
        },
        {
            "id": 3,
            "heatManager": 1,
            "pidDriveMin": 40,
            "pidDriveMax": 255,
            "pidMax": 255,
            "sensorType": 5,
            "sensorPin": "TEMP_4_PIN",
            "heaterPin": "HEATER_4_PIN",
            "maxFeedrate": 100,
            "startFeedrate": 40,
            "invert": "1",
            "invertEnable": "1",
            "acceleration": 5000,
            "watchPeriod": 1,
            "pidP": 8.94,
            "pidI": 0.51,
            "pidD": 20,
            "advanceK": 0,
            "advanceL": 0,
            "waitRetractTemp": 150,
            "waitRetractUnits": 0,
            "waitRetract": 0,
            "stepsPerMM": 257,
            "coolerPin": -1,
            "coolerSpeed": 255,
            "selectCommands": "",
            "deselectCommands": "",
            "xOffset": 0,
            "yOffset": 0,
            "zOffset": 0,
            "xOffsetSteps": 0,
            "yOffsetSteps": 0,
            "zOffsetSteps": 0,
            "stepper": {
                "name": "Extruder 3",
                "step": "ORIG_E3_STEP_PIN",
                "dir": "ORIG_E3_DIR_PIN",
                "enable": "ORIG_E3_ENABLE_PIN"
            },
            "advanceBacklashSteps": 0,
            "decoupleTestPeriod": 30,
            "jamPin": -1,
            "jamPullup": "0",
            "mirror": "0",
            "invert2": "0",
            "stepper2": {
                "name": "Extruder 3",
                "step": "ORIG_E3_STEP_PIN",
                "dir": "ORIG_E3_DIR_PIN",
                "enable": "ORIG_E3_ENABLE_PIN"
            },
            "preheat": 190
        }
    ],
    "uiLanguage": 0,
    "uiController": 0,
    "xMinEndstop": 1,
    "yMinEndstop": 1,
    "zMinEndstop": 1,
    "xMaxEndstop": 1,
    "yMaxEndstop": 1,
    "zMaxEndstop": 1,
    "x2MinEndstop": 0,
    "y2MinEndstop": 0,
    "x2MaxEndstop": 0,
    "y2MaxEndstop": 0,
    "motherboard": 35,
    "driveSystem": 0,
    "xMaxSpeed": 200,
    "xHomingSpeed": 40,
    "xTravelAcceleration": 1000,
    "xPrintAcceleration": 1000,
    "yMaxSpeed": 200,
    "yHomingSpeed": 40,
    "yTravelAcceleration": 1000,
    "yPrintAcceleration": 1000,
    "zMaxSpeed": 80,
    "zHomingSpeed": 40,
    "zTravelAcceleration": 50,
    "zPrintAcceleration": 50,
    "xMotor": {
        "name": "X motor",
        "step": "ORIG_X_STEP_PIN",
        "dir": "ORIG_X_DIR_PIN",
        "enable": "ORIG_X_ENABLE_PIN"
    },
    "yMotor": {
        "name": "Y motor",
        "step": "ORIG_Y_STEP_PIN",
        "dir": "ORIG_Y_DIR_PIN",
        "enable": "ORIG_Y_ENABLE_PIN"
    },
    "zMotor": {
        "name": "Z motor",
        "step": "ORIG_Z_STEP_PIN",
        "dir": "ORIG_Z_DIR_PIN",
        "enable": "ORIG_Z_ENABLE_PIN"
    },
    "enableBacklash": "1",
    "backlashX": 0,
    "backlashY": 0,
    "backlashZ": 0,
    "stepperInactiveTime": 360,
    "maxInactiveTime": 0,
    "xMinPos": 0,
    "yMinPos": 0,
    "zMinPos": 0,
    "xLength": 418,
    "yLength": 240,
    "zLength": 210,
    "alwaysCheckEndstops": "1",
    "disableX": "0",
    "disableY": "0",
    "disableZ": "0",
    "disableE": "0",
    "xHomeDir": "-1",
    "yHomeDir": "-1",
    "zHomeDir": "-1",
    "xEndstopBack": 1,
    "yEndstopBack": 1,
    "zEndstopBack": 0,
    "deltaSegmentsPerSecondPrint": 180,
    "deltaSegmentsPerSecondTravel": 70,
    "deltaDiagonalRod": 445,
    "deltaHorizontalRadius": 209.25,
    "deltaAlphaA": 210,
    "deltaAlphaB": 330,
    "deltaAlphaC": 90,
    "deltaDiagonalCorrA": 0,
    "deltaDiagonalCorrB": 0,
    "deltaDiagonalCorrC": 0,
    "deltaMaxRadius": 150,
    "deltaFloorSafetyMarginMM": 15,
    "deltaRadiusCorrA": 0,
    "deltaRadiusCorrB": 0,
    "deltaRadiusCorrC": 0,
    "deltaXOffsetSteps": 0,
    "deltaYOffsetSteps": 0,
    "deltaZOffsetSteps": 0,
    "deltaSegmentsPerLine": 24,
    "stepperHighDelay": 0,
    "directionDelay": 0,
    "stepDoublerFrequency": 12000,
    "allowQuadstepping": "1",
    "doubleStepDelay": 1,
    "maxJerk": 25,
    "maxZJerk": 0.3,
    "moveCacheSize": 24,
    "moveCacheLow": 10,
    "lowTicksPerMove": 250000,
    "enablePowerOnStartup": "1",
    "echoOnExecute": "1",
    "sendWaits": "1",
    "ackWithLineNumber": "1",
    "killMethod": 1,
    "useAdvance": "1",
    "useQuadraticAdvance": "0",
    "powerInverting": 0,
    "mirrorX": 0,
    "mirrorXMotor": {
        "name": "Extruder 1",
        "step": "ORIG_E1_STEP_PIN",
        "dir": "ORIG_E1_DIR_PIN",
        "enable": "ORIG_E1_ENABLE_PIN"
    },
    "mirrorY": 0,
    "mirrorYMotor": {
        "name": "Extruder 1",
        "step": "ORIG_E1_STEP_PIN",
        "dir": "ORIG_E1_DIR_PIN",
        "enable": "ORIG_E1_ENABLE_PIN"
    },
    "mirrorZ": 0,
    "mirrorZMotor": {
        "name": "Extruder 1",
        "step": "ORIG_E1_STEP_PIN",
        "dir": "ORIG_E1_DIR_PIN",
        "enable": "ORIG_E1_ENABLE_PIN"
    },
    "mirrorZ3": "0",
    "mirrorZ3Motor": {
        "name": "Extruder 2",
        "step": "ORIG_E2_STEP_PIN",
        "dir": "ORIG_E2_DIR_PIN",
        "enable": "ORIG_E2_ENABLE_PIN"
    },
    "mirrorZ4": "0",
    "mirrorZ4Motor": {
        "name": "Extruder 3",
        "step": "ORIG_E3_STEP_PIN",
        "dir": "ORIG_E3_DIR_PIN",
        "enable": "ORIG_E3_ENABLE_PIN"
    },
    "dittoPrinting": "1",
    "featureServos": "0",
    "servo0Pin": 11,
    "servo1Pin": -1,
    "servo2Pin": -1,
    "servo3Pin": -1,
    "featureWatchdog": "1",
    "hasHeatedBed": "1",
    "enableZProbing": "0",
    "extrudeMaxLength": 160,
    "homeOrder": "HOME_ORDER_XYZ",
    "featureController": 21,
    "uiPrinterName": "Stacker 500",
    "uiPrinterCompany": "Stacker LLC",
    "uiPagesDuration": 4000,
    "uiHeadline": "",
    "uiDisablePageswitch": "1",
    "uiAutoReturnAfter": 30000,
    "featureKeys": "0",
    "uiEncoderSpeed": 1,
    "uiReverseEncoder": "0",
    "uiKeyBouncetime": 10,
    "uiKeyFirstRepeat": 500,
    "uiKeyReduceRepeat": 50,
    "uiKeyMinRepeat": 50,
    "featureBeeper": "1",
    "uiMinHeatedBed": 30,
    "uiMaxHeatedBed": 120,
    "uiMinEtxruderTemp": 170,
    "uiMaxExtruderTemp": 280,
    "uiExtruderFeedrate": 2,
    "uiExtruderRetractDistance": 3,
    "uiSpeeddependentPositioning": "0",
    "maxBedTemperature": 120,
    "bedSensorType": 8,
    "bedSensorPin": "TEMP_1_PIN",
    "bedHeaterPin": "HEATER_1_PIN",
    "bedHeatManager": 1,
    "bedPreheat": 55,
    "bedUpdateInterval": 5000,
    "bedPidDriveMin": 80,
    "bedPidDriveMax": 255,
    "bedPidP": 196,
    "bedPidI": 33,
    "bedPidD": 290,
    "bedPidMax": 255,
    "bedDecoupleTestPeriod": 300,
    "caseLightPin": -1,
    "caseLightDefaultOn": "1",
    "bedSkipIfWithin": 3,
    "gen1T0": 25,
    "gen1R0": 100000,
    "gen1Beta": 4036,
    "gen1MinTemp": -20,
    "gen1MaxTemp": 300,
    "gen1R1": 0,
    "gen1R2": 4700,
    "gen2T0": 25,
    "gen2R0": 100000,
    "gen2Beta": 4036,
    "gen2MinTemp": -20,
    "gen2MaxTemp": 300,
    "gen2R1": 0,
    "gen2R2": 4700,
    "gen3T0": 25,
    "gen3R0": 100000,
    "gen3Beta": 4036,
    "gen3MinTemp": -20,
    "gen3MaxTemp": 300,
    "gen3R1": 0,
    "gen3R2": 4700,
    "userTable0": {
        "r1": 0,
        "r2": 4700,
        "temps": [
            {
                "t": 1000,
                "r": 0,
                "adc": 0
            },
            {
                "t": 285,
                "r": 80.65,
                "adc": 69.0830221832
            },
            {
                "t": 275,
                "r": 93,
                "adc": 79.4564990611
            },
            {
                "t": 265,
                "r": 107.9,
                "adc": 91.9009338797
            },
            {
                "t": 255,
                "r": 125.8,
                "adc": 106.749347258
            },
            {
                "t": 245,
                "r": 147.5,
                "adc": 124.602888087
            },
            {
                "t": 235.7,
                "r": 174,
                "adc": 146.18998769
            },
            {
                "t": 226.3,
                "r": 206.5,
                "adc": 172.346377255
            },
            {
                "t": 217,
                "r": 246.8,
                "adc": 204.302983747
            },
            {
                "t": 207.6,
                "r": 296.9,
                "adc": 243.311953411
            },
            {
                "t": 198.3,
                "r": 359.7,
                "adc": 291.118346938
            },
            {
                "t": 188.9,
                "r": 439.3,
                "adc": 350.034732357
            },
            {
                "t": 179.6,
                "r": 540.6,
                "adc": 422.424340724
            },
            {
                "t": 170.2,
                "r": 671.4,
                "adc": 511.855940723
            },
            {
                "t": 160.9,
                "r": 841.4,
                "adc": 621.780236041
            },
            {
                "t": 151.5,
                "r": 1064,
                "adc": 755.912560722
            },
            {
                "t": 142.2,
                "r": 1360,
                "adc": 919.00990099
            },
            {
                "t": 123.5,
                "r": 2298,
                "adc": 1344.71420406
            },
            {
                "t": 67.4,
                "r": 15440,
                "adc": 3139.36444886
            },
            {
                "t": 58,
                "r": 22510,
                "adc": 3387.66813671
            },
            {
                "t": 48.7,
                "r": 33490,
                "adc": 3591.03299293
            },
            {
                "t": 39.3,
                "r": 50960,
                "adc": 3749.21307941
            },
            {
                "t": 30,
                "r": 79360,
                "adc": 3866.0385439
            },
            {
                "t": 20,
                "r": 126800,
                "adc": 3948.63878327
            },
            {
                "t": 10,
                "r": 208600,
                "adc": 4004.76793249
            },
            {
                "t": 0,
                "r": 353700,
                "adc": 4041.29882812
            },
            {
                "t": -10,
                "r": 620000,
                "adc": 4064.19081159
            },
            {
                "t": -30,
                "r": 2132000,
                "adc": 4085.99241822
            },
            {
                "t": -50,
                "r": 8743000,
                "adc": 4092.79982167
            }
        ],
        "numEntries": 29
    },
    "userTable1": {
        "r1": 0,
        "r2": 4700,
        "temps": [],
        "numEntries": 0
    },
    "userTable2": {
        "r1": 0,
        "r2": 4700,
        "temps": [],
        "numEntries": 0
    },
    "tempHysteresis": 0,
    "pidControlRange": 20,
    "skipM109Within": 2,
    "extruderFanCoolTemp": 50,
    "minTemp": 150,
    "maxTemp": 280,
    "minDefectTemp": -10,
    "maxDefectTemp": 300,
    "arcSupport": "1",
    "featureMemoryPositionWatchdog": "1",
    "forceChecksum": "0",
    "sdExtendedDir": "1",
    "featureFanControl": "1",
    "fanPin": "ORIG_FAN_PIN",
    "featureFan2Control": "0",
    "fan2Pin": "ORIG_FAN2_PIN",
    "fanThermoPin": -1,
    "fanThermoMinPWM": 128,
    "fanThermoMaxPWM": 255,
    "fanThermoMinTemp": 45,
    "fanThermoMaxTemp": 60,
    "fanThermoThermistorPin": -1,
    "fanThermoThermistorType": 1,
    "scalePidToMax": 0,
    "zProbePin": -1,
    "zProbeBedDistance": 10,
    "zProbeDisableHeaters": "0",
    "zProbePullup": "0",
    "zProbeOnHigh": "0",
    "zProbeXOffset": 0,
    "zProbeYOffset": 0,
    "zProbeWaitBeforeTest": "0",
    "zProbeSpeed": 2,
    "zProbeXYSpeed": 150,
    "zProbeHeight": 40,
    "zProbeStartScript": "",
    "zProbeFinishedScript": "",
    "featureAutolevel": "0",
    "zProbeX1": 20,
    "zProbeY1": 20,
    "zProbeX2": 160,
    "zProbeY2": 20,
    "zProbeX3": 100,
    "zProbeY3": 160,
    "zProbeSwitchingDistance": 1,
    "zProbeRepetitions": 1,
    "zProbeMedian": "0",
    "zProbeEveryPoint": "",
    "sdSupport": "1",
    "sdCardDetectPin": "ORIG_SDCARDDETECT",
    "sdCardDetectInverted": "0",
    "uiStartScreenDelay": 1000,
    "xEndstopBackMove": 6,
    "yEndstopBackMove": 6,
    "zEndstopBackMove": 6,
    "xEndstopRetestFactor": 3,
    "yEndstopRetestFactor": 3,
    "zEndstopRetestFactor": 6,
    "xMinPin": "ORIG_X_MIN_PIN",
    "yMinPin": "ORIG_Y_MIN_PIN",
    "zMinPin": "ORIG_Z_MIN_PIN",
    "xMaxPin": "ORIG_X_MAX_PIN",
    "yMaxPin": "ORIG_Y_MAX_PIN",
    "zMaxPin": "ORIG_Z_MAX_PIN",
    "x2MinPin": -1,
    "y2MinPin": -1,
    "x2MaxPin": -1,
    "y2MaxPin": -1,
    "deltaHomeOnPower": "0",
    "fanBoardPin": "ORIG_FAN_PIN",
    "heaterPWMSpeed": 0,
    "featureBabystepping": "1",
    "babystepMultiplicator": 1,
    "pdmForHeater": "0",
    "pdmForCooler": "0",
    "psOn": -1,
    "mixingExtruder": "0",
    "decouplingTestMaxHoldVariance": 20,
    "decouplingTestMinTempRise": 1,
    "featureAxisComp": "0",
    "axisCompTanXY": 0,
    "axisCompTanXZ": 0,
    "axisCompTanYZ": 0,
    "retractOnPause": 4,
    "pauseStartCommands": "",
    "pauseEndCommands": "",
    "distortionCorrection": "0",
    "distortionCorrectionPoints": 5,
    "distortionCorrectionR": 100,
    "distortionPermanent": "1",
    "distortionUpdateFrequency": 15,
    "distortionStartDegrade": 0.5,
    "distortionEndDegrade": 1,
    "distortionExtrapolateCorners": "0",
    "distortionXMin": 10,
    "distortionXMax": 190,
    "distortionYMin": 10,
    "distortionYMax": 190,
    "sdRunOnStop": "",
    "sdStopHeaterMotorsOnStop": "1",
    "featureRetraction": "1",
    "autoretractEnabled": "0",
    "retractionLength": 2.5,
    "retractionLongLength": 2.5,
    "retractionSpeed": 50,
    "retractionZLift": 0,
    "retractionUndoExtraLength": 0,
    "retractionUndoExtraLongLength": 0,
    "retractionUndoSpeed": 40,
    "filamentChangeXPos": 0,
    "filamentChangeYPos": 0,
    "filamentChangeZAdd": 2,
    "filamentChangeRehome": 1,
    "filamentChangeShortRetract": 5,
    "filamentChangeLongRetract": 50,
    "fanKickstart": 200,
    "servo0StartPos": -1,
    "servo1StartPos": -1,
    "servo2StartPos": -1,
    "servo3StartPos": -1,
    "uiDynamicEncoderSpeed": "1",
    "uiServoControl": 0,
    "killIfSensorDefect": "1",
    "jamSteps": 220,
    "jamSlowdownSteps": 320,
    "jamSlowdownTo": 70,
    "jamErrorSteps": 500,
    "jamMinSteps": 10,
    "jamAction": 1,
    "jamMethod": 1,
    "primaryPort": 0,
    "numMotorDrivers": 0,
    "motorDrivers": [
        {
            "t": "None",
            "s": "",
            "invertEnable": "0",
            "invertDirection": "0",
            "stepsPerMM": 100,
            "speed": 10,
            "dirPin": -1,
            "stepPin": -1,
            "enablePin": -1,
            "endstopPin": -1,
            "invertEndstop": "0",
            "minEndstop": "1",
            "endstopPullup": "1",
            "maxDistance": 20
        },
        {
            "t": "None",
            "s": "",
            "invertEnable": "0",
            "invertDirection": "0",
            "stepsPerMM": 100,
            "speed": 10,
            "dirPin": -1,
            "stepPin": -1,
            "enablePin": -1,
            "endstopPin": -1,
            "invertEndstop": "0",
            "minEndstop": "1",
            "endstopPullup": "1",
            "maxDistance": 20
        },
        {
            "t": "None",
            "s": "",
            "invertEnable": "0",
            "invertDirection": "0",
            "stepsPerMM": 100,
            "speed": 10,
            "dirPin": -1,
            "stepPin": -1,
            "enablePin": -1,
            "endstopPin": -1,
            "invertEndstop": "0",
            "minEndstop": "1",
            "endstopPullup": "1",
            "maxDistance": 20
        },
        {
            "t": "None",
            "s": "",
            "invertEnable": "0",
            "invertDirection": "0",
            "stepsPerMM": 100,
            "speed": 10,
            "dirPin": -1,
            "stepPin": -1,
            "enablePin": -1,
            "endstopPin": -1,
            "invertEndstop": "0",
            "minEndstop": "1",
            "endstopPullup": "1",
            "maxDistance": 20
        },
        {
            "t": "None",
            "s": "",
            "invertEnable": "0",
            "invertDirection": "0",
            "stepsPerMM": 100,
            "speed": 10,
            "dirPin": -1,
            "stepPin": -1,
            "enablePin": -1,
            "endstopPin": -1,
            "invertEndstop": "0",
            "minEndstop": "1",
            "endstopPullup": "1",
            "maxDistance": 20
        },
        {
            "t": "None",
            "s": "",
            "invertEnable": "0",
            "invertDirection": "0",
            "stepsPerMM": 100,
            "speed": 10,
            "dirPin": -1,
            "stepPin": -1,
            "enablePin": -1,
            "endstopPin": -1,
            "invertEndstop": "0",
            "minEndstop": "1",
            "endstopPullup": "1",
            "maxDistance": 20
        }
    ],
    "manualConfig": "#define DEBUG_ECHO_ASCII\n\n\n#define MACHINE_TYPE \"STACKER\"\n#define ALTERNATIVE_JERK\n#define REDUCE_ON_SMALL_SEGMENTS\n#define MAX_JERK_DISTANCE 0.8 \n#define ZHOME_WAIT_UNSWING 500\n#define BIG_OUTPUT_BUFFER \/\/ allows complete temperature line as output\n#define CUSTOM_LOGO\n#define LOGO_WIDTH 128\n#define LOGO_HEIGHT 13\n#define LOGO_BITMAP const unsigned char logo[] PROGMEM = {\\\n0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,\\\n0x0F, 0xFF, 0xF3, 0xFF, 0xF9, 0xFF, 0xFE, 0x7F, 0xFF, 0x9E, 0x0F, 0x87, 0xFF, 0xF7, 0xFF, 0xFC,\\\n0x1F, 0xFF, 0xF3, 0xFF, 0xF3, 0xFF, 0xFC, 0xFF, 0xFF, 0x3C, 0x1F, 0x07, 0xFF, 0xE7, 0xFF, 0xF8,\\\n0x1F, 0xFF, 0xE7, 0xFF, 0xF3, 0xFF, 0xFC, 0xFF, 0xFF, 0x3C, 0x3E, 0x0F, 0xFF, 0xEF, 0xFF, 0xF8,\\\n0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00,\\\n0x38, 0x00, 0x00, 0x3C, 0x07, 0x80, 0x79, 0xE0, 0x00, 0x78, 0x00, 0x0E, 0x00, 0x0F, 0x00, 0xF8,\\\n0x3F, 0xFF, 0x80, 0x3C, 0x07, 0x3F, 0xF9, 0xE0, 0x00, 0x7B, 0xF8, 0x1F, 0xFF, 0x8F, 0x01, 0xF0,\\\n0x3F, 0xFF, 0xC0, 0x78, 0x0F, 0x7F, 0xF9, 0xC0, 0x00, 0x73, 0xF8, 0x1F, 0xFF, 0x8E, 0x7F, 0xE0,\\\n0x00, 0x03, 0xC0, 0x78, 0x0E, 0x00, 0x73, 0xC0, 0x00, 0xF0, 0x7C, 0x1E, 0x00, 0x1E, 0xFF, 0xC0,\\\n0x00, 0x03, 0xC0, 0x70, 0x0E, 0x00, 0xF3, 0xC0, 0x00, 0xF0, 0x3E, 0x3C, 0x00, 0x1E, 0xFF, 0xC0,\\\n0x7F, 0xFF, 0x80, 0xF0, 0x1E, 0x00, 0xF3, 0xFF, 0xFC, 0xF0, 0x1E, 0x3F, 0xFF, 0x9C, 0x07, 0xC0,\\\n0xFF, 0xFF, 0x00, 0xF0, 0x1E, 0x01, 0xE7, 0xFF, 0xFD, 0xE0, 0x1F, 0x3F, 0xFF, 0xBC, 0x03, 0xE0,\\\n0xFF, 0xFE, 0x01, 0xE0, 0x3E, 0x01, 0xE7, 0xFF, 0xF9, 0xE0, 0x0F, 0xBF, 0xFF, 0x3C, 0x01, 0xF0\\\n};\n\n#if 0\nInformations:\n\nExtruder temperatures use a user defined table for ATC 104GT sensor. Here a adjustment to\nreal temperatures in nozzle is included. So in deviation to original temperature table these\ntemperatures are used:\n-50 - 30: Original T\n30-260: T-(T-30)*15\/230\n260-300: T-15\n\nNew table stops now at 285\u00b0C so max. settable temperature is 280\u00b0C\n#endif",
    "zHomeMinTemperature": 0,
    "zHomeXPos": 999999,
    "zHomeYPos": 999999,
    "zHomeHeatHeight": 20,
    "zHomeHeatAll": "1",
    "zProbeZOffsetMode": 0,
    "zProbeZOffset": 0,
    "zProbeDelay": 0,
    "uiBedCoating": "0",
    "langEN": "1",
    "langDE": "1",
    "langNL": "0",
    "langPT": "1",
    "langIT": "1",
    "langES": "1",
    "langFI": "0",
    "langSE": "0",
    "langFR": "1",
    "langCZ": "0",
    "langPL": "0",
    "langTR": "0",
    "langRU": "0",
    "interpolateAccelerationWithZ": 0,
    "accelerationFactorTop": 100,
    "bendingCorrectionA": 0,
    "bendingCorrectionB": 0,
    "bendingCorrectionC": 0,
    "preventZDisableOnStepperTimeout": "1",
    "supportLaser": "0",
    "laserPin": -1,
    "laserOnHigh": "1",
    "laserWarmupTime": 0,
    "defaultPrinterMode": 0,
    "laserPwmMax": 255,
    "laserWatt": 2,
    "supportCNC": "0",
    "cncWaitOnEnable": 300,
    "cncWaitOnDisable": 0,
    "cncEnablePin": -1,
    "cncEnableWith": "1",
    "cncDirectionPin": -1,
    "cncDirectionCW": "1",
    "cncPwmMax": 255,
    "cncRpmMax": 8000,
    "cncSafeZ": 150,
    "startupGCode": "",
    "jsonOutput": "1",
    "bedLevelingMethod": 0,
    "bedCorrectionMethod": 0,
    "bedLevelingGridSize": 5,
    "bedLevelingRepetitions": 5,
    "bedMotor1X": 0,
    "bedMotor1Y": 0,
    "bedMotor2X": 200,
    "bedMotor2Y": 0,
    "bedMotor3X": 100,
    "bedMotor3Y": 200,
    "zProbeRequiresHeating": "0",
    "zProbeMinTemperature": 150,
    "adcKeypadPin": -1,
    "sharedExtruderHeater": "0",
    "extruderSwitchXYSpeed": 100,
    "dualXAxis": "0",
    "boardFanSpeed": 255,
    "keepAliveInterval": 2000,
    "moveXWhenHomed": "0",
    "moveYWhenHomed": "0",
    "moveZWhenHomed": "0",
    "preheatTime": 30000,
    "multiZEndstopHoming": "0",
    "z2MinMaxPin": -1,
    "z2MinMaxEndstop": 0,
    "extruderIsZProbe": "0",
    "boardFanMinSpeed": 0,
    "doorPin": -1,
    "doorEndstop": 1,
    "zhomePreRaise": 0,
    "zhomePreRaiseDistance": 10,
    "dualXResolution": "0",
    "x2axisStepsPerMM": 100,
    "coolerPWMSpeed": 0,
    "maxFanPWM": 255,
    "raiseZOnToolchange": 0,
    "distortionLimitTo": 2,
    "automaticPowerup": 0,
    "hasTMC2130": "0",
    "TMC2130Sensorless": "0",
    "TMC2130Steathchop": "1",
    "TMC2130Interpolate256": "1",
    "TMC2130StallguardSensitivity": 0,
    "TMC2130PWMAmpl": 255,
    "TMC2130PWMGrad": 1,
    "TMC2130PWMAutoscale": "1",
    "TMC2130PWMFreq": 2,
    "TMC2130CSX": -1,
    "TMC2130CSY": -1,
    "TMC2130CSZ": -1,
    "TMC2130CSE0": -1,
    "TMC2130CSE1": -1,
    "TMC2130CSE2": -1,
    "TMC2130CurrentX": 1000,
    "TMC2130CurrentY": 1000,
    "TMC2130CurrentZ": 1000,
    "TMC2130CurrentE0": 1000,
    "TMC2130CurrentE1": 1000,
    "TMC2130CurrentE2": 1000,
    "TMC2130CoolstepTresholdX": 300,
    "TMC2130CoolstepTresholdY": 300,
    "TMC2130CoolstepTresholdZ": 300,
    "microstepX": 16,
    "microstepY": 16,
    "microstepZ": 16,
    "microstepE0": 16,
    "microstepE1": 16,
    "microstepE2": 16,
    "parkPosX": 0,
    "parkPosY": 200,
    "parkPosZ": 10,
    "emergencyParser": 1,
    "hostRescue": "1",
    "MAX31855SwCS": -1,
    "MAX31855SwCLK": -1,
    "tempGain": "1",
    "uiAnimation": "0",
    "uiPresetBedTempPLA": 60,
    "uiPresetBedABS": 110,
    "uiPresetExtruderPLA": 190,
    "uiPresetExtruderABS": 240,
    "interpolateZAxis": "1",
    "zAccelerationTop": 30,
    "maxHalfstepInterval": 1999,
    "hasMAX6675": false,
    "hasMAX31855": false,
    "hasGeneric1": false,
    "hasGeneric2": false,
    "hasGeneric3": false,
    "hasUser0": true,
    "hasUser1": false,
    "hasUser2": false,
    "numExtruder": 4,
    "version": 100.4,
    "primaryPortName": "",
    "hasMAX31855SW": false
}
========== End configuration string ==========

*/
