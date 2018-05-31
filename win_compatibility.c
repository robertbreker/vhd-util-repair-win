/*
 * Copyright (c) 2016, Citrix Systems, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "win_compatibility.h"
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <uuid/uuid.h>
#include <assert.h>

ssize_t pread(int fd, void *buf, size_t count, off64_t offset) {
    lseek64(fd, offset, SEEK_SET);
    return read(fd, buf, count);
}

ssize_t pwrite(int fd, const void *buf, size_t count,
               off64_t offset) {
    lseek64(fd, offset, SEEK_SET);
    return write(fd, buf, count);
}

int posix_memalign(void **memptr, size_t alignment, size_t size){
   *memptr = malloc(size);
   return 0;
}

int fcntl(int fd, int cmd, ...){
   return 0;
}

int posix_fadvise(int fd, off_t offset, off_t len, int advice) {
    return 0;
}

int fsync(int fd) {
    return 0;
}

char *realpath(const char *path, char *resolved_path) {
    if(resolved_path!=NULL) {
        resolved_path = malloc(PATH_MAX);
    }
    strncpy(resolved_path, path, PATH_MAX);
    return resolved_path;
}

char *ctime_r(const time_t *timep, char *buf) {
    assert(0);
}

void syslog(int bla, const char *blub, ...){
    assert(0);
}

int uuid_is_null(const uuid_t uu) {
    return 0;
}
void uuid_generate(uuid_t out) {
    assert(0);
}
void uuid_copy(uuid_t dst, const uuid_t src){
    assert(0);
}
void uuid_clear(uuid_t uu) {
    assert(0);
}
void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset) {
    assert(0);
}
int munmap(void *addr, size_t length) {
    assert(0);
}
