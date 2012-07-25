include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/code
  ${CEF_INCLUDE_DIR}
)

set(CEFDESURA_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/code
    PARENT_SCOPE
)

file(GLOB Sources code/*.cpp)

add_library(cefdesura SHARED ${Sources})
target_link_libraries(cefdesura
    ${CEF_LIBRARIES}
)

install(TARGETS cefdesura
        DESTINATION "${LIB_INSTALL_DIR}")
