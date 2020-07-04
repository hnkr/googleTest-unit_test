
set(USER_APP_SRCS
	src/test_packet.c
	src/interface_app.c
)

add_library(user_app ${USER_APP_SRCS})
target_include_directories(user_app PUBLIC inc)


