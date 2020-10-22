/**
 * @file Envelope.h
 * 
 * @brief 
 * 
 * @author
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class Envelope : public Component
{
public:
    Envelope(JuceSynthFrameworkAudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;

private:

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceSynthFrameworkAudioProcessor& processor;

    Slider attackSlider;
    Slider decaySlider;
    Slider sustainSlider;
    Slider releaseSlider;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> decaySliderAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sustainSliderAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
