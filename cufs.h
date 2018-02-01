#ifndef CUFS_H
#define CUFS_H

#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISK "./diskimg"



#define BLK_SIZE 1024			//一个block的大小
#define BLK_MAX_NUMBER 102400	//block的数量
#define SUPER_BLK_SIZE 1		//超级块的大小
#define DATABLK_BITMAP_SIZE 13	//datablock bitmap的所占的block的个数
#define INODE_BITMAP_SIZE 7		//inode bitmap所占的block的个数
#define INODE_TABLE_SIZE 3200	//inode table 所占块数
#define INODE_SIZE 512			//一个INODE的大小
#define FILE_MAX_BLKS 119		//单个文件最大大小，119个块，482KB（为凑inode一个占512B）
#define DIR_SUB_MAX	20			//一个目录最多有的子项的个数
#define FILE_MAX_NAME 30

struct superblock{
		int ROOTDIR;		//下面这些……都是
		int DATABLK_BITMAP_START;
		int INODE_BITMAP_START;
		int INODE_TABLE_START;
		int DATABLK_START;
		int INODE_REMAIN;
		int DATABLK_REMAIN;
		int ROOTDIR_INODE;
}

struct inode{
	char i_FILENAME[FILE_MAX_NAME]; //占30B的名称
	int flag;						//标志位，0为目录，1为文件
	int i_DATABLK[FILE_MAX_BLKS];	//占476B
}
struct in_bit_map{     			//目录文件内的内容，标识目录内文件和目录的使用情况的
	char SUB_USAGE[DIR_SUB_MAX/2];	//使用半个Int表示一个目录项有没有被占用。
}
struct initem	{				//目录文件内容，标识目录里的文件，以及他们的inode号
	char SUB_NAME[FILE_MAX_NAME];	//存储子项的名字，30B	
	int SUB_INO_NO;					//子项的inode号，4B
	int trick[4];					//用这个int占地址，先凑50B一个目录项
}

#endif