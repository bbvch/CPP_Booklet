#include <tuple>
#include <array>
#include <map>

struct Packed {
    int x;
    char y;
    float z;
};

class cls
{
    public:
    int m;
    float n;
};

int main()
{
    auto tuple = std::make_tuple(1, 'a', 2.3);
    std::array<int, 3> a{1,2,3};
    Packed p;
    cls cl;


    // unpack the tuple into individual variables declared at the call site
    const auto [ i, c, d ] = tuple;
    // also works with references
    auto& [ref_i, ref_c, ref_d] = tuple;

    // fixed size array also works
    auto [j, k,l ] = a;

    // structs and classes can also be bound
    auto& [x, y, z] = p;
    auto [m, n] = cl;

    // extracting key & value at the same time from a map
    std::map<int, float> map;
    for(auto&& [k, v] : map)
    {
        // do something
    }

    return 0;
}
