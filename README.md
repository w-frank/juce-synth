# JUCE Synthesiser

## Download Maximilian
```bash
cd Source
git clone https://github.com/micknoise/Maximilian.git
```

Add `#include <limits>` to maximilian.h

# Setup VST3 Plugin Build

In /JuceLibraryCode/AppConfig.h, make sure:
```C++
    #define JUCE_PLUGINHOST_VST 0
    #define JUCE_PLUGINHOST_VST3 1
```