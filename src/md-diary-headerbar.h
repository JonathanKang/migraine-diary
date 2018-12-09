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

#ifndef MD_HEADER_BAR_H_
#define MD_HEADER_BAR_H_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MD_TYPE_DIARY_HEADERBAR (md_diary_headerbar_get_type ())
G_DECLARE_FINAL_TYPE (MdDiaryHeaderbar, md_diary_headerbar, MD, DIARY_HEADERBAR, GtkHeaderBar)

GtkWidget *md_diary_headerbar_new (void);

G_END_DECLS

#endif /* MD_HEADER_BAR_H_ */
