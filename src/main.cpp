/*--------------------------------------------------------------------------\
|   main.cpp of ConvNeurNet Project---------Student Work                    |
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
//#include <linux/soundcard.h>
//#include <iomanip>
#include "project.h"
#include "file_reader.h"
#define file(name) #name
using std::endl;
using conv::net;
using conv::vector;
using conv::ldouble;
using conv::ldvector;
using conv::string;
using conv::right_ref;
using conv::reader;
using andt=typename reader::analysed_data;
int main(int argc,char** argv){
    if(argc==2){
        if(string(argv[1])=="--help"){
            std::cout<<"exec <configure file> <object file>"<<endl;
            return 0;
        }
        else{
            std::cout<<"Unknown options."<<endl;
            return 0;
        }
    }
    else if(argc!=5){
        std::cout<<"Unknown options."<<endl;
        return 0;
    }
    net t1(argv[1]);
    net t2(argv[2]);
    net total(argv[3]);
    reader in;
    andt* obj=in.read(argv[4]);
    t1.set_object().copy(obj->chn1);
    t2.set_object().copy(obj->chn2);
    ldvector* rest1=t1.exec();
    ldvector* rest2=t2.exec();
    //std::cout<<rest1->size()<<endl<<rest2->size()<<endl;
    for(int i=0;i<rest2->size();i++){
        rest1->push_back((*rest2)[i]);
    }
    total.set_object().copy(*rest1);
    rest1->move(right_ref(*total.exec()));
    for(int i=0;i<(rest1->size());i++){
        std::cout<<(*rest1)[i]<<' ';
    }
    std::cout<<endl;
    delete obj;
    return 0;
}
