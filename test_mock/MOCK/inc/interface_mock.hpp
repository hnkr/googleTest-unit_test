

#ifndef INTERFACE_MOCK
#define INTERFACE_MOCK

#include <gmock/gmock.h>

class mock_interface{

    public:
    MOCK_METHOD( int, interface_read_data,(char *, int ));

    static mock_interface instance;
};

#endif