cmake_minimum_required( VERSION 3.6 )

# Create Project
project( project_name )

# Set StartUp Project
set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "project_name" )

# Find PCL Package
set( PCL_ROOT $ENV{PCL_ROOT} )
find_package( PCL 1.9.1 REQUIRED )

# Find VTK Package
set( VTK_DIR "$ENV{PCL_ROOT}/3rdParty/VTK" )
#set( VTK_DIR $ENV{VTK_DIR} )
find_package( VTK REQUIRED )

# Associate Files
file(GLOB all_src
    "*.h"
    "*.cpp"
)

# Add Executable
 add_executable( project_name ${all_src} )

# Find OpenCV Package
find_package( OpenCV REQUIRED )
# target_include_directories(project_name PUBLIC ${OpenCV_INCLUDE_DIRS})
# target_link_libraries(project_name ${OpenCV_LIBS})
if(OpenCV_FOUND)
 message("opencv found!!")
 target_include_directories(project_name PUBLIC ${OpenCV_INCLUDE_DIRS})
 target_link_libraries(project_name ${OpenCV_LIBS})
endif(OpenCV_FOUND)


# Additional Include Directories
include_directories( ${PCL_INCLUDE_DIRS} )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

# Load VTK Settings
include( ${VTK_USE_FILE} )

# Preprocessor Definitions
add_definitions( ${PCL_DEFINITIONS} )

# Additional Library Directories
link_directories( ${PCL_LIBRARY_DIRS} )

# Additional Dependencies
target_link_libraries( project_name ${PCL_LIBRARIES} ${VTK_LIBRARIES} )
