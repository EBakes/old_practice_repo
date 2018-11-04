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
	
	EEngine(): exit_code(0)
	{
		
	}
	
	int operator()()
	{
		template_array<eengine_window<engine_index>, engine_index>::Data().Init();
		
		do
		{
			template_array<eengine_window<engine_index>, engine_index>::Data().Update();
		}
		while (!template_array<eengine_window<engine_index>, engine_index>::Data().ShouldWindowClose());
		
		template_array<eengine_window<engine_index>, engine_index>::Data().Shutdown();
		
		return exit_code;
	}
	
	void Exit(int i_exit_code)
	{
		exit_code = i_exit_code;
	}

	private:
	int exit_code;
};

#endif
