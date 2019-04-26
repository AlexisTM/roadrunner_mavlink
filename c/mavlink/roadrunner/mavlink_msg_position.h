#pragma once
// MESSAGE POSITION PACKING

#define MAVLINK_MSG_ID_POSITION 2

MAVPACKED(
typedef struct __mavlink_position_t {
 float x; /*< X Position*/
 float y; /*< Y Position*/
 float z; /*< Z Position*/
 float vx; /*< X Speed*/
 float vy; /*< Y Speed*/
 float vz; /*< Z Speed*/
 float qx; /*< X quaternion*/
 float qy; /*< Y quaternion*/
 float qz; /*< Z quaternion*/
 float qw; /*< W quaternion*/
}) mavlink_position_t;

#define MAVLINK_MSG_ID_POSITION_LEN 40
#define MAVLINK_MSG_ID_POSITION_MIN_LEN 40
#define MAVLINK_MSG_ID_2_LEN 40
#define MAVLINK_MSG_ID_2_MIN_LEN 40

#define MAVLINK_MSG_ID_POSITION_CRC 56
#define MAVLINK_MSG_ID_2_CRC 56



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_POSITION { \
    2, \
    "POSITION", \
    10, \
    {  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_position_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_position_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_position_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_position_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_position_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_position_t, vz) }, \
         { "qx", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_position_t, qx) }, \
         { "qy", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_position_t, qy) }, \
         { "qz", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_position_t, qz) }, \
         { "qw", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_position_t, qw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_POSITION { \
    "POSITION", \
    10, \
    {  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_position_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_position_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_position_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_position_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_position_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_position_t, vz) }, \
         { "qx", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_position_t, qx) }, \
         { "qy", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_position_t, qy) }, \
         { "qz", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_position_t, qz) }, \
         { "qw", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_position_t, qw) }, \
         } \
}
#endif

/**
 * @brief Pack a position message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param x X Position
 * @param y Y Position
 * @param z Z Position
 * @param vx X Speed
 * @param vy Y Speed
 * @param vz Z Speed
 * @param qx X quaternion
 * @param qy Y quaternion
 * @param qz Z quaternion
 * @param qw W quaternion
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float x, float y, float z, float vx, float vy, float vz, float qx, float qy, float qz, float qw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POSITION_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, z);
    _mav_put_float(buf, 12, vx);
    _mav_put_float(buf, 16, vy);
    _mav_put_float(buf, 20, vz);
    _mav_put_float(buf, 24, qx);
    _mav_put_float(buf, 28, qy);
    _mav_put_float(buf, 32, qz);
    _mav_put_float(buf, 36, qw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_LEN);
#else
    mavlink_position_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.qx = qx;
    packet.qy = qy;
    packet.qz = qz;
    packet.qw = qw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POSITION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSITION_MIN_LEN, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
}

/**
 * @brief Pack a position message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param x X Position
 * @param y Y Position
 * @param z Z Position
 * @param vx X Speed
 * @param vy Y Speed
 * @param vz Z Speed
 * @param qx X quaternion
 * @param qy Y quaternion
 * @param qz Z quaternion
 * @param qw W quaternion
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_position_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float x,float y,float z,float vx,float vy,float vz,float qx,float qy,float qz,float qw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POSITION_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, z);
    _mav_put_float(buf, 12, vx);
    _mav_put_float(buf, 16, vy);
    _mav_put_float(buf, 20, vz);
    _mav_put_float(buf, 24, qx);
    _mav_put_float(buf, 28, qy);
    _mav_put_float(buf, 32, qz);
    _mav_put_float(buf, 36, qw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSITION_LEN);
#else
    mavlink_position_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.qx = qx;
    packet.qy = qy;
    packet.qz = qz;
    packet.qw = qw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSITION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POSITION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSITION_MIN_LEN, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
}

/**
 * @brief Encode a position struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_position_t* position)
{
    return mavlink_msg_position_pack(system_id, component_id, msg, position->x, position->y, position->z, position->vx, position->vy, position->vz, position->qx, position->qy, position->qz, position->qw);
}

/**
 * @brief Encode a position struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param position C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_position_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_position_t* position)
{
    return mavlink_msg_position_pack_chan(system_id, component_id, chan, msg, position->x, position->y, position->z, position->vx, position->vy, position->vz, position->qx, position->qy, position->qz, position->qw);
}

/**
 * @brief Send a position message
 * @param chan MAVLink channel to send the message
 *
 * @param x X Position
 * @param y Y Position
 * @param z Z Position
 * @param vx X Speed
 * @param vy Y Speed
 * @param vz Z Speed
 * @param qx X quaternion
 * @param qy Y quaternion
 * @param qz Z quaternion
 * @param qw W quaternion
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_position_send(mavlink_channel_t chan, float x, float y, float z, float vx, float vy, float vz, float qx, float qy, float qz, float qw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POSITION_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, z);
    _mav_put_float(buf, 12, vx);
    _mav_put_float(buf, 16, vy);
    _mav_put_float(buf, 20, vz);
    _mav_put_float(buf, 24, qx);
    _mav_put_float(buf, 28, qy);
    _mav_put_float(buf, 32, qz);
    _mav_put_float(buf, 36, qw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_MIN_LEN, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    mavlink_position_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.qx = qx;
    packet.qy = qy;
    packet.qz = qz;
    packet.qw = qw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)&packet, MAVLINK_MSG_ID_POSITION_MIN_LEN, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#endif
}

/**
 * @brief Send a position message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_position_send_struct(mavlink_channel_t chan, const mavlink_position_t* position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_position_send(chan, position->x, position->y, position->z, position->vx, position->vy, position->vz, position->qx, position->qy, position->qz, position->qw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)position, MAVLINK_MSG_ID_POSITION_MIN_LEN, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#endif
}

#if MAVLINK_MSG_ID_POSITION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_position_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float x, float y, float z, float vx, float vy, float vz, float qx, float qy, float qz, float qw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, z);
    _mav_put_float(buf, 12, vx);
    _mav_put_float(buf, 16, vy);
    _mav_put_float(buf, 20, vz);
    _mav_put_float(buf, 24, qx);
    _mav_put_float(buf, 28, qy);
    _mav_put_float(buf, 32, qz);
    _mav_put_float(buf, 36, qw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, buf, MAVLINK_MSG_ID_POSITION_MIN_LEN, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#else
    mavlink_position_t *packet = (mavlink_position_t *)msgbuf;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->vx = vx;
    packet->vy = vy;
    packet->vz = vz;
    packet->qx = qx;
    packet->qy = qy;
    packet->qz = qz;
    packet->qw = qw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSITION, (const char *)packet, MAVLINK_MSG_ID_POSITION_MIN_LEN, MAVLINK_MSG_ID_POSITION_LEN, MAVLINK_MSG_ID_POSITION_CRC);
#endif
}
#endif

#endif

// MESSAGE POSITION UNPACKING


/**
 * @brief Get field x from position message
 *
 * @return X Position
 */
