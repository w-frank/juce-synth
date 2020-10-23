/**
 * @file SynthVoice.h
 * 
 * @brief 
 * 
 * @author
 */


#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"


class SynthVoice : public SynthesiserVoice
{
public:
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast <SynthSound*>(sound) != nullptr;
    }

    void getOscWaveform(float waveform)
    {
        theWave = int(waveform);
    }

    double setOscWaveform()
    {
        switch(theWave)
        {
            case 0: return osc1.sinewave(frequency);
            case 1: return osc1.saw(frequency);
            case 2: return osc1.square(frequency);
            default: return osc1.sinewave(frequency); 
        }
    }

    void getEnvelope(float attack, float decay, float sustain, float release)
    {
        env1.setAttack(double(attack));
        env1.setDecay(double(decay));
        env1.setSustain(double(sustain));
        env1.setRelease(double(release));
    }

    double setEnvelope()
    {
        return env1.adsr(setOscWaveform(), env1.trigger);
    }

    void getFilter(float filterType, float filterCutoff, float filterResonance)
    {
        filterSelection = int(filterType);
        cutoff = filterCutoff;
        resonance = filterResonance;
    }

    double setFilter()
    {
        switch(filterSelection)
        {
            case 0: return filter1.lores(setEnvelope(), cutoff, resonance);
            case 1: return filter1.hires(setEnvelope(), cutoff, resonance);
            case 2: return filter1.bandpass(setEnvelope(), cutoff, resonance);
            default: return filter1.lores(setEnvelope(), cutoff, resonance);
        }
    }
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) override
    {
        env1.trigger = 1;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        level = velocity;
    }
    
    void stopNote (float velocity, bool allowTailOff) override
    {
        env1.trigger = 0;
        allowTailOff = true;
        
        if (velocity == 0)
            clearCurrentNote();
    }
    
    void pitchWheelMoved (int newPitchWheelValue) override
    {
        
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue) override
    {
        
    }
    
    void renderNextBlock (AudioBuffer <float> &outputBuffer, int startSample, int numSamples) override
    {
        for (int sample = 0; sample < numSamples; ++sample)
        {

            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, setFilter() * 0.3f);
            }
            ++startSample;
        }
    }

private:
    double level;
    double frequency;
    int theWave;

    int filterSelection;
    double cutoff;
    double resonance;
    
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;

};
