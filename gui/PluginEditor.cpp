/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
PluginAudioProcessorEditor::PluginAudioProcessorEditor (PluginAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);
    
    startTimerHz (30);
    
    addAndMakeVisible(ui = new PlugUI(p));
}

PluginAudioProcessorEditor::~PluginAudioProcessorEditor()
{
    ui = nullptr;
}

void PluginAudioProcessorEditor::timerCallback()
{
    std::cout << "inside timer callback";
    updateBpmDisplay (processor.lastPositionInfo);
}

void PluginAudioProcessorEditor::updateBpmDisplay(AudioPlayHead::CurrentPositionInfo currentPos)
{
   if (lastDisplayedPosition != currentPos) {
       lastDisplayedPosition = currentPos;
       
        MemoryOutputStream bpmDisplay;

        bpmDisplay << String(currentPos.bpm, 2);
        ui->bpmDisplay->setText(bpmDisplay.toString(), dontSendNotification);
    }
}

//==============================================================================
void PluginAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);
}

void PluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
