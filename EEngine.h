// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/1/18
// @file   EEngine.h
// @brief  contains engine implementation
// ---------------------------------------------------------------------
#ifndef EENGINE_H
#define EENGINE_H
#include "eengine_window.h"

template <unsigned engine_index = 0>
class EEngine
{
	public:
	
	EEngine()
	{
		eengine_window<engine_index>();
	}
	
	void Run()
	{
		
	}
};

#endif
