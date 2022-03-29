#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Direction.hpp"
#include "Row.hpp"
#include "Page.hpp"
#include <unordered_map>
using namespace std;

#ifndef MY_HEADER
#define MY_HEADER

namespace ariel{

    int illegalString(std::string const & str);
    int alreadyWrittenDeleted(std::string const & str);
    void checkNegative(int page, int row, int column, int length);

    // class Row{
    //     private:
    //         char line[100];
    //     public:
    //         Row();
    //         void addString(int column , std::string const & str);
    //         void addChar(int column , char ch);
    //         void eraseString(int column , int length);
    //         string look(int column , int length);
    // };

    // class Page{
    //     private:
    //         std::unordered_map<int, ariel::Row> rows;
    //         void emptyRow(int row);
    //     public:
    //         Page();
    //         void addToRowVer(int row , int column , std::string const & str);
    //         void addToRowHor(int row , int column , std::string const & str);
    //         string readVer(int row , int column , int length);
    //         string readHor(int row , int column , int length);
    //         void eraseVer(int row , int column , int length);
    //         void eraseHor(int row , int column , int length);
    //         int checkEmptyRow(int row);
    // };

    class Notebook{
        private:
            std::unordered_map<int, ariel::Page> pages;
            void emptyPage(int page);
            int checkEmptyPage(int page);
        public:
            Notebook();
            void write(int page, int row, int column, Direction dir, std::string const & str);
            string read(int page, int row, int column, Direction dir, int length);
            void erase(int page, int row, int column, Direction dir, int length);
            void show(int page);
    };

}

#endif