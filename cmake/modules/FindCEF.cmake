IF( CEF_INCLUDE_DIR )
    # Already in cache, be silent
    SET( CEF_FIND_QUIETLY TRUE )
ENDIF( CEF_INCLUDE_DIR )

FIND_PATH( CEF_INCLUDE_DIR "include/cef_app.h" )

FIND_LIBRARY( CEF_LIBRARIES
              NAMES "cef" )

# handle the QUIETLY and REQUIRED arguments and set CEF_FOUND to TRUE if
# all listed variables are TRUE
INCLUDE( "FindPackageHandleStandardArgs" )
FIND_PACKAGE_HANDLE_STANDARD_ARGS( "CEF" DEFAULT_MSG
                                   CEF_INCLUDE_DIR
                                   CEF_LIBRARIES )

MARK_AS_ADVANCED( CEF_INCLUDE_DIR CEF_LIBRARIES )
