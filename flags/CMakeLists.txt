add_library(flags)

target_sources(flags
    PRIVATE
        commands.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            commands.h
)