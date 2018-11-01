cmake_minimum_required(VERSION 3.5)
project ("EEngine")

enable_testing()

add_executable(EEngine main.cpp 
	)	
	
add_test(EEngineTest EEngine)
