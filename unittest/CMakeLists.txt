
# CMake file to register the csept unit test suite

# Build and register calitem unit test
add_executable(calitem_test calitem.cpp ../calitem.cpp)
target_link_libraries(calitem_test ${Boost_LIBRARIES})
add_test(calitem_unit_tests ${CMAKE_CURRENT_BINARY_DIR}/calitem_test)