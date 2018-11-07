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

enum state
{
	init = 0,
	update,
	shutdown,
	exit_engine
};

template <unsigned engine_index = 0>
class EEngine
{
	public:
	
	EEngine(): exit_code(0), next_state(init)
	{
		
	}

	
	int operator()()
	{
		NextState();
		
		return exit_code;
	}
	
	void Exit(int i_exit_code = 0)
	{
		exit_code = i_exit_code;
		next_state = shutdown;
	}

	private:
	state next_state;

	int exit_code;
	
	void NextState()
	{
		switch (next_state)
		{
			case init:
			template_array<eengine_window<engine_index>, engine_index>::Data().Init();
			next_state = update;
			NextState();
			break;
			
			case update:
			template_array<eengine_window<engine_index>, engine_index>::Data().Update();
			NextState();
			break;
			
			case shutdown:
			template_array<eengine_window<engine_index>, engine_index>::Data().Shutdown();
			next_state = exit_engine;
			NextState();
			break;
			
			case exit_engine:
			// todo: log stuff
			break;
		}
		
	}	

	

};

#endif
