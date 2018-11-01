project ("EEngine")

enable_testing()

add_executable(EEngine main.cpp 
	)	
	
add_test(EEngineTest EEngine)
