Name: brltty
Version: 4.1
Release: 1

Group: System Environment/Daemons
License: GPL
Vendor: The BRLTTY Team
Packager: Dave Mielke <dave@mielke.cc>
URL: http://mielke.cc/brltty/
Source: http://mielke.cc/brltty/releases/%{name}-%{version}.tar.gz

BuildRequires: autoconf >= 2.53
BuildRequires: make
BuildRequires: gcc
BuildRequires: /bin/sh
BuildRequires: /bin/ln
BuildRequires: /usr/bin/ld
BuildRequires: /sbin/ldconfig
BuildRequires: /usr/bin/ranlib
BuildRequires: /usr/bin/ar
BuildRequires: /usr/bin/awk
BuildRequires: /usr/bin/bison
BuildRequires: /usr/bin/install
BuildRequires: glibc-devel
BuildRequires: Pyrex
BuildRequires: tcl
BuildRequires: gcc-java

BuildRoot: %{_tmppath}/%{name}-%{version}-InstallRoot
%define _bindir /bin
%define _sbindir /sbin
%define _libdir /lib
%define _sysconfdir /etc

AutoProv: 1

AutoReq: 1
Requires: /bin/sh

Summary: Braille display driver for Linux/Unix.
%description
BRLTTY is a background process (daemon) which provides access to
the console screen (when in text mode) for a blind person using a
refreshable braille display.  It drives the braille display, and
provides complete screen review functionality.  Some speech capability
has also been incorporated.

Install this package if you use a refreshable braille display.

%package -n brlapi
Version: 0.5.4
Group: Applications/System
License: LGPL

AutoProv: 1

AutoReq: 1

Summary: Appliation Programming Interface for BRLTTY.
%description -n brlapi
This package provides the run-time support for the Application
Programming Interface to BRLTTY.

Install this package if you have an application
which directly accesses a refreshable braille display.

%package -n brlapi-caml
Version: 0.5.4
Group: Applications/System
License: LGPL

AutoProv: 1

AutoReq: 1

Summary: Caml bindings for BrlAPI.
%description -n brlapi-caml
This package provides the Caml bindings for BrlAPI,
which is the Application Programming Interface to BRLTTY.

Install this package if you have a Caml application
which directly accesses a refreshable braille display.

%package -n brlapi-java
Version: 0.5.4
Group: Applications/System
License: LGPL

AutoProv: 1

AutoReq: 1

Summary: Java bindings for BrlAPI.
%description -n brlapi-java
This package provides the Java bindings for BrlAPI,
which is the Application Programming Interface to BRLTTY.

Install this package if you have a Java application
which directly accesses a refreshable braille display.

%package -n brlapi-python
Version: 0.5.4
Group: Applications/System
License: LGPL

AutoProv: 1

AutoReq: 1

Summary: Python bindings for BrlAPI.
%description -n brlapi-python
This package provides the Python bindings for BrlAPI,
which is the Application Programming Interface to BRLTTY.

Install this package if you have a Python application
which directly accesses a refreshable braille display.

%package -n brlapi-tcl
Version: 0.5.4
Group: Applications/System
License: LGPL

AutoProv: 1

AutoReq: 1

Summary: Tcl bindings for BrlAPI.
%description -n brlapi-tcl
This package provides the Tcl bindings for BrlAPI,
which is the Application Programming Interface to BRLTTY.

Install this package if you have a Tcl application
which directly accesses a refreshable braille display.

%package -n brlapi-devel
Version: 0.5.4
Group: Development/System
License: LGPL

AutoProv: 1

AutoReq: 1
Requires: brlapi = 0.5.4

Summary: Headers, static archive, and documentation for BrlAPI.
%description -n brlapi-devel
This package provides the header files, static archive, shared object
linker reference, and reference documentation for BrlAPI (the
Application Programming Interface to BRLTTY).  It enables the
implementation of applications which take direct advantage of a
refreshable braille display in order to present information in ways
which are more appropriate for blind users and/or to provide user
interfaces which are more specifically atuned to their needs.

Install this package if you're developing or maintaining an application
which directly accesses a refreshable braille display.

%prep
# %setup -n %{name}-%{version}
%setup -n brltty-4.1

%build
%configure --disable-relocatable-install --with-install-root="${RPM_BUILD_ROOT}" --disable-gpm --without-flite --without-mikropuhe --without-swift --without-theta --without-viavoice --without-libbraille --without-curses --without-x --with-braille-driver=-tt
make

directory="doc"
mkdir -p "${directory}"
for file in `find . \( -path "./${directory}" -o -path ./Documents \) -prune -o \( -name 'README*' -o -name '*.patch' -o -name '*.txt' -o -name '*.html' -o -name '*.sgml' -o \( -path "./Bootdisks/*" -type f -perm +ugo=x \) \) -print`
do
   mkdir -p "${directory}/${file%/*}"
   cp -rp "${file}" "${directory}/${file}"
