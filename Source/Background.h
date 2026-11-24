#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

class Background : public juce::Component {

public:
    Background();

    void paint (juce::Graphics&) override;
    void BackgroundState(bool isColoured);
    juce::Image backgroundImage;
    juce::Image newbackgroundImage;
    int contrast = 183;
private:
    bool coloured = false;

};