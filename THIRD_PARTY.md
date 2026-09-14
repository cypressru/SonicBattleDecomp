# Third-party source references

`tools/setup_gcc_cpp.sh` downloads the GNU EGCS 1.1.2 release from
<https://gcc.gnu.org/pub/gcc/releases/egcs-1.1.2/egcs-1.1.2.tar.gz> and combines its C++ frontend
with the complete `gcc_arm` code generator and support files from the pinned public `pret/agbcc` revision
`da598c1d918402c42c0c0d7128ba14567f3175e9`. These compiler sources are licensed under GNU GPL
version 2 or later; their original notices and COPYING files remain in the retained local source
tree. The repository distributes only the setup script and compatibility patch, not compiler
binaries. See `docs/cpp-tus.md` for the compatibility changes and matching evidence.

The reconstructed `src/libc/memcmp.c`, `memcpy.c`, and `memset.c` units correlate to the newlib
string routines distributed with the pinned `pret/agbcc` toolchain. They are governed by the
applicable newlib notice, including the following default notice for files without a more specific
embedded notice:

Copyright (c) 1994, 1997 Cygnus Solutions.
All rights reserved.

Redistribution and use in source and binary forms are permitted
provided that the above copyright notice and this paragraph are
duplicated in all such forms and that any documentation,
advertising materials, and other materials related to such
distribution and use acknowledge that the software was developed
at Cygnus Solutions.  Cygnus Solutions may not be used to
endorse or promote products derived from this software without
specific prior written permission.
THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
