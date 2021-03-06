/*
    Copyright (C) 2016  Jeremy White <jwhite@codeweavers.com>
    All rights reserved.

    This file is part of x11spice

    x11spice is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    x11spice is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with x11spice.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GUI_H_
#define GUI_H_

#include <gtk/gtk.h>

struct session_struct;

/*----------------------------------------------------------------------------
**  Structure definitions
**--------------------------------------------------------------------------*/
typedef struct {
    GtkWidget *window;
    GtkWidget *button_box;
    GtkWidget *quit_button;
    GtkWidget *disconnect_button;
    GtkWidget *status_label;
    struct session_struct *session;
    int timeout_id;
} gui_t;

/*----------------------------------------------------------------------------
**  Prototypes
**--------------------------------------------------------------------------*/
int gui_create(gui_t *gui, struct session_struct *session, int argc, char *argv[]);
void gui_sigterm(void);
void gui_run(gui_t *gui);
void gui_destroy(gui_t *gui);

void gui_remote_connected(gui_t *gui, const char *details);
void gui_remote_disconnected(gui_t *gui);

void gui_report_error(gui_t *gui, const char *message);

#endif
