set(TOTO_SRCS
    main.cpp
)

add_definitions(
	${MOOST_DEFINITIONS}
)

include_directories(
	${MOOST_INCLUDE_DIR}
)

add_executable(echo
	${TOTO_SRCS}
)

target_link_libraries(echo
    ${MOOST_STASH_LINK_DEPENDENCIES}
)
