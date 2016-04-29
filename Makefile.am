ACLOCAL_AMFLAGS = -I m4

SUBDIRS = libapp bin

TESTS = \
	test/sample.test

.PHONY: help
help:
	@echo "Build targets:"
	@echo "    all          Build project"
	@echo "    check        Run project test-suite"
	@echo "    recheck      Run only previously failed tests"
	@echo ""
	@echo "Clean targets:"
	@echo "    clean              Remove built project files"
	@echo "    distclean          Remove built project files and build-system files"
	@echo "    maintainer-clean   Remove all derived files"
	@echo ""
	@echo "Documentation targets:"
	@echo "    dvi          Produce documentation in dvi format"
	@echo "    html         Produce documentation in html format"
	@echo "    pdf          Produce documentation in pdf format"
	@echo "    ps           Produce documentation in ps format"
	@echo ""
	@echo "Development targets:"
	@echo "    format       Format all the source code to project style"
	@echo "    clang-scan   Run clang static analyzer over project"
	@echo "    ccpcheck     Run ccpcheck static analyzer over project"
	@echo "    cscope       Produce a csope file for project"
	@echo "    ctags        Produce a (vi) ctags file for project"
	@echo "    tags         Produce an emacs tag file for project"
	@echo ""
	@echo "Packaging targets:"
	@echo "    dist         Package project into tarball for distribution"
	@echo "    install      Build project and install on local system"
	@echo "    uninstall    Remove previous install from local system"
	@echo ""

.PHONY: format
format:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		find $$subdir -iregex '.*\.\(cc\|hh\)$$' -exec clang-format -i {} +; \
	done

.PHONY: clang-scan
clang-scan:
	@make clean
	@scan-build ./configure
	@scan-build make

.PHONY: cppcheck
cppcheck:
	@cppcheck --std=c++11 \
		--enable=warning \
		--enable=performance \
		--enable=portability \
		--enable=style \
		. 2> cppcheck.err 1>/dev/null
	@echo "Finished! (check cppcheck.err)..."
	@echo ""
	@head cppcheck.err
