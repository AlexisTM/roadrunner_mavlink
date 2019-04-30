/** @file
 *    @brief MAVLink comm protocol testsuite generated from roadrunner.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef ROADRUNNER_TESTSUITE_H
#define ROADRUNNER_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_roadrunner(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_roadrunner(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_gyro_acc(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GYRO_ACC >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gyro_acc_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0
    };
    mavlink_gyro_acc_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.xacc = packet_in.xacc;
        packet1.yacc = packet_in.yacc;
        packet1.zacc = packet_in.zacc;
        packet1.xgyro = packet_in.xgyro;
        packet1.ygyro = packet_in.ygyro;
        packet1.zgyro = packet_in.zgyro;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GYRO_ACC_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gyro_acc_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gyro_acc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gyro_acc_pack(system_id, component_id, &msg , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro );
    mavlink_msg_gyro_acc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gyro_acc_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro );
    mavlink_msg_gyro_acc_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gyro_acc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gyro_acc_send(MAVLINK_COMM_1 , packet1.xacc , packet1.yacc , packet1.zacc , packet1.xgyro , packet1.ygyro , packet1.zgyro );
    mavlink_msg_gyro_acc_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_pose(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_POSE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pose_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0,241.0,269.0
    };
    mavlink_pose_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.vx = packet_in.vx;
        packet1.vy = packet_in.vy;
        packet1.vz = packet_in.vz;
        packet1.qx = packet_in.qx;
        packet1.qy = packet_in.qy;
        packet1.qz = packet_in.qz;
        packet1.qw = packet_in.qw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_POSE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_POSE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pose_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pose_pack(system_id, component_id, &msg , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz , packet1.qx , packet1.qy , packet1.qz , packet1.qw );
    mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pose_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz , packet1.qx , packet1.qy , packet1.qz , packet1.qw );
    mavlink_msg_pose_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pose_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pose_send(MAVLINK_COMM_1 , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz , packet1.qx , packet1.qy , packet1.qz , packet1.qw );
    mavlink_msg_pose_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_quaternion(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_QUATERNION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_quaternion_t packet_in = {
        17.0,45.0,73.0,101.0
    };
    mavlink_quaternion_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.qx = packet_in.qx;
        packet1.qy = packet_in.qy;
        packet1.qz = packet_in.qz;
        packet1.qw = packet_in.qw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_QUATERNION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_QUATERNION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_quaternion_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_quaternion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_quaternion_pack(system_id, component_id, &msg , packet1.qx , packet1.qy , packet1.qz , packet1.qw );
    mavlink_msg_quaternion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_quaternion_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.qx , packet1.qy , packet1.qz , packet1.qw );
    mavlink_msg_quaternion_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_quaternion_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_quaternion_send(MAVLINK_COMM_1 , packet1.qx , packet1.qy , packet1.qz , packet1.qw );
    mavlink_msg_quaternion_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tdoa_measurement(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TDOA_MEASUREMENT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tdoa_measurement_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,157.0,185.0,213.0
    };
    mavlink_tdoa_measurement_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.anchor_ax = packet_in.anchor_ax;
        packet1.anchor_ay = packet_in.anchor_ay;
        packet1.anchor_az = packet_in.anchor_az;
        packet1.anchor_bx = packet_in.anchor_bx;
        packet1.anchor_by = packet_in.anchor_by;
        packet1.anchor_bz = packet_in.anchor_bz;
        packet1.dist_diff = packet_in.dist_diff;
        packet1.stddev = packet_in.stddev;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TDOA_MEASUREMENT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_measurement_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tdoa_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_measurement_pack(system_id, component_id, &msg , packet1.anchor_ax , packet1.anchor_ay , packet1.anchor_az , packet1.anchor_bx , packet1.anchor_by , packet1.anchor_bz , packet1.dist_diff , packet1.stddev );
    mavlink_msg_tdoa_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_measurement_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.anchor_ax , packet1.anchor_ay , packet1.anchor_az , packet1.anchor_bx , packet1.anchor_by , packet1.anchor_bz , packet1.dist_diff , packet1.stddev );
    mavlink_msg_tdoa_measurement_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tdoa_measurement_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_measurement_send(MAVLINK_COMM_1 , packet1.anchor_ax , packet1.anchor_ay , packet1.anchor_az , packet1.anchor_bx , packet1.anchor_by , packet1.anchor_bz , packet1.dist_diff , packet1.stddev );
    mavlink_msg_tdoa_measurement_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tdoa_anchor(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TDOA_ANCHOR >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tdoa_anchor_t packet_in = {
        17.0,45.0,73.0,41
    };
    mavlink_tdoa_anchor_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.ID = packet_in.ID;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TDOA_ANCHOR_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_anchor_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tdoa_anchor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_anchor_pack(system_id, component_id, &msg , packet1.ID , packet1.x , packet1.y , packet1.z );
    mavlink_msg_tdoa_anchor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_anchor_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.ID , packet1.x , packet1.y , packet1.z );
    mavlink_msg_tdoa_anchor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tdoa_anchor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_anchor_send(MAVLINK_COMM_1 , packet1.ID , packet1.x , packet1.y , packet1.z );
    mavlink_msg_tdoa_anchor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_tdoa_measurement_short(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_tdoa_measurement_short_t packet_in = {
        17.0,17,84
    };
    mavlink_tdoa_measurement_short_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.distance = packet_in.distance;
        packet1.anchor_A = packet_in.anchor_A;
        packet1.anchor_B = packet_in.anchor_B;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TDOA_MEASUREMENT_SHORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_measurement_short_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_tdoa_measurement_short_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_measurement_short_pack(system_id, component_id, &msg , packet1.anchor_A , packet1.anchor_B , packet1.distance );
    mavlink_msg_tdoa_measurement_short_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_measurement_short_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.anchor_A , packet1.anchor_B , packet1.distance );
    mavlink_msg_tdoa_measurement_short_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_tdoa_measurement_short_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_tdoa_measurement_short_send(MAVLINK_COMM_1 , packet1.anchor_A , packet1.anchor_B , packet1.distance );
    mavlink_msg_tdoa_measurement_short_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_roadrunner(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_gyro_acc(system_id, component_id, last_msg);
    mavlink_test_pose(system_id, component_id, last_msg);
    mavlink_test_quaternion(system_id, component_id, last_msg);
    mavlink_test_tdoa_measurement(system_id, component_id, last_msg);
    mavlink_test_tdoa_anchor(system_id, component_id, last_msg);
    mavlink_test_tdoa_measurement_short(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ROADRUNNER_TESTSUITE_H
