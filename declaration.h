/*--------------------------------------------------------------------------\
|   declaration.h of ConvNeurNet Project---------Student Work               |
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
#ifndef   CONV_PROJECT_DEF
# define  CONV_PROJECT_DEF
//# include <iostream>
 namespace conv{
#    define    donothing
#    define    pure             =0
#    define    pi               acos(-1)
#    define    protected_section(mut,code) {using std::lock_guard;lock_guard a(mut);\
       code \
     }
     typedef   long double       ldouble,*pldouble        ;
     typedef   char              byte                     ;
     ldouble   max              (ldouble,ldouble)         ;
     ldouble   min              (ldouble,ldouble)         ;
     ldouble   sigmoid          (ldouble)                 ;
     ldouble   relu             (ldouble)                 ;
     ldouble   softplus         (ldouble)                 ;
     ldouble   normaldist       (ldouble,ldouble,ldouble) ;
     void      initweight       (ldouble&)                ;
//   inline    bool              running                  ;
     template <typename type>
     inline type&& right_ref(type& val){
         return static_cast<type&&>(val);
     }
 }
#endif
