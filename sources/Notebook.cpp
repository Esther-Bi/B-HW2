#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Row.hpp"
#include "Page.hpp"
#include <unordered_map>
#include "Notebook.hpp"
using namespace std;

namespace ariel
{

    int illegalString(std::string const & str){
        // not a writable symbol
        int ans = FALSE;
        for (int i=0 ; i<str.length() ; i++){
            if (str.at((unsigned long)i)<LOW_CHAR || str.at((unsigned long)i)>HIGH_CHAR){
                ans=TRUE;
                return ans;
            }
        }
        return ans;
    }

    int alreadyWrittenDeleted(std::string const & str){
        // there is a char in line which is not '_'
        int ans = FALSE;
        for (int i=0 ; i<str.length() ; i++){
            if (str.at((unsigned long)i) != '_'){
                ans = TRUE;
                return ans;
            }
        }
        return ans;
    }

    void checkNegative(int page, int row, int column, int length){
        // checks bad input
        if (page<0 || row<0 || column<0 || length<1){
            throw std::domain_error( "negative input" );
        }
    }

    Notebook::Notebook(){
        // constuctor
        this->pages[0] = Page();
    }

    void Notebook::emptyPage(int page){
        // if the given page is empty, open a new one
        if (this->pages.find(page) == this->pages.end()){
            this->pages[page]=Page();
        }
    }

    int Notebook::checkEmptyPage(int page){
        // return if the page is empty
        if (this->pages.find(page) == this->pages.end()){
            return TRUE; // empty page
        }
        return FALSE; // not empty page
    }

    // before all functions, check if the string is legal, if there is enough space in line, and if there is a page

    void Notebook::write(int page, int row, int column, ariel::Direction dir, std::string const & str){
        ariel::checkNegative(page,row,column,1);
        if ((dir == ariel::Direction::Horizontal && str.length()>LINE_LENGTH) || (dir == ariel::Direction::Horizontal && str.length()+(unsigned long)column>LINE_LENGTH)){
            throw std::domain_error( "not enough space for the word" );
        }
        if (dir == ariel::Direction::Vertical && column>LINE_LENGTH-1){
            throw std::domain_error( "can not write out of line" );
        }
        if (illegalString(str)==TRUE){
            throw std::domain_error( "illegal chars in word" );
        }
        if (this->checkEmptyPage(page)==FALSE && this->pages.at(page).checkEmptyRow(row)==FALSE && alreadyWrittenDeleted(Notebook::read(page,row,column,dir,str.length()))==TRUE){
            throw std::domain_error( "already written or erased" );
        }
        if (dir == ariel::Direction::Horizontal){
            this->emptyPage(page);
            this->pages.at(page).addToRowHor(row,column,str);
        }
        if (dir == ariel::Direction::Vertical){
            this->emptyPage(page);
            this->pages.at(page).addToRowVer(row,column,str);
        }
    }

    string Notebook::read(int page, int row, int column, ariel::Direction dir, int length){
        ariel::checkNegative(page,row,column,length);
        if ((dir == ariel::Direction::Horizontal && length>LINE_LENGTH) || (dir == ariel::Direction::Horizontal && length+column>LINE_LENGTH)){
            throw std::domain_error( "can not read out of line" );
        }
        if (dir == ariel::Direction::Vertical && column>LINE_LENGTH-1){
            throw std::domain_error( "can not read out of line" );
        }
        string ans;
        if (dir == ariel::Direction::Horizontal){
            if (this->checkEmptyPage(page)==TRUE){
                return "error : page is empty";
            }
            ans = this->pages.at(page).readHor(row,column,length);
        }
        if (dir == ariel::Direction::Vertical){
            if (this->checkEmptyPage(page)==TRUE){
                return "error : page is empty";
            }
            ans = this->pages.at(page).readVer(row,column,length);
        }
        return ans;
    }

    void Notebook::erase(int page, int row, int column, ariel::Direction dir, int length){
        ariel::checkNegative(page,row,column,length);
        if ((dir == ariel::Direction::Horizontal && length>LINE_LENGTH) || (dir == ariel::Direction::Horizontal && length+column>LINE_LENGTH)){
            throw std::domain_error( "can not erase out of line" );
        }
        if (dir == ariel::Direction::Vertical && column>LINE_LENGTH-1){
            throw std::domain_error( "can not erase out of line" );
        }
        if (dir == ariel::Direction::Horizontal){
            this->emptyPage(page);
            this->pages.at(page).eraseHor(row,column,length);
        }
        if (dir == ariel::Direction::Vertical){
            this->emptyPage(page);
            this->pages.at(page).eraseVer(row,column,length);
        }
    }

    void Notebook::show(int page){
        ariel::checkNegative(page,1,1,1);
        if (this->checkEmptyPage(page)==TRUE){
            cout << "0: __________\n1: __________\n2: __________" << endl;
        }
        else{
            int i=0;
            while (this->pages.at(page).checkEmptyRow(i)==FALSE){
                cout << i << ": " << this->read(page,i,0,ariel::Direction::Horizontal,LINE_LENGTH) << endl;
                i++;
            }
        }
    }
}