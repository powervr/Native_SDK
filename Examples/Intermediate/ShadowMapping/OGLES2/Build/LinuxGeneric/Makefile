#
# File			Makefile
# Title			Example makefile
#
# Copyright		Copyright (C) Imagination Technologies Limited.
#

.PHONY: clean

SDKDIR  = ../../../../../..
OUTNAME = OGLES2ShadowMapping
APIS    = OGLES2
DEPENDS = PVRSHELL PVRTOOLS

OBJECTS +=	\
           OGLES2ShadowMapping.o	\
           FragShader.o	\
           VertShader.o	\
           ShadowFragShader.o	\
           ShadowVertShader.o	\
           Scene.o	\
           Mask.o	\
           TableCover.o	\
           Torus.o

VPATH +=	\
         ../../Content

include $(SDKDIR)/Builds/Linux/make_example.mak

../../Content/FragShader.cpp ../../Content/VertShader.cpp ../../Content/ShadowFragShader.cpp ../../Content/ShadowVertShader.cpp ../../Content/Scene.cpp ../../Content/Mask.cpp ../../Content/TableCover.cpp ../../Content/Torus.cpp: wrap_content_files 

$(PLAT_OBJPATH)/%.o: ../../Content/%.cpp
	mkdir -p $(PLAT_OBJPATH)
	$(PLAT_CPP) $(PLAT_CFLAGS) $(INCLUDES) -MF"$(@:.o=.d)" -MG -MM -MP -MT"$(@:.o=.d)" -MT"$@" "$<"
	$(PLAT_CPP) -c $(PLAT_CFLAGS) $(INCLUDES) $< -o$@

