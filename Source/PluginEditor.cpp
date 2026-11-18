#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "juce_graphics/drawables/lunasvg/plutovg/source/plutovg-ft-types.h"

using namespace std::chrono_literals;

// Decribes the look of the plugin
//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), gainSliderAttachtment(processorRef.getState(), "gainknob", gain_Slider),
    driveSliderAttachment(processorRef.getState(), "driveknob", drive_Slider),
    playButtonAttachment(processorRef.getState(), "play", playbutton)
{

    juce::ignoreUnused (processorRef);
    startTimer(100);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    //
    // clock.startTimer(1000000);





    addAndMakeVisible(square);
    addAndMakeVisible(trashwang);
    addAndMakeVisible(drive_Slider);
    addAndMakeVisible(gain_Slider);
    addAndMakeVisible(background);
    addAndMakeVisible(playbutton);
    addAndMakeVisible(driveLabel);
    addAndMakeVisible(intensityLabel);
    addAndMakeVisible(companyLabel);

    driveLabel.setJustificationType(juce::Justification::centred);
    intensityLabel.setJustificationType(juce::Justification::centred);
    companyLabel.setJustificationType(juce::Justification::centred);

    gain_Slider.setMouseDragSensitivity(1000);
    gain_Slider.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    gain_Slider.setNumDecimalPlacesToDisplay(0);
    drive_Slider.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    gain_Slider.setNumDecimalPlacesToDisplay(0);

    driveLabel.setColour(juce::Label::textColourId, juce::Colours::black);
    intensityLabel.setColour(juce::Label::textColourId, juce::Colours::black);


    playbutton.setButtonText("Playing");
    playbutton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playbutton.setClickingTogglesState(true);

    playbutton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colour(53,124,154));
    playbutton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colour(53,124,241));
    gain_Slider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(255,255,255) );
    gain_Slider.setTextValueSuffix("hz");

    playbutton.onClick=[this]() {
      //change the state of the button when clicked

        const bool isPlaying = playbutton.getToggleState();
        playbutton.setButtonText(isPlaying ? "Playing" : "Bypass");
    };

    gain_Slider.setColour(3,juce::Colours::red);
    background.toBack();
    gain_Slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true,100,50);



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
    gain_Slider.setBounds(10,300,200,200);
    drive_Slider.setBounds(200,300,200,200);

    square.setBounds(100,50,200,200); // picture

    background.setBounds (getLocalBounds());

    trashwang.setBounds (90, 190, 200, 200);

    gain_Slider.setColour(30,juce::Colours::red);
    gain_Slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow,
    FALSE, 80,50);
    drive_Slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow,
FALSE, 80,50);

    playbutton.setBounds(getWidth() / 2 - 50, 550, 100, 20);
    driveLabel.setBounds(250, 280, 100, 20);
    intensityLabel.setBounds(60, 280, 100, 20);
    companyLabel.setBounds(300, 10,100,20);

    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void TimedComponent::timerCallback()
{


}

