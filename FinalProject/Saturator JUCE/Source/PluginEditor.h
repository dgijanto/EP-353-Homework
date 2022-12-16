/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
 
//==============================================================================
/**
*/
class CodingFinalAudioProcessorEditor  :
    public juce::AudioProcessorEditor,
    public juce::Slider::Listener,
    public juce::ComboBox::Listener
{
public:
    CodingFinalAudioProcessorEditor (CodingFinalAudioProcessor&);
    ~CodingFinalAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CodingFinalAudioProcessor& audioProcessor;
    
    juce::Slider gain;
    juce::Slider output;
    juce::ComboBox disType;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CodingFinalAudioProcessorEditor)
};
