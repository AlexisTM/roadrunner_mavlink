// MESSAGE TDOA_MEASUREMENT support class

#pragma once

namespace mavlink {
namespace roadrunner {
namespace msg {

/**
 * @brief TDOA_MEASUREMENT message
 *
 * TDOA Measurement
 */
struct TDOA_MEASUREMENT : mavlink::Message {
    static constexpr msgid_t MSG_ID = 4;
    static constexpr size_t LENGTH = 32;
    static constexpr size_t MIN_LENGTH = 32;
    static constexpr uint8_t CRC_EXTRA = 176;
    static constexpr auto NAME = "TDOA_MEASUREMENT";


    float anchor_ax; /*< Anchor Ax position */
    float anchor_ay; /*< Anchor Ay position */
    float anchor_az; /*< Anchor Az position */
    float anchor_bx; /*< Anchor Bx position */
    float anchor_by; /*< Anchor By position */
    float anchor_bz; /*< Anchor Bz position */
    float dist_diff; /*< Distance difference */
    float stddev; /*< Standard deviation of the measurement */


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
        ss << "  anchor_ax: " << anchor_ax << std::endl;
        ss << "  anchor_ay: " << anchor_ay << std::endl;
        ss << "  anchor_az: " << anchor_az << std::endl;
        ss << "  anchor_bx: " << anchor_bx << std::endl;
        ss << "  anchor_by: " << anchor_by << std::endl;
        ss << "  anchor_bz: " << anchor_bz << std::endl;
        ss << "  dist_diff: " << dist_diff << std::endl;
        ss << "  stddev: " << stddev << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << anchor_ax;                     // offset: 0
        map << anchor_ay;                     // offset: 4
        map << anchor_az;                     // offset: 8
        map << anchor_bx;                     // offset: 12
        map << anchor_by;                     // offset: 16
        map << anchor_bz;                     // offset: 20
        map << dist_diff;                     // offset: 24
        map << stddev;                        // offset: 28
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> anchor_ax;                     // offset: 0
        map >> anchor_ay;                     // offset: 4
        map >> anchor_az;                     // offset: 8
        map >> anchor_bx;                     // offset: 12
        map >> anchor_by;                     // offset: 16
        map >> anchor_bz;                     // offset: 20
        map >> dist_diff;                     // offset: 24
        map >> stddev;                        // offset: 28
    }
};

} // namespace msg
} // namespace roadrunner
} // namespace mavlink
