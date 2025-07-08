##################################################################################
# Default setup for a "docu" target using doxygen.
##################################################################################

##################################################################################
# find doxygen
##################################################################################
if (POLICY CMP0109)
  cmake_policy(SET CMP0109 NEW)
endif()

find_package(Doxygen)

##################################################################################
# create docu target, if package was found
##################################################################################
if(DOXYGEN_FOUND)
   if(NOT DOXYGEN_CONF_IN)
      set (conf_file "${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf.in")
   else(NOT DOXYGEN_CONF_IN)
      set(conf_file ${DOXYGEN_CONF_IN})
   endif(NOT DOXYGEN_CONF_IN)

   if(NOT EXISTS "${conf_file}")
      message(WARNING "No doxygen configuration found. Please create
                       '${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf.in'.
                       No documentation target created.")
   else(NOT EXISTS "${conf_file}")
      # configuration input and output
      set(DOXYGEN_CONF_IN ${conf_file})
      set(DOXYGEN_CONF_OUT doxygen.conf)

      # set to override variable within configuration
      if(NOT DOXYGEN_INPUT_PATH)
         set(DOXYGEN_INPUT_PATH "\"${CMAKE_CURRENT_SOURCE_DIR}\"")
      endif(NOT DOXYGEN_INPUT_PATH)
      if(NOT DOXYGEN_OUTPUT_PATH)
         set(DOXYGEN_OUTPUT_PATH "\"${CMAKE_CURRENT_BINARY_DIR}\"")
      endif(NOT DOXYGEN_OUTPUT_PATH)
      if(NOT DOXYGEN_IMAGE_PATH)
         set(DOXYGEN_IMAGE_PATH "\"${CMAKE_CURRENT_SOURCE_DIR}\"")
      endif(NOT DOXYGEN_IMAGE_PATH)
      if(NOT DOXYGEN_DOTFILE_PATH)
         set(DOXYGEN_DOTFILE_PATH "\"${CMAKE_CURRENT_SOURCE_DIR}\"")
      endif(NOT DOXYGEN_DOTFILE_PATH)

      # cleanup properties from html output
      set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
                      "${CMAKE_CURRENT_BINARY_DIR}/html"
      )

      # copy configuration file and replace input path
      configure_file( ${DOXYGEN_CONF_IN}
                      ${DOXYGEN_CONF_OUT}
                      @ONLY
      )

      # add documentation target
      add_custom_target(
          docu
          COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONF_OUT}
          COMMENT "Create HTML documentation."
      )
   endif(NOT EXISTS "${conf_file}")
else(DOXYGEN_FOUND)
   message(WARNING "Doxygen not found. Documentation target not created.")
endif(DOXYGEN_FOUND)


