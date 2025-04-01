#include "../headers/menus.h"

void tMenuManager::DisplayMenu()
{
    graphics_->PrintToScreen(currentMenuItem->DisplayMenuString());
}

void tMenuManager::Input(eInputType type)
{
    if (auto nextMenu = currentMenuItem->Interact(type))
    {
        currentMenuItem = nextMenu;
    }
}
