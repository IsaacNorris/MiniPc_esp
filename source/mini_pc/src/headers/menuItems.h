#pragma once

#include "menus.h"
#include <functional>
#include <string>
#include <vector>

enum class eInputType
{
    Up,
    Down,
    Enter
};

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
    tListItem(const std::string &l, eListType t, std::function<void(int)> onCall, int minn = 0, int maxn = 99, int stepsize = 1)
    {
        label = l;
        type = t;
        nextList = nullptr;
        data = minn;
        fOnCall = onCall;
        minNum = minn;
        maxNum = maxn;
        step = stepsize;
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
        if(type != eListType::Empty) str.append(": ");
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
            fOnCall(static_cast<int>(data));
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
                fOnCall(static_cast<int>(data));
            }
            return nullptr;
            break;
        case eListType::Toggle:
            if (input == eInputType::Enter)
            {
                data = !data;
                fOnCall(static_cast<int>(data));
            }
            return nullptr;
            break;
        }
        return nullptr;
    }

    void SetMaxNum(int num){
        maxNum = num;
        if (data > maxNum)
            data = minNum;
    }

    void SetData(int value){
        data = value;
    }

    const int GetData() const{
        return data;
    } 

    tMenu *nextList;

    bool isSelected = false;
    bool numberChanging = false;

    eListType type;
private:

    std::function<void(int)> fOnCall;

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

    int data;

    int step;
    int maxNum;
    int minNum;
};

class tMenu
{
public:
    void AddItem(tListItem *item)
    {
        listItems.push_back(item);

        maxItems = listItems.size();

        currentItem = 0;        
        listItems.at(0)->isSelected = true;
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

    tMenu *Interact(eInputType input, bool* exitMenu)
    {
        *exitMenu = false;
        auto menu = listItems.at(currentItem)->Interact(input);

        listItems.at(currentItem)->isSelected = false;

        if (input == eInputType::Enter)
        {
            if(menu != nullptr){
                menu = listItems.at(currentItem)->nextList;
            }else if(listItems.at(currentItem)->type != eListType::Number 
                && listItems.at(currentItem)->type != eListType::Toggle){
                *exitMenu = true; 
            }

            listItems.at(currentItem)->isSelected = true;
            return menu;
        }
        else if (input == eInputType::Up && !listItems.at(currentItem)->numberChanging)
        {
            currentItem--;
            if (currentItem < 0)
                currentItem = maxItems - 1;
        }
        else if (input == eInputType::Down && !listItems.at(currentItem)->numberChanging)
        { 
            currentItem++;
            if (currentItem >= maxItems)
                currentItem = 0;
        }

        listItems.at(currentItem)->isSelected = true;

        return nullptr;
    }

    std::vector<tListItem *> GetListItems() const {
        return listItems;
    }

    std::vector<tListItem *>& GetListItemsMod() {
        return listItems;
    }

private:
    std::vector<tListItem *> listItems;

    int8_t currentItem;
    int maxItems;
};