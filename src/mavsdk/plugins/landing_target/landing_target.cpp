// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/landing_target/landing_target.proto)

#include <iomanip>

#include "landing_target_impl.h"
#include "plugins/landing_target/landing_target.h"

namespace mavsdk {

using PositionLocal = LandingTarget::PositionLocal;




LandingTarget::LandingTarget(System& system) : PluginBase(), _impl{std::make_unique<LandingTargetImpl>(system)} {}

LandingTarget::LandingTarget(std::shared_ptr<System> system) : PluginBase(), _impl{std::make_unique<LandingTargetImpl>(system)} {}


LandingTarget::~LandingTarget() {}





LandingTarget::Result LandingTarget::publish_position_relative(PositionLocal position_local) const
{
    return _impl->publish_position_relative(position_local);
}



bool operator==(const LandingTarget::PositionLocal& lhs, const LandingTarget::PositionLocal& rhs)
{
    return
        ((std::isnan(rhs.x) && std::isnan(lhs.x)) || rhs.x == lhs.x) &&
        ((std::isnan(rhs.y) && std::isnan(lhs.y)) || rhs.y == lhs.y) &&
        ((std::isnan(rhs.z) && std::isnan(lhs.z)) || rhs.z == lhs.z);
}

std::ostream& operator<<(std::ostream& str, LandingTarget::PositionLocal const& position_local)
{
    str << std::setprecision(15);
    str << "position_local:" << '\n'
        << "{\n";
    str << "    x: " << position_local.x << '\n';
    str << "    y: " << position_local.y << '\n';
    str << "    z: " << position_local.z << '\n';
    str << '}';
    return str;
}



std::ostream& operator<<(std::ostream& str, LandingTarget::Result const& result)
{
    switch (result) {
        case LandingTarget::Result::Unknown:
            return str << "Unknown";
        case LandingTarget::Result::Success:
            return str << "Success";
        case LandingTarget::Result::NoSystem:
            return str << "No System";
        default:
            return str << "Unknown";
    }
}




} // namespace mavsdk