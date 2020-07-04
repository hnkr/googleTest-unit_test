#include <gtest/gtest.h>
 

struct Test_Fixture : public testing::Test{
    void SetUp(void){
        std::cout << "Setup" << std::endl;
    }

    void TearDown(void){
        std::cout << "Teardown" << std::endl;
    }
};

TEST_F(Test_Fixture, eq_pos) { 
    ASSERT_EQ(6,6);
}
 
TEST_F(Test_Fixture, eq_neg) {
    ASSERT_EQ(-1.0, -1.0);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

