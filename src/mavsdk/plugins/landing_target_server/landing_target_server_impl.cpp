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

LandingTargetServer::Result
LandingTargetServerImpl::publish_landing_target_relative(LandingTargetServer::Position position)
{
    UNUSED(position);

    // TODO :)
    return {};
}

} // namespace mavsdk