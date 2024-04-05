#ifndef BQ34ZGUARD_H
#define BQ34ZGUARD_H
#include <inttypes.h>
#include "Arduino.h"
#include "Wire.h"  // I2C library
#include <math.h>  
class bq34z100
{
private:
    uint32_t Read(int address, uint8_t length);

public:
    void begin();
    int writeConfig();//should only be done once
    bq34z100();
    uint8_t getSOC();//gets the current state of charge %
    int getTemp();//returns the temperature in C
    uint16_t getVoltage();//returns the battery voltage
    int getCapacity();//returns the current battery capacity
    int getCurrent();//returns the current flowing atm
    int getStatus();//returns the flags
    int getRemaining();
    int getFlags();

    uint16_t getVoltage2(); //returns the battery voltage
    uint8_t getMaxError();
    int getFlags2(();
    uint16_t getAverageTimeToEmty();
    uint16_t getAverageTimeToFull();
    int getPassedCharge();
    uint16_t getDoD0Time();
    uint16_t getavailableEnergy();
    uint16_t getAverragePower();
    uint16_t getSerialNumber();
    uint16_t getInternal_Temperature();
    uint16_t getCycleCount();
    uint16_t getStateOfHealth();
    int getChargeVoltage();
    int getChargeCurrent();
    int getPackConfiguration();
    int getDesingCapacity();
    int getDataFlashClass();
    int getDataFlashBlock();
    int getAuthenticate();
    int getAuthenticateCheckSum();
    int getBlockData();
    int getBlockDataCheckSum();
    int getBlockDataControl();
    int getGridNumber();
    int getLearnedStatus();
    int getDoD();
    int getQStart();
    int getTrueRC();
    int getTrueFCC();
    int getStateTime();
    int getQmaxPassedQ();
    uint16_t getDoD0();
    int getQmaxDoD0();
    int getQmaxTime();

    int readControl(uint8_t,uint8_t);
    int readInstantCurrent();
    bool readFlash(uint16_t , uint8_t );
    int enableIT();
    int enableCal();
    int exitCal();
    int enterCal();
    void reset();
    void checkSum(uint16_t , uint8_t);
    uint16_t CalibrateVoltageDivider(uint16_t);//used to calibrate the voltage divider
    void chgFlash(uint8_t, int);
    void chgFlashPair(uint8_t, int);
    void chg104Table(uint16_t Vdivider,float CCGain,float CCDelta);
    void chg48Table(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
    void chg49Table(uint16_t, uint16_t, uint16_t, uint16_t);
    void chg64Table(uint16_t, uint16_t, uint8_t, uint8_t);
    void chg83Table(uint16_t);
    void chg68Table(uint16_t);
    void chg80Table(uint16_t);
    void chg82Table(uint16_t, uint16_t);
    void writeTable(uint16_t , uint8_t );
    uint16_t readVDivider();//reads the currently set voltage divider
    uint32_t floatToXemics(float f);
    float XemicsTofloat(uint32_t inVal);
    int setup(uint8_t BatteryChemistry,uint8_t SeriesCells,uint16_t CellCapacity,uint16_t PackCurrentVoltage,uint16_t current);
    void chgFlashQuad(uint8_t index, uint32_t value);
    void CalibrateCurrentShunt(int16_t current);
    float readCurrentShunt();
};
#endif
