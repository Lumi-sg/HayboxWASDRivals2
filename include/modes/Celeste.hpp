#ifndef _MODES_CELESTE_HPP
#define _MODES_CELESTE_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

class Celeste : public ControllerMode {
  public:
    Celeste(socd::SocdType horizontal_socd, socd::SocdType vertical_socd);

  private:
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
};

#endif
