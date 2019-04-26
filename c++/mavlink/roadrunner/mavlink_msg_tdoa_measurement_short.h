#pragma once
// MESSAGE TDOA_MEASUREMENT_SHORT PACKING

#define MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT 6

MAVPACKED(
typedef struct __mavlink_tdoa_measurement_short_t {
 float distance; /*< distance*/
 uint8_t anchor_A; /*< Anchor ID*/
 uint8_t anchor_B; /*< Anchor ID*/
}) mavlink_tdoa_measurement_short_t;

#define MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN 6
#define MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN 6
#define MAVLINK_MSG_ID_6_LEN 6
#define MAVLINK_MSG_ID_6_MIN_LEN 6

#define MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_CRC 3
#define MAVLINK_MSG_ID_6_CRC 3



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TDOA_MEASUREMENT_SHORT { \
    6, \
    "TDOA_MEASUREMENT_SHORT", \
    3, \
    {  { "anchor_A", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_tdoa_measurement_short_t, anchor_A) }, \
         { "anchor_B", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_tdoa_measurement_short_t, anchor_B) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tdoa_measurement_short_t, distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TDOA_MEASUREMENT_SHORT { \
    "TDOA_MEASUREMENT_SHORT", \
    3, \
    {  { "anchor_A", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_tdoa_measurement_short_t, anchor_A) }, \
         { "anchor_B", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_tdoa_measurement_short_t, anchor_B) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tdoa_measurement_short_t, distance) }, \
         } \
}
#endif

/**
 * @brief Pack a tdoa_measurement_short message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param anchor_A Anchor ID
 * @param anchor_B Anchor ID
 * @param distance distance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tdoa_measurement_short_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t anchor_A, uint8_t anchor_B, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN];
    _mav_put_float(buf, 0, distance);
    _mav_put_uint8_t(buf, 4, anchor_A);
    _mav_put_uint8_t(buf, 5, anchor_B);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN);
#else
    mavlink_tdoa_measurement_short_t packet;
    packet.distance = distance;
    packet.anchor_A = anchor_A;
    packet.anchor_B = anchor_B;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_CRC);
}

/**
 * @brief Pack a tdoa_measurement_short message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param anchor_A Anchor ID
 * @param anchor_B Anchor ID
 * @param distance distance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tdoa_measurement_short_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t anchor_A,uint8_t anchor_B,float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN];
    _mav_put_float(buf, 0, distance);
    _mav_put_uint8_t(buf, 4, anchor_A);
    _mav_put_uint8_t(buf, 5, anchor_B);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN);
#else
    mavlink_tdoa_measurement_short_t packet;
    packet.distance = distance;
    packet.anchor_A = anchor_A;
    packet.anchor_B = anchor_B;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_CRC);
}

/**
 * @brief Encode a tdoa_measurement_short struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tdoa_measurement_short C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tdoa_measurement_short_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tdoa_measurement_short_t* tdoa_measurement_short)
{
    return mavlink_msg_tdoa_measurement_short_pack(system_id, component_id, msg, tdoa_measurement_short->anchor_A, tdoa_measurement_short->anchor_B, tdoa_measurement_short->distance);
}

/**
 * @brief Encode a tdoa_measurement_short struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tdoa_measurement_short C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tdoa_measurement_short_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tdoa_measurement_short_t* tdoa_measurement_short)
{
    return mavlink_msg_tdoa_measurement_short_pack_chan(system_id, component_id, chan, msg, tdoa_measurement_short->anchor_A, tdoa_measurement_short->anchor_B, tdoa_measurement_short->distance);
}

/**
 * @brief Send a tdoa_measurement_short message
 * @param chan MAVLink channel to send the message
 *
 * @param anchor_A Anchor ID
 * @param anchor_B Anchor ID
 * @param distance distance
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tdoa_measurement_short_send(mavlink_channel_t chan, uint8_t anchor_A, uint8_t anchor_B, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN];
    _mav_put_float(buf, 0, distance);
    _mav_put_uint8_t(buf, 4, anchor_A);
    _mav_put_uint8_t(buf, 5, anchor_B);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT, buf, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_CRC);
#else
    mavlink_tdoa_measurement_short_t packet;
    packet.distance = distance;
    packet.anchor_A = anchor_A;
    packet.anchor_B = anchor_B;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT, (const char *)&packet, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_CRC);
#endif
}

/**
 * @brief Send a tdoa_measurement_short message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tdoa_measurement_short_send_struct(mavlink_channel_t chan, const mavlink_tdoa_measurement_short_t* tdoa_measurement_short)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tdoa_measurement_short_send(chan, tdoa_measurement_short->anchor_A, tdoa_measurement_short->anchor_B, tdoa_measurement_short->distance);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT, (const char *)tdoa_measurement_short, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_CRC);
#endif
}

#if MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tdoa_measurement_short_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t anchor_A, uint8_t anchor_B, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, distance);
    _mav_put_uint8_t(buf, 4, anchor_A);
    _mav_put_uint8_t(buf, 5, anchor_B);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT, buf, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_CRC);
#else
    mavlink_tdoa_measurement_short_t *packet = (mavlink_tdoa_measurement_short_t *)msgbuf;
    packet->distance = distance;
    packet->anchor_A = anchor_A;
    packet->anchor_B = anchor_B;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT, (const char *)packet, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_CRC);
#endif
}
#endif

#endif

// MESSAGE TDOA_MEASUREMENT_SHORT UNPACKING


/**
 * @brief Get field anchor_A from tdoa_measurement_short message
 *
 * @return Anchor ID
 */
static inline uint8_t mavlink_msg_tdoa_measurement_short_get_anchor_A(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field anchor_B from tdoa_measurement_short message
 *
 * @return Anchor ID
 */
static inline uint8_t mavlink_msg_tdoa_measurement_short_get_anchor_B(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field distance from tdoa_measurement_short message
 *
 * @return distance
 */
static inline float mavlink_msg_tdoa_measurement_short_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a tdoa_measurement_short message into a struct
 *
 * @param msg The message to decode
 * @param tdoa_measurement_short C-struct to decode the message contents into
 */
static inline void mavlink_msg_tdoa_measurement_short_decode(const mavlink_message_t* msg, mavlink_tdoa_measurement_short_t* tdoa_measurement_short)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tdoa_measurement_short->distance = mavlink_msg_tdoa_measurement_short_get_distance(msg);
    tdoa_measurement_short->anchor_A = mavlink_msg_tdoa_measurement_short_get_anchor_A(msg);
    tdoa_measurement_short->anchor_B = mavlink_msg_tdoa_measurement_short_get_anchor_B(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN? msg->len : MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN;
        memset(tdoa_measurement_short, 0, MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_LEN);
    memcpy(tdoa_measurement_short, _MAV_PAYLOAD(msg), len);
#endif
}
