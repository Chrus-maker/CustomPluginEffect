//
// Created by Christopher Pierre on 11/1/26.
//

#include "TylerPicture.h"
#include "BinaryData.h"

TylerPicture::TylerPicture()
    : coverImage (juce::ImageCache::getFromMemory (BinaryData::Wolf_Remodel_png,
                                                   BinaryData::Wolf_Remodel_pngSize)),
    newImage(juce::ImageCache::getFromMemory(BinaryData::tyler_jpg,
        BinaryData::tyler_jpgSize))


{

}


void TylerPicture::Imagestate(bool useTyler) {
    if (usingtyler != useTyler) {
        usingtyler = useTyler;
        repaint();
    }
}

void TylerPicture::paint (juce::Graphics& g)
{
    const auto& currentImage = usingtyler ? newImage : coverImage;
    g.drawImageWithin (currentImage, 0, 0, getWidth(), getHeight(),
                       juce::RectanglePlacement::centred);
}

void TylerPicture::resized()
{
}
