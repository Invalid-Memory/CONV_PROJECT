MAKEPATH = mkdir
LINK     = g++ -std=c++2a -fPIC
MKSCPT   = $(PWD)/make
include $(MKSCPT)/objval.mk

total: mk link

mk:
	sh $(MKSCPT)/script/mkout.sh

link: $(OBJFILE)
	$(LINK) $(OBJFILE) -o $(OUTFILE) 
