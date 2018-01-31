#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cufs.h"

int main(){
	/*1设置superblock
	 *2设置datablock bitmap
	 *3设置inode bitmap
	 *4设置inode table
	 *5设置根目录的目录文件
	 */
	int res,cnt;
	File *fp = fopen("DISK","r+");						//待会用这个指针写入文件
	bu	Buffer[BLK_SIZE]
	if (*fp == NULL){
		log_msg("open diskimg failed!");
		printf("open diskimg failed, cufs init failed.\n");
		res = -1;
		goto end;
	}
		
/*11111111111111111111111111111111111111111111111111111*/	//设置superblock
	struct superblock *sp=malloc(sizeof(superblock));	
	if (*sp == NULL){
		log_msg("superblock malloc failed!");
		printf("superblock init failed, cufs init failed.\n");
		res = -1;
		goto end;
	}
	sp->ROOTDIR = 0;
	printf("ROOTDIR = %d\n",&sp->ROOTDIR);
	sp->DATABLK_BITMAP_START = sp->ROOTDIR +SUPER_BLK_SIZE;
	printf("DATABLK_BITMAP_START = %d\n",&sp->DATABLK_BITMAP_START);
	sp->INODE_BITMAP_START = sp->DATABLK_BITMAP_START+DATABLK_BITMAP_SIZE;
	pritf("INODE_BITMAP_START=%d\n",&sp->INODE_BITMAP_START);
	sp->INODE_TABLE_START = sp->INODE_BITMAP_START+INODE_BITMAP_SIZE;
	printf("INODE_TABLE_START = %d\n",&sp->INODE_TABLE_START);
	sp->DATABLK_START = sp->INODE_TABLE_START+INODE_TABLE_SIZE;
	printf("DATABLK_START = %d\n",&sp->DATABLK_START);
	sp->INODE_REMAIN = BLK_MAX_NUMBER - sp->DATABLK_START - 1 - 1;
	printf("INODE_REMAIN = %d\n",&sp->INODE_REMAIN);
	sp->DATABLK_REMAIN = sp->INODE_REMAIN;
	printf("DATABLK_REMAIN = %d\n",&sp->DATABLK_REMAIN);
	fwrite(sp,sizeof(superblock),1,fp)
/***********************test****************************/
	struct superblock *spt=malloc(sizeof(superblock));
	fread(spt,sizeof(superblock),1,fp);
	printf("test\nROOTDIR is %d\nDATABLK_BITMAP_START is %d\n",&spt->ROOTDIR,&spt-DATABLK_BITMAP_START);
	printf("INODE_TABLE_START is %d\nDATABLK_START is %d\n",&spt->INODE_TABLE_START,&spt->DATABLK_START);
	printf("INODE_REMAIN is %d\nDATABLK_REMAIN is %d\n",&spt->INODE_REMAIN,&spt->DATABLK_REMAIN);

/*22222222222222222222222222222222222222222222222222222*/	//设置datablock bitmap
															//会用到的地址fp+SUPER_BLK_SIZE*BLK_SIZE
/*33333333333333333333333333333333333333333333333333333*/	//设置datablock bitmap
															//会用到的地址fp+(SUPER_BLK_SIZE+DATABLK_BITMAP_SIZE)*BLK_SIZE
/*44444444444444444444444444444444444444444444444444444*/	//设置inode table 
															//会用到的地址fp+(SUPER_BLK_SIZE+DATABLK_BITMAP_SIZE+INODE_BITMAP_SIZE)*BLK_SIZE
/*55555555555555555555555555555555555555555555555555555*/	//设置datablock起始位置
															//会用到的地址fp+sp->DATABLK_START*BLK_SIZE
	end:
		free(*sp);
		return res
}