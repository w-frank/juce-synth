/**
 * @file Oscillator.cpp
 * 
 * @brief 
 * 
 * @author
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"


Oscillator::Oscillator(JuceSynthFrameworkAudioProcessor& p) :
processor(p)
{

    setSize(200, 200);

    wavefromSelector.addItem("Sine", 1);
    wavefromSelector.addItem("Saw", 2);
    wavefromSelector.addItem("Square", 3);
    addAndMakeVisible(&wavefromSelector);
    wavefromSelector.setJustificationType(Justification::centred);

    waveformSelectorAttachment = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.valueTree, "WAVEFORM", wavefromSelector);

}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
}

void Oscillator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);

    wavefromSelector.setBounds(area.removeFromTop(20));

}