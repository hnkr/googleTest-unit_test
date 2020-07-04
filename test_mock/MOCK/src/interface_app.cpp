#include <interface_app.h>
#include <interface_mock.hpp>

mock_interface mock_interface::instance;

int interface_read_data(char * _buf, int _len){
    return mock_interface::instance.interface_read_data(_buf, _len);
}