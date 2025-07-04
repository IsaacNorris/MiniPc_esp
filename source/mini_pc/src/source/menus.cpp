#include "../headers/menus.h"

void tMenuManager::DisplayMenu()
{
    graphics_->PrintToScreen(currentMenuItem->DisplayMenuString());
}

bool tMenuManager::Input(eInputType type)
{
    bool exitMenu = false;
    if (auto nextMenu = currentMenuItem->Interact(type, &exitMenu))
    {
        currentMenuItem = nextMenu;
        return true;
    }
    return !exitMenu;
}
