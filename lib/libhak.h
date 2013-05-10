/*  libhak.h - Main libhak header.
    
    Copyright 2013  Francisco Jose Monaco   <monaco.fj@gmail.com>

    This file is part of Libhack. 

    Libhack is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Libhack is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with .  If not, see <http://www.gnu.org/licenses/>. 

*/

#ifndef _LIBHAK_H
#define _LIBHAK_H

/* libhak.h is just a convenience header used to actually include the core
   headers corresponding to the core facilities of libhak. */

#include <config.h>		/* Autoconf's config.h */
#include <libhak/core.h>	/* libhak's core engine. */
#include <libhak/messages.h>	/* Fault report and logging messagens. */
#include <libhak/sysfun.h>	/* Convenience wrapping system functions. */

#endif	/* _LIBHAK_H */
