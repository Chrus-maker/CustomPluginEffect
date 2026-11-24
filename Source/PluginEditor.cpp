#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <list>
#include "juce_graphics/drawables/lunasvg/plutovg/source/plutovg-ft-types.h"
#include "juce_osc/osc/juce_OSCTypes.h"

using namespace std::chrono_literals;

// Decribes the look of the plugin
//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p), gainSliderAttachtment(processorRef.getState(), "gainknob", gain_Slider),
    driveSliderAttachment(processorRef.getState(), "volumeknob", drive_Slider),
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
    //addAndMakeVisible(playbutton);
    addAndMakeVisible(VolumeLabel);
    addAndMakeVisible(DriveLabel);
    addAndMakeVisible(companyLabel);

    gain_Slider.setLookAndFeel(&otherLookAndFeel);
    drive_Slider.setLookAndFeel(&otherLookAndFeel);

    getLookAndFeel().setColour(juce::Slider::thumbColourId, juce::Colours::purple);
    getLookAndFeel().setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::teal);
    getLookAndFeel().setColour(juce::Slider::backgroundColourId, juce::Colours::white);






    VolumeLabel.setJustificationType(juce::Justification::centred);
    DriveLabel.setJustificationType(juce::Justification::centred);
    companyLabel.setJustificationType(juce::Justification::centred);
    gain_Slider.setMouseDragSensitivity(1000);
    gain_Slider.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    gain_Slider.setNumDecimalPlacesToDisplay(0);
    drive_Slider.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    gain_Slider.setNumDecimalPlacesToDisplay(0);

    VolumeLabel.setColour(juce::Label::textColourId, juce::Colours::black);
    // VolumeLabel.setFont(juce::Font());
    auto list = juce::Font::findAllTypefaceNames();
    juce::Font customFont (juce::FontOptions("Poleno", 20.0f, juce::Font::bold));

    VolumeLabel.setFont(customFont);
    DriveLabel.setFont(customFont);
    auto textColor = 100;
    DriveLabel.setColour(textColor, juce::Colour(23,255,255));
    companyLabel.setFont(customFont);
   // VolumeLabel.setFont(juce::Font(juce::FontOptions().withName(list[40])));
    //DriveLabel.setFont(juce::Font(juce::FontOptions().withName(list[40])));
    //VolumeLabel.setFont(juce::FontOptions().withUnderline());
    //DriveLabel.setFont(juce::FontOptions().withUnderline());
    //30


    DriveLabel.setColour(juce::Label::textColourId, juce::Colours::black);


    playbutton.setButtonText("Playing");
    playbutton.setToggleState(true, juce::NotificationType::dontSendNotification);
    playbutton.setClickingTogglesState(true);

    playbutton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colour(53,124,154));
    playbutton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colour(53,124,241));
    gain_Slider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colour(255,255,255) );
    gain_Slider.setTextValueSuffix("");

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

    auto height = getHeight();
    auto width = getWidth();

    gain_Slider.setBounds(width/16,height/1.8,160,150);
    drive_Slider.setBounds(width/2,height/1.8,160,150);

    square.setBounds(100,50,200,200); // picture

    background.setBounds (getLocalBounds());

    trashwang.setBounds (90, 190, 200, 200);

    std::cout << height << std::endl;
    std::cout << width << std::endl;

    gain_Slider.setColour(30,juce::Colours::red);
    gain_Slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox,
    FALSE, 70,50);
    drive_Slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox,
FALSE, 80,50);

    playbutton.setBounds(getWidth() / 2 - 50, 550, 100, 20);

    VolumeLabel.setBounds(width/2, height/2, 150, 20);
    DriveLabel.setBounds(width/16, height/2, 150, 20);

    companyLabel.setBounds(300, 10,100,20);



    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void TimedComponent::timerCallback()
{


}

