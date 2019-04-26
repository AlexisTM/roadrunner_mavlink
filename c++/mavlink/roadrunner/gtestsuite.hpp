/** @file
 *	@brief MAVLink comm testsuite protocol generated from roadrunner.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "roadrunner.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(roadrunner, GYRO_ACC_TEMP)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::roadrunner::msg::GYRO_ACC_TEMP packet_in{};
    packet_in.xacc = 17.0;
    packet_in.yacc = 45.0;
    packet_in.zacc = 73.0;
    packet_in.xgyro = 101.0;
    packet_in.ygyro = 129.0;
    packet_in.zgyro = 157.0;
    packet_in.temperature = 185.0;

    mavlink::roadrunner::msg::GYRO_ACC_TEMP packet1{};
    mavlink::roadrunner::msg::GYRO_ACC_TEMP packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.xacc, packet2.xacc);
    EXPECT_EQ(packet1.yacc, packet2.yacc);
    EXPECT_EQ(packet1.zacc, packet2.zacc);
    EXPECT_EQ(packet1.xgyro, packet2.xgyro);
    EXPECT_EQ(packet1.ygyro, packet2.ygyro);
    EXPECT_EQ(packet1.zgyro, packet2.zgyro);
    EXPECT_EQ(packet1.temperature, packet2.temperature);
}

#ifdef TEST_INTEROP
TEST(roadrunner_interop, GYRO_ACC_TEMP)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_gyro_acc_temp_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0
    };

    mavlink::roadrunner::msg::GYRO_ACC_TEMP packet_in{};
    packet_in.xacc = 17.0;
    packet_in.yacc = 45.0;
    packet_in.zacc = 73.0;
    packet_in.xgyro = 101.0;
    packet_in.ygyro = 129.0;
    packet_in.zgyro = 157.0;
    packet_in.temperature = 185.0;

    mavlink::roadrunner::msg::GYRO_ACC_TEMP packet2{};

    mavlink_msg_gyro_acc_temp_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.xacc, packet2.xacc);
    EXPECT_EQ(packet_in.yacc, packet2.yacc);
    EXPECT_EQ(packet_in.zacc, packet2.zacc);
    EXPECT_EQ(packet_in.xgyro, packet2.xgyro);
    EXPECT_EQ(packet_in.ygyro, packet2.ygyro);
    EXPECT_EQ(packet_in.zgyro, packet2.zgyro);
    EXPECT_EQ(packet_in.temperature, packet2.temperature);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(roadrunner, POSITION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::roadrunner::msg::POSITION packet_in{};
    packet_in.x = 17.0;
    packet_in.y = 45.0;
    packet_in.z = 73.0;
    packet_in.vx = 101.0;
    packet_in.vy = 129.0;
    packet_in.vz = 157.0;
    packet_in.qx = 185.0;
    packet_in.qy = 213.0;
    packet_in.qz = 241.0;
    packet_in.qw = 269.0;

    mavlink::roadrunner::msg::POSITION packet1{};
    mavlink::roadrunner::msg::POSITION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.x, packet2.x);
    EXPECT_EQ(packet1.y, packet2.y);
    EXPECT_EQ(packet1.z, packet2.z);
    EXPECT_EQ(packet1.vx, packet2.vx);
    EXPECT_EQ(packet1.vy, packet2.vy);
    EXPECT_EQ(packet1.vz, packet2.vz);
    EXPECT_EQ(packet1.qx, packet2.qx);
    EXPECT_EQ(packet1.qy, packet2.qy);
    EXPECT_EQ(packet1.qz, packet2.qz);
    EXPECT_EQ(packet1.qw, packet2.qw);
}

#ifdef TEST_INTEROP
TEST(roadrunner_interop, POSITION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_position_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0, 241.0, 269.0
    };

    mavlink::roadrunner::msg::POSITION packet_in{};
    packet_in.x = 17.0;
    packet_in.y = 45.0;
    packet_in.z = 73.0;
    packet_in.vx = 101.0;
    packet_in.vy = 129.0;
    packet_in.vz = 157.0;
    packet_in.qx = 185.0;
    packet_in.qy = 213.0;
    packet_in.qz = 241.0;
    packet_in.qw = 269.0;

    mavlink::roadrunner::msg::POSITION packet2{};

    mavlink_msg_position_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.x, packet2.x);
    EXPECT_EQ(packet_in.y, packet2.y);
    EXPECT_EQ(packet_in.z, packet2.z);
    EXPECT_EQ(packet_in.vx, packet2.vx);
    EXPECT_EQ(packet_in.vy, packet2.vy);
    EXPECT_EQ(packet_in.vz, packet2.vz);
    EXPECT_EQ(packet_in.qx, packet2.qx);
    EXPECT_EQ(packet_in.qy, packet2.qy);
    EXPECT_EQ(packet_in.qz, packet2.qz);
    EXPECT_EQ(packet_in.qw, packet2.qw);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(roadrunner, QUATERNION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::roadrunner::msg::QUATERNION packet_in{};
    packet_in.qx = 17.0;
    packet_in.qy = 45.0;
    packet_in.qz = 73.0;
    packet_in.qw = 101.0;
    packet_in.Vqx = 129.0;
    packet_in.Vqy = 157.0;
    packet_in.Vqz = 185.0;
    packet_in.Vqw = 213.0;

    mavlink::roadrunner::msg::QUATERNION packet1{};
    mavlink::roadrunner::msg::QUATERNION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.qx, packet2.qx);
    EXPECT_EQ(packet1.qy, packet2.qy);
    EXPECT_EQ(packet1.qz, packet2.qz);
    EXPECT_EQ(packet1.qw, packet2.qw);
    EXPECT_EQ(packet1.Vqx, packet2.Vqx);
    EXPECT_EQ(packet1.Vqy, packet2.Vqy);
    EXPECT_EQ(packet1.Vqz, packet2.Vqz);
    EXPECT_EQ(packet1.Vqw, packet2.Vqw);
}

#ifdef TEST_INTEROP
TEST(roadrunner_interop, QUATERNION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_quaternion_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0
    };

    mavlink::roadrunner::msg::QUATERNION packet_in{};
    packet_in.qx = 17.0;
    packet_in.qy = 45.0;
    packet_in.qz = 73.0;
    packet_in.qw = 101.0;
    packet_in.Vqx = 129.0;
    packet_in.Vqy = 157.0;
    packet_in.Vqz = 185.0;
    packet_in.Vqw = 213.0;

    mavlink::roadrunner::msg::QUATERNION packet2{};

    mavlink_msg_quaternion_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.qx, packet2.qx);
    EXPECT_EQ(packet_in.qy, packet2.qy);
    EXPECT_EQ(packet_in.qz, packet2.qz);
    EXPECT_EQ(packet_in.qw, packet2.qw);
    EXPECT_EQ(packet_in.Vqx, packet2.Vqx);
    EXPECT_EQ(packet_in.Vqy, packet2.Vqy);
    EXPECT_EQ(packet_in.Vqz, packet2.Vqz);
    EXPECT_EQ(packet_in.Vqw, packet2.Vqw);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(roadrunner, TDOA_MEASUREMENT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::roadrunner::msg::TDOA_MEASUREMENT packet_in{};
    packet_in.anchor_ax = 17.0;
    packet_in.anchor_ay = 45.0;
    packet_in.anchor_az = 73.0;
    packet_in.anchor_bx = 101.0;
    packet_in.anchor_by = 129.0;
    packet_in.anchor_bz = 157.0;
    packet_in.dist_diff = 185.0;
    packet_in.stddev = 213.0;

    mavlink::roadrunner::msg::TDOA_MEASUREMENT packet1{};
    mavlink::roadrunner::msg::TDOA_MEASUREMENT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.anchor_ax, packet2.anchor_ax);
    EXPECT_EQ(packet1.anchor_ay, packet2.anchor_ay);
    EXPECT_EQ(packet1.anchor_az, packet2.anchor_az);
    EXPECT_EQ(packet1.anchor_bx, packet2.anchor_bx);
    EXPECT_EQ(packet1.anchor_by, packet2.anchor_by);
    EXPECT_EQ(packet1.anchor_bz, packet2.anchor_bz);
    EXPECT_EQ(packet1.dist_diff, packet2.dist_diff);
    EXPECT_EQ(packet1.stddev, packet2.stddev);
}

#ifdef TEST_INTEROP
TEST(roadrunner_interop, TDOA_MEASUREMENT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_tdoa_measurement_t packet_c {
         17.0, 45.0, 73.0, 101.0, 129.0, 157.0, 185.0, 213.0
    };

    mavlink::roadrunner::msg::TDOA_MEASUREMENT packet_in{};
    packet_in.anchor_ax = 17.0;
    packet_in.anchor_ay = 45.0;
    packet_in.anchor_az = 73.0;
    packet_in.anchor_bx = 101.0;
    packet_in.anchor_by = 129.0;
    packet_in.anchor_bz = 157.0;
    packet_in.dist_diff = 185.0;
    packet_in.stddev = 213.0;

    mavlink::roadrunner::msg::TDOA_MEASUREMENT packet2{};

    mavlink_msg_tdoa_measurement_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.anchor_ax, packet2.anchor_ax);
    EXPECT_EQ(packet_in.anchor_ay, packet2.anchor_ay);
    EXPECT_EQ(packet_in.anchor_az, packet2.anchor_az);
    EXPECT_EQ(packet_in.anchor_bx, packet2.anchor_bx);
    EXPECT_EQ(packet_in.anchor_by, packet2.anchor_by);
    EXPECT_EQ(packet_in.anchor_bz, packet2.anchor_bz);
    EXPECT_EQ(packet_in.dist_diff, packet2.dist_diff);
    EXPECT_EQ(packet_in.stddev, packet2.stddev);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(roadrunner, TDOA_ANCHOR)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::roadrunner::msg::TDOA_ANCHOR packet_in{};
    packet_in.ID = 41;
    packet_in.x = 17.0;
    packet_in.y = 45.0;
    packet_in.z = 73.0;

    mavlink::roadrunner::msg::TDOA_ANCHOR packet1{};
    mavlink::roadrunner::msg::TDOA_ANCHOR packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.ID, packet2.ID);
    EXPECT_EQ(packet1.x, packet2.x);
    EXPECT_EQ(packet1.y, packet2.y);
    EXPECT_EQ(packet1.z, packet2.z);
}

#ifdef TEST_INTEROP
TEST(roadrunner_interop, TDOA_ANCHOR)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_tdoa_anchor_t packet_c {
         17.0, 45.0, 73.0, 41
    };

    mavlink::roadrunner::msg::TDOA_ANCHOR packet_in{};
    packet_in.ID = 41;
    packet_in.x = 17.0;
    packet_in.y = 45.0;
    packet_in.z = 73.0;

    mavlink::roadrunner::msg::TDOA_ANCHOR packet2{};

    mavlink_msg_tdoa_anchor_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.ID, packet2.ID);
    EXPECT_EQ(packet_in.x, packet2.x);
    EXPECT_EQ(packet_in.y, packet2.y);
    EXPECT_EQ(packet_in.z, packet2.z);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(roadrunner, TDOA_MEASUREMENT_SHORT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::roadrunner::msg::TDOA_MEASUREMENT_SHORT packet_in{};
    packet_in.anchor_A = 17;
    packet_in.anchor_B = 84;
    packet_in.distance = 17.0;

    mavlink::roadrunner::msg::TDOA_MEASUREMENT_SHORT packet1{};
    mavlink::roadrunner::msg::TDOA_MEASUREMENT_SHORT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.anchor_A, packet2.anchor_A);
    EXPECT_EQ(packet1.anchor_B, packet2.anchor_B);
    EXPECT_EQ(packet1.distance, packet2.distance);
}

#ifdef TEST_INTEROP
TEST(roadrunner_interop, TDOA_MEASUREMENT_SHORT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_tdoa_measurement_short_t packet_c {
         17.0, 17, 84
    };

    mavlink::roadrunner::msg::TDOA_MEASUREMENT_SHORT packet_in{};
    packet_in.anchor_A = 17;
    packet_in.anchor_B = 84;
    packet_in.distance = 17.0;

    mavlink::roadrunner::msg::TDOA_MEASUREMENT_SHORT packet2{};

    mavlink_msg_tdoa_measurement_short_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.anchor_A, packet2.anchor_A);
    EXPECT_EQ(packet_in.anchor_B, packet2.anchor_B);
    EXPECT_EQ(packet_in.distance, packet2.distance);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
