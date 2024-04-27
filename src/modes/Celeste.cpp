#include "modes/Celeste.hpp"

Celeste::Celeste(socd::SocdType horizontal_socd, socd::SocdType vertical_socd) {
    _socd_pair_count = 0;
}

void Celeste::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.start || inputs.up2;

    // Menu keys
    if (inputs.mod_y) {
        outputs.start = inputs.start;
    }

    // Right hand bottom row
    outputs.a = inputs.x || inputs.mod_x;
    outputs.x = inputs.a;
    outputs.b = inputs.b;
    outputs.z = inputs.z;


    // Directional Dashes
    if (inputs.c_up) {
        outputs.x = true;
        outputs.dpadUp = true;
    }
    if (inputs.c_right) {
        outputs.x = true;
        outputs.dpadRight = true;
    }
    if (inputs.c_down) {
        outputs.x = true;
        outputs.dpadDown = true;
    }
    if (inputs.c_left) {
        outputs.x = true;
        outputs.dpadLeft = true;
    }

}

void Celeste::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
    outputs.triggerLAnalog = outputs.triggerLDigital ? 255 : 0;
    outputs.triggerRAnalog = outputs.triggerRDigital ? 255 : 0;
}
