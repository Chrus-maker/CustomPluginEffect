//
// Created by Christopher Pierre on 11/11/26.
//

#ifndef SIMPLEJUCEPLUGINTEMPLATE_SATURATION_H
#define SIMPLEJUCEPLUGINTEMPLATE_SATURATION_H
#include <juce_audio_basics/juce_audio_basics.h>
#include <vector>

class Saturation {
public:

    Saturation();
    ~Saturation();

    void prepare (double sampleRate, int numChannels);
    float processSample(float inputSample);
    void testprocess(juce::AudioBuffer<float>&buffer);

    void setDrive(float newDrive){drive = newDrive;}
    void setGain(float newGain){gain = newGain;}

    std::vector<float> currentTime;
    private:
    float drive = 2.0f;
    float gain = 3.7f;



};


#endif //SIMPLEJUCEPLUGINTEMPLATE_SATURATION_H
