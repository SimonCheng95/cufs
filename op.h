#ifndef OP_H
#define OP_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "ufs.h"

extern int op_readblock(int blockno, unsigned char buffer[BLOCK_BYTES]);	//读blockno的块，读入buffer
extern int op_writeblock(int blockno, unsigned char buffer[BLOCK_BYTES]);	//将buffer写入blockno的block
extern int op_readinode(int ino, struct inode *tmp);						//读编号ino的索引，写入tmp
extern int op_writeinode(int ino, struct inode *tmp);						//将tmp写入编号ino的索引
extern int op_path_open(const char *path, struct inode *inode);				//打开路径，修改inode并返回

extern int op_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi);
extern int op_mkdir(const char *path, mode_t flag);
extern int op_create(const char *path, mode_t flag, struct fuse_file_info *fi);
extern int op_mknod(const char *path, mode_t mode, dev_t rdev);
extern int op_unlink(const char *path);
extern int op_rmdir(const char *path)
extern int op_write(const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info *fi);
extern int op_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi);


extern int is_empty(const char *path);
extern int op_search_freeblk(int n, int *blk_no);
extern int op_set_blkstat(int blk_no, int stat);
extern int op_search_freeinode(int n, int *ino_no);
extern int op_set_inodestat(int ino_no, int stat);
extern int op_create(const char *path, mode_t flag);
extern int is_exist(const char *path, const char *name);
extern int op_rm(const char *path, int flag);
#endif

