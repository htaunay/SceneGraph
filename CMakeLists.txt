CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

PROJECT( SceneGraph )

FILE( GLOB source_files *.cpp )
FILE( GLOB header_files *.h )

FIND_PACKAGE( GLUT )
FIND_PACKAGE( OpenGL )

set( CORELIBS ${GLUT_LIBRARY} ${OPENGL_LIBRARY} )

INCLUDE_DIRECTORIES( /usr/include/GL )

ADD_EXECUTABLE( SceneGraph ${source_files} ${header_files} )

TARGET_LINK_LIBRARIES( SceneGraph ${CORELIBS} )

