// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/1/18
// @file   eengine_window.h
// @brief  contains eengine_window implementation
// ---------------------------------------------------------------------
#ifndef EENGINE_WINDOW_H
#define EENGINE_WINDOW_H
#include <GLFW/glfw3.h>
#include <iostream>
#include "template_array.h"

typedef GLFWwindow* GLFWwindowPtr; 

template <unsigned engine_index>
class eengine_window
{	
	private:
	GLFWwindow * m_window;
	public:
	
	eengine_window()
	{
		 
	}
	
	bool ShouldWindowClose()
	{
		return glfwWindowShouldClose(template_array<GLFWwindowPtr, engine_index>::Data());
		//return glfwWindowShouldClose(m_window);
	}
	
	void Init()
	{
		Init_glfw();
	}
	
	void Update()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(template_array<GLFWwindowPtr, engine_index>::Data());
		//glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	
	void Shutdown()
	{
		glfwTerminate();	
	}
	
	private:
	
	int Init_glfw()
	{
		if (!glfwInit())
		{
			std::cerr << "GLFW INIT FAILED" << std::endl;
			return -1;
		}
		
		template_array<GLFWwindowPtr, engine_index>::Data()  = glfwCreateWindow(640, 480, "EEngine V0.0", nullptr, 
															  nullptr);
		//m_window  = glfwCreateWindow(640, 480, "EEngine V0.0", 0, 
			//												  0	);
															  
		if (template_array<GLFWwindowPtr, engine_index>::Data() == nullptr)
		{
			std::cerr << "COULD NOT MAKE WINDOW" << std::endl;
			glfwTerminate();
			return -1;
		}
		
		glfwMakeContextCurrent(template_array<GLFWwindowPtr, engine_index>::Data());		
		return 0;							  
	}
	
};

#endif
