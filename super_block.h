#ifndef SUPER_BLOCK_H
#define SUPER_BLOCK_H

#include "fs.h"
#include <stdint.h>
//超级块头文件 超级块一般放在第二扇区
typedef struct super_block
{
    uint32_t magic;                 // 用来标识该文件系统
    uint32_t sector_count;          // 该超级块所在文件系统的扇区数
    uint32_t inode_count;           // 该超级块所在文件系统的 inode 数
    uint32_t start_sector_lba;      // 该分区的起始 lba

    uint32_t block_bitmap_lba;	    // 块位图本身起始 lba
    uint32_t block_bitmap_sectors;  // 扇区位图本身占用的扇区数量

    uint32_t inode_bitmap_lba;	    // i结点位图起始 lba
    uint32_t inode_bitmap_sectors;	// i结点位图占用的扇区数量

    uint32_t inode_table_lba;	    // i结点表起始扇区lba
    uint32_t inode_table_sects;	    // i结点表占用的扇区数量

    uint32_t data_start_lba;	    // 数据区开始的第一个 lba
    uint32_t root_inode_no;	        // 根目录所在的I结点号
    uint32_t dir_entry_size;	    // 目录项大小

    // 13*32/8 加上460字节,凑够512字节
    uint8_t  pad[BLOCK_SIZE - 13 * 32 / 8];
}superblock __attribute__ ((packed));

#endif