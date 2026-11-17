//
// Created by Christopher Pierre on 11/3/26.
//

#include "Background.h"

#include "juce_osc/osc/juce_OSCTypes.h"

Background::Background() {

}

void Background::BackgroundState(bool isColoured) {
    if (coloured != isColoured) {
        coloured = isColoured;
        repaint();
    }
}

void Background::paint(juce::Graphics& g) {
    const auto bounds = getLocalBounds().toFloat();

    // const auto& currentColour
    if (coloured == true) {
        const juce::ColourGradient gradient(
        juce::Colour(217, 50, 35), bounds.getX(), bounds.getY(),
        juce::Colour(153, 73, 26), bounds.getRight(), bounds.getBottom(),
        false);

        g.setGradientFill(gradient);
        g.fillRect(bounds);
    } else {
        const juce::ColourGradient gradient(
            juce::Colour(100, 200, 200), bounds.getX(), bounds.getY(),
            juce::Colour(255, 255, 255), bounds.getRight(), bounds.getBottom(),
            false);

        g.setGradientFill(gradient);
        g.fillRect(bounds);
    }


}