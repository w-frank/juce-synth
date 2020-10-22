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

    void getEnvelope(float attack, float decay, float sustain, float release)
    {
        env1.setAttack(double(attack));
        env1.setDecay(double(decay));
        env1.setSustain(double(sustain));
        env1.setRelease(double(release));
    }

    void getOscWaveform(float waveform)
    {
        theWave = waveform;
    }

    double setOscWaveform()
    {
        //std::cout<<int(theWave)<<std::endl;
        switch(int(theWave))
        {
            case 0: return osc1.sinewave(frequency);
            case 1: return osc1.saw(frequency);
            case 2: return osc1.square(frequency);
            default: return osc1.sinewave(frequency); 
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

            double theSound = env1.adsr(setOscWaveform(), env1.trigger) * level;
            double filteredSound = filter1.lores(theSound, 200, 0.1);
            
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, theSound);
            }
            ++startSample;
        }
    }

private:
    double level;
    double frequency;
    int theWave;
    
    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter filter1;

};
