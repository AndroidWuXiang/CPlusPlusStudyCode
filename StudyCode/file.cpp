#include <stdlib.h>
#include <iostream>
#include "string.h"
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sstream>

#define MAXSIZE 1024*1024

int main() {
    printf("start\n");
    unsigned int start_time= time(NULL);
    // printf("start_time %d(s)\n",start_time);
    //获取文件属性
//     struct stat {
//     dev_t         st_dev;       //文件的设备编号
//     ino_t         st_ino;       //节点
//     mode_t        st_mode;      //文件的类型和存取的权限
//     nlink_t       st_nlink;     //连到该文件的硬连接数目，刚建立的文件值为1
//     uid_t         st_uid;       //用户ID
//     gid_t         st_gid;       //组ID
//     dev_t         st_rdev;      //(设备类型)若此文件为设备文件，则为其设备编号
//     off_t         st_size;      //文件字节数(文件大小)
//     unsigned long st_blksize;   //块大小(文件系统的I/O 缓冲区大小)
//     unsigned long st_blocks;    //块数
//     time_t        st_atime;     //最后一次访问时间
//     time_t        st_mtime;     //最后一次修改时间
//     time_t        st_ctime;     //最后一次改变时间(指属性)
// };
    struct stat fileInfo;
    stat("3.mkv", &fileInfo);
    printf("%f m\n", (fileInfo.st_size)/1024.0/1024);
    // FILE* fp1 = fopen("1.mkv", "rb");
    // FILE* fp2 = fopen("2.mkv", "wb");
    // if(fp1 == NULL || fp2 == NULL) {
    //     printf("文件操作失败！！！\n");
    //     return -1;
    // }

    // char* ch = (char*)malloc(sizeof(char)*MAXSIZE); 
    // memset(ch, 0, MAXSIZE);
    // while(feof(fp1) == 0) {
    //     int len = fread(ch, sizeof(char), MAXSIZE, fp1);
    //     fwrite(ch, sizeof(char), len, fp2);
    //     memset(ch, 0, MAXSIZE);
    // }

    // fclose(fp2);
    // fclose(fp1);
    // free(ch);
    // ch = nullptr;
	// unsigned int end_time=time(NULL);
	
	// printf("end_time %d(s)\n",end_time - start_time);
    return 0;
}