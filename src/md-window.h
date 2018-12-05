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

#ifndef MD_WINDOW_H_
#define MD_WINDOW_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MD_TYPE_WINDOW (md_window_get_type ())
G_DECLARE_FINAL_TYPE (MdWindow, md_window, MD, WINDOW, GtkApplicationWindow)

GtkWidget *md_window_new (GtkApplication *application);

G_END_DECLS

#endif /* MD_WINDOW_H_ */
