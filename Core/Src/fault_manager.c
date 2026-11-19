
/*
====================================================
 PROJECT : AECU V2.0
 MODULE  : Fault Management System
 FILE    : fault_manager.c
 LANGUAGE: Embedded C

 FEATURES:
 - Sensor fault detection
 - Over-temperature detection
 - Voltage monitoring
 - Fault state management
 - Safety state activation
====================================================
*/

#include <stdint.h>
#include <stdbool.h>

/* SYSTEM CONFIGURATION */

#define MAX_TEMPERATURE 85.0f
#define MIN_TEMPERATURE -10.0f

#define MAX_VOLTAGE 15.0f
#define MIN_VOLTAGE 9.0f

/* FAULT DEFINITIONS */

typedef enum
{
    FAULT_NONE = 0,
    FAULT_SENSOR,
    FAULT_OVERTEMPERATURE,
    FAULT_OVERVOLTAGE,
    FAULT_UNDERVOLTAGE
} FaultCode;

/* SYSTEM STATE */

typedef enum
{
    STATE_INIT = 0,
    STATE_RUNNING,
    STATE_WARNING,
    STATE_SAFE_MODE
} SystemState;

/* SENSOR DATA */

typedef struct
{
    float temperature;
    float voltage;
    bool sensorValid;
} SensorData;

/* FAULT MANAGER */

static FaultCode activeFault = FAULT_NONE;

static SystemState currentState = STATE_INIT;

/* SENSOR VALIDATION */

static bool Sensor_Validate(SensorData data)
{
    if (!data.sensorValid)
        return false;

    if (data.temperature != data.temperature)
        return false;

    if (data.voltage != data.voltage)
        return false;

    if (data.temperature < -100.0f ||
        data.temperature > 200.0f)
        return false;

    return true;
}

/* FAULT DETECTION */

FaultCode FaultManager_Check(SensorData data)
{
    if (!Sensor_Validate(data))
    {
        activeFault = FAULT_SENSOR;
        currentState = STATE_SAFE_MODE;

        return activeFault;
    }

    if (data.temperature > MAX_TEMPERATURE)
    {
        activeFault = FAULT_OVERTEMPERATURE;
        currentState = STATE_SAFE_MODE;

        return activeFault;
    }

    if (data.temperature < MIN_TEMPERATURE)
    {
        activeFault = FAULT_SENSOR;
        currentState = STATE_SAFE_MODE;

        return activeFault;
    }

    if (data.voltage > MAX_VOLTAGE)
    {
        activeFault = FAULT_OVERVOLTAGE;
        currentState = STATE_SAFE_MODE;

        return activeFault;
    }

    if (data.voltage < MIN_VOLTAGE)
    {
        activeFault = FAULT_UNDERVOLTAGE;
        currentState = STATE_SAFE_MODE;

        return activeFault;
    }

    activeFault = FAULT_NONE;
    currentState = STATE_RUNNING;

    return activeFault;
}

/* SYSTEM STATE ACCESS */

SystemState FaultManager_GetState(void)
{
    return currentState;
}

/* FAULT RESET */

void FaultManager_Reset(void)
{
    activeFault = FAULT_NONE;
    currentState = STATE_INIT;
}

/* FAULT STATUS */

FaultCode FaultManager_GetActiveFault(void)
{
    return activeFault;
}
