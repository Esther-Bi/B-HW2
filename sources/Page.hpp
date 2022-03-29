#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Direction.hpp"
#include "Row.hpp"
#include <unordered_map>
using namespace std;

#ifndef MY_PAGE_HEADER
#define MY_PAGE_HEADER

namespace ariel{

    class Page{
        private:
            std::unordered_map<int, ariel::Row> rows;
            void emptyRow(int row);
        public:
            Page();
            void addToRowVer(int row , int column , std::string const & str);
            void addToRowHor(int row , int column , std::string const & str);
            string readVer(int row , int column , int length);
            string readHor(int row , int column , int length);
            void eraseVer(int row , int column , int length);
            void eraseHor(int row , int column , int length);
            int checkEmptyRow(int row);
    };

}

#endif