done

%install
make install
install -m 644 Documents/brltty.conf "${RPM_BUILD_ROOT}%{_sysconfdir}"

%clean
rm -fr "${RPM_BUILD_ROOT}"

%files
%defattr(-,root,root)
%{_bindir}/brltty
%{_bindir}/brltty-*
%{_bindir}/vstp
%{_libdir}/brltty
%{_sysconfdir}/brltty
%doc %{_mandir}/man1/*
%doc Documents/Manual-BRLTTY/English/*.{sgml,txt,html}
%doc LICENSE-GPL
%doc Documents/ChangeLog Documents/TODO
%doc doc/*
%config(noreplace) %verify(not size md5 mtime) %{_sysconfdir}/brltty.conf

%files -n brlapi
%defattr(-,root,root)
%{_libdir}/libbrlapi.so.*
%{_bindir}/xbrlapi
%doc Documents/Manual-BrlAPI/English/*.{sgml,txt,html}

%files -n brlapi-caml
/usr/lib/ocaml/brlapi

%files -n brlapi-java
/usr/share/java/*
/usr/lib/java/*

%files -n brlapi-python
/usr/lib/python2.5/site-packages/[bB]rlapi[-.]*

%files -n brlapi-tcl
/usr/lib/brlapi-0.5.4/libbrlapi_tcl.so
/usr/lib/brlapi-0.5.4/pkgIndex.tcl

%files -n brlapi-devel
%defattr(-,root,root)
%{_libdir}/libbrlapi.a
%{_libdir}/libbrlapi.so
%{_includedir}/brlapi.h
%{_includedir}/brlapi_*.h
%{_includedir}/brltty
%doc %{_mandir}/man3/*
%doc Documents/BrlAPIref

%changelog
* Thu Oct  8 2009 Dave Mielke <dave@mielke.cc> 4.1
+  General Changes:
      BRL_CMD_WINUP can go above the top row of the screen.
      Protect against NULL being given to snprintf() for a string.
      Change the "braille display offline/online" logs to DEBUG (from NOTICE).
      Fixes to status field initialization during a preferences file upgrade.
      Default status field selection should take into account 66-cell displays.
      Remove usbResetEndpoint().
      Resolve gcc-4.4 warnings.
      Resolve 64-bit warnings.
      C compilers needn't deallocate variable-size arrays until function return.
      Updates to the English Grade 2 contraction table.
      Updates to the German contraction table.
      Change ctbtest to expect input encoded in UTF-8.
      liblouis tables use y for 5-digit and z for 8-digit characters.
+  Baum Braille Driver Changes:
      Fix the support for display key #6 in PB2 mode.
+  EuroBraille Braille Driver Changes:
      Re-add some bindings forgotten during the driver rewrite for 3.10.
      Rework the bindings a bit for greater consistency and easier learning.
      Add new bindings to support as many commands as possible.
+  Papenmeier Braille Driver Changes:
      Interpret the EL66S Easy Access Bar correctly.
+  TSI Braille Driver Changes:
      Increase the write delay a bit.
+  Linux Screen Driver Changes:
      Give KD_FONT_OP_GET maximum (rather than reasonably high) font dimensions.
+  Java Bindings Changes:
      Define the DOTn constants as bytes (rather than as chars).
      JNI fixes for Sun-based JVMs.
      Load the JNI part automatically at startup.
+  Lisp Bindings Changes:
      Reference version 0.5.3 of BrlAPI.
+  Python Bindings Changes:
      Pyrex doesn't automatically convert C's NULL to Python's None.
      Translate BrlAPI exceptions into Python exceptions.
+  BrlAPI Changes:
      Remove all mention of key sets.
      Handle unbound key ranges.
      Fix an issue with TCP/IP socket connection on Windows.
      Handle the possibility of a different braille device after resuming.
+  Windows Changes:
      Fix a compile problem.
      The screen driver should refer to "consoles" rather than to "terminals".
+  Documentation Updates:
      Update the French manual from 3.10 to 4.0.
      Document that the EuroBraille Esys is supported.
      Update the supported FreedomScientific model lists.
      Clarify that --with-*-table sets the fallback (not the default) table.
      Change log fixes.
      Update the TSI braille driver's README.
      Add README.Bluetooth.
      The README for how to use a Seika with the TSI driver is no longer needed.
      E-mail address change for Nicolas Pitre.
      E-mail address change for Jean-Philippe Mengual.
+  Build Changes:
      The API socket directory should be created under the install root.
      Add the --disable-stripping configure option.
      Remove the --disable-preferences-menu configure option.
      Remove the --disable-table-selection configure option.
      Fedora no longer creates "/usr/lib/ocaml/stublibs/dllbrlapi_stubs.*".

