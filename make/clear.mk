REMOVE = rm -rf
MKSCPT   = $(PWD)/make
include $(MKSCPT)/objval.mk

total:
	$(REMOVE) $(OBJFILE)
	$(REMOVE) $(OBJPATH)
