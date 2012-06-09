/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2012 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef __SPLITTER_H_A75239F7__
#define __SPLITTER_H_A75239F7__

#ifdef WIN32
#include <Windows.h>
#endif
#include "../../../JuceLibraryCode/JuceHeader.h"
#include "../GenericProcessor.h"

#include <stdio.h>


/**

  Allows the user to split the signal chain.

  @see GenericProcessor, ProcessorGraph

*/


class Splitter : public GenericProcessor
{
public:

	Splitter();
	~Splitter();

	AudioProcessorEditor* createEditor();

	void process(AudioSampleBuffer &buffer, MidiBuffer &midiMessages, int& nSamples) {}
   // void setParameter (int parameterIndex, float newValue) {}

	bool isSplitter() {return true;}

	void switchIO(int);
    void switchIO();
	void setSplitterDestNode(GenericProcessor* dn);

    void setPathToProcessor(GenericProcessor* processor);

    int getPath();

private:

	GenericProcessor* destNodeA;
	GenericProcessor* destNodeB;
	int activePath;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Splitter);
	
};


#endif  // __SPLITTER_H_A75239F7__
