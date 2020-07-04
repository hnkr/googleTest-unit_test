#include <gtest/gtest.h>
 
TEST(test_hello, eq_pos) { 
    ASSERT_EQ(10,10);
    std::cout << "10 EQ 10" << std::endl;
    ASSERT_NE(10,11);
    std::cout << "10 NOT EQ 11" << std::endl;
}
 
TEST(test_hello, eq_neg) {
    ASSERT_EQ(-10, -10);
    std::cout << "-10 EQ -10" << std::endl;
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}