// MESSAGE TDOA_ANCHOR support class

#pragma once

namespace mavlink {
namespace roadrunner {
namespace msg {

/**
 * @brief TDOA_ANCHOR message
 *
 * Anchor ID and position
 */
struct TDOA_ANCHOR : mavlink::Message {
    static constexpr msgid_t MSG_ID = 5;
    static constexpr size_t LENGTH = 13;
    static constexpr size_t MIN_LENGTH = 13;
    static constexpr uint8_t CRC_EXTRA = 254;
    static constexpr auto NAME = "TDOA_ANCHOR";


    uint8_t ID; /*< Anchor ID */
    float x; /*< Anchor X */
    float y; /*< Anchor Y */
    float z; /*< Anchor Z */


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
        ss << "  ID: " << +ID << std::endl;
        ss << "  x: " << x << std::endl;
        ss << "  y: " << y << std::endl;
        ss << "  z: " << z << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << x;                             // offset: 0
        map << y;                             // offset: 4
        map << z;                             // offset: 8
        map << ID;                            // offset: 12
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> x;                             // offset: 0
        map >> y;                             // offset: 4
        map >> z;                             // offset: 8
        map >> ID;                            // offset: 12
    }
};

} // namespace msg
} // namespace roadrunner
} // namespace mavlink
