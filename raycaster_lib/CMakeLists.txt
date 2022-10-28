add_library(raycaster_lib SHARED
    life.h
    life.cpp
)

target_include_directories(raycaster_lib PUBLIC
	${CMAKE_CURRENT_LIST_DIR}
)