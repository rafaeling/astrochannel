template<class T, dimension D, class Alloc>
class array: {
	static_assert(
		std::is_same<typename array::alloc_traits::value_type, T>{}
	or	std::is_same<typename array::alloc_traits::value_type, void{}, "!"
	);
}
