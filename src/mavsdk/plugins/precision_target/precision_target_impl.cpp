#include "precision_target_impl.h"
#include <chrono>

namespace mavsdk {

PrecisionTargetImpl::PrecisionTargetImpl(System& system) : PluginImplBase(system)
{
    _parent->register_plugin(this);
}

PrecisionTargetImpl::PrecisionTargetImpl(std::shared_ptr<System> system) :
    PluginImplBase(std::move(system))
{
    _parent->register_plugin(this);
}

PrecisionTargetImpl::~PrecisionTargetImpl()
{
    _parent->unregister_plugin(this);
}

void PrecisionTargetImpl::init() {}

void PrecisionTargetImpl::deinit() {}

void PrecisionTargetImpl::enable() {}

void PrecisionTargetImpl::disable() {}

PrecisionTarget::Result PrecisionTargetImpl::publish_position_relative(
    PrecisionTarget::PositionLocal position_local,
    PrecisionTarget::ObservationFrame observation_frame)
{
    const uint64_t unix_timestamp = std::chrono::seconds(std::time(NULL)).count();
    const float target_num = 0;
    uint8_t frame = NAN;
    float angle_x_rad = NAN;
    float angle_y_rad = NAN;
    const float distance = NAN;
    const float size_x = NAN;
    const float size_y = NAN;
    float pos_x_m = NAN;
    float pos_y_m = NAN;
    float pos_z_m = NAN;
    const float q[4] = {}; // TODO: Needs to be added to PROTO for orientation
    bool position_valid = true;

    switch (observation_frame) {
        case PrecisionTarget::ObservationFrame::LocalNed:
            frame = MAV_FRAME_LOCAL_NED;
            pos_x_m = position_local.x;
            pos_y_m = position_local.y;
            pos_z_m = position_local.z;
            break;

        case PrecisionTarget::ObservationFrame::BodyFrd:
            frame = MAV_FRAME_BODY_FRD;
            position_valid = false;
            angle_x_rad = position_local.x / position_local.z;
            angle_y_rad = position_local.y / position_local.z;
            break;
    }

    mavlink_message_t msg;
    mavlink_msg_landing_target_pack(
        _parent->get_own_system_id(),
        _parent->get_own_component_id(),
        &msg,
        unix_timestamp,
        target_num,
        frame,
        angle_x_rad,
        angle_y_rad,
        distance,
        size_x,
        size_y,
        pos_x_m,
        pos_y_m,
        pos_z_m,
        q,
        LANDING_TARGET_TYPE_VISION_OTHER,
        position_valid);

    if (!_parent->send_message(msg)) {
        LogErr() << debug_str << "publish_landing_target_relative() failed..";
        return PrecisionTarget::Result::Unknown;
    }

    return PrecisionTarget::Result::Success;
}

} // namespace mavsdk