// MESSAGE QUATERNION support class

#pragma once

namespace mavlink {
namespace roadrunner {
namespace msg {

/**
 * @brief QUATERNION message
 *
 * The Quaternion
 */
struct QUATERNION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 3;
    static constexpr size_t LENGTH = 32;
    static constexpr size_t MIN_LENGTH = 32;
    static constexpr uint8_t CRC_EXTRA = 182;
    static constexpr auto NAME = "QUATERNION";


    float qx; /*< X quaternion */
    float qy; /*< Y quaternion */
    float qz; /*< Z quaternion */
    float qw; /*< W quaternion */
    float Vqx; /*< X quaternion covariance */
    float Vqy; /*< Y quaternion covariance */
    float Vqz; /*< Z quaternion covariance */
    float Vqw; /*< W quaternion covariance */


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
        ss << "  qx: " << qx << std::endl;
        ss << "  qy: " << qy << std::endl;
        ss << "  qz: " << qz << std::endl;
        ss << "  qw: " << qw << std::endl;
        ss << "  Vqx: " << Vqx << std::endl;
        ss << "  Vqy: " << Vqy << std::endl;
        ss << "  Vqz: " << Vqz << std::endl;
        ss << "  Vqw: " << Vqw << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << qx;                            // offset: 0
        map << qy;                            // offset: 4
        map << qz;                            // offset: 8
        map << qw;                            // offset: 12
        map << Vqx;                           // offset: 16
        map << Vqy;                           // offset: 20
        map << Vqz;                           // offset: 24
        map << Vqw;                           // offset: 28
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> qx;                            // offset: 0
        map >> qy;                            // offset: 4
        map >> qz;                            // offset: 8
        map >> qw;                            // offset: 12
        map >> Vqx;                           // offset: 16
        map >> Vqy;                           // offset: 20
        map >> Vqz;                           // offset: 24
        map >> Vqw;                           // offset: 28
    }
};

} // namespace msg
} // namespace roadrunner
} // namespace mavlink
