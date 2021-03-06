/* vifm
 * Copyright (C) 2011 xaizek.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef VIFM__OPT_HANDLERS_H__
#define VIFM__OPT_HANDLERS_H__

#include "ui/ui.h"

enum
{
	VIFMINFO_OPTIONS   = 1 << 0,
	VIFMINFO_FILETYPES = 1 << 1,
	VIFMINFO_COMMANDS  = 1 << 2,
	VIFMINFO_MARKS     = 1 << 3,
	VIFMINFO_BOOKMARKS = 1 << 4,
	VIFMINFO_TUI       = 1 << 5,
	VIFMINFO_DHISTORY  = 1 << 6,
	VIFMINFO_STATE     = 1 << 7,
	VIFMINFO_CS        = 1 << 8,
	VIFMINFO_SAVEDIRS  = 1 << 9,
	VIFMINFO_CHISTORY  = 1 << 10,
	VIFMINFO_SHISTORY  = 1 << 11,
	VIFMINFO_DIRSTACK  = 1 << 12,
	VIFMINFO_REGISTERS = 1 << 13,
	VIFMINFO_PHISTORY  = 1 << 14,
	VIFMINFO_FHISTORY  = 1 << 15,
};

const char * cursorline_enum[3];

void init_option_handlers(void);

/* Resets local options so that they use values of global options. */
void reset_local_options(FileView *view);

/* Loads view-specific settings into corresponding options. */
void load_view_options(FileView *view);

/* Clones all local options of *from into *to.  The defer_slow flag might be
 * used to postpone updates related to options, which will either be applied
 * from the outside or should be skipped. */
void clone_local_options(const FileView *from, FileView *to, int defer_slow);

/* Handles various kinds of :set command displaying output/errors.  At least one
 * of global and local must be set on call.  Returns negative number on error,
 * zero on success without message and positive number on success with a
 * message. */
int process_set_args(const char args[], int global, int local);

void load_sort_option(FileView *view);

/* Updates view columns value as if 'viewcolumns' option has been changed.
 * Doesn't change actual value of the option, which is important for setting
 * sorting order via sort dialog. */
void load_view_columns_option(FileView *view, const char value[]);

/* Updates geometry related options. */
void load_geometry(void);

/* Formats string with representation of the 'classify' option value.  Returns
 * NULL on error or pointer, which is valid until the next invocation. */
const char * classify_to_str(void);

#endif /* VIFM__OPT_HANDLERS_H__ */

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 filetype=c : */
