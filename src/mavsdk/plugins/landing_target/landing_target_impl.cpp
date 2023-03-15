#include "landing_target_impl.h"
#include <chrono>

namespace mavsdk {


LandingTargetImpl::LandingTargetImpl(System& system) : PluginImplBase(system)
{
    _parent->register_plugin(this);
}

LandingTargetImpl::LandingTargetImpl(std::shared_ptr<System> system) : PluginImplBase(std::move(system))
{
    _parent->register_plugin(this);
}


LandingTargetImpl::~LandingTargetImpl()
{

    _parent->unregister_plugin(this);

}

void LandingTargetImpl::init() {}

void LandingTargetImpl::deinit() {}


void LandingTargetImpl::enable() {}

void LandingTargetImpl::disable() {}






LandingTarget::Result LandingTargetImpl::publish_position_relative(LandingTarget::PositionLocal position_local)
{
    uint64_t unix_timestamp = std::chrono::seconds(std::time(NULL)).count();
    float target_num = 0;
    float angle_x_rad = 0;
    float angle_y_rad = 0;
    float distance = 0;
    float size_x = 0;
    float size_y = 0;
    const float q[4] = {};
    bool position_valid = true;

    mavlink_message_t msg;
    mavlink_msg_landing_target_pack(
        _parent->get_own_system_id(),
        _parent->get_own_component_id(),
        &msg,
        unix_timestamp,
        target_num,
        MAV_FRAME_LOCAL_NED,
        angle_x_rad,
        angle_y_rad,
        distance,
        size_x,
        size_y,
        position_local.x,
        position_local.y,
        position_local.z,
        q,
        LANDING_TARGET_TYPE_VISION_OTHER,
        position_valid);

    if (!_parent->send_message(msg)) {
        LogErr() << debug_str << "publish_landing_target_relative() failed..";
        return LandingTarget::Result::Unknown;
    }

    return LandingTarget::Result::Success;
}



} // namespace mavsdk