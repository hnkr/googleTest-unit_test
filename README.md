# googleTest-unit_test
- Example usages of GTest and GMock from googletest.
- Includes 3 mini-projects:
    - test_hello 
    - test_fixture
    - test_mock


## Requirements
- CMake (version > 3.15.2)

## Projects
    - test_hello : How to start with GTest
    - test_fixture: How to use fixture from GTest
    - test_mock: How to use GMock from googletest with an example. APP_SOURCES is assumed the code under test, which is also using an interface to receive data. MOCK is the mocking of external interface on which the APP_SOURCES has dependency.

## Build & Run
- Build:
    -   Get in build directory of each mini-project and type "cmake .."
    -   In the build directory type "make"
- Run:
    - ./test_hello for test_hello mini-project.
    - ./test_fixture for test_fixture mini-project.
    - ./test_mock for test_mock mini-project.

