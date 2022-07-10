GCC := $(shell command -v gcc 2> /dev/null)
MUSL := $(shell command -v musl-gcc 2> /dev/null)

all: gcc-all musl-all

gcc-all: gcc gcc-static

gcc: mem_layout.c
ifndef GCC
	$(error "gcc has not been installed, please install")
endif
	$(GCC) -o mem_layout_gcc $<

gcc-static: mem_layout.c
ifndef GCC
	$(error "gcc has not been installed, please install")
endif
	$(GCC) -o mem_layout_gcc_static $< -static

musl-all: musl musl-static

musl: mem_layout.c
ifndef MUSL
	$(error "musl-gcc has not been installed, please install")
endif
	$(MUSL) -o mem_layout_musl $<

musl-static: mem_layout.c
ifndef MUSL
	$(error "musl-gcc has not been installed, please install")
endif
	$(MUSL) -o mem_layout_musl_static $< -static


