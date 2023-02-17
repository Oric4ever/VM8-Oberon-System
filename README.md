# VM8-Oberon-System
An Oberon System for the VM-8 computer, and a Linux emulator

This is the third version of a system for the VM-8 Computer : now it is written in Oberon-07 only, and the Turbo Modula-2 Reloaded compiler is not supported any more...

Short rationale for the abandon of Turbo Modula-2 : 

- firstly, the Turbo Modula-2 compiler actually required more than 64 KB (in order to run in the 64 KB address space, it used overlays, ie. the code of several modules shared the same location, these modules were loaded from disk each time a call or return required them to be present in memory), 
- secondly, I have been experimenting working with a small stack (1 KB typically), it cannot work with the Turbo Modula-2 compiler (due to some recursions in the linked-lists of the symbol table), whilst it can work with the Oberon compiler,
- and thirdly, I gave up providing a proper decompiled source of Turbo Modula-2 (because the use of variant records make the decompiling process such a hard puzzle to decipher).

The Oberon-07 compiler is derived from Project Oberon (http://www.projectoberon.com/) : roughly, it replaces the custom-RISC code generator with a new code generator that targets a modified Turbo Modula-2 Reloaded VM (some opcodes are modified, and some other opcodes have been added).

The firmware for the VM-8 computer (ie. the Modified Turbo Modula-2 Virtual Machine) is provided on the `MCodeOnAVR` repository.
Alternatively, the system can be run on Linux-type systems, with the provided (ugly) VM implementation for Linux.

<!---
TRY IT:

1. Download the virtual machine for Linux and compile it (make). It should work without modification on Linux, Android (in Termux), Windows (with Cygwin).

2. Download the zipped system disk and extract it (system.dsk) in the same directory as the virtual machine interpreters, it is an image of a FAT32 filesystem with my current small operating system pre-installed in it. You can check the contents of this image:

- file system.dsk reveals it has 128 reserved sectors (the system image is installed in the reserved sectors), apart from this it is a normal FAT32 filesystem.
- you can access the contents with the mtools on Linux, or mount this disk image (e.g sudo mount -o loop system.dsk /mnt). For convenience, this repository also shows many files of this disk (the Oberon compiler, the system sources, etc.).

3. Start the virtual machine, telling it to boot on the disk image:
./vm4 system.dsk

4. Try some examples:
- dir
- pipe <loadpath.txt  (this file contains the top level directory names that are looked up when you ask for a module to load (e.g dir and pipe are in SHELL.DIR)
- cd examples
- pipe <hello.obn (yeap this one is an Oberon module)
- obn hello (this compiles the Oberon module)
- hello (this runs the compiled module)
- root (go back to root dir)
- cd demo
- rushhour <level.030  (this solves a rushhour puzzle, and animates the solution)
- ...

-->

STATUS:
The system is up and running, it is able to compile itself and can be modified.
However, this is not the final released version yet, I intend to optimize the set of opcodes used in the VM. 
But for these experiments on the VM opcodes, it might be faster to have a cross-compiler in order to generate the VM and the system at the same time (this type of modification is currently very cumbersome to do on the target platform itself)...
So, I'm currently developing an Oberon compiler targetting LLVM's Intermediate Representation.
