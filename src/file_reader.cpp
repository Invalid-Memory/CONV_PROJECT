/*--------------------------------------------------------------------------\
|   file_reader.cpp of ConvNeurNet Project---------Student Work             |
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
#include "file_reader.h"
using std::ios;
using std::endl;
#define unsigned_byte(val) static_cast<unsigned char>(val)
typename conv::reader::analysed_data* conv::reader::read(string inputfile){
    input.open(static_cast<char*>(inputfile),ios::in|ios::binary);
    if(input.is_open()==false){
        std::cout<<"Failed to open "<<inputfile<<endl;
        throw -1;
    }
    analysed_data* res=new analysed_data;
    int filelen;
    input.seekg(0,ios::end);
    filelen=input.tellg();
    input.seekg(0,ios::beg);
    byte* buf=new byte[filelen];
    input.read(buf,filelen);
    if(unsigned_byte(buf[22])!=2){
        std::cerr<<"reader::read(): Single channel unsupported"<<endl;
        throw -1;
    }
    unsigned int bytes=unsigned_byte(buf[34]);
    if(bytes!=8){
        std::cerr<<"reader::read(): Only 8 bytes support, for the time being"<<endl;
        throw -1;
    }
    unsigned int pos=filelen-1;
    unsigned long long int num=0;
    num|=static_cast<unsigned long long int>(unsigned_byte(buf[40]));
    num|=static_cast<unsigned long long int>(unsigned_byte(buf[41]))<<8;
    num|=static_cast<unsigned long long int>(unsigned_byte(buf[42]))<<16;
    num|=static_cast<unsigned long long int>(unsigned_byte(buf[43]))<<32;
    //std::cout<<num;
    for(int i=0;i<num;i+=2){
        res->chn1.push_back(static_cast<ldouble>(unsigned_byte(buf[pos])));
        res->chn2.push_back(static_cast<ldouble>(unsigned_byte(buf[pos-1])));
        pos-=2;
    }
    return res;
}
