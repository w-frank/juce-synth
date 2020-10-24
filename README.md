# JUCE Synthesiser

A simple MIDI controlled subtractive synthesiser built using the [JUCE](https://github.com/juce-framework/JUCE) 
audio application framework and  [Maximillian](https://github.com/micknoise/Maximilian) audio synthesis 
and signal processing library. Includes an oscillator with sine, square and saw waveforms, 
a configurable filter with cutoff and resonance control, and an envelope.

Based on the excellent tutorials by [The Audio Programmer](https://github.com/TheAudioProgrammer/juceSynthFramework).

## Build Environment
* JUCE v6.0.4
* Ubuntu 18.04.5 LTS

## Download Maximilian
```bash
cd Source
git clone https://github.com/micknoise/Maximilian.git
```

Add `#include <limits>` to `Maximilian/src/maximilian.h` for std::numeric_limits arithmetic type property queries.

## Setup VST3 Plugin Build

In /JuceLibraryCode/AppConfig.h, set:
```C++
    #define JUCE_VST3_CAN_REPLACE_VST2 0

    #define JUCE_PLUGINHOST_VST 0
    #define JUCE_PLUGINHOST_VST3 1
```

## Build
```bash
cd Builds/LinuxMakefile
make
```