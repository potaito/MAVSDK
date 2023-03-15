#pragma once

#include "plugins/landing_target/landing_target.h"

#include "plugin_impl_base.h"


namespace mavsdk {


class LandingTargetImpl : public PluginImplBase {
public:
    explicit LandingTargetImpl(System& system);
    explicit LandingTargetImpl(std::shared_ptr<System> system);

    ~LandingTargetImpl() override;

    void init() override;
    void deinit() override;

    void enable() override;
    void disable() override;



    LandingTarget::Result publish_position_relative(LandingTarget::PositionLocal position_local);



private:
    std::string debug_str = "LandingTargetServer: ";
};

} // namespace mavsdk