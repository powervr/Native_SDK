#
# File			Makefile
# Title			Example makefile
#
# Copyright		Copyright (C) Imagination Technologies Limited.
#

.PHONY: clean

SDKDIR  = ../../../../../..
OUTNAME = OGLES2PVRScopeExample
APIS    = OGLES2
DEPENDS = PVRSHELL PVRTOOLS

OBJECTS +=	\
           OGLES2PVRScopeExample.o	\
           PVRScopeGraphAPI.o	\
           PVRScopeGraph.o	\
           Reflection.o	\
           Thickness.o	\
           FragShader.o	\
           VertShader.o	\
           Mask.o

VPATH +=	\
         ../../.. : 	\
         ../../Content

INCLUDES += 	\
         -I../../..	\
         -I$(SDKDIR)/Builds/Include

LINK +=	\
       -L$(SDKDIR)/Builds/Linux/$(PLAT_SUFFIX)/Lib	\
       -lPVRScopeDeveloper	\
       -ldl

include $(SDKDIR)/Builds/Linux/make_example.mak

../../Content/Reflection.cpp ../../Content/Thickness.cpp ../../Content/FragShader.cpp ../../Content/VertShader.cpp ../../Content/Mask.cpp: wrap_content_files 

$(PLAT_OBJPATH)/%.o: ../../Content/%.cpp
	mkdir -p $(PLAT_OBJPATH)
	$(PLAT_CPP) $(PLAT_CFLAGS) $(INCLUDES) -MF"$(@:.o=.d)" -MG -MM -MP -MT"$(@:.o=.d)" -MT"$@" "$<"
	$(PLAT_CPP) -c $(PLAT_CFLAGS) $(INCLUDES) $< -o$@

