// MESSAGE TDOA_MEASUREMENT_SHORT support class

#pragma once

namespace mavlink {
namespace roadrunner {
namespace msg {

/**
 * @brief TDOA_MEASUREMENT_SHORT message
 *
 * Anchor ID and position
 */
struct TDOA_MEASUREMENT_SHORT : mavlink::Message {
    static constexpr msgid_t MSG_ID = 6;
    static constexpr size_t LENGTH = 6;
    static constexpr size_t MIN_LENGTH = 6;
    static constexpr uint8_t CRC_EXTRA = 3;
    static constexpr auto NAME = "TDOA_MEASUREMENT_SHORT";


    uint8_t anchor_A; /*< Anchor ID */
    uint8_t anchor_B; /*< Anchor ID */
    float distance; /*< distance */


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
        ss << "  anchor_A: " << +anchor_A << std::endl;
        ss << "  anchor_B: " << +anchor_B << std::endl;
        ss << "  distance: " << distance << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << distance;                      // offset: 0
        map << anchor_A;                      // offset: 4
        map << anchor_B;                      // offset: 5
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> distance;                      // offset: 0
        map >> anchor_A;                      // offset: 4
        map >> anchor_B;                      // offset: 5
    }
};

} // namespace msg
} // namespace roadrunner
} // namespace mavlink
