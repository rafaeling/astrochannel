#include <memory>

namespace astrochannel
{
    template<class T, std::size_t D, class A = std::allocator<T>> struct channelarray;

    template<typename T, std::size_t D, class Alloc = std::allocator<T>>
    struct static_channelarray
    {
        //using static_ = static_array<T, D, Alloc>;
    };

    template<typename T, class Alloc>
    struct static_channelarray<T, 0, Alloc>
    {
    };
  
    template<typename T, std::size_t D, class Alloc>
    struct channelarray : static_channelarray<T, D, Alloc>
    {
        // using static_ = static_array<T, D, Alloc>;
        // using static_::static_;
	    // using typename static_::value_type;
        
    	// channelarray(std::initializer_list<typename static_array<T, D>::value_type> ilv)
	    // : static_{static_array<T, D>(ilv.begin(), ilv.end())} {}  // construct all with default constructor and copy to special memory at the end

        channelarray() = default;
    };

    template<typename T, class Alloc>
    struct channelarray<T, 0, Alloc> : static_channelarray<T, 0, Alloc>
    {
        // using static_ = static_array<T, 0, Alloc>;
        // using static_::static_;
        
        channelarray() = default;
    };

}