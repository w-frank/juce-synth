/**
 * @file PluginEditor.cpp
 * 
 * @brief 
 * 
 * @author
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"


JuceSynthFrameworkAudioProcessorEditor::JuceSynthFrameworkAudioProcessorEditor (JuceSynthFrameworkAudioProcessor& p) :
AudioProcessorEditor (&p), processor (p), oscGui(p), envGui(p)
{
    setSize (400, 200);

    addAndMakeVisible(&oscGui);
    addAndMakeVisible(&envGui);

}

JuceSynthFrameworkAudioProcessorEditor::~JuceSynthFrameworkAudioProcessorEditor()
{
}

void JuceSynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void JuceSynthFrameworkAudioProcessorEditor::resized()
{

    Rectangle<int> area = getLocalBounds();

    const int componentWidth = 200;
    const int componentHeight = 200;

    oscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    envGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));

}