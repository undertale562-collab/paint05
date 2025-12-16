project(tests LANGUAGES CXX)
enable_testing(true)

find_package(Qt6 REQUIRED COMPONENTS Test)
add_executable(painttest testssrc/main.cpp testssrc/painttest.h testssrc/painttest.cpp)
add_test(NAME painttest COMMAND painttest)
target_link_libraries(painttest PRIVATE Qt6::Test Qt::Widgets Qt::Gui paint05lib)
