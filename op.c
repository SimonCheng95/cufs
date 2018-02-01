#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>

#include "op.h"
#include "cufs.h"

int op_readblock(int blockno, unsigned char buffer[BLOCK_BYTES]);	//读blockno的块，读入buffer
int op_writeblock(int blockno, unsigned char buffer[BLOCK_BYTES]);	//将buffer写入blockno的block
int op_readinode(int ino, struct inode *tmp);						//读编号ino的索引，写入tmp
int op_writeinode(int ino, struct inode *tmp);						//将tmp写入编号ino的索引
int op_path_open(const char *path, struct inode *inode);				//打开路径，修改inode并返回

int op_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi);
int op_mkdir(const char *path, mode_t flag);
int op_create(const char *path, mode_t flag, struct fuse_file_info *fi);
int op_mknod(const char *path, mode_t mode, dev_t rdev);
int op_unlink(const char *path);
int op_rmdir(const char *path)
int op_write(const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info *fi);
int op_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi);


int is_empty(const char *path);
int op_search_freeblk(int n, int *blk_no);
int op_set_blkstat(int blk_no, int stat);
int op_search_freeinode(int n, int *ino_no);
int op_set_inodestat(int ino_no, int stat);
int op_create(const char *path, mode_t flag);
int is_exist(const char *path, const char *name);
int op_rm(const char *path, int flag);








