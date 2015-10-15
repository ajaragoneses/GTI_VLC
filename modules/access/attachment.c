/*****************************************************************************
 * attachment.c: Input reading an attachment.
 *****************************************************************************
 * Copyright (C) 2009 Laurent Aimar
 * $Id: 1fda56bee79131822d8046548e59ca630d98d12a $
 *
 * Authors: Laurent Aimar <fenrir _AT_ videolan _DOT_ org>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

/*****************************************************************************
 * Preamble
 *****************************************************************************/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <vlc_common.h>
#include <vlc_plugin.h>
#include <vlc_access.h>
#include <vlc_input.h>

/*****************************************************************************
 * Module descriptor
 *****************************************************************************/
static int  Open (vlc_object_t *);
static void Close(vlc_object_t *);

vlc_module_begin()
    set_shortname(N_("Attachment"))
    set_description(N_("Attachment input"))
    set_category(CAT_INPUT)
    set_subcategory(SUBCAT_INPUT_ACCESS)

    set_capability("access", 0)
    add_shortcut("attachment")
    set_callbacks(Open, Close)
vlc_module_end()

/*****************************************************************************
 * Local prototypes
 *****************************************************************************/
static ssize_t Read(access_t *, uint8_t *, size_t);
static int     Seek(access_t *, uint64_t);
static int     Control(access_t *, int, va_list);

/* */
static int Open(vlc_object_t *object)
{
    access_t     *access = (access_t *)object;

    input_thread_t *input = access->p_input;
    if (!input)
        return VLC_EGENERIC;

    input_attachment_t *a;
    if (input_Control(input, INPUT_GET_ATTACHMENT, &a, access->psz_location))
        a = NULL;

    if (!a) {
        msg_Err(access, "Failed to find the attachment '%s'",
                access->psz_location);
        return VLC_EGENERIC;
    }

    /* */
    access_InitFields(access);
    access->pf_read    = Read;
    access->pf_block   = NULL;
    access->pf_control = Control;
    access->pf_seek    = Seek;
    access->p_sys      = (void *)a;
    return VLC_SUCCESS;
}

/* */
static void Close(vlc_object_t *object)
{
    access_t     *access = (access_t *)object;
    input_attachment_t *a = (void *)access->p_sys;

    vlc_input_attachment_Delete(a);
}

/* */
static ssize_t Read(access_t *access, uint8_t *buffer, size_t size)
{
    input_attachment_t *a = (void *)access->p_sys;

    access->info.b_eof = access->info.i_pos >= (uint64_t)a->i_data;
    if (access->info.b_eof)
        return 0;

    const size_t copy = __MIN(size, a->i_data - access->info.i_pos);
    memcpy(buffer, (uint8_t *)a->p_data + access->info.i_pos, copy);
    access->info.i_pos += copy;
    return copy;
}

/* */
static int Seek(access_t *access, uint64_t position)
{
    access->info.i_pos = position;
    access->info.b_eof = false;
    return VLC_SUCCESS;
}

/* */
static int Control(access_t *access, int query, va_list args)
{
    input_attachment_t *a = (void *)access->p_sys;

    switch (query)
    {
    case ACCESS_CAN_SEEK:
    case ACCESS_CAN_FASTSEEK:
    case ACCESS_CAN_PAUSE:
    case ACCESS_CAN_CONTROL_PACE:
        *va_arg(args, bool *) = true;
        break;
    case ACCESS_GET_SIZE:
        *va_arg(args, uint64_t *) = a->i_data;
        break;
    case ACCESS_GET_PTS_DELAY:
        *va_arg(args, int64_t *) = DEFAULT_PTS_DELAY;
        break;
    case ACCESS_SET_PAUSE_STATE:
        return VLC_SUCCESS;

    default:
        return VLC_EGENERIC;
    }
    return VLC_SUCCESS;
}

