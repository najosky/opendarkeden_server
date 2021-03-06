#--------------------------------------------------------------------------------
#
# Filename    : Makefile
# Written By  : Reiot
#
#--------------------------------------------------------------------------------

#--------------------------------------------------------------------------------
# Directories
#--------------------------------------------------------------------------------
VSHOME  = ../../..
STLDIR  = /usr/include/STL
BINDIR  = $(VSHOME)/bin
LIBDIR  = $(VSHOME)/lib
SRCDIR  = $(VSHOME)/src
COREDIR = $(SRCDIR)/Core
SERVDIR = $(SRCDIR)/server
TOSDIR  = $(SERVDIR)/theoneserver
GSDIR   = $(SERVDIR)/gameserver
DBDIR	= $(SERVDIR)/database


#--------------------------------------------------------------------------------
# General Rules
#--------------------------------------------------------------------------------
.SUFFIXES : .cpp .tos.o .gs.o

CC       = g++
DEFS     = -D__LINUX__ -D_REENTRANT -D__DEBUG__
INCLUDES = -I$(STLDIR) -I$(COREDIR)
CCFLAGS  = -Wall -c -g
#CCFLAGS  = -Wall -c

TARGET1 = $(LIBDIR)/libTheOneServerPackets.a
TARGET2 = $(LIBDIR)/libGameServerPackets.a

OBJS1	= \
		GTOAcknowledgement.tos.o GTOAcknowledgementHandler.tos.o

OBJS2	= \
		GTOAcknowledgement.gs.o GTOAcknowledgementHandler.gs.o

SRCS	= $(OBJS1:.tos.o=.cpp)

.cpp.tos.o : 
	$(CC) $(CCFLAGS) $(DEFS) -D__THE_ONE_SERVER__ $(INCLUDES) -I$(TOSDIR) -I$(SERVDIR) -I$(DBDIR) -o $*.tos.o $<

.cpp.gs.o : 
	$(CC) $(CCFLAGS) $(DEFS) -D__GAME_SERVER__ $(INCLUDES) -I$(GSDIR) -I$(SERVDIR) -I$(DBDIR) -o $*.gs.o $<



#--------------------------------------------------------------------------------
# Actions
#--------------------------------------------------------------------------------

all : $(TARGET1) $(TARGET2)
#all : $(TARGET1)

alltheoneserver : $(TARGET1)

allgameserver : $(TARGET2)

$(TARGET1) : $(OBJS1)
	ar rc $@ $(OBJS1)

$(TARGET2) : $(OBJS2)
	ar r $@ $(OBJS2)

clean :
	rm -rf *.o

cleantheoneserver :
	rm -rf *.tos.o

cleangameserver :
	rm -rf *.gs.o

cleanall :
	rm -rf *.o $(TARGET1) $(TARGET2)

depall :
	gccmakedep  $(SRCS) $(INCLUDES)

dep :
	gccmakedep  $(SRCS) $(INCLUDES)

# DO NOT DELETE
GTOAcknowledgement.o: GTOAcknowledgement.cpp /usr/include/stdc-predef.h \
 GTOAcknowledgement.h ../../../src/Core/DatagramPacket.h \
 ../../../src/Core/Packet.h ../../../src/Core/Types.h \
 ../../../src/Core/types/SystemTypes.h /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Exception.h ../../../src/Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc ../../../src/Core/SocketInputStream.h \
 ../../../src/Core/Socket.h ../../../src/Core/SocketImpl.h \
 ../../../src/Core/SocketAPI.h ../../../src/Core/SocketOutputStream.h \
 ../../../src/Core/Datagram.h ../../../src/Core/PacketFactory.h
