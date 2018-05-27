cmake_minimum_required (VERSION 3.1)
project (checkMacAddr)

# System Requirement
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
# find_package( Threads REQUIRED)



# Executable 2
set( exe1 readBinaryFileAndPrintToScreen.exe ) 
add_executable(${exe1} readBinaryFileAndPrintToScreen.cpp)
set_target_properties(${exe1} PROPERTIES LINK_FLAGS "-static -static-libgcc" )

# Executable 2
set( exe2 optimizeHardwareForESSI.exe ) 
add_executable(${exe2} readHardwareAndWriteToBinaryFile.cpp)
set_target_properties(${exe2} PROPERTIES LINK_FLAGS "-static -static-libgcc" )
# target_link_libraries(${exe2} Threads::Threads)


enable_testing()
add_test(exe1 ${exe1})
add_test(exe2 ${exe2})

