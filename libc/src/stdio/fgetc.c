/*
 * Copyright (c) 2015-2018, Davide Galassi. All rights reserved.
 *
 * This file is part of the BeeOS software.
 *
 * BeeOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with BeeOS; if not, see <http://www.gnu/licenses/>.
 */

#include "FILE.h"
#include <stdio.h>
#include <unistd.h>

int fgetc(FILE *stream)
{
    char character;
    ssize_t n;
    if ((n = read(stream->fd, &character, 1)) != 1)
    {
        if (n == 0)
            stream->flags |= FILE_FLAG_EOF;
        else
            stream->flags |= FILE_FLAG_ERROR;
        return EOF;
    }
    return (int)character;
}
