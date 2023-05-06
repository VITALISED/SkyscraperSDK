#pragma once
#include "pch.h"

struct cGcAsyncLoadOps
{
	enum Operation : __int32
	{
		DrainFileIO = 0x0,
		DrainShaders = 0x1,
		DrainTasks = 0x2,
	};

	//typedef cGcAsyncLoadOps::Operation cGcApplicationDeathState::Phase;

	cTkStackVector<enum cGcAsyncLoadOps::Operation> mMidPhaseOps;
	Engine::cEgShaderCompilationState* mpShaderCompilationState;
};

struct __declspec(align(16)) cGcApplicationCoreServicesState : cGcApplicationBaseLoadingState
{
	CoreSrvLoadPhase::Enum mPhase;
};

template <unsigned int size, typename T>
struct cTkAlignedBlock/*<16, 4>*/
{
	Y data_[T];
};

template <class T>
struct StackAllocator/*<enum cGcAsyncLoadOps::Operation, 4, -1>*/ : std::allocator<T>
{
	struct __declspec(align(4)) /*<enum cGcAsyncLoadOps::Operation, 4, -1>*/Source
	{
		cTkAlignedBlock<16, 4> stack_buffer_;
		bool used_stack_buffer_;
	};

	StackAllocator<enum cGcAsyncLoadOps::Operation, 4, -1>::Source* source_;
};

//FIXME
template <class T>
struct StackContainer/*<std::vector<enum cGcAsyncLoadOps::Operation, StackAllocator<enum cGcAsyncLoadOps::Operation> > >*/
{
	StackAllocator<enum cGcAsyncLoadOps::Operation>::Source stack_data_;
	StackAllocator<enum cGcAsyncLoadOps::Operation> allocator_;
	std::vector<enum cGcAsyncLoadOps::Operation, StackAllocator<enum cGcAsyncLoadOps::Operation, 4, -1> > container_;
};

template <class T>
struct cTkStackVector : StackContainer<T> {};