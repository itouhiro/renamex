renamex
=======
                              Time-stamp: <Dec 31 2012>
                              author: itouhiro


Description
-----------

rename all files to add/delete the extension '.xx'

This pronounces 'rename x'.


![add/delete extension](http://img.f.hatena.ne.jp/images/fotolife/i/itouhiro/20121231/20121231102637.gif)



Usage
-----

### setup

put a shortcut icon of 'renamex.exe' to

- (Windows7) `C:\Users\<YOUR USERNAME>\AppData\Roaming\Microsoft\Windows\SendTo`
- (WindowsXP) `C:\Documents and Settings\<YOUR USERNAME>\SendTo`

![SendTo Folder](http://img.f.hatena.ne.jp/images/fotolife/i/itouhiro/20121231/20121231103044.gif)


### rename files to add '.xx'

- select files in some filer (like Explorer)
- right-click -> SendTo -> renamex


### rename files to delete '.xx'

- select files in some filer (like Explorer)
- right-click -> SendTo -> renamex



Note
----

-   You can change the extension '.xx' with the command line option '-e'.

-   how to compile (with Cygwin)

        $ gcc -O2 -mwindows -o renamex.exe renamex.c ; strip renamex.exe



License
-------

MIT License

    Copyright (c) 2012 Itou Hiroki
    
    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the
    "Software"), to deal in the Software without restriction, including
    without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and/or sell copies of the Software, and to
    permit persons to whom the Software is furnished to do so, subject to
    the following conditions:
    
    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
