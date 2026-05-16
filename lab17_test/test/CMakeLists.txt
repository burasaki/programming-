find_package(PkgConfig REQUIRED)
pkg_check_modules(CMOCKA REQUIRED cmocka)

set(TEST_FILES
    test_other.c
    test_simple_func.c
    test_trig.c
)

foreach(file ${TEST_FILES})
    get_filename_component(test_name ${file} NAME_WE)
    
    add_executable(${test_name} ${file} ../main.c)
    
    target_link_libraries(${test_name} PRIVATE main ${CMOCKA_LIBRARIES})
    target_include_directories(${test_name} PRIVATE ${CMOCKA_INCLUDE_DIRS})
    
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
