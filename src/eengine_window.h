// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/1/18
// @file   eengine_window.h
// @brief  contains eengine_window implementation
// ---------------------------------------------------------------------
#ifndef EENGINE_WINDOW_H
#define EENGINE_WINDOW_H
#include <chrono>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "template_array.h"
#include "eengine_graphics.h"

typedef GLFWwindow* GLFWwindowPtr; 

int EngineExit()
{
	
}

template <unsigned engine_index>
class eengine_window
{
	public:
	
	bool ShouldWindowClose()
	{
		return glfwWindowShouldClose(template_array<GLFWwindowPtr, engine_index>::Data());
	}
	
	void Init()
	{
		Init_glfw();
		
		template_array<graphics_handler<engine_index>, engine_index>::Data().Init();
	}
	
	void Update()
	{
		
		
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(template_array<GLFWwindowPtr, engine_index>::Data());
		
		glfwPollEvents();
	
		template_array<graphics_handler<engine_index>, engine_index>::Data().Update();
	}
	
	void Shutdown()
	{
		template_array<graphics_handler<engine_index>, engine_index>::Data().Shutdown();
		
		glfwTerminate();	
	}
	
	private:
	std::chrono::duration<float> frame_time;

	int Init_glfw()
	{
		if (!glfwInit())
		{
			return -1;
		}
		
		template_array<GLFWwindowPtr, engine_index>::Data()  = glfwCreateWindow(640, 480, "EEngine V0.0", nullptr, nullptr);
															  
		if (template_array<GLFWwindowPtr, engine_index>::Data() == nullptr)
		{
			glfwTerminate();
			return -1;
		}
		
		//glfwSetWindowCloseCallback((GLFWwindowCloseFun)Exit);
		
		glfwMakeContextCurrent(template_array<GLFWwindowPtr, engine_index>::Data());		
		return 0;							  
	}
	
};

#endif
