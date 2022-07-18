cmake_minimum_required (VERSION 3.11)

project (Skillbox_Search_Engine)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Tests)

include(FetchContent)
	FetchContent_Declare(
		json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz
	)
	FetchContent_MakeAvailable(
		json
	)

set(Headers
	Src/ConverterJSON.cpp
	Src/InvertedIndex.cpp
	Src/SearchServer.cpp
)

add_library(Project_library ${Headers})

add_executable (Skillbox_Search_Engine Skillbox_Search_Engine.cpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Skillbox_Search_Engine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
target_link_libraries(Project_library PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Skillbox_Search_Engine Project_library)