/**
 * @file Envelope.cpp
 * 
 * @brief 
 * 
 * @author
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"


Envelope::Envelope(JuceSynthFrameworkAudioProcessor& p) :
processor(p)
{

    setSize(200, 200);

    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    //attackSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    attackSlider.setValue(0.1f);
    addAndMakeVisible(&attackSlider);

    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(1.0f, 2000.0f);
    //decaySlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    decaySlider.setValue(1.0f);
    addAndMakeVisible(&decaySlider);

    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0.0f, 1.0f);
    //sustainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    sustainSlider.setValue(0.8f);
    addAndMakeVisible(&sustainSlider);

    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    //releaseSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 20, 10);
    releaseSlider.setValue(0.1f);
    addAndMakeVisible(&releaseSlider);

    attackSliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.valueTree, "ATTACK", attackSlider);
    decaySliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.valueTree, "DECAY", decaySlider);
    sustainSliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.valueTree, "SUSTAIN", sustainSlider);
    releaseSliderAttachment = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.valueTree, "RELEASE", releaseSlider);

}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
}

void Envelope::resized()
{

    Rectangle<int> area = getLocalBounds().reduced(40);
    attackSlider.setBounds(10, 10, 40, 100);
    decaySlider.setBounds(60, 10, 40, 100);
    sustainSlider.setBounds(110, 10, 40, 100);
    releaseSlider.setBounds(160, 10, 40, 100);

}
