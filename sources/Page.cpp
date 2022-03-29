#include <iostream>
#include <string>
#include "Direction.hpp"
#include <unordered_map>
#include "Row.hpp"
#include "Page.hpp"
using namespace std;

namespace ariel
{

    Page::Page(){
        // constuctor
        this->rows[0] = Row();
    }

    void Page::emptyRow(int row){
        // if the given row is empty, open a new one
        if (this->rows.find(row) == this->rows.end()) {
            this->rows[row]=Row();
        }
    }

    int Page::checkEmptyRow(int row){
        // return if the row is empty
        if (this->rows.find(row) == this->rows.end()) {
            return TRUE; // empty row
        }
        return FALSE; // not empty row
    }

    void Page::addToRowHor(int row , int column , std::string const & str){
        // --- ofki
        this->emptyRow(row);
        this->rows.at(row).addString(column,str);
    }

    void Page::addToRowVer(int row , int column , std::string const & str){
        // | anachi
        for (int i=0 ; i <str.length() ; i++){
            this->emptyRow(row+i);
            this->rows.at(row+i).addChar(column,str.at((unsigned long)i)); // add one char to each row
        }
    }

    string Page::readHor(int row , int column , int length){
        string ans;
        if (this->checkEmptyRow(row)==TRUE){ // row is empty
                ans.assign((unsigned long)length, '_');
        }
        else{
            ans = this->rows.at(row).look(column,length);
        }
        return ans;
    }

    string Page::readVer(int row , int column , int length){
        string ans;
        for (int i=0 ; i<length ; i++){
            if (this->checkEmptyRow(row+i)==TRUE){ // column in row is empty
                ans.append("_");
                continue;
            }
            ans.append(this->rows.at(row+i).look(column,1));
        }
        return ans;
    }

    void Page::eraseHor(int row , int column , int length){
        this->emptyRow(row);
        this->rows.at(row).eraseString(column,length);
    }

    void Page::eraseVer(int row , int column , int length){
        for (int i=0 ; i<length ; i++){
            this->emptyRow(row+i);
            this->rows.at(row+i).eraseString(column,1);
        }
    }

}