//
// Created by Christopher Pierre on 11/3/26.
//

#include "Background.h"

#include "BinaryData.h"
#include "juce_osc/osc/juce_OSCTypes.h"

Background::Background()
    : backgroundImage(juce::ImageCache::getFromMemory (BinaryData::Image_background_jpg,
                        BinaryData::Image_background_jpgSize)),
     newbackgroundImage(juce::ImageCache::getFromMemory (BinaryData::flowerbackground_jpg,
         BinaryData::flowerbackground_jpgSize))
{

}

void Background::BackgroundState(bool isColoured) {
    if (coloured != isColoured) {
        coloured = isColoured;
        repaint();
    }
}

void Background::paint(juce::Graphics& g) {
    const auto InitialBounds = getLocalBounds();
    const auto NewBounds = getLocalBounds().toFloat();

    // const auto& currentColour
    if (coloured == true) {



        g.drawImageWithin(newbackgroundImage, InitialBounds.getX(), InitialBounds.getY(),
           InitialBounds.getWidth(),InitialBounds.getHeight(),juce::RectanglePlacement::stretchToFit);


        // const juce::ColourGradient gradient(juce::Colour(183,61,63), NewBounds.getX(), NewBounds.getY(),
        //                                     juce::Colours::darkred,NewBounds.getRight(),NewBounds.getBottom(),
        // false);






    } else {




        // const juce::ColourGradient gradient(
        //     juce::Colour(100, 200, 200), bounds.getX(), bounds.getY(),
        //     juce::Colour(255, 255, 255), bounds.getRight(), bounds.getBottom(),
        //     false);

        g.drawImageWithin(backgroundImage, InitialBounds.getX(), InitialBounds.getY(),
            InitialBounds.getWidth(),InitialBounds.getHeight(),juce::RectanglePlacement::stretchToFit);
        // g.setGradientFill(gradient);
        // g.fillRect(bounds);
    }


}