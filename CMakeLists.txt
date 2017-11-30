cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(G4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH /home/nick/geant4/geant4.10.01.p03-install)
set(GEANT4_USE_QT ON)

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)


file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(ExG4 ExampleG4.cc ${sources} ${headers} src/SensitiveDetector.cc include/SensitiveDetector.hh src/PhysicsList.cc include/PhysicsList.hh)
target_link_libraries(ExG4 ${Geant4_LIBRARIES})

set(EXG4_SCRIPTS
        vis.mac
        )

foreach(_script ${EXAMPLEB1_SCRIPTS})
  configure_file(
          ${PROJECT_SOURCE_DIR}/${_script}
          ${PROJECT_BINARY_DIR}/${_script}
          COPYONLY
  )
endforeach()

add_custom_target(G4 DEPENDS ExG4)


install(TARGETS ExG4 DESTINATION bin)


