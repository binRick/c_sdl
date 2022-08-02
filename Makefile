default: all
##############################################################
PASSH=$(shell command -v passh)
GIT=$(shell command -v git)
SED=$(shell command -v gsed||command -v sed)
NODEMON=$(shell command -v nodemon)
FZF=$(shell command -v fzf)
BLINE=$(shell command -v bline)
UNCRUSTIFY=$(shell command -v uncrustify)
PWD=$(shell command -v pwd)
FIND=$(shell command -v find)
EMBED_BINARY=$(shell command -v embed)
JQ_BIN=$(shell command -v jq)
DIR=$(shell pwd)	
##############################################################
TIDIED_FILES = \
			   sdl-*/*.c sdl-*/*.h \
			   sdl-*-test/*.c sdl-*-test/*.h \
			   *-test/*.c *-test/*.h
########################################################
##############################################################
uncrustify:
	@$(UNCRUSTIFY) -c submodules/c_deps/etc/uncrustify.cfg --replace $(TIDIED_FILES)||true
uncrustify-clean:
	@find  . -type f -maxdepth 2 -name "*unc-back*"|xargs -I % unlink %
clean:
	@rm -rf build .cache
fix-dbg:
	@$(SED) 's|, % c);|, %c);|g' -i $(TIDIED_FILES)
	@$(SED) 's|, % s);|, %s);|g' -i $(TIDIED_FILES)
	@$(SED) 's|, % lu);|, %lu);|g' -i $(TIDIED_FILES)
	@$(SED) 's|, % d);|, %d);|g' -i $(TIDIED_FILES)
	@$(SED) 's|, % zu);|, %zu);|g' -i $(TIDIED_FILES)
do-meson:
	@meson build || { meson build --reconfigure || { meson build --wipe; } && meson build; }
do-ninja:
	@ninja -C build
do-ninja-test:
	@passh ninja test -C build -v
do-nodemon:
	@$(PASSH) -L .nodemon.log $(NODEMON) \
		--delay .3 \
		-w "sdl/*.c" -w "sdl/*.h" -w "*-test/*.c" -w "*-test/*.h" \
		-w 'meson/meson.build' -w 'meson/deps/*/meson.build' -w 'meson.build' -w submodules/meson.build \
		-w Makefile \
		-w 'submodules/meson.build' -w meson.build \
		-i '*/embeds/*' -i 'subprojects/*/' -i submodules -i 'build/*' \
			-e Makefile,tpl,build,sh,c,h,Makefile \
			-x env -- bash -xc 'make'

git-submodules-pull:
	@git submodule foreach git pull origin master --jobs=10

git-submodules-update:
	@git submodule update --init

git-pull:
	@git pull --recurse-submodules

do-uncrustify: uncrustify uncrustify-clean fix-dbg
do-build: do-meson do-ninja
do-test: do-ninja-test
test: do-test
build: do-meson do-build
ansi: all do-sync do-ansi-make
tidy: do-uncrustify
dev: do-nodemon
all: do-build 
meson-introspect-targets:
	@meson introspect --targets -i meson.build

meson-binaries:
	@meson introspect --targets  meson.build -i | jq 'map(select(.type == "executable").filename)|flatten|join("\n")' -Mrc
