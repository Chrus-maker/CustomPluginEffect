#pragma once

#include "Background.h"
#include "PluginProcessor.h"
#include "TylerPicture.h"
#include "Trashwang.h"
#include <juce_gui_basics/juce_gui_basics.h>
#include <BinaryData.h>





class OtherLookAndFeel : public juce::LookAndFeel_V4 {
public:
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
        float rotaryStartAngle, float rotaryEndAngle, juce::Slider &slider) override
    {

        auto wolf = juce::ImageCache::getFromMemory(BinaryData::Image_background_jpg, BinaryData::Image_background_jpgSize);
        juce::ignoreUnused (slider);

        constexpr float outlineThickness = 5.0f;
        const float diameter = juce::jmax (0.0f, static_cast<float> (juce::jmin (width, height)) - outlineThickness);
        const float radius = diameter * 0.5f;
        const float centreX = static_cast<float> (x) + static_cast<float> (width) * 0.5f;
        const float centreY = static_cast<float> (y) + static_cast<float> (height) * 0.5f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

        const juce::Rectangle<float> dialArea (centreX - radius, centreY - radius, diameter, diameter);

        g.setColour(juce::Colours::transparentBlack);
        g.fillEllipse(dialArea);



        g.setColour(juce::Colours::teal);
        juce::Path dialTick;
        dialTick.addRectangle (0.0f, -radius, outlineThickness, radius);
        g.fillPath (dialTick, juce::AffineTransform::rotation (angle).translated (centreX, centreY));


        const juce::ColourGradient gradient(
            juce::Colour(100,200,200), centreX, centreY,
            juce::Colour(255,255,255), centreX-radius, centreY-radius, false);
        g.setGradientFill(gradient);
        g.drawEllipse (dialArea, outlineThickness);

    }

};

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
    TylerPicture square;
    juce::Slider gain_Slider;
    juce::Slider drive_Slider;
    juce::ToggleButton TylerButton;
    Trashwang trashwang;
    OtherLookAndFeel otherLookAndFeel;
    Background background;
    juce::TextButton playbutton;
    juce::Label VolumeLabel{"VolumeLabel", "Volume"};
    juce::Label DriveLabel{"gainLabel", "Drive"};
    juce::Label companyLabel{"companyLabel", "Krisp Sounds"};


    void timerCallback() override {
        bool highdrive = (gain_Slider.getValue() > 3.5);
        square.Imagestate(highdrive);
        background.BackgroundState(highdrive);

        if (drive_Slider.getValue() > 10) {
            for (float i = 0; i < drive_Slider.getValue(); i = i + 2) {
                background.contrast++;

            }
        }


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


