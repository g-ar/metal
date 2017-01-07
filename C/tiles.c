#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define width 1920
#define height 1080

char pic[height][width][3];

int main()
{
    unsigned int i, j;
    int fd;
    char buffer[100];

    for (i = 0; i < height; i++)
	for (j = 0; j < width; j++) {
	    pic[i][j][0] = 0;
	    pic[i][j][1] = 0;
	    pic[i][j][2] = (((i ^ (~j)) & ((~i - 350) >> 3))) & 255;
	}

    if ((fd = open("image.tga", O_RDWR + O_CREAT, S_IRUSR | S_IWUSR)) == -1) {
	printf("error opening file\n");
	exit(1);
    }
    buffer[0]  = 0;
    buffer[1]  = 0;
    buffer[2]  = 2;
    buffer[8]  = 0;
    buffer[9]  = 0;
    buffer[10] = 0;
    buffer[11] = 0;
    buffer[12] = (width & 0x00FF);
    buffer[13] = (width & 0xFF00) >> 8;
    buffer[14] = (height & 0x00FF);
    buffer[15] = (height & 0xFF00) >> 8;
    buffer[16] = 24;
    buffer[17] = 0;
    write(fd, buffer, 18);
    write(fd, pic, width * height * 3);
    close(fd);
    return 0;
}
