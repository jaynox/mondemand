# BEGIN: Variables to change.

# any additional includes to add to the compile lines
myincludes = @LWES_CFLAGS@

# any additional files to add to the distribution
myextradist =

# any additional files to clean up with 'make clean'
mycleanfiles =

# any additional files to clean up with 'make maintainer-clean'
mymaintainercleanfiles = config.h.in

# list of public library header files
myheaderfiles = m_hash.h \
                m_mem.h \
                mondemand_trace.h \
                mondemand_transport.h \
                mondemand_types.h \
                mondemandlib.h

# list of private library header files
# these aren't installed or listed in the library common header
myprivateheaderfiles = 

# include a top level header which includes all other headers
# if set, MUST be of the form @PACKAGEPACKED@.h
mybaseincludeheader = @PACKAGEPACKED@.h

# list of source files comprising shared library
mysourcefiles = \
  m_mem.c \
  m_hash.c \
  mondemand_trace.c \
  mondemand_transport.c \
  mondemandlib.c

# sigh ... automake/autoconf/libtool is not smart enough to handle AC_SUBST
# for libtool library names, so you have to fill this out yourself
#
# it should look like: lib@PACKAGE@.la
lib_LTLIBRARIES = \
  libmondemand.la
libmondemand_la_SOURCES = ${mysourcefiles}
libmondemand_la_LIBADD = @LWES_LIBS@
libmondemand_la_LDFLAGS = -version-info @MAJOR_VERSION@:@MINOR_VERSION@:0 @GCOV_LTFLAGS@

bin_PROGRAMS = \
  mondemand-tool

mondemand_tool_SOURCES = \
  mondemand-tool.c
mondemand_tool_LDADD = \
  lib@PACKAGE@.la

# END: Variables to change
# past here, hopefully, there is no need to edit anything

INCLUDES = ${myincludes}

baseincludedir = $(includedir)/@PACKAGE_NAME@-@MAJOR_VERSION@
baseinclude_HEADERS = ${mybaseincludeheader}

@PACKAGEPACKED@.h: Makefile
	@(echo "/* Automatically generated common header file */";     \
	  echo "";                                                     \
	  perl -le                                                     \
	    'foreach (@ARGV) { print "#include <@PACKAGE_NAME@-@PACKAGE_VERSION@/$$_>"; }'\
	  ${myheaderfiles}) > @PACKAGEPACKED@.h

betterincludedir = $(baseincludedir)/@PACKAGE_NAME@-@PACKAGE_VERSION@

betterinclude_HEADERS = ${myheaderfiles}

noinst_HEADERS = ${myprivateheaderfiles}

EXTRA_DIST =                            \
  ${myprivateheaderfiles}               \
  ${myextradist}

CLEANFILES =                            \
  @PACKAGEPACKED@.h                     \
  *.bb                                  \
  *.bbg                                 \
  *.da                                  \
  *.gcno                                \
  *.gcda                                \
  ${mycleanfiles}

MAINTAINERCLEANFILES =                  \
  Makefile.in                           \
  ${mymaintainercleanfiles}

# .BEGIN is ignored by GNU make so we can use it as a guard
.BEGIN:
	@echo "error: GNU Make is required, try aliasing gmake to make"
	@exit 1
