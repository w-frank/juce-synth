/**
 * @file SynthSound.h
 * 
 * @brief 
 * 
 * @author
 */


#pragma once

#include "../JuceLibraryCode/JuceHeader.h"



class SynthSound : public SynthesiserSound
{

public:
    bool appliesToNote (int midiNoteNumber) override
    {
        return true;
    }
    
    bool appliesToChannel (int midiNoteNumber) override
    {
        return true;
    }    
};
