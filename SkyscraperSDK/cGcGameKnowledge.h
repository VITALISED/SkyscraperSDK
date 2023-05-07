#pragma once
#include "cGcAsyncLoadOps.h"

struct cGcGameKnowledge
{
	cGcGameKnowledge::Data* mpData;
	cTkStackVector<IKnowledgeEventHandler*, 2, -1> mCachedHandlers;
};
