#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include "juce_graphics/image_formats/jpglib/jconfig.h"
#include "juce_graphics/image_formats/pnglib/png.h"

//inherenit from the juce libriary
//bc right now it doesn't know about juce
//displays the picture of tyler the creator
class TylerPicture : public juce::Component
{
public:
    TylerPicture();
    void paint (juce::Graphics&) override;
    void resized() override;
    juce::Image coverImage;
    void Imagestate(bool useTyler);



private:
    juce::Image newImage;
    bool usingtyler = false;


};