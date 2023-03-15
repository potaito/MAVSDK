#include "landing_target_server_impl.h"

namespace mavsdk {

LandingTargetServerImpl::LandingTargetServerImpl(
    std::shared_ptr<ServerComponent> server_component) :
    ServerPluginImplBase(server_component)
{
    _server_component_impl->register_plugin(this);
}

LandingTargetServerImpl::~LandingTargetServerImpl()
{
    _server_component_impl->unregister_plugin(this);
}

void LandingTargetServerImpl::init() {}

void LandingTargetServerImpl::deinit() {}

LandingTarget::Result
LandingTargetImpl::publish_landing_target_relative(LandingTarget::Position position)
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
        position.x,
        position.y,
        position.z,
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