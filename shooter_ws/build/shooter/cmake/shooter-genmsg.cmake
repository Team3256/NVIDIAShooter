# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "shooter: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ishooter:/home/ubuntu/shooter_ws/src/shooter/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(shooter_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ubuntu/shooter_ws/src/shooter/msg/JoyValues.msg" NAME_WE)
add_custom_target(_shooter_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "shooter" "/home/ubuntu/shooter_ws/src/shooter/msg/JoyValues.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(shooter
  "/home/ubuntu/shooter_ws/src/shooter/msg/JoyValues.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/shooter
)

### Generating Services

### Generating Module File
_generate_module_cpp(shooter
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/shooter
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(shooter_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(shooter_generate_messages shooter_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/shooter_ws/src/shooter/msg/JoyValues.msg" NAME_WE)
add_dependencies(shooter_generate_messages_cpp _shooter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(shooter_gencpp)
add_dependencies(shooter_gencpp shooter_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS shooter_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(shooter
  "/home/ubuntu/shooter_ws/src/shooter/msg/JoyValues.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/shooter
)

### Generating Services

### Generating Module File
_generate_module_lisp(shooter
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/shooter
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(shooter_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(shooter_generate_messages shooter_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/shooter_ws/src/shooter/msg/JoyValues.msg" NAME_WE)
add_dependencies(shooter_generate_messages_lisp _shooter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(shooter_genlisp)
add_dependencies(shooter_genlisp shooter_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS shooter_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(shooter
  "/home/ubuntu/shooter_ws/src/shooter/msg/JoyValues.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/shooter
)

### Generating Services

### Generating Module File
_generate_module_py(shooter
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/shooter
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(shooter_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(shooter_generate_messages shooter_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubuntu/shooter_ws/src/shooter/msg/JoyValues.msg" NAME_WE)
add_dependencies(shooter_generate_messages_py _shooter_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(shooter_genpy)
add_dependencies(shooter_genpy shooter_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS shooter_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/shooter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/shooter
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(shooter_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/shooter)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/shooter
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(shooter_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/shooter)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/shooter\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/shooter
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(shooter_generate_messages_py std_msgs_generate_messages_py)
