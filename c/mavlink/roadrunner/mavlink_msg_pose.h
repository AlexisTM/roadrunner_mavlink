#pragma once
// MESSAGE POSE PACKING

#define MAVLINK_MSG_ID_POSE 2

MAVPACKED(
typedef struct __mavlink_pose_t {
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
}) mavlink_pose_t;

#define MAVLINK_MSG_ID_POSE_LEN 40
#define MAVLINK_MSG_ID_POSE_MIN_LEN 40
#define MAVLINK_MSG_ID_2_LEN 40
#define MAVLINK_MSG_ID_2_MIN_LEN 40

#define MAVLINK_MSG_ID_POSE_CRC 71
#define MAVLINK_MSG_ID_2_CRC 71



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_POSE { \
    2, \
    "POSE", \
    10, \
    {  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pose_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pose_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pose_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pose_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pose_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pose_t, vz) }, \
         { "qx", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_pose_t, qx) }, \
         { "qy", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_pose_t, qy) }, \
         { "qz", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_pose_t, qz) }, \
         { "qw", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_pose_t, qw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_POSE { \
    "POSE", \
    10, \
    {  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_pose_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_pose_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_pose_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_pose_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_pose_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_pose_t, vz) }, \
         { "qx", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_pose_t, qx) }, \
         { "qy", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_pose_t, qy) }, \
         { "qz", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_pose_t, qz) }, \
         { "qw", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_pose_t, qw) }, \
         } \
}
#endif

/**
 * @brief Pack a pose message
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
static inline uint16_t mavlink_msg_pose_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float x, float y, float z, float vx, float vy, float vz, float qx, float qy, float qz, float qw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POSE_LEN];
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSE_LEN);
#else
    mavlink_pose_t packet;
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POSE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_POSE_MIN_LEN, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
}

/**
 * @brief Pack a pose message on a channel
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
static inline uint16_t mavlink_msg_pose_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float x,float y,float z,float vx,float vy,float vz,float qx,float qy,float qz,float qw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POSE_LEN];
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_POSE_LEN);
#else
    mavlink_pose_t packet;
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

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_POSE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_POSE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_POSE_MIN_LEN, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
}

/**
 * @brief Encode a pose struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pose C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pose_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pose_t* pose)
{
    return mavlink_msg_pose_pack(system_id, component_id, msg, pose->x, pose->y, pose->z, pose->vx, pose->vy, pose->vz, pose->qx, pose->qy, pose->qz, pose->qw);
}

/**
 * @brief Encode a pose struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pose C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pose_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pose_t* pose)
{
    return mavlink_msg_pose_pack_chan(system_id, component_id, chan, msg, pose->x, pose->y, pose->z, pose->vx, pose->vy, pose->vz, pose->qx, pose->qy, pose->qz, pose->qw);
}

/**
 * @brief Send a pose message
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

static inline void mavlink_msg_pose_send(mavlink_channel_t chan, float x, float y, float z, float vx, float vy, float vz, float qx, float qy, float qz, float qw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_POSE_LEN];
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, buf, MAVLINK_MSG_ID_POSE_MIN_LEN, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#else
    mavlink_pose_t packet;
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, (const char *)&packet, MAVLINK_MSG_ID_POSE_MIN_LEN, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#endif
}

/**
 * @brief Send a pose message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pose_send_struct(mavlink_channel_t chan, const mavlink_pose_t* pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pose_send(chan, pose->x, pose->y, pose->z, pose->vx, pose->vy, pose->vz, pose->qx, pose->qy, pose->qz, pose->qw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, (const char *)pose, MAVLINK_MSG_ID_POSE_MIN_LEN, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#endif
}

#if MAVLINK_MSG_ID_POSE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pose_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float x, float y, float z, float vx, float vy, float vz, float qx, float qy, float qz, float qw)
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, buf, MAVLINK_MSG_ID_POSE_MIN_LEN, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#else
    mavlink_pose_t *packet = (mavlink_pose_t *)msgbuf;
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

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_POSE, (const char *)packet, MAVLINK_MSG_ID_POSE_MIN_LEN, MAVLINK_MSG_ID_POSE_LEN, MAVLINK_MSG_ID_POSE_CRC);
#endif
}
#endif

#endif

// MESSAGE POSE UNPACKING


/**
 * @brief Get field x from pose message
 *
 * @return X Position
 */
static inline float mavlink_msg_pose_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from pose message
 *
 * @return Y Position
 */
static inline float mavlink_msg_pose_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field z from pose message
 *
 * @return Z Position
 */
static inline float mavlink_msg_pose_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field vx from pose message
 *
 * @return X Speed
 */
static inline float mavlink_msg_pose_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field vy from pose message
 *
 * @return Y Speed
 */
static inline float mavlink_msg_pose_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field vz from pose message
 *
 * @return Z Speed
 */
static inline float mavlink_msg_pose_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field qx from pose message
 *
 * @return X quaternion
 */
static inline float mavlink_msg_pose_get_qx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field qy from pose message
 *
 * @return Y quaternion
 */
static inline float mavlink_msg_pose_get_qy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field qz from pose message
 *
 * @return Z quaternion
 */
static inline float mavlink_msg_pose_get_qz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field qw from pose message
 *
 * @return W quaternion
 */
static inline float mavlink_msg_pose_get_qw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a pose message into a struct
 *
 * @param msg The message to decode
 * @param pose C-struct to decode the message contents into
 */
static inline void mavlink_msg_pose_decode(const mavlink_message_t* msg, mavlink_pose_t* pose)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pose->x = mavlink_msg_pose_get_x(msg);
    pose->y = mavlink_msg_pose_get_y(msg);
    pose->z = mavlink_msg_pose_get_z(msg);
    pose->vx = mavlink_msg_pose_get_vx(msg);
    pose->vy = mavlink_msg_pose_get_vy(msg);
    pose->vz = mavlink_msg_pose_get_vz(msg);
    pose->qx = mavlink_msg_pose_get_qx(msg);
    pose->qy = mavlink_msg_pose_get_qy(msg);
    pose->qz = mavlink_msg_pose_get_qz(msg);
    pose->qw = mavlink_msg_pose_get_qw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_POSE_LEN? msg->len : MAVLINK_MSG_ID_POSE_LEN;
        memset(pose, 0, MAVLINK_MSG_ID_POSE_LEN);
    memcpy(pose, _MAV_PAYLOAD(msg), len);
#endif
}
