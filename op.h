fndef OP_H
#define OP_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "ufs.h"

extern int op_readblock(int blockno, unsigned char buffer[BLOCK_BYTES]);
extern int op_writeblock(int blockno, unsigned char buffer[BLOCK_BYTES]);
extern int op_readinode(int ino, struct inode *tmp);
extern int op_writeinode(int ino, struct inode *tmp);
extern int op_path_open(const char *path, struct inode *inode);

extern int is_empty(const char *path);
extern int op_search_freeblk(int n, int *blk_no);
extern int op_set_blkstat(int blk_no, int stat);
extern int op_search_freeinode(int n, int *ino_no);
extern int op_set_inodestat(int ino_no, int stat);
extern int op_create(const char *path, mode_t flag);
extern int is_exist(const char *path, const char *name);
extern int op_rm(const char *path, int flag);
#endif

