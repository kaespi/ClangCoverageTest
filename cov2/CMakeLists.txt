set(NAME "libcov2")

add_library(${NAME} SHARED)

target_sources(${NAME}
    PUBLIC
        include/cov2/cov2.h
    PRIVATE
        cov2.cpp
)

target_include_directories(${NAME}
    PUBLIC
        include
)

target_link_libraries(${NAME}
    PRIVATE
        libcov1
)

# unittests for the library
set(NAME_UNITTESTS "${NAME}_tests")
add_executable(${NAME_UNITTESTS})

target_sources(${NAME_UNITTESTS}
    PRIVATE
        tests/cov2_tests.cpp
)

target_link_libraries(${NAME_UNITTESTS}
    PRIVATE
        ${NAME}
        Catch2::Catch2
)

catch_discover_tests(${NAME_UNITTESTS}
    PROPERTIES
        ENVIRONMENT "LLVM_PROFILE_FILE=${COVERAGE_FILE}"
)
