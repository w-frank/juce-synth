/**
 * @file Oscillator.h
 * 
 * @brief 
 * 
 * @author
 */

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class Oscillator : public Component
{
public:
    Oscillator(JuceSynthFrameworkAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;

private:
    ComboBox wavefromSelector;

    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> waveformSelectorAttachment;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceSynthFrameworkAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
