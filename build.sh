set -eux

x86_64-w64-mingw32-gcc.exe *.c -I . -D O_LARGEFILE=0 -D F_SETFL=0 -D F_GETFL=0 -D O_DIRECT=O_RDWR -D POSIX_FADV_RANDOM=0 -D O_DSYNC -D MAP_SHARED -D MAP_FAILED -D PROT_READ -D MAP_ANONYMOUS -D unlikely -D bswap_32=__builtin_bswap32 -D bswap_64=__builtin_bswap64 -liconv -w -static -o vhd-util-repair.exe
