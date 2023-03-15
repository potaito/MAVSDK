#pragma once

#include "plugins/landing_target_server/landing_target_server.h"

#include "server_plugin_impl_base.h"


namespace mavsdk {


class LandingTargetServerImpl : public ServerPluginImplBase {
public:
    explicit LandingTargetServerImpl(std::shared_ptr<ServerComponent> server_component);

    ~LandingTargetServerImpl() override;

    void init() override;
    void deinit() override;





    LandingTargetServer::Result publish_landing_target_relative(LandingTargetServer::Position position);



private:
};

} // namespace mavsdk