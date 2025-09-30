cmake_minimum_required(VERSION 3.16)

project(LEARN_OPENGL LANGUAGES C CXX)

include(FetchContent)

# ---- GLFW options (set before fetching) ----
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL        OFF CACHE BOOL "" FORCE)  # set ON if you want `make install`

# ---- Fetch GLFW ----
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4            # pick a specific release tag
)
FetchContent_MakeAvailable(glfw) # adds target `glfw` and alias `glfw::glfw`

FetchContent_Declare(
  glad2
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG        glad2
  SOURCE_SUBDIR  cmake  # Tell CMake to look for CMakeLists.txt in the cmake subdirectory
)

FetchContent_MakeAvailable(glad2)

glad_add_library(glad_gl STATIC
  REPRODUCIBLE
  API gl:core=4.6  # request OpenGL 4.6 Core
  LANGUAGE c
)

find_package(OpenGL REQUIRED)

macro(gl_link NAME)
    target_link_libraries(${NAME} PRIVATE glfw glad_gl OpenGL::GL)
    if (MSVC)
        target_compile_definitions(${NAME} PRIVATE UNICODE _UNICODE)
    endif()
endmacro()


add_executable(test_glfw test/glfw_test.cc)
gl_link(test_glfw)

add_subdirectory(chapters)
