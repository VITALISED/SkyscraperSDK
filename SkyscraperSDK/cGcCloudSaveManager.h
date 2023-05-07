#pragma once
#include "cTkTypes.h"

struct TkCloudDataInfo
{
	unsigned __int64 mUploadTimestamp;
	cTkFixedString<512, char> mMetaDataJson;
};

struct __declspec(align(8)) cGcCloudSaveManager
{
	cGcGameState* mpGameState;
	std::function<void __cdecl(bool)> mpOnCompletionCallback;
	unsigned __int64 mTempJsonFile;
	unsigned __int64 mTempLZ4File;
	nms_rapidjson::GenericDocument<nms_rapidjson::UTF8<char>, nms_rapidjson::MemoryPoolAllocator<nms_rapidjson::CrtAllocator>, nms_rapidjson::CrtAllocator> mJsonDocument;
	char* mpStreamBuffer;
	TkCloudDataInfo mCloudDataInfo;
	bool mbCancelTransferRequested;
};
