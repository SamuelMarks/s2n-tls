#ifndef S2N_WIN_SHIM_H
#define S2N_WIN_SHIM_H

#ifdef WIN32

#include <CRTDEFS.H>

struct iovec {
    size_t iov_len;
    void *iov_base;
};

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif /* !MIN */

#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif /* !MAX */

/* <mmap-windows> */

#define PROT_READ     0x1
#define PROT_WRITE    0x2
/* This flag is only available in WinXP+ */
#ifdef FILE_MAP_EXECUTE
    #define PROT_EXEC     0x4
#else
    #define PROT_EXEC        0x0
    #define FILE_MAP_EXECUTE 0
#endif

#define MAP_SHARED    0x01
#define MAP_PRIVATE   0x02
#define MAP_ANONYMOUS 0x20
#define MAP_ANON      MAP_ANONYMOUS
#define MAP_FAILED    ((void *) -1)

#ifdef __USE_FILE_OFFSET64
    # define DWORD_HI(x) (x >> 32)
    # define DWORD_LO(x) ((x) & 0xffffffff)
#else
    # define DWORD_HI(x) (0)
    # define DWORD_LO(x) (x)
#endif

void *mmap(void *, size_t, int, int, int, off_t);
void munmap(void *, size_t);

/* </mmap-windows> */

#endif /* WIN32 */

#endif  /* !S2N_WIN_SHIM_H */
