#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Direction.hpp"
#include <unordered_map>
using namespace std;

#ifndef MY_ROW_HEADER
#define MY_ROW_HEADER

namespace ariel{

    const int LINE_LENGTH = 100;
    const int LOW_CHAR = 32;
    const int HIGH_CHAR = 125;
    const int TRUE = 1;
    const int FALSE = 0;
    
    class Row{
        private:
            std::vector<char> line;
        public:
            Row();
            void addString(int column , std::string const & str);
            void addChar(int column , char ch);
            void eraseString(int column , int length);
            string look(int column , int length);
    };

}

#endif