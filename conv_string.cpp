/*--------------------------------------------------------------------------\
|   conv_string.cpp of ConvNeurNet Project---------Student Work             |
|   Copyright (C) 2021  丁嘉一                                               |
+                                                                           +
|   This program is free software: you can redistribute it and/or modify    |
|   it under the terms of the GNU General Public License as published by    |
|   the Free Software Foundation, either version 3 of the License, or       |
|   (at your option) any later version.                                     |
+                                                                           +
|   This program is distributed in the hope that it will be useful,         |
|   but WITHOUT ANY WARRANTY; without even the implied warranty of          |
|   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           |
|   GNU General Public License for more details.                            |
+                                                                           +
|   You should have received a copy of the GNU General Public License       |
|   along with this program.  If not, see <https://www.gnu.org/licenses/>.  |
\--------------------------------------------------------------------------*/
#include <iostream>
#include "string.h"
using std::istream;
using std::ostream;
using conv::string;
conv::string::string(void):vector(),len(0),buf(nullptr){
}
conv::string::string(char* copy):vector(),len(0),buf(nullptr){
    for(int i=0;copy[i]!=0;i++) {
        this->push_back(copy[i]);
        len++;
    }
    this->push_back(static_cast<char>(0));
}
conv::string::string(const char* copy):vector(),len(0),buf(nullptr){
    for(int i=0;copy[i]!=0;i++) {
        this->push_back(copy[i]);
        len++;
    }
    this->push_back(static_cast<char>(0));
}
conv::string::string(const string& cp):vector(),buf(nullptr){
    this->copy(cp);
}
conv::string::~string(void){
    if(buf!=nullptr){
        delete[] buf;
    }
}
void conv::string::check_length(void){
    len=0;
    for(int& i=len;(*this)[i]!=0;i++){
        continue;
    }
}
void conv::string::copy(const string& cp){
    dynamic_cast<vector<char>*>(this)->copy(cp);
}
const string& conv::string::operator=(const string& cp){
    this->copy(cp);
    return *this;
}
bool conv::operator==(const string& a,const string& b){
    for(int i=0;a[i]!=0||b[i]!=0;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
conv::string::operator char*(void)const{
    if(buf!=nullptr){
        delete[] buf;
    }
    buf=new char[len+1]{0};
    for(int i=0;i<len;i++){
        buf[i]=(*this)[i];
    }
    return buf;
}
conv::string::operator const char*(void)const{
    return static_cast<char*>(*this);
}
istream& conv::operator>>(istream& input,string& aim){
    char* mid=new char[2021]{0};
    input>>mid;
    aim.copy(mid);
    aim.check_length();
    return input;
}
ostream& conv::operator<<(ostream& output,const string& aim){
    output<<static_cast<char*>(aim);
    return output;
}
