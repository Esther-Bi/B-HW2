#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Row.hpp"
#include <unordered_map>
using namespace std;

namespace ariel
{

    Row::Row(){
        // constuctor
        this->line.reserve(LINE_LENGTH);
        for (int i=0 ; i<LINE_LENGTH ; i++){
            this->line[(unsigned long)i] = '_';
        }
    }

    void Row::addString(int column , std::string const & str){
        // add given string to line in column
        for (int i=column ; i<str.length()+(unsigned long)column ; i++){
            this->line[(unsigned long)i]=str.at((unsigned long)(i-column));
        }
    }

    void Row::addChar(int column , char ch){
        // add given char to line in column
        this->line[(unsigned long)column]=ch;
    }

    void Row::eraseString(int column , int length){
        // erase string from line by length
        for (int i=column ; i<length+column ; i++){
            this->line[(unsigned long)i] = '~';
        }
    }

    string Row::look(int column , int length){
        // return string of line
        string ans;
        for (int i=column ; i<length+column ; i++){
            unsigned long index = (unsigned long) (i);
            ans.push_back(this->line[index]);
        }
        return ans;
    }

}