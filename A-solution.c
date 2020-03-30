/*@-skipposixheaders@*/
#include <stdio.h>
/*@-skipposixheaders@*/
#include <stdlib.h>

static char* stringcopy(/*@out@*/ char *str1, /*@returned@*/ char *str2)
/*@requires maxRead(str2) >= 0 /\ maxSet(str1) >= 0@*/;

int main(int argc, char **argv)
/*@requires maxRead(argv) >= 1 /\ maxRead(argv[1]) >= 0 @*/;

static char* stringcopy(char *str1, char *str2)
{
    int i = 0;
    while(*str2 != '\0' && i < 15){
        *str1++ = *str2++;
        i++;
    }
    *str1 = '\0';
    return str2;
}

int main(int argc, char **argv)
{
    if(argc > 1 && sizeof(argv) >= 1){
        char* ret;
        char *buffer = (char *)malloc(16 * sizeof(char));
        if(buffer == NULL) return 0;

        ret = stringcopy(buffer, argv[1]);
        printf("%s\n", buffer);

        free(buffer);
        free(ret); //forse non è da mettere
    }
    return 0;
}
