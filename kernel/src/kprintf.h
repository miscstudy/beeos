/*
 * Copyright (c) 2015-2017, Davide Galassi. All rights reserved.
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

#ifndef BEEOS_KPRINTF_H_
#define BEEOS_KPRINTF_H_

#include <stdarg.h>

/**
 * Prints a format string to the kernel stardard output.
 * Version with variable arguments list.
 *
 * @param fmt   Format string pointer.
 * @return      Number of bytes written.
 */
int kprintf(const char *fmt, ...);

/**
 * Prints a format string to the kernel standard output.
 * Version with va_list argument.
 *
 * @param fmt   Format string pointer.
 * @param arg   Arguments list.
 * @return      Number of bytes written.
 */
int kvprintf(const char *fmt, va_list arg);

#endif /* BEEOS_KPRINTF_H_ */

