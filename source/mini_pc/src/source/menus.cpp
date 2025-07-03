#include "../headers/menus.h"

void tMenuManager::DisplayMenu()
{
    graphics_->PrintToScreen(currentMenuItem->DisplayMenuString());
}

bool tMenuManager::Input(eInputType type)
{
    if (auto nextMenu = currentMenuItem->Interact(type); nextMenu != nullptr)
    {
        currentMenuItem = nextMenu;
        return true;
    }
    return false;
}
