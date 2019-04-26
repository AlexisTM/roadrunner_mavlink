// MESSAGE POSITION support class

#pragma once

namespace mavlink {
namespace roadrunner {
namespace msg {

/**
 * @brief POSITION message
 *
 * The EKF output
 */
struct POSITION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 2;
    static constexpr size_t LENGTH = 40;
    static constexpr size_t MIN_LENGTH = 40;
    static constexpr uint8_t CRC_EXTRA = 56;
    static constexpr auto NAME = "POSITION";


    float x; /*< X Position */
    float y; /*< Y Position */
    float z; /*< Z Position */
    float vx; /*< X Speed */
    float vy; /*< Y Speed */
    float vz; /*< Z Speed */
    float qx; /*< X quaternion */
    float qy; /*< Y quaternion */
    float qz; /*< Z quaternion */
    float qw; /*< W quaternion */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  x: " << x << std::endl;
        ss << "  y: " << y << std::endl;
        ss << "  z: " << z << std::endl;
        ss << "  vx: " << vx << std::endl;
        ss << "  vy: " << vy << std::endl;
        ss << "  vz: " << vz << std::endl;
        ss << "  qx: " << qx << std::endl;
        ss << "  qy: " << qy << std::endl;
        ss << "  qz: " << qz << std::endl;
        ss << "  qw: " << qw << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << x;                             // offset: 0
        map << y;                             // offset: 4
        map << z;                             // offset: 8
        map << vx;                            // offset: 12
        map << vy;                            // offset: 16
        map << vz;                            // offset: 20
        map << qx;                            // offset: 24
        map << qy;                            // offset: 28
        map << qz;                            // offset: 32
        map << qw;                            // offset: 36
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> x;                             // offset: 0
        map >> y;                             // offset: 4
        map >> z;                             // offset: 8
        map >> vx;                            // offset: 12
        map >> vy;                            // offset: 16
        map >> vz;                            // offset: 20
        map >> qx;                            // offset: 24
        map >> qy;                            // offset: 28
        map >> qz;                            // offset: 32
        map >> qw;                            // offset: 36
    }
};

} // namespace msg
} // namespace roadrunner
} // namespace mavlink
