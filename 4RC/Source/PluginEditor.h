/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class _4rcAudioProcessorEditor  : public AudioProcessorEditor,
	private Slider::Listener, private ComboBox::Listener
{
public:
    _4rcAudioProcessorEditor (_4rcAudioProcessor&);
    ~_4rcAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    _4rcAudioProcessor& processor;

	void comboBoxChanged(ComboBox* cb) override;
	void sliderValueChanged(Slider* slider) override;

	Slider midiVolume;
	Label deviceSelectLbl;
	ComboBox deviceSelect;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_4rcAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
