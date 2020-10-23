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
    Rectangle<int> titleArea (0, 10, getWidth(), 20);

    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Oscillator", titleArea, Justification::centredTop);

    Rectangle<float> area (25, 25, 150, 150);

    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Oscillator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);

    wavefromSelector.setBounds(area.removeFromTop(20));

}