#pragma once

#include "Background.h"
#include "PluginProcessor.h"
#include "Square.h"
#include "Trashwang.h"
#include <juce_gui_basics/juce_gui_basics.h>
#include <BinaryData.h>

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor, private juce::Timer
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
    juce::Slider gain_Slider;
    juce::Slider drive_Slider;
    juce::ToggleButton TylerButton;
    Trashwang trashwang;
    Background background;
    juce::TextButton playbutton;
    juce::Label driveLabel{"driveLabel", "Drive"};
    juce::Label gainLabel{"gainLabel", "Gain"};

    void timerCallback() override {
        bool highdrive = (drive_Slider.getValue() > 10);
        square.Imagestate(highdrive);
    }
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    juce::AudioProcessorValueTreeState::SliderAttachment gainSliderAttachtment;
    juce::AudioProcessorValueTreeState::SliderAttachment driveSliderAttachment;
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



