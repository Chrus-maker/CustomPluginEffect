//
// Created by Christopher Pierre on 11/1/26.
//

#include "Square.h"
#include "BinaryData.h"

Square::Square()
    : coverImage (juce::ImageCache::getFromMemory (BinaryData::Wolf_Cover2_jpg,
                                                   BinaryData::Wolf_Cover2_jpgSize)),
    newImage(juce::ImageCache::getFromMemory(BinaryData::tyler_jpg,
        BinaryData::tyler_jpgSize))


{

}


void Square::Imagestate(bool useTyler) {
    if (usingtyler != useTyler) {
        usingtyler = useTyler;
        repaint();
    }
}

void Square::paint (juce::Graphics& g)
{
    const auto& currentImage = usingtyler ? newImage : coverImage;
    g.drawImageWithin (currentImage, 0, 0, getWidth(), getHeight(),
                       juce::RectanglePlacement::centred);
}

void Square::resized()
{
}
