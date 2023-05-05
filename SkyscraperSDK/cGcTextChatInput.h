#pragma once
#include "pch.h"

#include "cTkNGui.h"
#include "cTkTypes.h"

struct __declspec(align(4)) StbUndoRecord
{
	int where;
	__int16 insert_length;
	__int16 delete_length;
	__int16 char_storage;
};

struct StbUndoState
{
	StbUndoRecord undo_rec[99];
	char undo_char[999];
	__int16 undo_point;
	__int16 redo_point;
	__int16 undo_char_point;
	__int16 redo_char_point;
};

struct STB_TexteditState
{
	int cursor;
	int select_start;
	int select_end;
	unsigned __int8 insert_mode;
	unsigned __int8 cursor_at_end_of_line;
	unsigned __int8 initialized;
	unsigned __int8 has_preferred_x;
	unsigned __int8 single_line;
	unsigned __int8 padding1;
	unsigned __int8 padding2;
	unsigned __int8 padding3;
	float preferred_x;
	StbUndoState undostate;
};


class cGcTextChatInput
{
	cTkNGuiTextEditState mEditText;
	cTkFixedString<1023, char> msText;
	cTkFixedString<1023, char> msInputTextDisplayString;
	bool mbTextInputActive;
	bool mbWaitingForNoKeyboardInput;
	bool mbButtonReleased;
	byte meCurrentCommand[1];
	byte mePendingCommand[1];

	const struct SCommandLookup
	{
		const char* mpcCommandName;
		const char* mpcShortCommandName;
	};

	const cGcTextChatInput::SCommandLookup* mpLookupTable;

	typedef void(__fastcall *cTkNGuiTextEditState)(cTkNGuiTextEditState* _this);


};