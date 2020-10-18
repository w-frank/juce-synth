# JUCE Synthesiser

## Download Maximilian
cd Source
git clone https://github.com/micknoise/Maximilian.git

#include <limits> in maximilian.h

# Setup VST3 Plugin Build
In /JuceLibraryCode/AppConfig.h
    #define JUCE_PLUGINHOST_VST 0
    #define JUCE_PLUGINHOST_VST3 1