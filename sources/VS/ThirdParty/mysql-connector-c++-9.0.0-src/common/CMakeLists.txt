# Copyright (c) 2017, 2024, Oracle and/or its affiliates.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License, version 2.0, as
# published by the Free Software Foundation.
#
# This program is designed to work with certain software (including
# but not limited to OpenSSL) that is licensed under separate terms, as
# designated in a particular file or component or in included license
# documentation. The authors of MySQL hereby grant you an additional
# permission to link the program and your derivative works with the
# separately licensed software that they have either included with
# the program or referenced in the documentation.
#
# Without limiting anything contained in the foregoing, this file,
# which is part of Connector/C++, is also subject to the
# Universal FOSS Exception, version 1.0, a copy of which can be found at
# https://oss.oracle.com/licenses/universal-foss-exception.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License, version 2.0, for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA


file(GLOB HEADERS *.h)

add_library(common STATIC
  session.cc result.cc collection.cc value.cc
  ${HEADERS}
)

target_link_libraries(common cdk)

#TODO: Remove -Wno-delete-non-abstract-non-virtual-dtor when bumping ABI and
  #      adding virtual destructor for DbDoc, Value and Column_detail
if(CLANG)
  target_compile_options(common PRIVATE
    -Wno-delete-non-abstract-non-virtual-dtor
  )
endif()

#
# Note: generated version_info.h is placed in the build location
# and the common target is configured to include it before the
# original version in the sources
#

configure_file(version_info.h ${CMAKE_BINARY_DIR}/include/mysqlx/version_info.h @ONLY)

# FIXME: This include path is made public, because other components
# such as devapi use private headers of the common component.

target_include_directories(common
  BEFORE PUBLIC ${CMAKE_BINARY_DIR}/include/mysqlx/
)

ADD_TEST_INCLUDES(${CMAKE_BINARY_DIR}/include/mysqlx/)

INSTALL(FILES ${CMAKE_BINARY_DIR}/include/mysqlx/version_info.h DESTINATION ${INSTALL_INCLUDE_DIR}/mysqlx COMPONENT XDevAPIDev)

add_subdirectory(tests)
