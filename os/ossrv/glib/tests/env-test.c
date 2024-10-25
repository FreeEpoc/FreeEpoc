/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 * Portion Copyright � 2008-09 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/. 
 */

#include "config.h"

#undef G_DISABLE_ASSERT
#undef G_LOG_DOMAIN

#ifdef GLIB_COMPILATION
#undef GLIB_COMPILATION
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <glib.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef __SYMBIAN32__
#include "mrt2_glib2_test.h"
#endif /*__SYMBIAN32__*/


int 
main (int argc, char *argv[])
{
  gboolean result;
  const gchar *data;
  gchar *variable = "TEST_G_SETENV";
  gchar *value1 = "works";
  gchar *value2 = "again";

  #ifdef __SYMBIAN32__
  g_log_set_handler (NULL,  G_LOG_FLAG_FATAL| G_LOG_FLAG_RECURSION | G_LOG_LEVEL_CRITICAL | G_LOG_LEVEL_WARNING | G_LOG_LEVEL_MESSAGE | G_LOG_LEVEL_INFO | G_LOG_LEVEL_DEBUG, &mrtLogHandler, NULL);
  g_set_print_handler(mrtPrintHandler); 
  #endif /*__SYMBIAN32__*/
	  
  data = g_getenv (variable);
  g_assert (data == NULL && "TEST_G_SETENV already set");
  
  result = g_setenv (variable, value1, TRUE);
  g_assert (result && "g_setenv() failed");
  
  data = g_getenv (variable);
  g_assert (data != NULL && "g_getenv() returns NULL");
  g_assert (strcmp (data, value1) == 0 && "g_getenv() returns wrong value");

  result = g_setenv (variable, value2, FALSE);
  g_assert (result && "g_setenv() failed");
  
  data = g_getenv (variable);
  g_assert (data != NULL && "g_getenv() returns NULL");
  g_assert (strcmp (data, value2) != 0 && "g_setenv() always overwrites");
  g_assert (strcmp (data, value1) == 0 && "g_getenv() returns wrong value");

  result = g_setenv (variable, value2, TRUE);
  g_assert (result && "g_setenv() failed");
  
  data = g_getenv (variable);
  g_assert (data != NULL && "g_getenv() returns NULL");
  g_assert (strcmp (data, value1) != 0 && "g_setenv() doesn't overwrite");
  g_assert (strcmp (data, value2) == 0 && "g_getenv() returns wrong value");

  g_unsetenv (variable);
  data = g_getenv (variable);
  g_assert (data == NULL && "g_unsetenv() doesn't work");

#if 0
  /* We can't test this, because it's an illegal argument that
   * we g_return_if_fail for.
   */
  result = g_setenv ("foo=bar", "baz", TRUE);
  g_assert (!result && "g_setenv() accepts '=' in names");
#endif  

  result = g_setenv ("foo", "bar=baz", TRUE);
  g_assert (result && "g_setenv() doesn't accept '=' in values");
#if 0
  /* While glibc supports '=' in names in getenv(), SUS doesn't say anything about it,
   * and Solaris doesn't support it.
   */
  data = g_getenv ("foo=bar");
  g_assert (strcmp (data, "baz") == 0 && "g_getenv() doesn't support '=' in names");
#endif
  data = g_getenv ("foo");
  g_assert (strcmp (data, "bar=baz") == 0 && "g_getenv() doesn't support '=' in values");

#if 0  
  /* We can't test this, because it's an illegal argument that
   * we g_return_if_fail for. Plus how would we check for failure,
   * since we can't set the value...
   */
  g_unsetenv ("foo=bar");
#endif  
  g_unsetenv ("foo");
  data = g_getenv ("foo");
  g_assert (data == NULL && "g_unsetenv() doesn't support '=' in values");
  
  #if __SYMBIAN32__
  testResultXml("env-test");
  #endif /* EMULATOR */
   

  return 0;
}
