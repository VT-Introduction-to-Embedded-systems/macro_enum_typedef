
#include <stdio.h>

// typedef is used to give one type another name you like
typedef char my_byte_t;


typedef enum {
    STOP,
    CAUTION,
    GO
}   lights_t;

lights_t nextLight(lights_t light)
{
    switch (light)
    {
    case STOP:
        light = GO;
        break;
    case CAUTION:
        light = STOP;
        break;
    case GO:
        light = CAUTION;
        break;
    }

    return(light);
}



void main() {
    lights_t myLight = CAUTION; // It writes 2 to myLight

    while (1)
        myLight = nextLight(myLight);
}
