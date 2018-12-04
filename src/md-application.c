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

#include "md-application.h"

struct _MdApplication
{
    /*< private >*/
    GtkApplication parent_instance;
};

G_DEFINE_TYPE (MdApplication, md_application, GTK_TYPE_APPLICATION)

static void
md_application_activate (GApplication *application)
{
    GtkWidget *window;

    window = gtk_application_window_new (GTK_APPLICATION (application));
    gtk_widget_show (window);
}

static void
md_application_init (MdApplication *application)
{
}

static void
md_application_class_init (MdApplicationClass *klass)
{
    GApplicationClass *app_class;

    app_class = G_APPLICATION_CLASS (klass);
    app_class->activate = md_application_activate;
}

GtkApplication *
md_application_new ()
{
    return g_object_new (MD_TYPE_APPLICATION,
                         "application-id", "com.jonathankang.MigraineDiary",
                         NULL);
}
