#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include <Arduino.h>
#include <M5StickCPlus.h>

class UIManager
{
public:
    void begin();
    void setStatusbar(String message, bool isError = false);
};

#endif