# WolfSat

## Description 📝:
A audio satuator effect plugin built using the `JUCE` framework and `C++`. This project is inspired by my love for Tyler the Creator's use of saturation in his audio mixes. Thus, I built my own that replicated his sound and added fun UI designs to further it.

## Features 🚀:
Wolfsat comes with a saturator as the base with a drive knob to control the intensity of the wave curve and a volume knob to adjust the overall volume of the intrument to the user's liking. To appeal to Tyler the Creator fans, I also added a feature switch the background of the audio plugin which will not affect the audio mix but is a nice feature for the user to play with.

## Process 👾:
Throughtout the development process of this plugin, I fell into many rabbit holes of youtube videos and juce documnetion to get a clear picture on how the juce framework works as this was my first time using it. My first challenge was adding background changing logic. Figuring out how to communicate the background between the different files introduced itself as a diffcult task. However I succed with the logic and understood more about headers in c++ as a result

## Biggest Challenge 😱:
The biggest challenge that I had to face was customizing the look of the knobs, using the `lookandfeel_V4`. I had to build a circle from around the given rectangle object that juce gives by default. However by doing some math establsihing the radius through the diameter, I was able to have a nice gradient dial for both the volumen and the knob.

## What I Learned 🎓:
Through completing this project, I not only learned my way around the juce framework but also how audio is processed. I learned that audio process in the juce framework is given priority and thus adding a mutex lock for multithreading disrupts the logical flow. I heard with crackles and pops when I tried to add a wait mechanic to the audio process. Because audio is continous, it must not be interupted by another processs and thus be given priority.

## Demo Video:


## Whats Next 🎛️:
I would like to add all the rest of the albums covers to the background logic for ui changes. pertaining to audio changes, I would like to create a dry/wet slider that doesn't kill the audio input entirely but effects the plugin itself. Lastly, I would like to add a feature that will allow the user to adjust which frequency range will get hit with the saturation the most.

