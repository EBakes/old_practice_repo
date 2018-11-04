// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/1/18
// @file   EEngine.h
// @brief  contains engine implementation
// ---------------------------------------------------------------------
#ifndef EENGINE_H
#define EENGINE_H
#include "eengine_window.h"
#include "template_array.h"

template <unsigned engine_index = 0>
class EEngine
{
	public:
	
	EEngine()
	{
		
	}
	
	void operator()()
	{
		template_array<eengine_window<engine_index>, engine_index>::Data().Init();
		
		do
		{
			template_array<eengine_window<engine_index>, engine_index>::Data().Update();
		}
		while (!template_array<eengine_window<engine_index>, engine_index>::Data().ShouldWindowClose());
		
		template_array<eengine_window<engine_index>, engine_index>::Data().Shutdown();
	}

	private:
	
};

#endif
