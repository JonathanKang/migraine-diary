/*
 *  GNOME Logs - View and search logs
 *  Copyright (C) 2018 Jonathan Kang <jonathankang@gnome.org>.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "md-window.h"

struct _MdWindow
{
    /*< private >*/
    GtkApplicationWindow parent_instance;
};

G_DEFINE_TYPE (MdWindow, md_window, GTK_TYPE_APPLICATION_WINDOW)

static void
md_window_init (MdWindow *window)
{
}

static void
md_window_class_init (MdWindowClass *klass)
{
}

GtkWidget *
md_window_new (GtkApplication *application)
{
    return g_object_new (MD_TYPE_WINDOW,
                         "application", application,
                         NULL);
}
