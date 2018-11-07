// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/3/18
// @file   eengine_graphics.h
// @brief  contains eengine_window implementation
// ---------------------------------------------------------------------
#ifndef EENGINE_GRAPHICS_H
#define EENGINE_GRAPHICS_H
#include <GL/glew.h>
#include <iostream>


struct Vector3f
{
	Vector3f(float ix = 0, float iy = 0, float iz = 0) : x(ix), y(iy), z(iz) {}
	float x;
	float y;
	float z;
};



template <unsigned engine_index>
class graphics_handler
{
	Vector3f verts[1];
	
	GLuint VBO;
	
	public:
	
	graphics_handler()
	{
		
	}

	
	void Init()
	{
		GLenum res = glewInit();
		if (res != GLEW_OK)
		{
			std::cerr << "GLEW INIT FAILED" << std::endl;
		}
		
		verts[0] = Vector3f();
	
		glGenBuffers(1, &VBO);
		
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
	}
	
	void Update()
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		
		glDrawArrays(GL_POINTS, 0, 1);
		
		glDisableVertexAttribArray(0);
		
	}
	
	void Shutdown()
	{
		
	}
};

#endif
