/* Imagine an AC system that is controlled using an 8-bit number:
 * The lowest two bits of the number show the fan setting: 00 is for off, 01 is for low, 10 is for medium and 11 is for high.
 * The second two bits of the number show the humidity setting: 00 is for low, 01 is for medium, and 10 is for high. 11 is not an option.
 * The upper 4 bits show the temperature setting. 60 degrees is represented as 0000, 61 as 0001 and so on. The highest temperature setting is 75 as 1111.
 * The following functions are written to set, update or print this AC's settings
*/

// We use enum and define so that all the setting values are in one place at the beginning of the program
// We try to avoid hard-coding actual numbers inside the code as much as possible

// For each of the below masks, all the bits are 0 except for the specific bit mentioned
// Each of BIT0_MASK, .... BIT7_MASK are called macros in C.
#define BIT0_MASK 1
#define BIT1_MASK (1<<1)
#define BIT2_MASK (1<<2)
#define BIT3_MASK (1<<3)
#define BIT4_MASK (1<<4)
#define BIT5_MASK (1<<5)
#define BIT6_MASK (1<<6)
#define BIT7_MASK (1<<7)

// fan_setting_type is a name we give to the enum that holds fan setting macros
typedef enum {FAN_OFF, FAN_LOW, FAN_MED, FAN_HIGH} fan_setting_type;

// humidity_setting_type is a name we give to the enum that holds humidity setting macros
typedef enum {HUMIDITY_LOW, HUMIDITY_MED, HUMIDITY_HIGH} humidity_setting_type;

// We can create more interesting masks using single bit masks
// The mask for the fan has 1 for the lowest two bits and 0 for the rest
#define FAN_MASK (BIT0_MASK | BIT1_MASK)
#define FAN_BIT_POS 0

// The mask for humidity
#define HUMIDITY_MASK (BIT2_MASK | BIT3_MASK)
#define HUMIDITY_BIT_POS 2

// The mask for temperature
#define TEMPERATURE_MASK (BIT4_MASK | BIT5_MASK | BIT6_MASK | BIT7_MASK)
#define TEMPERATURE_BIT_POS  4

#define MIN_TEMP 60
#define MAX_TEMP 75



// This function isolates fanSetting and returns it as an integer
fan_setting_type getFanSetting(int ACSetting)
{
    fan_setting_type fanSetting = (fan_setting_type) ((ACSetting & FAN_MASK) >> FAN_BIT_POS);
    return fanSetting;
}

// This function isolates humiditySetting and returns it as an integer
humidity_setting_type getHumiditySetting(int ACSetting)
{
    humidity_setting_type humiditySetting = (humidity_setting_type) ((ACSetting & HUMIDITY_MASK) >> HUMIDITY_BIT_POS);
    return humiditySetting;
}

// This function isolates temperatureSetting and returns it as an integer
// TODO: Write this function
int getTemperatureSetting(int ACSetting)
{
    int temperatureSetting;

    return temperatureSetting;
}


// fanSetting is a number between 0 and 3
// This functions returns the new ACSetting where all is the same except for the new fanSetting
int updateFanSetting(int ACSetting, fan_setting_type fanSetting)
{

    // FAN_MASK in binary is 11. This means it has a 1 exactly where fan setting bits are
    // inverted mask will have 1 in all bits except for fan setting bits.
    // Note that ! operation is logical operation and is not bitwise, so it cannot be used here.
    // Instead, we use ~ which does bit-wise inversion
    int invertedFAN_MASK = ~FAN_MASK;

    //This clears the old fan setting bits
    int updatedACSetting = ACSetting & invertedFAN_MASK;

    //This puts fanSetting and the rest of AC setting together
    updatedACSetting = updatedACSetting | (fanSetting << FAN_BIT_POS);

    return (updatedACSetting);

    // We wrote the above code for maximum readability. Here is the short version of the same code
    // return( ((ACSetting & ~FAN_MASK) | fanSetting);

}


// humiditySetting is a number between 0 and 2
// This functions returns the new ACSetting where all is the same except for the new hunmiditySetting
// TODO: Write this function
int updateHumiditySetting(int ACSetting, humidity_setting_type humiditySetting)
{

}

// tempSetting is a number between 60 and 75
// This functions returns the new ACSetting where all is the same except for the new tempSetting
int updateTemperatureSetting(int ACSetting, int temperatureSetting)
{
    return(((ACSetting & ~TEMPERATURE_MASK) | (temperatureSetting << TEMPERATURE_BIT_POS)));
}



int main(void)
{
 //   initialize();
    int ACSetting = 0x0;

    fan_setting_type fanSetting = FAN_HIGH;
    ACSetting  = updateFanSetting(ACSetting, fanSetting);

    humidity_setting_type humiditySetting = HUMIDITY_LOW;
    ACSetting  = updateHumiditySetting(ACSetting, humiditySetting);

    // temperture should be 60-75
    int temperatureSetting = 72;
    ACSetting  = updateTemperatureSetting(ACSetting, temperatureSetting);

    while (1);

}
