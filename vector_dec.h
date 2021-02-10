/*--------------------------------------------------------------------------\
|   vector_dec.h of ConvNeurNet Project---------Student Work                |
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
#ifndef   CONV_PROJECT_VECTOR_DECLARATION
# define  CONV_PROJECT_VECTOR_DECLARATION
# include "declaration.h"
 namespace conv{
     template <class type> class vector{
     protected:
         struct   lelem{
                  type*    it                                   ;
                  lelem*   up                                   ;
                  lelem*   next                                 ;
         }                                                      ;
         typedef  type*&   fptype                               ;
         typedef  lelem*&  fplelem                              ;
         lelem*            head                                 ;
         lelem*            tail                                 ;
         int               vsize                                ;
         inline   void     swap       (int&,int&)               ;
         inline   void     swap       (fplelem,fplelem)         ;
//       template                     <typename...argpack>
//       inline   type*    alloc      (argpack...)              ;
     public:
         explicit inline   vector     (void)                    ;
         explicit inline   vector     (vector&&)                ;
         virtual  inline  ~vector     (void)                    ;
         void              copy       (const vector&)           ;
         void              copy       (type*,int)               ;
         void              move       (vector&&)                ;
         template                     <typename...argpack>
         void              push_back  (argpack...)              ;
         template                     <typename...argpack>
         void              push_front (argpack...)              ;
         void              clear      (void)                    ;
         type&             operator[] (int)                const;
         inline   int      size       (void)               const;
     }                                                          ;
 }
#endif
