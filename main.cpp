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
using std::endl;
using conv::net;
using conv::vector;
using conv::ldouble;
using conv::ldvector;
using conv::string;
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
    else if(argc!=3){
        std::cout<<"Unknown options."<<endl;
        return 0;
    }
    net convpart(argv[1]);
    ldvector* res=convpart.exec(argv[2]);
    for(int i=0;i<(res->size());i++){
        std::cout<<(*res)[i]<<' ';
    }
    //std::cout<<endl<<res->size()<<endl;
   // delete res;
    return 0;
}
