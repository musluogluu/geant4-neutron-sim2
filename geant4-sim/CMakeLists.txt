cmake_minimum_required(VERSION 3.16)
project(NeutronSimulation)

find_package(Geant4 REQUIRED)

add_executable(sim main.cc
  src/DetectorConstruction.cc
  src/PrimaryGeneratorAction.cc
  src/ActionInitialization.cc
  src/RunAction.cc
  src/EventAction.cc
  src/SteppingAction.cc
)

target_include_directories(sim PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(sim ${Geant4_LIBRARIES})

