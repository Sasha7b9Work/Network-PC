# Copyright (c) 2013, 2024, Oracle and/or its affiliates.
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

##########################################################################

# The parameter can be either T or D
MACRO(CHANGE_CRT _switch2use)
  # Or should that be check for VS?
  IF(WIN32)
      SET(switch2change "D")

      IF(_switch2use STREQUAL "D" OR _switch2use STREQUAL "MD" OR _switch2use STREQUAL "/MD")
        SET(switch2use "D")
        SET(switch2change "T")
      ELSE(switch2use STREQUAL "D" OR _switch2use STREQUAL "MD" OR _switch2use STREQUAL "/MD")
        #Default is to change to /MT
        SET(switch2use "T")
      ENDIF(_switch2use STREQUAL "D" OR _switch2use STREQUAL "MD" OR _switch2use STREQUAL "/MD")

      FOREACH(flags CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        IF(${flags} MATCHES "/M${switch2change}")
          STRING(REGEX REPLACE "/M${switch2change}" "/M${switch2use}" ${flags} "${${flags}}")
        ENDIF(${flags} MATCHES "/M${switch2change}")

        MESSAGE(STATUS, "CHANGE_CRT ${flags} ${${flags}}")

      ENDFOREACH(flags)
  ENDIF(WIN32)

ENDMACRO(CHANGE_CRT _switch2use)
