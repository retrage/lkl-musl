/* copied from kernel definition (arch/lkl/include/uapi/asm-generic/stat.h),
 * but with struct timespec replaced by the corresponding correctly-sized
 * userspace types. */

/* copied from arch/x86/include/uapi/asm/stat.h  */
/* XXX: how to handle other case ? */
struct stat {
	unsigned long	st_dev;
	unsigned long	st_ino;
	unsigned long	st_nlink;

	unsigned int		st_mode;
	unsigned int		st_uid;
	unsigned int		st_gid;
	unsigned int		__pad0;
	unsigned long	st_rdev;
	long		st_size;
	long		st_blksize;
	long		st_blocks;	/* Number 512-byte blocks allocated. */

	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	long		__unused[3];
};

/* copied from uapi/asm-generic/stat.h */
/* This matches struct stat64 in glibc2.1. Only used for 32 bit. */
#if __BITS_PER_LONG != 64 || defined(__ARCH_WANT_STAT64)
struct stat64 {
	unsigned long long st_dev;	/* Device.  */
	unsigned long long st_ino;	/* File serial number.  */
	unsigned int	st_mode;	/* File mode.  */
	unsigned int	st_nlink;	/* Link count.  */
	unsigned int	st_uid;		/* User ID of the file's owner.  */
	unsigned int	st_gid;		/* Group ID of the file's group. */
	unsigned long long st_rdev;	/* Device number, if device.  */
	unsigned long long __pad1;
	long long	st_size;	/* Size of file, in bytes.  */
	int		st_blksize;	/* Optimal block size for I/O.  */
	int		__pad2;
	long long	st_blocks;	/* Number 512-byte blocks allocated. */
	struct timespec st_atim;
	struct timespec st_mtim;
	struct timespec st_ctim;
	unsigned int	__unused4;
	unsigned int	__unused5;
};
#endif
