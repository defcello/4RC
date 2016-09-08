/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
_4rcAudioProcessorEditor::_4rcAudioProcessorEditor (_4rcAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);

	midiVolume.setSliderStyle(Slider::LinearBarVertical);
	midiVolume.setRange(0.0, 127.0, 1.0);
	midiVolume.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	midiVolume.setPopupDisplayEnabled(true, this);
	midiVolume.setTextValueSuffix(" Volume");
	midiVolume.setValue(1.0);
	midiVolume.addListener(this);

	char* synths[2] = {
		"Microsoft GS Wavetable Synth",
		"Roland Fantom-XR",
	};
	deviceSelect.addItemList(StringArray(synths, 2), 1);
	deviceSelectLbl.setText(
		deviceSelect.getItemText(deviceSelect.getSelectedItemIndex()),
		juce::NotificationType::sendNotification
	);
	addAndMakeVisible(&midiVolume);
	addAndMakeVisible(&deviceSelect);
	addAndMakeVisible(&deviceSelectLbl);
}

_4rcAudioProcessorEditor::~_4rcAudioProcessorEditor()
{
}

//==============================================================================
void _4rcAudioProcessorEditor::comboBoxChanged(ComboBox* cb) {
	int selectedIdx = cb->getSelectedItemIndex();
	int selectedId = cb->getSelectedId();
	String selectedTxt = cb->getItemText(selectedIdx);
	DBG(String::formatted("Selected Item %d: '%s'", selectedId, selectedTxt));
	deviceSelectLbl.setText(selectedTxt, juce::NotificationType::sendNotification);
}

void _4rcAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	processor.noteOnVel = midiVolume.getValue();
}

void _4rcAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
    g.drawFittedText ("Midi Volume", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void _4rcAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	int padding = 5;
	midiVolume.setBounds(40, 30, 20, getHeight() - 60);
	deviceSelect.setBounds(midiVolume.getX() + midiVolume.getWidth() + padding, midiVolume.getY(), 20, 20);
	deviceSelectLbl.setBounds(deviceSelect.getX() + deviceSelect.getWidth(), deviceSelect.getY(), 100, 20);
}
