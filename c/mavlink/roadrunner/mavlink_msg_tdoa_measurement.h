#pragma once
// MESSAGE TDOA_MEASUREMENT PACKING

#define MAVLINK_MSG_ID_TDOA_MEASUREMENT 4

MAVPACKED(
typedef struct __mavlink_tdoa_measurement_t {
 float anchor_ax; /*< Anchor Ax position*/
 float anchor_ay; /*< Anchor Ay position*/
 float anchor_az; /*< Anchor Az position*/
 float anchor_bx; /*< Anchor Bx position*/
 float anchor_by; /*< Anchor By position*/
 float anchor_bz; /*< Anchor Bz position*/
 float dist_diff; /*< Distance difference*/
}) mavlink_tdoa_measurement_t;

#define MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN 28
#define MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN 28
#define MAVLINK_MSG_ID_4_LEN 28
#define MAVLINK_MSG_ID_4_MIN_LEN 28

#define MAVLINK_MSG_ID_TDOA_MEASUREMENT_CRC 163
#define MAVLINK_MSG_ID_4_CRC 163



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TDOA_MEASUREMENT { \
    4, \
    "TDOA_MEASUREMENT", \
    7, \
    {  { "anchor_ax", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tdoa_measurement_t, anchor_ax) }, \
         { "anchor_ay", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tdoa_measurement_t, anchor_ay) }, \
         { "anchor_az", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tdoa_measurement_t, anchor_az) }, \
         { "anchor_bx", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_tdoa_measurement_t, anchor_bx) }, \
         { "anchor_by", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_tdoa_measurement_t, anchor_by) }, \
         { "anchor_bz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_tdoa_measurement_t, anchor_bz) }, \
         { "dist_diff", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_tdoa_measurement_t, dist_diff) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TDOA_MEASUREMENT { \
    "TDOA_MEASUREMENT", \
    7, \
    {  { "anchor_ax", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tdoa_measurement_t, anchor_ax) }, \
         { "anchor_ay", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tdoa_measurement_t, anchor_ay) }, \
         { "anchor_az", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tdoa_measurement_t, anchor_az) }, \
         { "anchor_bx", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_tdoa_measurement_t, anchor_bx) }, \
         { "anchor_by", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_tdoa_measurement_t, anchor_by) }, \
         { "anchor_bz", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_tdoa_measurement_t, anchor_bz) }, \
         { "dist_diff", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_tdoa_measurement_t, dist_diff) }, \
         } \
}
#endif

/**
 * @brief Pack a tdoa_measurement message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param anchor_ax Anchor Ax position
 * @param anchor_ay Anchor Ay position
 * @param anchor_az Anchor Az position
 * @param anchor_bx Anchor Bx position
 * @param anchor_by Anchor By position
 * @param anchor_bz Anchor Bz position
 * @param dist_diff Distance difference
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tdoa_measurement_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float anchor_ax, float anchor_ay, float anchor_az, float anchor_bx, float anchor_by, float anchor_bz, float dist_diff)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN];
    _mav_put_float(buf, 0, anchor_ax);
    _mav_put_float(buf, 4, anchor_ay);
    _mav_put_float(buf, 8, anchor_az);
    _mav_put_float(buf, 12, anchor_bx);
    _mav_put_float(buf, 16, anchor_by);
    _mav_put_float(buf, 20, anchor_bz);
    _mav_put_float(buf, 24, dist_diff);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN);
#else
    mavlink_tdoa_measurement_t packet;
    packet.anchor_ax = anchor_ax;
    packet.anchor_ay = anchor_ay;
    packet.anchor_az = anchor_az;
    packet.anchor_bx = anchor_bx;
    packet.anchor_by = anchor_by;
    packet.anchor_bz = anchor_bz;
    packet.dist_diff = dist_diff;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TDOA_MEASUREMENT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_CRC);
}

/**
 * @brief Pack a tdoa_measurement message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param anchor_ax Anchor Ax position
 * @param anchor_ay Anchor Ay position
 * @param anchor_az Anchor Az position
 * @param anchor_bx Anchor Bx position
 * @param anchor_by Anchor By position
 * @param anchor_bz Anchor Bz position
 * @param dist_diff Distance difference
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tdoa_measurement_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float anchor_ax,float anchor_ay,float anchor_az,float anchor_bx,float anchor_by,float anchor_bz,float dist_diff)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN];
    _mav_put_float(buf, 0, anchor_ax);
    _mav_put_float(buf, 4, anchor_ay);
    _mav_put_float(buf, 8, anchor_az);
    _mav_put_float(buf, 12, anchor_bx);
    _mav_put_float(buf, 16, anchor_by);
    _mav_put_float(buf, 20, anchor_bz);
    _mav_put_float(buf, 24, dist_diff);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN);
#else
    mavlink_tdoa_measurement_t packet;
    packet.anchor_ax = anchor_ax;
    packet.anchor_ay = anchor_ay;
    packet.anchor_az = anchor_az;
    packet.anchor_bx = anchor_bx;
    packet.anchor_by = anchor_by;
    packet.anchor_bz = anchor_bz;
    packet.dist_diff = dist_diff;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TDOA_MEASUREMENT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_CRC);
}

/**
 * @brief Encode a tdoa_measurement struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tdoa_measurement C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tdoa_measurement_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tdoa_measurement_t* tdoa_measurement)
{
    return mavlink_msg_tdoa_measurement_pack(system_id, component_id, msg, tdoa_measurement->anchor_ax, tdoa_measurement->anchor_ay, tdoa_measurement->anchor_az, tdoa_measurement->anchor_bx, tdoa_measurement->anchor_by, tdoa_measurement->anchor_bz, tdoa_measurement->dist_diff);
}

/**
 * @brief Encode a tdoa_measurement struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tdoa_measurement C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tdoa_measurement_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tdoa_measurement_t* tdoa_measurement)
{
    return mavlink_msg_tdoa_measurement_pack_chan(system_id, component_id, chan, msg, tdoa_measurement->anchor_ax, tdoa_measurement->anchor_ay, tdoa_measurement->anchor_az, tdoa_measurement->anchor_bx, tdoa_measurement->anchor_by, tdoa_measurement->anchor_bz, tdoa_measurement->dist_diff);
}

/**
 * @brief Send a tdoa_measurement message
 * @param chan MAVLink channel to send the message
 *
 * @param anchor_ax Anchor Ax position
 * @param anchor_ay Anchor Ay position
 * @param anchor_az Anchor Az position
 * @param anchor_bx Anchor Bx position
 * @param anchor_by Anchor By position
 * @param anchor_bz Anchor Bz position
 * @param dist_diff Distance difference
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tdoa_measurement_send(mavlink_channel_t chan, float anchor_ax, float anchor_ay, float anchor_az, float anchor_bx, float anchor_by, float anchor_bz, float dist_diff)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN];
    _mav_put_float(buf, 0, anchor_ax);
    _mav_put_float(buf, 4, anchor_ay);
    _mav_put_float(buf, 8, anchor_az);
    _mav_put_float(buf, 12, anchor_bx);
    _mav_put_float(buf, 16, anchor_by);
    _mav_put_float(buf, 20, anchor_bz);
    _mav_put_float(buf, 24, dist_diff);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT, buf, MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_CRC);
#else
    mavlink_tdoa_measurement_t packet;
    packet.anchor_ax = anchor_ax;
    packet.anchor_ay = anchor_ay;
    packet.anchor_az = anchor_az;
    packet.anchor_bx = anchor_bx;
    packet.anchor_by = anchor_by;
    packet.anchor_bz = anchor_bz;
    packet.dist_diff = dist_diff;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT, (const char *)&packet, MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_CRC);
#endif
}

/**
 * @brief Send a tdoa_measurement message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tdoa_measurement_send_struct(mavlink_channel_t chan, const mavlink_tdoa_measurement_t* tdoa_measurement)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tdoa_measurement_send(chan, tdoa_measurement->anchor_ax, tdoa_measurement->anchor_ay, tdoa_measurement->anchor_az, tdoa_measurement->anchor_bx, tdoa_measurement->anchor_by, tdoa_measurement->anchor_bz, tdoa_measurement->dist_diff);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT, (const char *)tdoa_measurement, MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_CRC);
#endif
}

#if MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tdoa_measurement_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float anchor_ax, float anchor_ay, float anchor_az, float anchor_bx, float anchor_by, float anchor_bz, float dist_diff)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, anchor_ax);
    _mav_put_float(buf, 4, anchor_ay);
    _mav_put_float(buf, 8, anchor_az);
    _mav_put_float(buf, 12, anchor_bx);
    _mav_put_float(buf, 16, anchor_by);
    _mav_put_float(buf, 20, anchor_bz);
    _mav_put_float(buf, 24, dist_diff);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT, buf, MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_CRC);
#else
    mavlink_tdoa_measurement_t *packet = (mavlink_tdoa_measurement_t *)msgbuf;
    packet->anchor_ax = anchor_ax;
    packet->anchor_ay = anchor_ay;
    packet->anchor_az = anchor_az;
    packet->anchor_bx = anchor_bx;
    packet->anchor_by = anchor_by;
    packet->anchor_bz = anchor_bz;
    packet->dist_diff = dist_diff;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT, (const char *)packet, MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_CRC);
#endif
}
#endif

#endif

// MESSAGE TDOA_MEASUREMENT UNPACKING


/**
 * @brief Get field anchor_ax from tdoa_measurement message
 *
 * @return Anchor Ax position
 */
static inline float mavlink_msg_tdoa_measurement_get_anchor_ax(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field anchor_ay from tdoa_measurement message
 *
 * @return Anchor Ay position
 */
static inline float mavlink_msg_tdoa_measurement_get_anchor_ay(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field anchor_az from tdoa_measurement message
 *
 * @return Anchor Az position
 */
static inline float mavlink_msg_tdoa_measurement_get_anchor_az(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field anchor_bx from tdoa_measurement message
 *
 * @return Anchor Bx position
 */
static inline float mavlink_msg_tdoa_measurement_get_anchor_bx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field anchor_by from tdoa_measurement message
 *
 * @return Anchor By position
 */
static inline float mavlink_msg_tdoa_measurement_get_anchor_by(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field anchor_bz from tdoa_measurement message
 *
 * @return Anchor Bz position
 */
static inline float mavlink_msg_tdoa_measurement_get_anchor_bz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field dist_diff from tdoa_measurement message
 *
 * @return Distance difference
 */
static inline float mavlink_msg_tdoa_measurement_get_dist_diff(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a tdoa_measurement message into a struct
 *
 * @param msg The message to decode
 * @param tdoa_measurement C-struct to decode the message contents into
 */
static inline void mavlink_msg_tdoa_measurement_decode(const mavlink_message_t* msg, mavlink_tdoa_measurement_t* tdoa_measurement)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tdoa_measurement->anchor_ax = mavlink_msg_tdoa_measurement_get_anchor_ax(msg);
    tdoa_measurement->anchor_ay = mavlink_msg_tdoa_measurement_get_anchor_ay(msg);
    tdoa_measurement->anchor_az = mavlink_msg_tdoa_measurement_get_anchor_az(msg);
    tdoa_measurement->anchor_bx = mavlink_msg_tdoa_measurement_get_anchor_bx(msg);
    tdoa_measurement->anchor_by = mavlink_msg_tdoa_measurement_get_anchor_by(msg);
    tdoa_measurement->anchor_bz = mavlink_msg_tdoa_measurement_get_anchor_bz(msg);
    tdoa_measurement->dist_diff = mavlink_msg_tdoa_measurement_get_dist_diff(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN? msg->len : MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN;
        memset(tdoa_measurement, 0, MAVLINK_MSG_ID_TDOA_MEASUREMENT_LEN);
    memcpy(tdoa_measurement, _MAV_PAYLOAD(msg), len);
#endif
}
