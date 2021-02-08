/*--------------------------------------------------------------------------\
|   string.h of ConvNeurNet Project---------Student Work                    |
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
#ifndef  CONV_PROJECT_STRING
# define CONV_PROJECT_STRING
# include "vector.h"
//# include <iostream>
 namespace conv{
     class string:private vector<char>{
     private:
#        ifdef    _GLIBCXX_IOSTREAM
//        using                           stream                                =std::ios;
#         define                          instream                           std::istream
#         define                          outstream                          std::ostream
#        endif
         int                              len                                            ;
         mutable   char*                  buf                                            ;
         void                             check_length (void)                             ;
     public:
         explicit                         string       (void)                             ;
                                          string       (char*)                            ;
                                          string       (const char*)                      ;
                                          string       (const string&)                    ;
         virtual                         ~string       (void)                             ;
         void                             copy         (const string&)                    ;
         inline    void                   move         (string&&)                         ;
         explicit  operator               char*        (void)                        const;
         explicit  operator               const char*  (void)                        const;
         inline    int                    length       (void)                             ;
         inline    char&                  operator[]   (int)                         const;
         const     string&                operator=    (const string&)                    ;
         friend    bool                   operator==   (const string&,const string&)      ;
         friend    inline           bool  operator!=   (const string&,const string&)      ;
#        ifdef    _GLIBCXX_IOSTREAM
          friend   instream&              operator>>   (instream&,string&)                ;
          friend   outstream&             operator<<   (outstream&,const string&)         ;
#        endif
     };
#    ifdef       _GLIBCXX_IOSTREAM
      instream&   operator>>       (instream&,string&)        ;
      outstream&  operator<<       (outstream&,const string&) ;
#     undef       instream
#     undef       outstream
#    endif
     bool operator==(const string&,const string&);
     inline char& string::operator[](int i)const{
         return dynamic_cast<const vector<char>&>(*this)[i];
     }
     inline int string::length(void){
         return len;
     }
     inline void string::move(string&& mv){
         dynamic_cast<vector<char>*>(this)->move(right_ref(mv));
     }
     inline bool operator!=(const string& a,const string& b){
         return !(a==b);
     }
 }
#endif
