#include <wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

#define ADDRESS 56 //0x38
#define COLS 16
#define ROWS 2

LiquidCrystal_I2C lcd(ADDRESS, COLS, ROWS);  // Address 0x27 for 16x2 LCD

typedef void (*MenuFunction)();

struct MenuItem {
    const char* name;
    MenuFunction action;
};

class Menu {
public:
    Menu(const MenuItem* items, size_t numItems, LiquidCrystal_I2C& lcd)
        : menuItems(items), numItems(numItems), currentIndex(0), lcd(lcd) {}

    void displayMenu() const {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Menu:");
        for (size_t i = 0; i < numItems; ++i) {
            lcd.setCursor(0, i + 1);
            lcd.print(i + 1);
            lcd.print(". ");
            lcd.print(menuItems[i].name);
        }
    }

    void displayCurrentItem() const {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Selected:");
        lcd.setCursor(0, 1);
        lcd.print(menuItems[currentIndex].name);
    }

    void selectItem(size_t index) {
        if (index < numItems) {
            if (menuItems[index].action) {
                menuItems[index].action();
            }
        }
    }

    void nextItem() {
        currentIndex = (currentIndex + 1) % numItems;
        displayCurrentItem();
    }

    void previousItem() {
        if (currentIndex == 0) {
            currentIndex = numItems - 1;
        } else {
            --currentIndex;
        }
        displayCurrentItem();
    }

    void selectCurrentItem() {
        selectItem(currentIndex);
    }

private:
    const MenuItem* menuItems;
    size_t numItems;
    size_t currentIndex;
    LiquidCrystal_I2C& lcd;
};
