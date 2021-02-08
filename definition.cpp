/*--------------------------------------------------------------------------\
|   declaration.cpp of ConvNeurNet Project---------Student Work             |
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
#include "declaration.h"
#include <random>
#include <ctime>
using random_engine=std::default_random_engine;
using conv::ldouble;
using conv::pldouble;
static random_engine rdm(time(0));
ldouble conv::max(ldouble a,ldouble b){
    return (a>b)?(a):(b);
}
ldouble conv::min(ldouble a,ldouble b){
    return (a<b)?(a):(b);
}
ldouble conv::sigmoid(ldouble x){
    return 1.0f/(1+exp(x));
}
ldouble conv::relu(ldouble x){
    return max(0,x);
}
ldouble conv::softplus(ldouble x){
    return log(1+exp(x));
}
ldouble conv::normaldist(ldouble x,ldouble w,ldouble o){
    return sqrt(1.0f/(2*pi*o*o))*exp((-1.0f/(2*o*o))*(x-w)*(x-w));
}
void conv::initweight(ldouble& w){
    w=rdm()%5;
    if(rdm()%10>5&&w!=0){
        w*=-1;
    }
    w/=5;
}
