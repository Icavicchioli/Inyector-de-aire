#include <wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>



typedef void (*MenuFunction)();

struct MenuItem {
    const char* name;
    MenuFunction action;
};

class Menu {
public:
    Menu(const MenuItem* items, size_t numItems, LiquidCrystal_I2C& lcd)
        : menuItems(items), numItems(numItems), currentIndex(0), lcd(lcd) {}

    void display_Menu(char* text) const {//la cambié para que muestre texto
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(text);
    }

    void display_Current_Item() const {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Selected:");
        lcd.setCursor(0, 1);
        lcd.print(menuItems[currentIndex].name);
    }

    void select_Item(size_t index) {
        if (index < numItems) {
            if (menuItems[index].action) {
                menuItems[index].action();
            }
        }
    }

    void next_Item() {
        currentIndex = (currentIndex + 1) % numItems;
        display_Current_Item();
    }

    void previous_Item() {
        if (currentIndex == 0) {
            currentIndex = numItems - 1;
        } else {
            --currentIndex;
        }
        display_Current_Item();
    }

    void select_Current_Item() {
        select_Item(currentIndex);
    }

private:
    const MenuItem* menuItems;
    size_t numItems;
    size_t currentIndex;
    LiquidCrystal_I2C& lcd;
};
