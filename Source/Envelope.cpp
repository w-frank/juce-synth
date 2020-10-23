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
    Rectangle<int> titleArea (0, 10, getWidth(), 20);

    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    g.drawText("Envelope", titleArea, Justification::centredTop);

    // TODO: Static positioning for now, make dynamic
    g.drawText("A", 53, 150, 20, 20, Justification::centredTop);
    g.drawText("D", 77, 150, 20, 20, Justification::centredTop);
    g.drawText("S", 103, 150, 20, 20, Justification::centredTop);
    g.drawText("R", 128, 150, 20, 20, Justification::centredTop);

    Rectangle<float> area (25, 25, 150, 150);

    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Envelope::resized()
{

    Rectangle<int> area = getLocalBounds().reduced(50);

    int sliderWidth = 25;
    int sliderHeight = 175;

    attackSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    decaySlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    sustainSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    releaseSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));

}
