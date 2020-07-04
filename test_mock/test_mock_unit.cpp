#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <algorithm>


#include <interface_mock.hpp>
#include <src/test_packet.c>

using namespace std;

using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::SetArrayArgument;


struct test_mock_fixture : public ::testing::Test
{
    void SetUp(){
        
    }

    void TearDown(){
        
    }
};


TEST_F(test_mock_fixture, test_get_packet_validator){
    char buf[MAX_RECV_LENGTH + 1];
    ASSERT_EQ(-1, get_packet((char *)NULL, 5));
    ASSERT_EQ(-1, get_packet(buf, 0));
    ASSERT_EQ(-1, get_packet(buf, MAX_RECV_LENGTH + 1));
}

TEST_F(test_mock_fixture, test_get_packet_recv_fail){
    char buf[MAX_RECV_LENGTH];
    EXPECT_CALL(mock_interface::instance, interface_read_data(_,_))
        .Times(AtLeast(1))
        .WillOnce(Return (-1));
    ASSERT_EQ(-1, get_packet(buf, 5));

    EXPECT_CALL(mock_interface::instance, interface_read_data(_,_))
        .Times(AtLeast(1))
        .WillOnce(Return (0));
    ASSERT_EQ(-1, get_packet(buf, 5));

    EXPECT_CALL(mock_interface::instance, interface_read_data(_,_))
        .Times(AtLeast(1))
        .WillOnce(Return (2));
    ASSERT_NE(5, get_packet(buf, 5));
}



TEST_F(test_mock_fixture, test_get_packet_recv_success){
    char buf[MAX_RECV_LENGTH];
    EXPECT_CALL(mock_interface::instance, interface_read_data(_,_))
        .Times(AtLeast(1))
        .WillOnce(Return (5));
    ASSERT_EQ(5, get_packet(buf, 5));

    memset(buf, 0, MAX_RECV_LENGTH);
    char *dummy =  (char *)"test1";
    int length = strlen(dummy);
    char * end = (char *)(dummy + length);
    EXPECT_CALL(mock_interface::instance, interface_read_data(_,_))
        .Times(AtLeast(1))
        .WillOnce(DoAll(SetArrayArgument<0>(dummy, dummy + length), Return (length)));
    ASSERT_EQ(length, get_packet(buf, length));
    ASSERT_STREQ(dummy, buf);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc,argv);

    return RUN_ALL_TESTS();
}