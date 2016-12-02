# Specify the minimum CMAKE version required
cmake_minimum_required(VERSION 2.8)

# Your project's name
project(OGL)

# Make your header file accessible to the compiler
include_directories(include)

# Set the source files for the project
set (SRC src/main.cpp src/Timer.cpp src/Renderer.cpp src/Shader.cpp src/Model.cpp src/Terrain.cpp src/Chunk.cpp)
set (SHADERS shaders/shader.frag shaders/shader.vert)

# Use GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(dependencies/glfw)

# Use GL3W
add_subdirectory(dependencies/gl3w)
include_directories(dependencies/gl3w/include)

# Use GLM
include_directories(dependencies/glm/include)

# Use FastNoise
add_subdirectory(dependencies/fastnoise)
include_directories(dependencies/fastnoise/include)

find_package(OpenGL REQUIRED)

# Define the executable
add_executable(OGL ${SRC})
target_link_libraries(OGL gl3w glfw ${OPENGL_LIBRARIES} fastnoise)

# Enable C++ 11
set_target_properties(OGL PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Create Debugging Symbols
set(CMAKE_BUILD_TYPE Debug)

# Copy shaders
file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})
