cmake_minimum_required(VERSION 3.2)

SET(PROJ_NAME painter)

if($ENV{TRAVIS_BUILD_NUMBER})
    project(${PROJ_NAME} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(${PROJ_NAME} VERSION 0.0.42)
endif()

configure_file(description.json.in description.json)

set(INCLUDE ${CMAKE_BINARY_DIR}/../include)
include_directories(${INCLUDE}
                    ${INCLUDE}/ui
                    ${INCLUDE}/primitives
                    ${INCLUDE}/primitives/interfaces
                    ${INCLUDE}/mvc
                    ${INCLUDE}/mvc/interfaces)


set(SOURCE ${CMAKE_BINARY_DIR}/../source)
add_executable(${PROJ_NAME} ${SOURCE}/main.cpp 
                            ${SOURCE}/mvc/Controller.cpp
                            ${SOURCE}/mvc/Model.cpp
                            ${SOURCE}/mvc/UI.cpp)


set_target_properties(painter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if(MSVC)
    target_compile_options(${PROJ_NAME} PRIVATE
        /W4
    )
else()
    target_compile_options(${PROJ_NAME} PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ${PROJ_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

#doxygen
find_package(Doxygen REQUIRED)
set(DOXYGEN_OUTPUT_DIRECTORY)
set(DOXYGEN_PROJECT_NUMBER ${VERSION})
set(DOXYGEN_HAVE_DOT YES)
set(DOXYGEN_EXTRACT_ALL YES)
doxygen_add_docs(${PROJ_NAME}_doc
    ${INCLUDE} ${SOURCE} 
)