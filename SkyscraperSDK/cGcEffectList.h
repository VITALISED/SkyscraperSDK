#pragma once

template <class T, int size>
struct __declspec(align(16)) cGcEffectList/*<cGcExplosion, 512>*/
{
	cTkClassPool<cGcExplosion, size> maEffects;
	int miNumber;
};
