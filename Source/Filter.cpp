/*
  ==============================================================================

    Filter.cpp
    Created: 23 Oct 2020 6:22:17am
    Author:  will

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"


Filter::Filter(JuceSynthFrameworkAudioProcessor& p) :
processor(p)
{
    setSize(200, 200);

    filterSelector.addItem("Low Pass", 1);
    filterSelector.addItem("High Pass", 2);
    filterSelector.addItem("Band Pass", 3);
    filterSelector.setJustificationType(Justification::centred);
    addAndMakeVisible(&filterSelector);
    filterSelectorAttachment = std::make_unique<AudioProcessorValueTreeState::ComboBoxAttachment>(processor.valueTree, "FILTER_TYPE", filterSelector);

    filterCutoff.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterCutoff.setRange(20.0f, 10000.0f);
    filterCutoff.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    filterCutoff.setValue(400.0f);
    addAndMakeVisible(&filterCutoff);
    filterCutoffAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.valueTree, "FILTER_CUTOFF", filterCutoff);
    filterCutoff.setSkewFactorFromMidPoint(1000.0);

    filterResonance.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterResonance.setRange(1.0f, 5.0f);
    filterResonance.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    filterResonance.setValue(1.0f);
    addAndMakeVisible(&filterResonance);
    filterResonanceAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.valueTree, "FILTER_RESONANCE", filterResonance);

}

Filter::~Filter()
{
}

void Filter::paint (juce::Graphics& g)
{
    Rectangle<int> titleArea (0, 10, getWidth(), 20);

    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter", titleArea, Justification::centredTop);

    Rectangle<float> area (25, 25, 150, 150);

    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Filter::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);

    filterSelector.setBounds(area.removeFromTop(20));
    filterCutoff.setBounds(30, 100, 70, 70);
    filterResonance.setBounds(100, 100, 70, 70);
    

}
