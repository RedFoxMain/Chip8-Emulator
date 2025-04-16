cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Chip8_Emulator")

add_subdirectory("${CMAKE_SOURCE_DIR}/thirdparty/SDL")

set( EXEC_FILES
	"src/cpu.h"
	"src/cpu.c"
	"src/main.c"
	"src/display.h"
	"src/display.c"
)

add_executable(${PROJECT_NAME} ${EXEC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/thirdparty/SDL/include")
target_link_libraries(${PROJECT_NAME} SDL2::SDL2-static SDL2::SDL2main )