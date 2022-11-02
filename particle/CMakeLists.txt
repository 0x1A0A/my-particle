file(
	GLOB_RECURSE APP_SRC
	"${CMAKE_CURRENT_LIST_DIR}/src/*"
)

add_executable(particle ${APP_SRC})
target_link_libraries(particle PRIVATE raylib)
