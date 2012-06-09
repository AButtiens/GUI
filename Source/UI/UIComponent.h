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

#ifndef __UICOMPONENT_H_D97C73CF__
#define __UICOMPONENT_H_D97C73CF__

#ifdef WIN32
#include <Windows.h>
#endif
#include "../../JuceLibraryCode/JuceHeader.h"
#include "InfoLabel.h"
#include "ControlPanel.h"
#include "ProcessorList.h"
#include "EditorViewport.h"
#include "DataViewport.h"
#include "MessageCenter.h"
#include "../Processors/ProcessorGraph.h"
#include "../Audio/AudioComponent.h"
#include "../MainWindow.h"

#include "../OpenGL.h"

/**
  
  Creates objects for user interaction.

  The UIComponent can relay messages its sub-components, such as
  the MessageCenter

  @see ControlPanel, ProcessorList, EditorViewport, DataViewport,
       MessageCenter, Configuration

*/

class MainWindow;
class ProcessorList;

class EditorViewportButton;

class UIComponent : public Component,
				    public ActionBroadcaster,
				    public MenuBarModel,
				    public ApplicationCommandTarget,
				    public DragAndDropContainer // required for 
				    				            // drag-and-drop
				    				            // internal components
				    

{
public: 
	UIComponent(MainWindow* mainWindow_, ProcessorGraph* pgraph, AudioComponent* audio);
	~UIComponent();

	EditorViewport* getEditorViewport() {return editorViewport;}
	ProcessorList* getProcessorList() {return processorList;}
	DataViewport* getDataViewport() {return dataViewport;}
	ProcessorGraph* getProcessorGraph() {return processorGraph;}
	ControlPanel* getControlPanel() {return controlPanel;}
	MessageCenter* getMessageCenter() {return messageCenter;}
	UIComponent* getUIComponent() {return this;}
	AudioComponent* getAudioComponent() {return audio;}

	//void transmitMessage(const String& message);
	void disableCallbacks();
	void disableDataViewport();

	void childComponentChanged();

	const StringArray getMenuBarNames();
	const PopupMenu getMenuForIndex(int topLevelMenuIndex, const String& menuName);
	void menuItemSelected(int menuItemID, int topLevelMenuIndex);

	//ApplicationCommandTarget interface:
	ApplicationCommandTarget* getNextCommandTarget();
	void getAllCommands (Array <CommandID>& commands);
	void getCommandInfo (CommandID commandID, ApplicationCommandInfo& result);
	bool perform (const InvocationInfo& info);

private:

	DataViewport* dataViewport;
	EditorViewport* editorViewport;
	EditorViewportButton* editorViewportButton;
	ProcessorList* processorList;
	ControlPanel* controlPanel;
	MessageCenter* messageCenter;
	InfoLabel* infoLabel;

	MainWindow* mainWindow;
	TooltipWindow tooltipWindow;

	ProcessorGraph* processorGraph;
	AudioComponent* audio;

	void resized();

	enum CommandIDs
	{
		openConfiguration 		= 0x2001,
	 	saveConfiguration		= 0x2002,
	 	undo					= 0x2003,
	 	redo 					= 0x2004,
	 	copySignalChain			= 0x2005,
	 	pasteSignalChain		= 0x2006,
	 	clearSignalChain		= 0x2007,
	 	toggleProcessorList 	= 0x2008,
	 	toggleSignalChain	    = 0x2009,
	 	toggleFileInfo			= 0x2010,
	 	showHelp				= 0x2011
	};

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UIComponent);
	
};



class EditorViewportButton : public OpenGLComponent
{
public:
	EditorViewportButton(UIComponent* ui);
	~EditorViewportButton();

	bool isOpen() {return open;}

	void newOpenGLContextCreated();
	void renderOpenGL();

	void drawName();
	void drawButton();

	void toggleState();

	void mouseDown(const MouseEvent& e);

private:	

	UIComponent* UI;
	bool open;

	FTPixmapFont* font;

};

#endif  // __UICOMPONENT_H_D97C73CF__
