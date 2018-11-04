#ifndef TEMPLATE_ARRAY_H
#define TEMPLATE_ARRAY_H

template <typename T, unsigned i = 0>
struct template_array
{
	static T& Data()
	{
		static T data;
		return data;
	}
	
};

#endif
