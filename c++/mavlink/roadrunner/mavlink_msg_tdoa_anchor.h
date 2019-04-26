#pragma once
// MESSAGE TDOA_ANCHOR PACKING

#define MAVLINK_MSG_ID_TDOA_ANCHOR 5

MAVPACKED(
typedef struct __mavlink_tdoa_anchor_t {
 float x; /*< Anchor X*/
 float y; /*< Anchor Y*/
 float z; /*< Anchor Z*/
 uint8_t ID; /*< Anchor ID*/
}) mavlink_tdoa_anchor_t;

#define MAVLINK_MSG_ID_TDOA_ANCHOR_LEN 13
#define MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN 13
#define MAVLINK_MSG_ID_5_LEN 13
#define MAVLINK_MSG_ID_5_MIN_LEN 13

#define MAVLINK_MSG_ID_TDOA_ANCHOR_CRC 254
#define MAVLINK_MSG_ID_5_CRC 254



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TDOA_ANCHOR { \
    5, \
    "TDOA_ANCHOR", \
    4, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tdoa_anchor_t, ID) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tdoa_anchor_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tdoa_anchor_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tdoa_anchor_t, z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TDOA_ANCHOR { \
    "TDOA_ANCHOR", \
    4, \
    {  { "ID", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_tdoa_anchor_t, ID) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tdoa_anchor_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_tdoa_anchor_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_tdoa_anchor_t, z) }, \
         } \
}
#endif

/**
 * @brief Pack a tdoa_anchor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ID Anchor ID
 * @param x Anchor X
 * @param y Anchor Y
 * @param z Anchor Z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tdoa_anchor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ID, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_ANCHOR_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, z);
    _mav_put_uint8_t(buf, 12, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN);
#else
    mavlink_tdoa_anchor_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TDOA_ANCHOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_CRC);
}

/**
 * @brief Pack a tdoa_anchor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ID Anchor ID
 * @param x Anchor X
 * @param y Anchor Y
 * @param z Anchor Z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tdoa_anchor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ID,float x,float y,float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_ANCHOR_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, z);
    _mav_put_uint8_t(buf, 12, ID);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN);
#else
    mavlink_tdoa_anchor_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.ID = ID;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TDOA_ANCHOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_CRC);
}

/**
 * @brief Encode a tdoa_anchor struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tdoa_anchor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tdoa_anchor_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tdoa_anchor_t* tdoa_anchor)
{
    return mavlink_msg_tdoa_anchor_pack(system_id, component_id, msg, tdoa_anchor->ID, tdoa_anchor->x, tdoa_anchor->y, tdoa_anchor->z);
}

/**
 * @brief Encode a tdoa_anchor struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tdoa_anchor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tdoa_anchor_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tdoa_anchor_t* tdoa_anchor)
{
    return mavlink_msg_tdoa_anchor_pack_chan(system_id, component_id, chan, msg, tdoa_anchor->ID, tdoa_anchor->x, tdoa_anchor->y, tdoa_anchor->z);
}

/**
 * @brief Send a tdoa_anchor message
 * @param chan MAVLink channel to send the message
 *
 * @param ID Anchor ID
 * @param x Anchor X
 * @param y Anchor Y
 * @param z Anchor Z
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tdoa_anchor_send(mavlink_channel_t chan, uint8_t ID, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TDOA_ANCHOR_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, z);
    _mav_put_uint8_t(buf, 12, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_ANCHOR, buf, MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_CRC);
#else
    mavlink_tdoa_anchor_t packet;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_ANCHOR, (const char *)&packet, MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_CRC);
#endif
}

/**
 * @brief Send a tdoa_anchor message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tdoa_anchor_send_struct(mavlink_channel_t chan, const mavlink_tdoa_anchor_t* tdoa_anchor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tdoa_anchor_send(chan, tdoa_anchor->ID, tdoa_anchor->x, tdoa_anchor->y, tdoa_anchor->z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_ANCHOR, (const char *)tdoa_anchor, MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_CRC);
#endif
}

#if MAVLINK_MSG_ID_TDOA_ANCHOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tdoa_anchor_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ID, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, z);
    _mav_put_uint8_t(buf, 12, ID);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_ANCHOR, buf, MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_CRC);
#else
    mavlink_tdoa_anchor_t *packet = (mavlink_tdoa_anchor_t *)msgbuf;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->ID = ID;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TDOA_ANCHOR, (const char *)packet, MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN, MAVLINK_MSG_ID_TDOA_ANCHOR_CRC);
#endif
}
#endif

#endif

// MESSAGE TDOA_ANCHOR UNPACKING


/**
 * @brief Get field ID from tdoa_anchor message
 *
 * @return Anchor ID
 */
static inline uint8_t mavlink_msg_tdoa_anchor_get_ID(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field x from tdoa_anchor message
 *
 * @return Anchor X
 */
static inline float mavlink_msg_tdoa_anchor_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from tdoa_anchor message
 *
 * @return Anchor Y
 */
static inline float mavlink_msg_tdoa_anchor_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field z from tdoa_anchor message
 *
 * @return Anchor Z
 */
static inline float mavlink_msg_tdoa_anchor_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a tdoa_anchor message into a struct
 *
 * @param msg The message to decode
 * @param tdoa_anchor C-struct to decode the message contents into
 */
static inline void mavlink_msg_tdoa_anchor_decode(const mavlink_message_t* msg, mavlink_tdoa_anchor_t* tdoa_anchor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tdoa_anchor->x = mavlink_msg_tdoa_anchor_get_x(msg);
    tdoa_anchor->y = mavlink_msg_tdoa_anchor_get_y(msg);
    tdoa_anchor->z = mavlink_msg_tdoa_anchor_get_z(msg);
    tdoa_anchor->ID = mavlink_msg_tdoa_anchor_get_ID(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TDOA_ANCHOR_LEN? msg->len : MAVLINK_MSG_ID_TDOA_ANCHOR_LEN;
        memset(tdoa_anchor, 0, MAVLINK_MSG_ID_TDOA_ANCHOR_LEN);
    memcpy(tdoa_anchor, _MAV_PAYLOAD(msg), len);
#endif
}
