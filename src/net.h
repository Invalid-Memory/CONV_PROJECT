/*--------------------------------------------------------------------------\
|   net.h of ConvNeurNet Project---------Student Work                       |
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
#ifndef   CONV_PROJECT_NET
# define  CONV_PROJECT_NET
# include "layer.h"
# define hexout(val) std::hex<<"0x"<<std::uppercase<<static_cast<int>(val)<<std::nouppercase<<std::dec
 namespace conv{
     class net{
     private:
         vector<layer*> ly;
         int layernum;
         ldvector object;
         int objectlength;
         string inputfile;
//       int inputlen;
     public:
         explicit net(string);
         ~net(void);
         ldvector* exec(string);
         void train(string,string);
         inline vector<layer*> &get_net(void);
         inline ldvector& get_object(void);
         inline int get_objectlen(void);
     };
     inline vector<layer*>& net::get_net(void){
         return ly;
     }
     inline ldvector& net::get_object(void){
         return object;
     }
     inline int net::get_objectlen(void){
         return objectlength;
     }
 }
#endif
