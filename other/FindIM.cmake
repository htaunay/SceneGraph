FILE( TO_CMAKE_PATH "$ENV{SDK}" SDK_DIR )

IF (UNIX)
	
	FIND_PATH( 
		IM_INCLUDE_PATH im.h
		/usr/libim/include
		/usr/local/libim/include
		/sw/libim/include
		/opt/local/libim/include
		${SDK_DIR}/libim/include
		DOC "The directory where im.h resides")
		
		FIND_LIBRARY( 
		IM_LIBRARY
		NAMES libim.so
		PATHS
		${SDK_DIR}/libim
		/usr/lib64
		/usr/lib
		/usr/local/lib64
		/usr/local/lib
		/sw/lib
		/opt/local/lib
		DOC "The IM library")
		
ENDIF (UNIX)

IF (WIN32)

	FIND_PATH( 
		IM_INCLUDE_PATH im.h
		${SDK_DIR}/libim/include
		DOC "The directory where libim resides")
		
	FIND_LIBRARY( 
		IM_LIBRARY
		NAMES libim
		PATHS
		${SDK_DIR}/libim/lib
		DOC "The IM library")
		
ENDIF (WIN32)

IF (IM_INCLUDE_PATH )
	SET( IM_FOUND 1 CACHE STRING "Set to 1 if IM is found, 0 otherwise")
ELSE (IM_INCLUDE_PATH )
	SET( IM_FOUND 0 CACHE STRING "Set to 1 if IM is found, 0 otherwise")
ENDIF (IM_INCLUDE_PATH )

MARK_AS_ADVANCED( IM_FOUND )

