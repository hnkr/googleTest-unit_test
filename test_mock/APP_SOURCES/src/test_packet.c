//function under test
#ifdef __cplusplus
    extern "C" {
#endif

#include <interface_app.h>
#include <test_packet.h>
#include <string.h>


static int recv_packet(char * _buf, int _len){
    int ret = interface_read_data(_buf, _len);
    if(ret <= 0) return -1;
    return ret;
}


int get_packet(char * _buf_for_data, int _len){
    if(_buf_for_data == NULL) return -1;
    if(!_len    ||  _len > MAX_RECV_LENGTH)    return -1;
    memset(_buf_for_data, 0, _len);
    int ret = recv_packet(_buf_for_data, _len);
    return ret;
}


#ifdef __cplusplus
    }
#endif
