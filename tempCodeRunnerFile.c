#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_types.h"

extern void  Screeninit(void);
extern int   SelectMode(void);

int main(void)
{

    Screeninit();
    while(SelectMode());
    while(1);

    return 0;
}
