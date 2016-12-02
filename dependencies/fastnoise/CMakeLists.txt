project(fastnoise)

add_library(fastnoise fastnoise.cpp)
include_directories(./include)

# Enable C++ 11
set_target_properties(fastnoise PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
