/** @file
 *  @brief MAVLink comm protocol generated from roadrunner.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_ROADRUNNER_H
#define MAVLINK_ROADRUNNER_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_ROADRUNNER.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{1, 61, 28, 0, 0, 0}, {2, 56, 40, 0, 0, 0}, {3, 182, 32, 0, 0, 0}, {4, 176, 32, 0, 0, 0}, {5, 254, 13, 0, 0, 0}, {6, 3, 6, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_ROADRUNNER

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_gyro_acc_temp.h"
#include "./mavlink_msg_position.h"
#include "./mavlink_msg_quaternion.h"
#include "./mavlink_msg_tdoa_measurement.h"
#include "./mavlink_msg_tdoa_anchor.h"
#include "./mavlink_msg_tdoa_measurement_short.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_GYRO_ACC_TEMP, MAVLINK_MESSAGE_INFO_POSITION, MAVLINK_MESSAGE_INFO_QUATERNION, MAVLINK_MESSAGE_INFO_TDOA_MEASUREMENT, MAVLINK_MESSAGE_INFO_TDOA_ANCHOR, MAVLINK_MESSAGE_INFO_TDOA_MEASUREMENT_SHORT}
# define MAVLINK_MESSAGE_NAMES {{ "GYRO_ACC_TEMP", 1 }, { "POSITION", 2 }, { "QUATERNION", 3 }, { "TDOA_ANCHOR", 5 }, { "TDOA_MEASUREMENT", 4 }, { "TDOA_MEASUREMENT_SHORT", 6 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_ROADRUNNER_H
