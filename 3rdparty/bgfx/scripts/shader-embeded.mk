#
# Copyright 2011-2016 Branimir Karadzic. All rights reserved.
# License: http://www.opensource.org/licenses/BSD-2-Clause
#

THISDIR:=$(dir $(lastword $(MAKEFILE_LIST)))
include $(THISDIR)/tools.mk

VS_FLAGS+=-i $(THISDIR)../src/ --type vertex
FS_FLAGS+=-i $(THISDIR)../src/ --type fragment
CS_FLAGS+=-i $(THISDIR)../src/ --type compute

VS_SOURCES=$(wildcard vs_*.sc)
FS_SOURCES=$(wildcard fs_*.sc)
CS_SOURCES=$(wildcard cs_*.sc)

VS_BIN = $(addsuffix .bin.h, $(basename $(VS_SOURCES)))
FS_BIN = $(addsuffix .bin.h, $(basename $(FS_SOURCES)))
CS_BIN = $(addsuffix .bin.h, $(basename $(CS_SOURCES)))

BIN = $(VS_BIN) $(FS_BIN) $(CS_BIN)

SHADER_TMP = $(TEMP)/tmp

vs_%.bin.h : vs_%.sc
	@echo [$(<)]
	 $(SILENT) $(SHADERC) $(VS_FLAGS) --platform linux                  -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_glsl
	@cat $(SHADER_TMP) > $(@)
	-$(SILENT) $(SHADERC) $(VS_FLAGS) --platform windows -p vs_3_0 -O 3 -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_dx9
	-@cat $(SHADER_TMP) >> $(@)
	-$(SILENT) $(SHADERC) $(VS_FLAGS) --platform windows -p vs_4_0 -O 3 -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_dx11
	-@cat $(SHADER_TMP) >> $(@)
	-$(SILENT) $(SHADERC) $(VS_FLAGS) --platform ios     -p metal  -O 3 -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_mtl
	-@cat $(SHADER_TMP) >> $(@)

fs_%.bin.h : fs_%.sc
	@echo [$(<)]
	 $(SILENT) $(SHADERC) $(FS_FLAGS) --platform linux                  -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_glsl
	@cat $(SHADER_TMP) > $(@)
	-$(SILENT) $(SHADERC) $(FS_FLAGS) --platform windows -p ps_3_0 -O 3 -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_dx9
	-@cat $(SHADER_TMP) >> $(@)
	-$(SILENT) $(SHADERC) $(FS_FLAGS) --platform windows -p ps_4_0 -O 3 -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_dx11
	-@cat $(SHADER_TMP) >> $(@)
	-$(SILENT) $(SHADERC) $(FS_FLAGS) --platform ios     -p metal  -O 3 -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_mtl
	-@cat $(SHADER_TMP) >> $(@)

cs_%.bin.h : cs_%.sc
	@echo [$(<)]
	 $(SILENT) $(SHADERC) $(CS_FLAGS) --platform linux -p 430           -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_glsl
	@cat $(SHADER_TMP) > $(@)
	-$(SILENT) $(SHADERC) $(CS_FLAGS) --platform windows -p cs_5_0 -O 1 -f $(<) -o $(SHADER_TMP) --bin2c $(basename $(<))_dx11
	-@cat $(SHADER_TMP) >> $(@)

.PHONY: all
all: $(BIN)

.PHONY: clean
clean:
	@echo Cleaning...
	@-rm -vf $(BIN)

.PHONY: rebuild
rebuild: clean all
