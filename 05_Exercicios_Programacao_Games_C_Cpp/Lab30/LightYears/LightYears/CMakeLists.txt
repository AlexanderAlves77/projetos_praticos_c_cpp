add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-audio)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(
		TARGET ${TARGET_NAME}
		POST_BUILD 
		COMMAND
		${CMAKE_COMMAND} -E copy_if_different 
		$<TARGET_FILE:${LIB_NAME}>
		$<TARGET_FILE_DIR:${TARGET_NAME}>
	)
endfunction()

CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-window ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_GAME_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_GAME_TARGET_NAME})
