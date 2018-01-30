#include<cufs.h>

int main(){
	/*1设置superblock
	 *2设置datablock bitmap
	 *3设置inode bitmap
	 *4设置inode table
	 *5设置根目录的目录文件
	 */
	int res,cnt;
	File *fp = fopen("diskimg","r");						//待会用这个指针写入文件
	if (*fp == NULL){
		log_msg("open diskimg failed!");
		printf("open diskimg failed, cufs init failed.\n");
		res = -1;
		goto end;
	}
		
/*11111111111111111111111111111111111111111111111111111*/	//设置superblock
	struct superblock *sp=malloc(sizeof(superblock));	
	if (*sp == NULL){
		log_msg("malloc for superblock failed!");
		printf("superblock init failed, cufs init failed.\n");
		res = -1;
		goto end;
	}
	sp->ROOTDIR = 0;
	sp->DATABLK_BITMAP_START = sp->ROOTDIR +SUPER_BLK_SIZE;
	sp->INODE_BITMAP_START = sp->DATABLK_BITMAP_START+DATABLK_BITMAP_SIZE;
	sp->INODE_TABLE_START = sp->INODE_BITMAP_START+INODE_BITMAP_SIZE
	sp->DATABLK_START = sp->INODE_TABLE_START+INODE_TABLE_SIZE
	

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