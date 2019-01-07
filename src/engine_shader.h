// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/9/18
// @file   engine_shader.h
// @brief  contains engine shader wrapper implementation
// ---------------------------------------------------------------------

enum engine_shader_type
{
	engine_vertex_shader = 0,
	engine_fragment_shader
}

class engine_shader
{
public:

	void AddShader(const char * path, engine_shader_type type);
	
	void Use();
	
	void SetBool(bool value);
	
	void SetInteger(int value);

private:
	
};
