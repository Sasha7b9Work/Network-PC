/*
 * Copyright (c) 2000, 2024, Oracle and/or its affiliates.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0, as
 * published by the Free Software Foundation.
 *
 * This program is designed to work with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms, as
 * designated in a particular file or component or in included license
 * documentation. The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have either included with
 * the program or referenced in the documentation.
 *
 * Without limiting anything contained in the foregoing, this file,
 * which is part of Connector/C++, is also subject to the
 * Universal FOSS Exception, version 1.0, a copy of which can be found at
 * https://oss.oracle.com/licenses/universal-foss-exception.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */




#if !defined(_my_no_pthread_h) && !defined(THREAD)
#define _my_no_pthread_h

/*
  This block is to access some thread-related type definitions
  even in builds which do not need thread functions,
  as some variables (based on these types) are declared
  even in non-threaded builds.
  Case in point: 'mf_keycache.c'
*/
#if defined(_WIN32) || defined(_WIN64)
#else /* Normal threads */
#include <pthread.h>
#endif /* defined(__WIN__) */


/*
  This undefs some pthread mutex locks when one isn't using threads
  to make thread safe code, that should also work in single thread
  environment, easier to use.
*/
#define pthread_mutex_init(A,B)
#define pthread_mutex_lock(A)
#define pthread_mutex_unlock(A)
#define pthread_mutex_destroy(A)

#endif