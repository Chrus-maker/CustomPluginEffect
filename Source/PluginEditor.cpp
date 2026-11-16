#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "juce_graphics/drawables/lunasvg/plutovg/source/plutovg-ft-types.h"

using namespace std::chrono_literals;

// Decribes the look of the plugin
//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), freqSliderAttachtment(processorRef.getState(), "gainknob", intensity_Slider),
    playButtonAttachment(processorRef.getState(), "play", playbutton)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    //
    // clock.startTimer(1000000);





    addAndMakeVisible(square);
    addAndMakeVisible(trashwang);

    addAndMakeVisible(intensity_Slider);
    addAndMakeVisible(background);
    addAndMakeVisible(playbutton);
    addAndMakeVisible(frequencyLabel);


    frequencyLabel.setJustificationType(juce::Justification::centred);

    intensity_Slider.setMouseDragSensitivity(1000);
    intensity_Slider.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    intensity_Slider.setNumDecimalPlacesToDisplay(0);
    frequencyLabel.setColour(juce::Label::textColourId, juce::Colours::black);


    playbutton.setButtonText("Playing");
    playbutton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playbutton.setClickingTogglesState(true);

    playbutton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colour(53,124,154));
    playbutton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colour(53,124,241));
    intensity_Slider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(255,255,255) );
    intensity_Slider.setTextValueSuffix("hz");

    playbutton.onClick=[this]() {
      //change the state of the button when clicked

        const bool isPlaying = playbutton.getToggleState();
        playbutton.setButtonText(isPlaying ? "Playing" : "Bypass");
    };

    intensity_Slider.setColour(3,juce::Colours::red);
    background.toBack();
    intensity_Slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true,100,50);



    setSize (400, 600);



}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void AudioPluginAudioProcessorEditor::resized()
{
    intensity_Slider.setBounds(100,300,200,200);
    square.setBounds(100,50,200,200); // picture
    background.setBounds (getLocalBounds());
    trashwang.setBounds (90, 190, 200, 200);
    intensity_Slider.setColour(30,juce::Colours::red);
    intensity_Slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow,
    FALSE, 80,50);
    playbutton.setBounds(getWidth() / 2 - 50, 550, 100, 20);
    frequencyLabel.setBounds(getWidth() / 2 - 50, 280, 100, 20);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void TimedComponent::timerCallback()
{


}