static inline float mavlink_msg_position_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from position message
 *
 * @return Y Position
 */
static inline float mavlink_msg_position_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field z from position message
 *
 * @return Z Position
 */
static inline float mavlink_msg_position_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vx from position message
 *
 * @return X Speed
 */
static inline float mavlink_msg_position_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field vy from position message
 *
 * @return Y Speed
 */
static inline float mavlink_msg_position_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field vz from position message
 *
 * @return Z Speed
 */
static inline float mavlink_msg_position_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field qx from position message
 *
 * @return X quaternion
 */
static inline float mavlink_msg_position_get_qx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field qy from position message
 *
 * @return Y quaternion
 */
static inline float mavlink_msg_position_get_qy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field qz from position message
 *
 * @return Z quaternion
 */
static inline float mavlink_msg_position_get_qz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field qw from position message
 *
 * @return W quaternion
 */
static inline float mavlink_msg_position_get_qw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a position message into a struct
 *
 * @param msg The message to decode
 * @param position C-struct to decode the message contents into
 */
static inline void mavlink_msg_position_decode(const mavlink_message_t* msg, mavlink_position_t* position)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    position->x = mavlink_msg_position_get_x(msg);
    position->y = mavlink_msg_position_get_y(msg);
    position->z = mavlink_msg_position_get_z(msg);
    position->vx = mavlink_msg_position_get_vx(msg);
    position->vy = mavlink_msg_position_get_vy(msg);
    position->vz = mavlink_msg_position_get_vz(msg);
    position->qx = mavlink_msg_position_get_qx(msg);
    position->qy = mavlink_msg_position_get_qy(msg);
    position->qz = mavlink_msg_position_get_qz(msg);
    position->qw = mavlink_msg_position_get_qw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_POSITION_LEN? msg->len : MAVLINK_MSG_ID_POSITION_LEN;
        memset(position, 0, MAVLINK_MSG_ID_POSITION_LEN);
    memcpy(position, _MAV_PAYLOAD(msg), len);
#endif
}
