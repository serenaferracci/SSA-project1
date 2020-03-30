/*@-skipposixheaders@*/
#include <stdlib.h>
/*@-skipposixheaders@*/
#include <unistd.h>


void func(int fd)
{
    int i = 0;
    char *buf;
    ssize_t ret;
    size_t len;
    ret = read(fd, &len, sizeof(len));
    if(ret == -1) return;
    if(len > 1024)
        return;
    buf = malloc(len+1);
    if(buf == NULL) return;
    do{
        char c;
        ret = read(fd, &c, 1);
        if(ret == -1){
            free(buf);
            return;
        }
        buf[i++] = c;
    } while(ret != 0 && i < (int)len);
    buf[len] = '\0';
    free(buf);
}


