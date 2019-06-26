
# Cmake setup with import of necessary libraries

# Standard cmake version requirement
cmake_minimum_required(VERSION 2.6)


# Inform user
MESSAGE("Configuring program.")

# Project (fortran must be enabled for OpenCMISS compatibility)
PROJECT( LibraryExamples LANGUAGES C CXX Fortran )

# Add all the local source files from the folder "src" to the makefile
file(GLOB_RECURSE LIBRARY_EXAMPLES_SRC_LIBRARY
    "*.hpp"
    "*.cpp"
)

# Application source: could make this to select various files
# or just compile different .exe's which would be a little weird
file(GLOB_RECURSE LIBRARY_EXAMPLES_SRC_APPLICATION
    "*.hpp"
    "*.cpp"
)


#---- external packages ----#
# 1. MPI
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

# 2. VTK
find_package( VTK REQUIRED NO_MODULE ) 
include_directories(${VTK_INCLUDE_DIRS})
include(${VTK_USE_FILE})

# 3. Octave
find_library(OCTAVE_LIBRARY_PATH octave HINTS "${OCTAVE_LIB_PATH}")
include_directories( ${OCTAVE_INCLUDE_PATH} )

# 3. Add the paths to the utility function lib and include
find_library(UTILITYFUNCTION_LIBRARY_PATH utilityFunctionLibrary HINTS "${UtilityFunctionLibrary_INSTALL_DIR}/lib")
include_directories( ${UtilityFunctionLibrary_INSTALL_DIR}/include )

# 4. VTK function library
find_library(VTKFUNCTION_LIBRARY_PATH vtkFunctionLibrary HINTS "${VTKFunctionLibrary_INSTALL_DIR}/lib")
include_directories( ${VTKFunctionLibrary_INSTALL_DIR}/include )

# 5. PNOL
find_library(PNOL_LIBRARY_PATH pnol HINTS "${PNOL_INSTALL_DIR}/lib")
include_directories( ${PNOL_INSTALL_DIR}/include )

# 6. NAS
find_library(NAS_LIBRARY_PATH nas HINTS "${NAS_INSTALL_DIR}/lib")
include_directories( ${NAS_INSTALL_DIR}/include )

# Add the execubale using the source files in (src)
add_executable(LibraryExamples ${LIBRARY_EXAMPLES_SRC_APPLICATION})


# Link the local and external libraries to the executable
target_link_libraries( 
	LibraryExamples
	mpi
	mpi_cxx
	${MPI_LIBRARIES}
	${VTK_LIBRARIES}
	${UTILITYFUNCTION_LIBRARY_PATH}
	${VTKFUNCTION_LIBRARY_PATH}
	${PNOL_LIBRARY_PATH}
	${NAS_LIBRARY_PATH}
	${OCTAVE_LIBRARY_PATH}
)



# Install the application binary
install(TARGETS LibraryExamples
        RUNTIME DESTINATION bin
)

# Install the header files
INSTALL ( DIRECTORY ${CMAKE_SOURCE_DIR}/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING PATTERN "*.hpp"
  )

# Install the header files
INSTALL ( DIRECTORY ${CMAKE_SOURCE_DIR}/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING PATTERN "*.h"
  )


INSTALL ( DIRECTORY ${CMAKE_SOURCE_DIR}/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
  FILES_MATCHING PATTERN "*.m"
  )

INSTALL ( DIRECTORY ${CMAKE_SOURCE_DIR}/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
  FILES_MATCHING PATTERN "*.txt"
  )













































