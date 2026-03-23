cmake_minimum_required(VERSION 3.10)

project(Engine-Python)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB SOURCES "src/*.c")
add_executable(libgame.so ${SOURCES})

target_include_directories(libgame.so PUBLIC "${PROJECT_SOURCE_DIR}/inc")
file(COPY "${PROJECT_SOURCE_DIR}/assets" DESTINATION "${CMAKE_BINARY_DIR}")

if(M_WIN32)
	set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-gcc)
	#set(CMAKE_BUILD_TYPE Debug)
	#target_compile_options(libgame.so PRIVATE -Wall -Wextra -Wpedantic -Werror -O3)
	target_include_directories(libgame.so PUBLIC "${PROJECT_SOURCE_DIR}/inc/win32")
	# Directorio con las dependencias .a
	target_link_directories(libgame.so PUBLIC "${PROJECT_SOURCE_DIR}/libs/win32")
	file(GLOB LIBS "${PROJECT_SOURCE_DIR}/libs/win32/*.a")
	target_link_libraries(libgame.so PUBLIC ${LIBS}
						-lole32 -lgdi32 -lwinmm -lsetupapi -limm32
						-loleaut32 -lversion -luuid -lrpcrt4 -lws2_32
						-liphlpapi -lmingw32 -lSDL2main)
	target_link_options(libgame.so PUBLIC -shared -static-libgcc -static-libstdc++ -static)
	message(STATUS "Compilando para windows")
elseif(UNIX)
	set(CMAKE_CXX_COMPILER gcc)
	#set(CMAKE_BUILD_TYPE Debug)
	# Directorio con las dependencias .a
	#target_link_directories(game PUBLIC "${PROJECT_SOURCE_DIR}/libs/linux")
	#file(GLOB LIBS "${PROJECT_SOURCE_DIR}/libs/linux/*.a")
	#target_link_libraries(game ${LIBS})
	target_link_libraries(libgame.so "SDL3 -lSDL3_image")
	target_link_options(libgame.so PUBLIC -shared -static-libgcc -static-libstdc++)
	message(STATUS "Compilando para linux")
elseif(WIN32)
	set(CMAKE_CXX_COMPILER gcc)
	target_include_directories(libgame.so PUBLIC "${PROJECT_SOURCE_DIR}/inc/win32")
	target_link_directories(libgame.so PUBLIC "${PROJECT_SOURCE_DIR}/libs/win32")
	file(GLOB LIBS "${PROJECT_SOURCE_DIR}/libs/win32/*.a")
	target_link_libraries(libgame.so PUBLIC ${LIBS}
						-lole32 -lgdi32 -lwinmm -lsetupapi -limm32
						-loleaut32 -lversion -luuid -lrpcrt4 -lws2_32
						-liphlpapi -lmingw32 -lSDL2main)
	target_link_options(libgame.so PUBLIC -shared -static-libgcc -static-libstdc++ -static)
	message(STATUS "Compilando para windows")
else(FATAL_ERROR "No soporta la plataforma")
endif()
