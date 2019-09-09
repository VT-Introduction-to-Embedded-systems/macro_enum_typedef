// STOP, CAUTION, and Go are called Macros.
// Usually we use all caps for macros, but it is not needed.
// Any time we use STOP in the code, the compiler replaced it with 0. It has no other effect.

#define STOP 0
#define CAUTION 1
#define GO 2



// The below 5 lines mean exactly what the above commented out 3 lines say
// In other words, STOP is 0, CAUTION is 1, and GO is 2
/*
enum traffic_light_states {
  STOP,
  CAUTION,
  GO
};
*/


 // It is possible to have multiple names for the same integers in the same program
#define OFF 0
#define ON 1



void main()
{
    int light = CAUTION;

    while (1)
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
    }
}