GTOAcknowledgementHandler.o: GTOAcknowledgementHandler.cpp \
 /usr/include/stdc-predef.h GTOAcknowledgement.h \
 ../../../src/Core/DatagramPacket.h ../../../src/Core/Packet.h \
 ../../../src/Core/Types.h ../../../src/Core/types/SystemTypes.h \
 /usr/include/c++/5/iostream \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 /usr/include/x86_64-linux-gnu/bits/wordsize.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs.h \
 /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h \
 /usr/include/c++/5/ostream /usr/include/c++/5/ios \
 /usr/include/c++/5/iosfwd /usr/include/c++/5/bits/stringfwd.h \
 /usr/include/c++/5/bits/memoryfwd.h /usr/include/c++/5/bits/postypes.h \
 /usr/include/c++/5/cwchar /usr/include/wchar.h /usr/include/stdio.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
 /usr/include/x86_64-linux-gnu/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h /usr/include/xlocale.h \
 /usr/include/c++/5/exception \
 /usr/include/c++/5/bits/atomic_lockfree_defines.h \
 /usr/include/c++/5/bits/char_traits.h \
 /usr/include/c++/5/bits/stl_algobase.h \
 /usr/include/c++/5/bits/functexcept.h \
 /usr/include/c++/5/bits/exception_defines.h \
 /usr/include/c++/5/bits/cpp_type_traits.h \
 /usr/include/c++/5/ext/type_traits.h \
 /usr/include/c++/5/ext/numeric_traits.h \
 /usr/include/c++/5/bits/stl_pair.h /usr/include/c++/5/bits/move.h \
 /usr/include/c++/5/bits/concept_check.h \
 /usr/include/c++/5/bits/stl_iterator_base_types.h \
 /usr/include/c++/5/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/5/debug/debug.h /usr/include/c++/5/bits/stl_iterator.h \
 /usr/include/c++/5/bits/ptr_traits.h \
 /usr/include/c++/5/bits/predefined_ops.h \
 /usr/include/c++/5/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h \
 /usr/include/c++/5/clocale /usr/include/locale.h \
 /usr/include/x86_64-linux-gnu/bits/locale.h /usr/include/c++/5/cctype \
 /usr/include/ctype.h /usr/include/x86_64-linux-gnu/bits/types.h \
 /usr/include/x86_64-linux-gnu/bits/typesizes.h /usr/include/endian.h \
 /usr/include/x86_64-linux-gnu/bits/endian.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap.h \
 /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
 /usr/include/c++/5/bits/ios_base.h /usr/include/c++/5/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/x86_64-linux-gnu/bits/sched.h \
 /usr/include/x86_64-linux-gnu/bits/time.h \
 /usr/include/x86_64-linux-gnu/bits/timex.h \
 /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
 /usr/include/x86_64-linux-gnu/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h \
 /usr/include/c++/5/bits/locale_classes.h /usr/include/c++/5/string \
 /usr/include/c++/5/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h \
 /usr/include/c++/5/ext/new_allocator.h /usr/include/c++/5/new \
 /usr/include/c++/5/bits/ostream_insert.h \
 /usr/include/c++/5/bits/cxxabi_forced.h \
 /usr/include/c++/5/bits/stl_function.h \
 /usr/include/c++/5/backward/binders.h \
 /usr/include/c++/5/bits/range_access.h \
 /usr/include/c++/5/bits/basic_string.h \
 /usr/include/c++/5/ext/alloc_traits.h \
 /usr/include/c++/5/bits/basic_string.tcc \
 /usr/include/c++/5/bits/locale_classes.tcc /usr/include/c++/5/stdexcept \
 /usr/include/c++/5/streambuf /usr/include/c++/5/bits/streambuf.tcc \
 /usr/include/c++/5/bits/basic_ios.h \
 /usr/include/c++/5/bits/locale_facets.h /usr/include/c++/5/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h \
 /usr/include/c++/5/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h \
 /usr/include/c++/5/bits/locale_facets.tcc \
 /usr/include/c++/5/bits/basic_ios.tcc \
 /usr/include/c++/5/bits/ostream.tcc /usr/include/c++/5/istream \
 /usr/include/c++/5/bits/istream.tcc /usr/include/c++/5/fstream \
 /usr/include/c++/5/bits/codecvt.h /usr/include/c++/5/cstdio \
 /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
 /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h \
 /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h \
 /usr/include/c++/5/bits/fstream.tcc \
 ../../../src/Core/types/PlayerTypes.h \
 ../../../src/Core/types/SystemTypes.h \
 ../../../src/Core/types/ObjectTypes.h \
 ../../../src/Core/types/CreatureTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/ZoneTypes.h \
 ../../../src/Core/types/QuestTypes.h ../../../src/Core/types/ShopTypes.h \
 ../../../src/Core/types/ItemTypes.h ../../../src/Core/types/GuildTypes.h \
 ../../../src/Core/types/WarTypes.h ../../../src/Core/types/ServerType.h \
 ../../../src/Core/Utility.h /usr/include/stdlib.h \
 /usr/include/x86_64-linux-gnu/bits/waitflags.h \
 /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
 /usr/include/x86_64-linux-gnu/sys/types.h \
 /usr/include/x86_64-linux-gnu/sys/select.h \
 /usr/include/x86_64-linux-gnu/bits/select.h \
 /usr/include/x86_64-linux-gnu/bits/sigset.h \
 /usr/include/x86_64-linux-gnu/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/x86_64-linux-gnu/bits/stdlib-float.h /usr/include/string.h \
 ../../../src/Core/Exception.h ../../../src/Core/StringStream.h \
 /usr/include/c++/5/list /usr/include/c++/5/bits/stl_list.h \
 /usr/include/c++/5/bits/list.tcc ../../../src/Core/SocketInputStream.h \
 ../../../src/Core/Socket.h ../../../src/Core/SocketImpl.h \
 ../../../src/Core/SocketAPI.h ../../../src/Core/SocketOutputStream.h \
 ../../../src/Core/Datagram.h ../../../src/Core/PacketFactory.h \
 ../../../src/Core/Properties.h /usr/include/c++/5/map \
 /usr/include/c++/5/bits/stl_tree.h /usr/include/c++/5/bits/stl_map.h \
 /usr/include/c++/5/bits/stl_multimap.h
