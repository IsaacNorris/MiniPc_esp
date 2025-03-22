#pragma once

#include <string>

enum class eListType
{
    Empty,
    Number,
    Toggle,
};

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

    std::string DisplayString()
    {
        std::string str = isSelected == true ? "*" : "-";
        str.append(" ");
        str.append(label);
        str.append(": ");
        str.append(DataToStr());
        return str;
    }

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

    std::string label;
    eListType type;

    int data;
    bool isSelected;
};