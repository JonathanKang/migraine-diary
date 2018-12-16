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

typedef struct
{
    GtkListBox *diaries_list;
} MdDiaryListPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (MdDiaryList, md_diary_list, GTK_TYPE_BOX)

static GtkWidget *
md_diary_list_create_placeholder (void)
{
    GtkStyleContext *style;
    GtkWidget *box;
    GtkWidget *image;
    GtkWidget *label;
    gchar *markup;

    box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 12);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand(box, TRUE);
    gtk_widget_set_vexpand(box, TRUE);
    style = gtk_widget_get_style_context(box);
    gtk_style_context_add_class(style, "dim-label");

    image = gtk_image_new_from_icon_name ("action-unavailable-symbolic", 0);
    gtk_image_set_pixel_size (GTK_IMAGE (image), 64);
    style = gtk_widget_get_style_context (image);
    gtk_style_context_add_class (style, "dim-label");
    gtk_box_pack_start (GTK_BOX (box), image, TRUE, TRUE, 0);

    label = gtk_label_new(NULL);
    markup = g_markup_printf_escaped("<big>%s</big>", "No diary found, create one.");
    gtk_label_set_markup (GTK_LABEL (label), markup);
    gtk_box_pack_end (GTK_BOX (box), label, TRUE, TRUE, 0);

    gtk_widget_show_all (box);

    g_free (markup);

    return box;
}

static void
md_diary_list_init (MdDiaryList *list)
{
    MdDiaryListPrivate *priv;
    GtkWidget *placeholder;

    priv = md_diary_list_get_instance_private (list);
    placeholder = md_diary_list_create_placeholder ();

    gtk_widget_init_template (GTK_WIDGET (list));

    gtk_list_box_set_placeholder (priv->diaries_list, placeholder);
}

static void
md_diary_list_class_init (MdDiaryListClass *klass)
{
    GtkWidgetClass *widget_class;

    widget_class = GTK_WIDGET_CLASS (klass);
    gtk_widget_class_set_template_from_resource (widget_class,
                                                 "/com/jonathankang/MigraineDiary/md-diary-list.ui");
    gtk_widget_class_bind_template_child_private (widget_class, MdDiaryList, diaries_list);
}

GtkWidget *
md_diary_list_new ()
{
    return g_object_new (MD_TYPE_DIARY_LIST, NULL);
}
