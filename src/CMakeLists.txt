
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

list(APPEND ANTLR4_INCLUDE_DIR E:/msys64/mingw64/include/antlr4-runtime)
foreach(dir ${ANTLR4_INCLUDE_DIR})
    target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${dir}
    )
endforeach()

foreach(dir ${ANTLR4_LIBRARY_DIR})
    target_link_directories(${PROJECT_NAME}
        PRIVATE
        ${dir}
        )
endforeach()

list(APPEND ANTLR4_LIBRARY_NAME libantlr4-runtime)
foreach(lib ${ANTLR4_LIBRARY_NAME})
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${lib}
        )
endforeach()

target_compile_features(${PROJECT_NAME}
    PRIVATE
    cxx_std_20
)

if(MINGW OR CMAKE_GNU_COMPILER_ID)
    target_compile_options(${PROJECT_NAME}
        PRIVATE
        -Wno-attributes
    )
endif()

add_custom_command(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "$<TARGET_FILE:${PROJECT_NAME}>"
)

