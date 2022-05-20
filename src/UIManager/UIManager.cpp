#include "UIManager.h"

void UIManager::begin()
{
    M5.Lcd.begin();
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(2, 40);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.print("TVOC");

    M5.Lcd.setCursor(2, 100);
    M5.Lcd.print("eCO2");
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

void UIManager::updateUI(float tvoc, float eco2)
{
    M5.Lcd.fillRect(60, 40, 135, 100, BLACK); // cleanup

    M5.Lcd.setTextSize(2);

    M5.Lcd.setCursor(60, 40);
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.print(tvoc, 1);

    M5.Lcd.setCursor(60, 100);
    M5.Lcd.print(eco2, 1);
}