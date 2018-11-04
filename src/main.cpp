// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/1/18
// @file   main.cpp
// @brief  contains start of program
// ---------------------------------------------------------------------
#include "EEngine.h"
	
int main(int argc, char** argv)
{
	// id corresponds to the instance of engine required classes it uses
	// (future proofing for *super* easy threading)
	EEngine<0>()();
	//engine<0>.Run();
		
	return 0;
}
