// MESSAGE GYRO_ACC_TEMP support class

#pragma once

namespace mavlink {
namespace roadrunner {
namespace msg {

/**
 * @brief GYRO_ACC_TEMP message
 *
 * The Gryo and Accelerometer readings S.I. body frame.
 */
struct GYRO_ACC_TEMP : mavlink::Message {
    static constexpr msgid_t MSG_ID = 1;
    static constexpr size_t LENGTH = 28;
    static constexpr size_t MIN_LENGTH = 28;
    static constexpr uint8_t CRC_EXTRA = 61;
    static constexpr auto NAME = "GYRO_ACC_TEMP";


    float xacc; /*< X acceleration */
    float yacc; /*< Y acceleration */
    float zacc; /*< Z acceleration */
    float xgyro; /*< Angular speed around X axis */
    float ygyro; /*< Angular speed around Y axis */
    float zgyro; /*< Angular speed around Z axis */
    float temperature; /*< Temperature */


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
        ss << "  xacc: " << xacc << std::endl;
        ss << "  yacc: " << yacc << std::endl;
        ss << "  zacc: " << zacc << std::endl;
        ss << "  xgyro: " << xgyro << std::endl;
        ss << "  ygyro: " << ygyro << std::endl;
        ss << "  zgyro: " << zgyro << std::endl;
        ss << "  temperature: " << temperature << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << xacc;                          // offset: 0
        map << yacc;                          // offset: 4
        map << zacc;                          // offset: 8
        map << xgyro;                         // offset: 12
        map << ygyro;                         // offset: 16
        map << zgyro;                         // offset: 20
        map << temperature;                   // offset: 24
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> xacc;                          // offset: 0
        map >> yacc;                          // offset: 4
        map >> zacc;                          // offset: 8
        map >> xgyro;                         // offset: 12
        map >> ygyro;                         // offset: 16
        map >> zgyro;                         // offset: 20
        map >> temperature;                   // offset: 24
    }
};

} // namespace msg
} // namespace roadrunner
} // namespace mavlink
