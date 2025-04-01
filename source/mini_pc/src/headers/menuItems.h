#pragma once

#include "menus.h"

#include <string>
#include <vector>

enum class eListType
{
    Empty,
    Number,
    Toggle,
};

class tMenu;

class tListItem
{
public:
    tListItem(const std::string &l, eListType t)
    {
        label = l;
        type = t;
    }
    ~tListItem()
    {
    }

    const std::string DisplayString()
    {
        std::string str = isSelected == true ? "*" : "-";
        if (type == eListType::Number && numberChanging)
        {
            str = '@';
        }
        str.append(" ");
        str.append(label);
        str.append(": ");
        str.append(DataToStr());
        return str;
    }

    // TODO: instead of returning the next menu make it so that
    //  it instead calls upon a std::function.

    tMenu *Interact(eInputType input)
    {
        switch (type)
        {
        case eListType::Empty:
            return nextList;
            break;
        case eListType::Number:
            if (input == eInputType::Enter)
                numberChanging = !numberChanging;
            else if (numberChanging)
            {
                if (input == eInputType::Up)
                {
                    NumberIncrease();
                }
                else if (input == eInputType::Down)
                {
                    NumberDecrease();
                }
            }
            return nullptr;
            break;
        case eListType::Toggle:
            if (input == eInputType::Enter)
            {
                data = !data;
            }
            return nullptr;
            break;
        }
        return nullptr;
    }

    tMenu *nextList;

    bool isSelected = false;
    bool numberChanging = false;

private:
    std::string DataToStr()
    {
        std::string str;
        switch (type)
        {
        case eListType::Empty:
            str = "";
            break;
        case eListType::Number:
            str = std::to_string(data);
            break;
        case eListType::Toggle:
            str = data == false ? "Off" : "On";
            break;
        }

        return str;
    }

    void NumberDecrease()
    {
        data -= step;
        if (data < minNum)
            data = maxNum;
    }

    void NumberIncrease()
    {
        data += step;
        if (data > maxNum)
            data = minNum;
    }

    std::string label;
    eListType type;

    int data;

    int step = 1;
    int maxNum = 99;
    int minNum = 0;
};

class tMenu
{
public:
    void AddItem(tListItem *item)
    {
        listItems.push_back(item);

        maxItems = listItems.size();
    }

    const std::string DisplayMenuString()
    {
        std::string str = "";

        for (auto item : listItems)
        {
            str.append(item->DisplayString());
            str.append("\n");
        }

        return str;
    }

    tMenu *Interact(eInputType input)
    {
        auto menu = listItems.at(currentItem)->Interact(input);
        listItems.at(currentItem)->isSelected = false;
        if (menu && input != eInputType::Enter)
        {
            menu = nullptr;
        }
        else if (input == eInputType::Up && !listItems.at(currentItem)->numberChanging)
        {
            currentItem++;
            if (currentItem > maxItems - 1)
                currentItem = 0;
        }
        else if (input == eInputType::Down && !listItems.at(currentItem)->numberChanging)
        {
            currentItem--;
            if (currentItem < 0)
                currentItem = maxItems;
        }
        listItems.at(currentItem)->isSelected = true;
        return menu;
    }

private:
    std::vector<tListItem *> listItems;

    uint8_t currentItem;
    uint8_t maxItems;
};