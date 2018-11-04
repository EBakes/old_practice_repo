// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/1/18
// @file   eengine_window.h
// @brief  contains eengine_window implementation
// ---------------------------------------------------------------------
#ifndef EENGINE_WINDOW_H
#define EENGINE_WINDOW_H
#include <GLFW/glfw3.h>

template <unsigned engine_index>
class eengine_window
{
	private:
	
	static GLFWwindow * m_window;
	
	public:
	
	eengine_window()
	{
		 
	}
	
	bool ShouldWindowClose()
	{
		return glfwWindowShouldClose(m_window);
	}
	
	void Init()
	{
		glfwInit();
	}
	
	void Update()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	
	void Shutdown()
	{
		glfwTerminate();
	}
	
	private:
	
	int glfwInit()
	{
		if (!glfwInit())
		{
			return -1;
		}
		
		m_window = glfwCreateWindow(640, 480, "EEngine V0.0", nullptr, 
															  nullptr);
															  
		if (!m_window)
		{
			glfwTerminate();
			return -1;
		}
		
		glfwMakeContextCurrent(m_window);									  
	}
	
};

#endif
