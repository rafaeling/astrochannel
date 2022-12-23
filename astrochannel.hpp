#include <memory>

namespace astrochannel
{

    template<class T, std::size_t D, class Alloc>
    struct static_storage_allocator : std::allocator_traits<Alloc> 
    {
        public:
            typedef T value_type;
            static const std::size_t internal_capacity = D;
        
            std::size_t max_size() const
            {
                return D;
            }
    };

    template<class T, std::size_t D, class A = std::allocator<T>> struct channelarray;

    template<typename T, std::size_t D, class Alloc = std::allocator<T>>
    struct static_channelarray : protected static_storage_allocator<T, D, Alloc>
    {
        public:
            // typedef typename std::allocator_traits<Alloc>::value_type value_type;
            // typedef typename std::allocator_traits<Alloc>::pointer pointer;
            // typedef typename std::allocator_traits<Alloc>::const_pointer const_pointer;
            // typedef typename std::allocator_traits<Alloc>::size_type size_type;
            // typedef typename std::allocator_traits<Alloc>::difference_type difference_type;
            // typedef typename std::allocator_traits<Alloc>::const_void_pointer const_void_pointer;

            // typedef Alloc allocator_type;
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
        int test;
        channelarray(std::initializer_list<T> list) : test(1){}

        channelarray() = default;
        channelarray(channelarray const&) = delete;
        channelarray(channelarray&& other) = delete;
    };

    template<typename T, class Alloc>
    struct channelarray<T, 0, Alloc> : static_channelarray<T, 0, Alloc>
    {
        // using static_ = static_array<T, 0, Alloc>;
        // using static_::static_;
        
        channelarray() = default;
    };

}