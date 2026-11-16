//
// Created by Christopher Pierre on 11/3/26.
//

#include "Background.h"

Background::Background() {

}

void Background::paint(juce::Graphics& g) {
    const auto bounds = getLocalBounds().toFloat();
    const juce::ColourGradient gradient(
        juce::Colour(100, 200, 200), bounds.getX(), bounds.getY(),
        juce::Colour(255, 255, 255), bounds.getRight(), bounds.getBottom(),
        false);

    g.setGradientFill(gradient);
    g.fillRect(bounds);
}