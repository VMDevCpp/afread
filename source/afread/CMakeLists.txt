file(GLOB afread_src
	"src/*.h"
	"src/*.cpp"
)

add_executable (afread ${afread_src})

target_link_libraries(afread affinity)
target_link_libraries(afread zstd)
target_link_libraries(afread miniz)
target_link_libraries(afread cxxopts)

set_target_properties(afread PROPERTIES LINK_FLAGS "${AF_LD_OPTIONS}")


