#include "UIManager.h"

void UIManager::begin()
{
    M5.Lcd.begin();
}

void UIManager::setStatusbar(String message, bool isError)
{
    M5.Lcd.setTextSize(1);
    M5.Lcd.setCursor(2, 220);
    if (isError)
        M5.Lcd.setTextColor(RED);
    else
        M5.Lcd.setTextColor(WHITE);
    M5.Lcd.fillRect(0, 220, 135, 240, BLACK); // cleanup status bar rect
    M5.Lcd.print(message);

    Serial.println("Statusbar: " + message);
}