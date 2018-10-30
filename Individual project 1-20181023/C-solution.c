/*@-skipposixheaders@*/
#include <stdlib.h>

void func(int fd)
{
    char* buf;
    size_t len;
    ssize_t ret;
    ret = read(fd, &len, sizeof(len));
    if(ret == -1) return;
    buf = malloc(len+1);
    if(buf == NULL) return;
    ret = read(fd, buf, len);
    if(ret == -1){
        free(buf);
        return;
    }
    buf[len] = '\0';
    free(buf);
}
