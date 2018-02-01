#define FUSE_USE_VERSION 26
#include <string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fuse.h>
#include<fcntl.h>

#include"cufs.h"
#include"op.h"

int log_to_stderr;

static int cufs_getattr(const char *path, struct stat *stbuf){

}

static int cufs_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi){
	int res;
	res = op_readdir(path, buf, filler, offset, fi);
	return res;
}
static int cufs_mkdir(const char *path, mode_t flag){
	int res;
	res = op_mkdir(path, flag);
	return res;
}

static int cufs_create(const char *path, mode_t flag, struct fuse_file_info *fi){
	int res;
	res = op_create(path, flag, fi);
	return res;
}

static int cufs_mknod(const char *path, mode_t mode, dev_t rdev){
	int res;
	res = op_mknod(path, mode, rdev);
	return res;
}

static int cufs_unlink(const char *path){
	int res;
	res = op_unlink(path);
	return res;
}

static int cufs_rmdir(const char *path){
	int res;
	res = op_rmdir(path);
	return res;
}

static int cufs_write(const char *path, const char *buffer, size_t size, off_t offset, struct fuse_file_info *fi){
	int res;
	res = op_write(path, buffer, size, offset, fi)
	return res;
}


static int cufs_read(const char *path, char *buffer, size_t size, off_t offset, struct fuse_file_info *fi){
	int res;
	res = op_read(path, buffer, size, offset, fi);
	return res;
}
/*
 * static int ufs_truncate(const char *path, off_t length){
 *
 *	log_msg("ufs_truncate called");
 *		log_msg("ufs_truncate returned");
 *			return 0;
 *			}
 *
 *			static int ufs_ftruncate(const char *path, off_t length,
 *								struct fuse_file_info *fi){
 *
 *
 *									log_msg("ufs_ftruncate called");
 *										log_msg("ufs_ftruncate returned");
 *											return 0;
 *											}
 *											*/

static struct fuse_operations cufs_oper = {
		.getattr = cufs_getattr,
		.readdir = cufs_readdir,
		.mkdir = cufs_mkdir,
		.create = cufs_create,
		.mknod = cufs_mknod,
		.unlink = cufs_unlink,
		.rmdir = cufs_rmdir,
		.write = cufs_write,
		.read = cufs_read,
											//.truncate = ufs_truncate,
											//	//.ftruncate = ufs_ftruncate,
											//	};
											//
											//	int main(int argc, char *argv[]){
											//
											//		log_msg("start ufs filesystem");
											//			return fuse_main(argc, argv, &ufs_oper, NULL);
											//			}
}

int main(int argc, char *argv[]){

		log_msg("start ufs filesystem");
			return fuse_main(argc, argv, &ufs_oper, NULL);
}
