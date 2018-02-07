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


#ifndef BEEOS_SYS_H_
#define BEEOS_SYS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>


/**
 * Terminate the calling process "immeditely".
 *
 * @param status    Exit status for the parent process.
 *                  Will be collected via one the "waitpid" syscall.
 */
void sys_exit(int status);


/**
 * Create a child process.
 *
 * Creates a new process by duplicating the calling one.
 *
 * @return  On success, the pid of the child process is retuned in the
 *          parent and 0 is returned in the child.
 *          On failure, -errno is retuned in the parent.
 */
pid_t sys_fork(void);


/**
 * Read from a file descriptor.
 *
 * Attempts to read up to count bytes from file descriptor fd into the
 * buffer starting at buf.
 *
 * @param fd    File descriptor.
 * @param buf   Destination buffer.
 * @param count Number of bytes to read.
 * @return      On success, the number of bytes read (zero if EOF).
 *              On error -errno is returned.
 */
ssize_t sys_read(int fd, void *buf, size_t count);


/**
 * Write to a file descriptor.
 *
 * Writes up to count bytes from the buffer pointer buf to the file
 * referred to by the file descriptor fd.
 *
 * @param fd    File descriptor.
 * @param buf   Source buffer.
 * @param count Number of bytes to write.
 * @return      On success, the number of written bytes is returned.
 *              On error -errno is returned.
 */
ssize_t sys_write(int fd, const void *buf, size_t count);


/**
 * Create a special or ordinary file
 *
 * @param pathname  Path in the filesystem.
 * @param mode      Specifies both the file mode and the type to use.
 * @param dev       Major and minor numbers if is a character or block device.
 * @return          Return zero on success, or -errno if an error occurred.
 */
int sys_mknod(const char *pathname, mode_t mode, dev_t dev);


/**
 * Open and possibly create a file.
 *
 * @pathname    Path in the filesystem.
 * @flags       Open flags (see fcntl.h).
 * @mode        One of the following access modes: O_RDONLY, O_WRONLY
 *              or O_RDWR
 * @return      Return the new descriptor, or -errono if an error occurred.
 */
int sys_open(const char *pathname, int flags, mode_t mode);



int sys_close(int fd);



off_t sys_lseek(int fd, off_t offset, int whence);



int sys_dup(int oldfd);



int sys_dup2(int oldfd, int newfd);



pid_t sys_waitpid(pid_t pid, int *wstatus, int options);



pid_t sys_getpid(void);



pid_t sys_getppid(void);



char *sys_getcwd(char *buf, size_t size);


uid_t sys_getuid(void);


gid_t sys_getgid(void);


int sys_setuid(uid_t uid);


int sys_setgid(gid_t gid);


pid_t sys_getpgid(pid_t pid);


int sys_setpgid(pid_t pid, pid_t pgid);


pid_t sys_tcgetpgrp(int fd);


int sys_tcsetpgrp(int fd, pid_t pgrp);


int sys_execve(const char *path, const char *argv[], const char *envp[]);


void *sys_sbrk(intptr_t incr);


int sys_nanosleep(const struct timespec *req, struct timespec *rem);


int sys_fstat(int fd, struct stat *buf);


int sys_info(int type);


int sys_sigaction(int sig, const struct sigaction *act,
                  struct sigaction *oact);


int sys_sigreturn(void);


int sys_sigsuspend(const sigset_t *mask);


int sys_kill(pid_t pid, int sig);


int sys_sigprocmask(int how, const sigset_t *set, sigset_t *oldset);


int sys_pipe(int pipefd[2]);


int sys_chdir(const char *path);


unsigned int sys_alarm(unsigned int seconds);


void syscall_init(void);


#endif /* BEEOS_SYS_H_ */

