#pragma once

#include "plugins/precision_target/precision_target.h"

#include "plugin_impl_base.h"


namespace mavsdk {


class PrecisionTargetImpl : public PluginImplBase {
public:
    explicit PrecisionTargetImpl(System& system);
    explicit PrecisionTargetImpl(std::shared_ptr<System> system);

    ~PrecisionTargetImpl() override;

    void init() override;
    void deinit() override;

    void enable() override;
    void disable() override;



    PrecisionTarget::Result publish_position_relative(PrecisionTarget::PositionLocal position_local);



private:
    std::string debug_str = "PrecisionTargetServer: ";
};

} // namespace mavsdk