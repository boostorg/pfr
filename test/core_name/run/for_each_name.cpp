#include <string>
#include <type_traits>
#include <vector>

#include <boost/pfr/core_name.hpp>
#include <boost/core/lightweight_test.hpp>


struct SimpleStruct {
    char c;
    std::string str;
    int i;
};

struct EmptyStruct {};

struct stateful_counting_visitor {
    std::size_t count = 0;

    void operator()(std::string_view /*name*/) { ++count; }
};

int main () {
    std::vector<std::string> names;
    boost::pfr::for_each_name<SimpleStruct>([&names](std::string_view name) {
        names.emplace_back(name);
    });
    BOOST_TEST_EQ(names.size(), 3);
    BOOST_TEST_EQ(names[0], "c");
    BOOST_TEST_EQ(names[1], "str");
    BOOST_TEST_EQ(names[2], "i");

    std::vector<std::string> names_by_index(3);
    boost::pfr::for_each_name<SimpleStruct>([&names_by_index](std::string_view name, auto index) {
        static_assert(std::is_same_v<
            decltype(index),
            std::integral_constant<std::size_t, decltype(index)::value>
        >);
        names_by_index[index] = std::string(name);
        BOOST_TEST((name == boost::pfr::get_name<decltype(index)::value, SimpleStruct>()));
    });
    BOOST_TEST_EQ(names_by_index[0], "c");
    BOOST_TEST_EQ(names_by_index[1], "str");
    BOOST_TEST_EQ(names_by_index[2], "i");

    stateful_counting_visitor counting_visitor;
    boost::pfr::for_each_name<SimpleStruct>(counting_visitor);
    BOOST_TEST_EQ(counting_visitor.count, 3);

    std::size_t empty_count = 0;
    boost::pfr::for_each_name<EmptyStruct>([&empty_count](std::string_view) { ++empty_count; });
    BOOST_TEST_EQ(empty_count, 0);

    constexpr std::size_t constexpr_count = [] {
        std::size_t count = 0;
        boost::pfr::for_each_name<SimpleStruct>([&count](std::string_view) { ++count; });
        return count;
    }();
    static_assert(constexpr_count == 3);

    return boost::report_errors();
}
