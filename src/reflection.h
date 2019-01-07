// ---------------------------------------------------------------------
// @author Erik Baker
// @date   11/9/18
// @file   reflection.h
// @brief  contains reflection classes/macros
// ---------------------------------------------------------------------
#ifndef REFLECTION_H
#define REFLECTION_H
#include <type_traits>

#define pp_concat(token_a, token_b) token_a_##token_b 


template <class CheckingType>
class sfinae_shell
{
	private:
	
	// if a dummy int is passed into the test_validity it'll be true
	template <class TypeToCheck>
	constexpr auto test_validity(int) -> decltype(std::declval<CheckingType>()(std::declval<TypeToCheck>()), bool())
	{
		return true;
	}
	
	// anything else -> return false
	template <class Param>
	constexpr bool test_validity(...)
	{
		return false;
	}
	
	public:
	
	template <class TypeToCheck>
	constexpr bool operator()(const TypeToCheck& p)
	{
		return test_validity<TypeToCheck>(int());
	}
};

template <class CheckingType>
constexpr sfinae_shell<CheckingType> is_valid(const CheckingType& t)
{
	return sfinae_shell<CheckingType>();
}


#endif
