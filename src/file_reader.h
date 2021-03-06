/*--------------------------------------------------------------------------\
|   file_reader.h of ConvNeurNet Project---------Student Work               |
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
#ifndef  CONV_PROJECT_FILE
# define CONV_PROJECT_FILE
# include <fstream>
# include "string.h"
 namespace conv{
     class reader{
     private:
         using            fstr                              =std::fstream;
         fstr             input                                          ;
     public:
         using            ldvector                 =conv::vector<ldouble>;
         struct           analysed_data{
             ldvector     chn1;
             ldvector     chn2;
         };
         explicit inline  reader          (void)                 =default;
         inline          ~reader          (void)                 =default;
         analysed_data*   read            (string)                       ;
     }                                                                   ;
 }
#endif
