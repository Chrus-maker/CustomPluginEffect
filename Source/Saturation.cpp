//
// Created by Christopher Pierre on 11/11/26.
//

#include "Saturation.h"

Saturation::Saturation() {

}
Saturation::~Saturation() {

}

float Saturation::processSample(float inputSample) {
    float driven = inputSample * drive;
    float clipped = std::tanh(driven);
    return clipped * gain;
}

// void Saturation::setDrive(float newDrive) {
//     drive = newDrive;
//     gain = 1.0f / std::tanh(drive);
// }

void Saturation::testprocess(juce::AudioBuffer<float> &buffer) {
    const auto numChannels = buffer.getNumChannels();


}


