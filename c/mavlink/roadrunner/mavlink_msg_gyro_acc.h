#pragma once
// MESSAGE GYRO_ACC PACKING

#define MAVLINK_MSG_ID_GYRO_ACC 1

MAVPACKED(
typedef struct __mavlink_gyro_acc_t {
 float xacc; /*< X acceleration*/
 float yacc; /*< Y acceleration*/
 float zacc; /*< Z acceleration*/
 float xgyro; /*< Angular speed around X axis*/
 float ygyro; /*< Angular speed around Y axis*/
 float zgyro; /*< Angular speed around Z axis*/
}) mavlink_gyro_acc_t;

#define MAVLINK_MSG_ID_GYRO_ACC_LEN 24
#define MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN 24
#define MAVLINK_MSG_ID_1_LEN 24
#define MAVLINK_MSG_ID_1_MIN_LEN 24

#define MAVLINK_MSG_ID_GYRO_ACC_CRC 6
#define MAVLINK_MSG_ID_1_CRC 6



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GYRO_ACC { \
    1, \
    "GYRO_ACC", \
    6, \
    {  { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gyro_acc_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gyro_acc_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gyro_acc_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gyro_acc_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gyro_acc_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gyro_acc_t, zgyro) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GYRO_ACC { \
    "GYRO_ACC", \
    6, \
    {  { "xacc", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_gyro_acc_t, xacc) }, \
         { "yacc", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_gyro_acc_t, yacc) }, \
         { "zacc", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_gyro_acc_t, zacc) }, \
         { "xgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_gyro_acc_t, xgyro) }, \
         { "ygyro", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_gyro_acc_t, ygyro) }, \
         { "zgyro", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_gyro_acc_t, zgyro) }, \
         } \
}
#endif

/**
 * @brief Pack a gyro_acc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param xacc X acceleration
 * @param yacc Y acceleration
 * @param zacc Z acceleration
 * @param xgyro Angular speed around X axis
 * @param ygyro Angular speed around Y axis
 * @param zgyro Angular speed around Z axis
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gyro_acc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GYRO_ACC_LEN];
    _mav_put_float(buf, 0, xacc);
    _mav_put_float(buf, 4, yacc);
    _mav_put_float(buf, 8, zacc);
    _mav_put_float(buf, 12, xgyro);
    _mav_put_float(buf, 16, ygyro);
    _mav_put_float(buf, 20, zgyro);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GYRO_ACC_LEN);
#else
    mavlink_gyro_acc_t packet;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GYRO_ACC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GYRO_ACC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN, MAVLINK_MSG_ID_GYRO_ACC_LEN, MAVLINK_MSG_ID_GYRO_ACC_CRC);
}

/**
 * @brief Pack a gyro_acc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param xacc X acceleration
 * @param yacc Y acceleration
 * @param zacc Z acceleration
 * @param xgyro Angular speed around X axis
 * @param ygyro Angular speed around Y axis
 * @param zgyro Angular speed around Z axis
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gyro_acc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float xacc,float yacc,float zacc,float xgyro,float ygyro,float zgyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GYRO_ACC_LEN];
    _mav_put_float(buf, 0, xacc);
    _mav_put_float(buf, 4, yacc);
    _mav_put_float(buf, 8, zacc);
    _mav_put_float(buf, 12, xgyro);
    _mav_put_float(buf, 16, ygyro);
    _mav_put_float(buf, 20, zgyro);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GYRO_ACC_LEN);
#else
    mavlink_gyro_acc_t packet;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GYRO_ACC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GYRO_ACC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN, MAVLINK_MSG_ID_GYRO_ACC_LEN, MAVLINK_MSG_ID_GYRO_ACC_CRC);
}

/**
 * @brief Encode a gyro_acc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gyro_acc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gyro_acc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gyro_acc_t* gyro_acc)
{
    return mavlink_msg_gyro_acc_pack(system_id, component_id, msg, gyro_acc->xacc, gyro_acc->yacc, gyro_acc->zacc, gyro_acc->xgyro, gyro_acc->ygyro, gyro_acc->zgyro);
}

/**
 * @brief Encode a gyro_acc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gyro_acc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gyro_acc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gyro_acc_t* gyro_acc)
{
    return mavlink_msg_gyro_acc_pack_chan(system_id, component_id, chan, msg, gyro_acc->xacc, gyro_acc->yacc, gyro_acc->zacc, gyro_acc->xgyro, gyro_acc->ygyro, gyro_acc->zgyro);
}

/**
 * @brief Send a gyro_acc message
 * @param chan MAVLink channel to send the message
 *
 * @param xacc X acceleration
 * @param yacc Y acceleration
 * @param zacc Z acceleration
 * @param xgyro Angular speed around X axis
 * @param ygyro Angular speed around Y axis
 * @param zgyro Angular speed around Z axis
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gyro_acc_send(mavlink_channel_t chan, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GYRO_ACC_LEN];
    _mav_put_float(buf, 0, xacc);
    _mav_put_float(buf, 4, yacc);
    _mav_put_float(buf, 8, zacc);
    _mav_put_float(buf, 12, xgyro);
    _mav_put_float(buf, 16, ygyro);
    _mav_put_float(buf, 20, zgyro);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_ACC, buf, MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN, MAVLINK_MSG_ID_GYRO_ACC_LEN, MAVLINK_MSG_ID_GYRO_ACC_CRC);
#else
    mavlink_gyro_acc_t packet;
    packet.xacc = xacc;
    packet.yacc = yacc;
    packet.zacc = zacc;
    packet.xgyro = xgyro;
    packet.ygyro = ygyro;
    packet.zgyro = zgyro;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_ACC, (const char *)&packet, MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN, MAVLINK_MSG_ID_GYRO_ACC_LEN, MAVLINK_MSG_ID_GYRO_ACC_CRC);
#endif
}

/**
 * @brief Send a gyro_acc message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gyro_acc_send_struct(mavlink_channel_t chan, const mavlink_gyro_acc_t* gyro_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gyro_acc_send(chan, gyro_acc->xacc, gyro_acc->yacc, gyro_acc->zacc, gyro_acc->xgyro, gyro_acc->ygyro, gyro_acc->zgyro);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_ACC, (const char *)gyro_acc, MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN, MAVLINK_MSG_ID_GYRO_ACC_LEN, MAVLINK_MSG_ID_GYRO_ACC_CRC);
#endif
}

#if MAVLINK_MSG_ID_GYRO_ACC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gyro_acc_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, xacc);
    _mav_put_float(buf, 4, yacc);
    _mav_put_float(buf, 8, zacc);
    _mav_put_float(buf, 12, xgyro);
    _mav_put_float(buf, 16, ygyro);
    _mav_put_float(buf, 20, zgyro);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_ACC, buf, MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN, MAVLINK_MSG_ID_GYRO_ACC_LEN, MAVLINK_MSG_ID_GYRO_ACC_CRC);
#else
    mavlink_gyro_acc_t *packet = (mavlink_gyro_acc_t *)msgbuf;
    packet->xacc = xacc;
    packet->yacc = yacc;
    packet->zacc = zacc;
    packet->xgyro = xgyro;
    packet->ygyro = ygyro;
    packet->zgyro = zgyro;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GYRO_ACC, (const char *)packet, MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN, MAVLINK_MSG_ID_GYRO_ACC_LEN, MAVLINK_MSG_ID_GYRO_ACC_CRC);
#endif
}
#endif

#endif

// MESSAGE GYRO_ACC UNPACKING


/**
 * @brief Get field xacc from gyro_acc message
 *
 * @return X acceleration
 */
static inline float mavlink_msg_gyro_acc_get_xacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field yacc from gyro_acc message
 *
 * @return Y acceleration
 */
static inline float mavlink_msg_gyro_acc_get_yacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field zacc from gyro_acc message
 *
 * @return Z acceleration
 */
static inline float mavlink_msg_gyro_acc_get_zacc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field xgyro from gyro_acc message
 *
 * @return Angular speed around X axis
 */
static inline float mavlink_msg_gyro_acc_get_xgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field ygyro from gyro_acc message
 *
 * @return Angular speed around Y axis
 */
static inline float mavlink_msg_gyro_acc_get_ygyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field zgyro from gyro_acc message
 *
 * @return Angular speed around Z axis
 */
static inline float mavlink_msg_gyro_acc_get_zgyro(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a gyro_acc message into a struct
 *
 * @param msg The message to decode
 * @param gyro_acc C-struct to decode the message contents into
 */
static inline void mavlink_msg_gyro_acc_decode(const mavlink_message_t* msg, mavlink_gyro_acc_t* gyro_acc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gyro_acc->xacc = mavlink_msg_gyro_acc_get_xacc(msg);
    gyro_acc->yacc = mavlink_msg_gyro_acc_get_yacc(msg);
    gyro_acc->zacc = mavlink_msg_gyro_acc_get_zacc(msg);
    gyro_acc->xgyro = mavlink_msg_gyro_acc_get_xgyro(msg);
    gyro_acc->ygyro = mavlink_msg_gyro_acc_get_ygyro(msg);
    gyro_acc->zgyro = mavlink_msg_gyro_acc_get_zgyro(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GYRO_ACC_LEN? msg->len : MAVLINK_MSG_ID_GYRO_ACC_LEN;
        memset(gyro_acc, 0, MAVLINK_MSG_ID_GYRO_ACC_LEN);
    memcpy(gyro_acc, _MAV_PAYLOAD(msg), len);
#endif
}
