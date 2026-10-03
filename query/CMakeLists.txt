add_library(query)

target_sources(query
    PRIVATE
        query.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            query.h
)

find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

target_link_libraries(query
    PRIVATE
        cpr::cpr
        nlohmann_json::nlohmann_json
)