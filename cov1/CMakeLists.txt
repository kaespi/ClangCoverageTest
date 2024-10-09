set(NAME "libcov1")

add_library(${NAME} SHARED)

target_sources(${NAME}
    PUBLIC
        include/cov1/cov1_a.h
        include/cov1/cov1_b.h
    PRIVATE
        cov1_a.cpp
        cov1_b.cpp
)

target_include_directories(${NAME}
    PUBLIC
        include
)

# unittests for the library
set(NAME_UNITTESTS "${NAME}_tests")
add_executable(${NAME_UNITTESTS})

target_sources(${NAME_UNITTESTS}
    PRIVATE
        tests/cov1_tests.cpp
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
