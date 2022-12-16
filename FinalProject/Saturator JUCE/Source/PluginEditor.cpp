/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h" 
#include "PluginEditor.h"

//==============================================================================
CodingFinalAudioProcessorEditor::CodingFinalAudioProcessorEditor (CodingFinalAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);

}

CodingFinalAudioProcessorEditor::~CodingFinalAudioProcessorEditor(){
    
}

//==============================================================================
void CodingFinalAudioProcessorEditor::paint (juce::Graphics& g){
    
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Saturator", getLocalBounds(), juce::Justification::centred, 1);
}

void CodingFinalAudioProcessorEditor::resized(){
    gain.setBounds(80, 40, 40, 40);
    output.setBounds(80, 120, 40, 40);
    disType.setBounds(70, 90, 60, 20);
}
