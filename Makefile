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

run-binary:
	@clear; make meson-binaries | env FZF_DEFAULT_COMMAND= \
        fzf --reverse \
            --preview-window='follow,wrap,right,80%' \
            --bind 'ctrl-b:preview(make meson-build)' \
            --preview='env bash -c {} -v -a' \
            --ansi --border \
            --cycle \
            --header='Select Test Binary' \
            --height='100%' \
    | xargs -I % env bash -c "./%"
run-binary-nodemon:
	@make meson-binaries | fzf --reverse | xargs -I % nodemon -w build --delay 1000 -x passh "./%"
meson-tests-list:
	@meson test -C build --list
meson-tests:
	@{ make meson-tests-list; } |fzf \
        --reverse \
        --bind 'ctrl-b:preview(make meson-build)' \
        --bind 'ctrl-t:preview(make meson-tests-list)'\
        --bind 'ctrl-l:reload(make meson-tests-list)'\
        --bind 'ctrl-k:preview(make clean meson-build)'\
        --bind 'ctrl-y:preview-half-page-up'\
        --bind 'ctrl-u:preview-half-page-down'\
        --bind 'ctrl-/:change-preview-window(right,90%|down,90%,border-horizontal)' \
        --preview='\
            meson test --num-processes 1 -C build -v \
                --no-stdsplit --print-errorlogs {}' \
        --preview-window='follow,wrap,bottom,85%' \
        --ansi \
        --header='Select Test Case |ctrl+b:rebuild project|ctrl+k:clean build|ctrl+t:list tests|ctrl+l:reload test list|ctrl+/:toggle preview style|ctrl+y/u:scroll preview|'\
        --header-lines=0 \
        --height='100%'
