/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "EnvPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EnvPanel::EnvPanel (SynthParams &p)
    : PanelBase(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (attackTime = new MouseOverKnob ("Attack Time"));
    attackTime->setRange (0.001, 5, 0);
    attackTime->setSliderStyle (Slider::RotaryVerticalDrag);
    attackTime->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackTime->addListener (this);
    attackTime->setSkewFactor (0.5);

    addAndMakeVisible (decayTime = new MouseOverKnob ("Decay Time"));
    decayTime->setRange (0.001, 5, 0);
    decayTime->setSliderStyle (Slider::RotaryVerticalDrag);
    decayTime->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decayTime->addListener (this);
    decayTime->setSkewFactor (0.5);

    addAndMakeVisible (sustainLevel = new MouseOverKnob ("Sustain"));
    sustainLevel->setRange (-96, 0, 0);
    sustainLevel->setSliderStyle (Slider::RotaryVerticalDrag);
    sustainLevel->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sustainLevel->addListener (this);

    addAndMakeVisible (releaseTime = new MouseOverKnob ("Release Time"));
    releaseTime->setRange (0.001, 5, 0);
    releaseTime->setSliderStyle (Slider::RotaryVerticalDrag);
    releaseTime->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseTime->addListener (this);
    releaseTime->setSkewFactor (0.5);

    addAndMakeVisible (attackShape = new MouseOverKnob ("Attack Shape"));
    attackShape->setRange (0.01, 10, 0);
    attackShape->setSliderStyle (Slider::RotaryVerticalDrag);
    attackShape->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackShape->addListener (this);
    attackShape->setSkewFactor (0.3);

    addAndMakeVisible (decayShape = new MouseOverKnob ("Decay Shape"));
    decayShape->setRange (0.01, 10, 0);
    decayShape->setSliderStyle (Slider::RotaryVerticalDrag);
    decayShape->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decayShape->addListener (this);
    decayShape->setSkewFactor (0.3);

    addAndMakeVisible (releaseShape = new MouseOverKnob ("Release Shape"));
    releaseShape->setRange (0.01, 10, 0);
    releaseShape->setSliderStyle (Slider::RotaryVerticalDrag);
    releaseShape->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseShape->addListener (this);
    releaseShape->setSkewFactor (0.3);

    addAndMakeVisible (keyVelToEnv = new MouseOverKnob ("Vel to Env"));
    keyVelToEnv->setRange (0, 1, 0);
    keyVelToEnv->setSliderStyle (Slider::RotaryVerticalDrag);
    keyVelToEnv->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    keyVelToEnv->addListener (this);

    addAndMakeVisible (VolEnvLabel = new Label ("Volume Envelope",
                                                TRANS("Volume Envelope")));
    VolEnvLabel->setFont (Font (15.00f, Font::plain));
    VolEnvLabel->setJustificationType (Justification::centredLeft);
    VolEnvLabel->setEditable (false, false, false);
    VolEnvLabel->setColour (TextEditor::textColourId, Colours::black);
    VolEnvLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (volEnvSpeedModSrc1 = new ComboBox ("volEnvSpeedModSrcBox1"));
    volEnvSpeedModSrc1->setEditableText (false);
    volEnvSpeedModSrc1->setJustificationType (Justification::centred);
    volEnvSpeedModSrc1->setTextWhenNothingSelected (TRANS("No Mod"));
    volEnvSpeedModSrc1->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    volEnvSpeedModSrc1->addListener (this);

    addAndMakeVisible (volEnvSpeedModSrc2 = new ComboBox ("volEnvSpeedModSrcBox2"));
    volEnvSpeedModSrc2->setEditableText (false);
    volEnvSpeedModSrc2->setJustificationType (Justification::centred);
    volEnvSpeedModSrc2->setTextWhenNothingSelected (TRANS("No Mod"));
    volEnvSpeedModSrc2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    volEnvSpeedModSrc2->addListener (this);


    //[UserPreSize]
    registerSlider(attackTime, &params.envAttack);
    registerSlider(decayTime, &params.envDecay);
    registerSlider(sustainLevel, &params.envSustain);
    registerSlider(releaseTime, &params.envRelease);
    registerSlider(attackShape, &params.envAttackShape);
    registerSlider(decayShape, &params.envDecayShape);
    registerSlider(releaseShape, &params.envReleaseShape);
    registerSlider(keyVelToEnv, &params.keyVelToEnv);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

EnvPanel::~EnvPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    attackTime = nullptr;
    decayTime = nullptr;
    sustainLevel = nullptr;
    releaseTime = nullptr;
    attackShape = nullptr;
    decayShape = nullptr;
    releaseShape = nullptr;
    keyVelToEnv = nullptr;
    VolEnvLabel = nullptr;
    volEnvSpeedModSrc1 = nullptr;
    volEnvSpeedModSrc2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EnvPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EnvPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    attackTime->setBounds (8, 32, 64, 64);
    decayTime->setBounds (80, 32, 64, 64);
    sustainLevel->setBounds (152, 32, 64, 64);
    releaseTime->setBounds (224, 32, 64, 64);
    attackShape->setBounds (8, 104, 64, 64);
    decayShape->setBounds (80, 104, 64, 64);
    releaseShape->setBounds (224, 104, 64, 64);
    keyVelToEnv->setBounds (296, 32, 64, 64);
    VolEnvLabel->setBounds (8, 8, 150, 24);
    volEnvSpeedModSrc1->setBounds (8, 192, 64, 16);
    volEnvSpeedModSrc2->setBounds (80, 192, 64, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EnvPanel::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    handleSlider(sliderThatWasMoved);
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == attackTime)
    {
        //[UserSliderCode_attackTime] -- add your slider handling code here..
        //[/UserSliderCode_attackTime]
    }
    else if (sliderThatWasMoved == decayTime)
    {
        //[UserSliderCode_decayTime] -- add your slider handling code here..
        //[/UserSliderCode_decayTime]
    }
    else if (sliderThatWasMoved == sustainLevel)
    {
        //[UserSliderCode_sustainLevel] -- add your slider handling code here..
        //[/UserSliderCode_sustainLevel]
    }
    else if (sliderThatWasMoved == releaseTime)
    {
        //[UserSliderCode_releaseTime] -- add your slider handling code here..
        //[/UserSliderCode_releaseTime]
    }
    else if (sliderThatWasMoved == attackShape)
    {
        //[UserSliderCode_attackShape] -- add your slider handling code here..
        //[/UserSliderCode_attackShape]
    }
    else if (sliderThatWasMoved == decayShape)
    {
        //[UserSliderCode_decayShape] -- add your slider handling code here..
        //[/UserSliderCode_decayShape]
    }
    else if (sliderThatWasMoved == releaseShape)
    {
        //[UserSliderCode_releaseShape] -- add your slider handling code here..
        //[/UserSliderCode_releaseShape]
    }
    else if (sliderThatWasMoved == keyVelToEnv)
    {
        //[UserSliderCode_keyVelToEnv] -- add your slider handling code here..
        //[/UserSliderCode_keyVelToEnv]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void EnvPanel::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == volEnvSpeedModSrc1)
    {
        //[UserComboBoxCode_volEnvSpeedModSrc1] -- add your combo box handling code here..
        //[/UserComboBoxCode_volEnvSpeedModSrc1]
    }
    else if (comboBoxThatHasChanged == volEnvSpeedModSrc2)
    {
        //[UserComboBoxCode_volEnvSpeedModSrc2] -- add your combo box handling code here..
        //[/UserComboBoxCode_volEnvSpeedModSrc2]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EnvPanel" componentName=""
                 parentClasses="public PanelBase" constructorParams="SynthParams &amp;p"
                 variableInitialisers="PanelBase(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="Attack Time" id="3c32cde7173ddbe6" memberName="attackTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="8 32 64 64"
          min="0.0010000000000000000208" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Decay Time" id="84a4159bee0728d6" memberName="decayTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="80 32 64 64"
          min="0.0010000000000000000208" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Sustain" id="4bc867c016d7595f" memberName="sustainLevel"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="152 32 64 64"
          min="-96" max="0" int="0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Release Time" id="c8bc1120a33101cd" memberName="releaseTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="224 32 64 64"
          min="0.0010000000000000000208" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Attack Shape" id="27ef7f1857e5d79b" memberName="attackShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="8 104 64 64"
          min="0.010000000000000000208" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="Decay Shape" id="18adbff3650623b1" memberName="decayShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="80 104 64 64"
          min="0.010000000000000000208" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="Release Shape" id="adb5f4f555fb76d1" memberName="releaseShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="224 104 64 64"
          min="0.010000000000000000208" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.2999999999999999889"/>
  <SLIDER name="Vel to Env" id="595a20e744f094d5" memberName="keyVelToEnv"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="296 32 64 64"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Volume Envelope" id="b3d84b49f651b0e" memberName="VolEnvLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume Envelope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="volEnvSpeedModSrcBox1" id="6dae6bde5fbe8153" memberName="volEnvSpeedModSrc1"
            virtualName="" explicitFocusOrder="0" pos="8 192 64 16" editable="0"
            layout="36" items="" textWhenNonSelected="No Mod" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="volEnvSpeedModSrcBox2" id="401dffa72d979c97" memberName="volEnvSpeedModSrc2"
            virtualName="" explicitFocusOrder="0" pos="80 192 64 16" editable="0"
            layout="36" items="" textWhenNonSelected="No Mod" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
