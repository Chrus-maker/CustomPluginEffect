#pragma once

#include "Background.h"
#include "PluginProcessor.h"
#include "Square.h"
#include "Trashwang.h"
#include <juce_gui_basics/juce_gui_basics.h>

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
 //created an object in the editor
    Square square;
    juce::Slider intensity_Slider;
    juce::ToggleButton TylerButton;
    Trashwang trashwang;
    Background background;
    juce::TextButton playbutton;
    juce::Label frequencyLabel{"FrequencyLabel", "Frequency"};

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    juce::AudioProcessorValueTreeState::SliderAttachment freqSliderAttachtment;
    juce::AudioProcessorValueTreeState::ButtonAttachment playButtonAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};

//the gui that will update overtime


class TimedComponent : public juce::Component, public juce::Timer
{
    public:
    TimedComponent();
    ~TimedComponent() override;
    void timerCallback() override;
};




