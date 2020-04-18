file(GLOB affinity_src
	"src/*.cpp"
)

add_library(affinity STATIC ${affinity_src})

target_include_directories(affinity PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


