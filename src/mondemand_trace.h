/*======================================================================*
 * Copyright (C) 2010 Mondemand                                         *
 * All rights reserved.                                                 *
 *                                                                      *
 * This program is free software; you can redistribute it and/or modify *
 * it under the terms of the GNU General Public License as published by *
 * the Free Software Foundation; either version 2 of the License, or    *
 * (at your option) any later version.                                  *
 *                                                                      *
 * This program is distributed in the hope that it will be useful,      *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 * GNU General Public License for more details.                         *
 *                                                                      *
 * You should have received a copy of the GNU General Public License    *
 * along with this program; if not, write to the Free Software          *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,                   *
 * Boston, MA 02110-1301 USA.                                           *
 *======================================================================*/
#ifndef __M_TRACE__
#define __M_TRACE__

/* defines a trace_id structure. should not be accessed directly in case
 * the type changes. */
struct mondemand_trace_id
{
  unsigned long _id;
};
extern const struct mondemand_trace_id MONDEMAND_NULL_TRACE_ID;


/*!\fn mondemand_trace_id
 * \brief creates a trace ID from an unsigned long.
 */
struct mondemand_trace_id mondemand_trace_id(unsigned long id);

/*!\fn mondemand_trace_id_compare
 * \brief compares one trace_id to another.
 */
int mondemand_trace_id_compare(const struct mondemand_trace_id *a,
                               const struct mondemand_trace_id *b);


#endif

