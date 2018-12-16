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

#include <gtk/gtk.h>

#include "md-diary-list.h"

struct _MdDiaryList
{
    /*< private >*/
    GtkBox parent_instance;
};

G_DEFINE_TYPE (MdDiaryList, md_diary_list, GTK_TYPE_BOX)

static void
md_diary_list_init (MdDiaryList *list)
{
    gtk_widget_init_template (GTK_WIDGET (list));
}

static void
md_diary_list_class_init (MdDiaryListClass *klass)
{
    GtkWidgetClass *widget_class;

    widget_class = GTK_WIDGET_CLASS (klass);
    gtk_widget_class_set_template_from_resource (widget_class,
                                                 "/com/jonathankang/MigraineDiary/md-diary-list.ui");
}

GtkWidget *
md_diary_list_new ()
{
    return g_object_new (MD_TYPE_DIARY_LIST, NULL);
}
