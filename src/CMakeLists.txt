
add_executable(${PROJECT_NAME}
  ObcLexer.cpp
  ObcParser.cpp
  ObcHelper.cpp
  ObcVisitor.cpp
  ObcBaseVisitor.cpp
  ObcTreeVisitor.cpp
  ObcErrorListener.cpp
  ObcCmdParser.cpp
  
  main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${ANTLR4_INCLUDE_PATH}
)

target_compile_features(${PROJECT_NAME}
    PRIVATE
    cxx_std_20
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    libantlr4-runtime
)

if(MINGW)
    target_compile_options(${PROJECT_NAME}
        PRIVATE
        -Wno-attributes
    )
endif()

add_custom_command(TARGET ${PROJECT_NAME}
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E echo "$<TARGET_FILE:${PROJECT_NAME}>"
)

