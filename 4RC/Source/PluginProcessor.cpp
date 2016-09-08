/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
_4rcAudioProcessor::_4rcAudioProcessor()
{
}

_4rcAudioProcessor::~_4rcAudioProcessor()
{
}

//==============================================================================
const String _4rcAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool _4rcAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool _4rcAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double _4rcAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int _4rcAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int _4rcAudioProcessor::getCurrentProgram()
{
    return 0;
}

void _4rcAudioProcessor::setCurrentProgram (int index)
{
}

const String _4rcAudioProcessor::getProgramName (int index)
{
    return String();
}

void _4rcAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void _4rcAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void _4rcAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool _4rcAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void _4rcAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	buffer.clear();

	MidiBuffer processedMidi;
	int time;
	MidiMessage m;

	for (MidiBuffer::Iterator i(midiMessages); i.getNextEvent(m, time);) {
		if (m.isNoteOn()) {
			uint8 newVal = (uint8)noteOnVel;
			m = MidiMessage::noteOn(m.getChannel(), m.getNoteNumber(), newVal);
		} else if (m.isNoteOff()) {

		} else if (m.isAftertouch()) {

		} else if (m.isPitchWheel()) {

		}
		processedMidi.addEvent(m, time);
	}

	midiMessages.swapWith(processedMidi);


}

//==============================================================================
bool _4rcAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* _4rcAudioProcessor::createEditor()
{
    return new _4rcAudioProcessorEditor (*this);
}

//==============================================================================
void _4rcAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void _4rcAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new _4rcAudioProcessor();
}
