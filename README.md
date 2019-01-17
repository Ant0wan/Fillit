# Fillit [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg)

Algorithm which fits some Tetriminos together into tha smallest possible square.

It is written in C and according the 42's Norme coding standard.

Allowed functions were:
```
exit, open, close, write, read, malloc and free.
```

The makefile contains the following rules : all, clean, fclean et re. It compile a ./fillit using Wall, Wextra and Werror flags. Any other flag, and especially for optimising purposes, were strictly forbidden.

Example of forbidden flags:

-O or -O1
```
-fauto-inc-dec 
-fbranch-count-reg 
-fcombine-stack-adjustments 
-fcompare-elim 
-fcprop-registers 
-fdce 
-fdefer-pop 
-fdelayed-branch 
-fdse 
-fforward-propagate 
-fguess-branch-probability 
-fif-conversion 
-fif-conversion2 
-finline-functions-called-once 
-fipa-profile 
-fipa-pure-const 
-fipa-reference 
-fipa-reference-addressable 
-fmerge-constants 
-fmove-loop-invariants 
-fomit-frame-pointer 
-freorder-blocks 
-fshrink-wrap 
-fshrink-wrap-separate 
-fsplit-wide-types 
-fssa-backprop 
-fssa-phiopt 
-ftree-bit-ccp 
-ftree-ccp 
-ftree-ch 
-ftree-coalesce-vars 
-ftree-copy-prop 
-ftree-dce 
-ftree-dominator-opts 
-ftree-dse 
-ftree-forwprop 
-ftree-fre 
-ftree-phiprop 
-ftree-pta 
-ftree-scev-cprop 
-ftree-sink 
-ftree-slsr 
-ftree-sra 
-ftree-ter 
-funit-at-a-time
```

-O2
```
-falign-functions  -falign-jumps 
-falign-labels  -falign-loops 
-fcaller-saves 
-fcode-hoisting 
-fcrossjumping 
-fcse-follow-jumps  -fcse-skip-blocks 
-fdelete-null-pointer-checks 
-fdevirtualize  -fdevirtualize-speculatively 
-fexpensive-optimizations 
-fgcse  -fgcse-lm  
-fhoist-adjacent-loads 
-finline-small-functions 
-findirect-inlining 
-fipa-bit-cp  -fipa-cp  -fipa-icf 
-fipa-ra  -fipa-sra  -fipa-vrp 
-fisolate-erroneous-paths-dereference 
-flra-remat 
-foptimize-sibling-calls 
-foptimize-strlen 
-fpartial-inlining 
-fpeephole2 
-freorder-blocks-algorithm=stc 
-freorder-blocks-and-partition  -freorder-functions 
-frerun-cse-after-loop  
-fschedule-insns  -fschedule-insns2 
-fsched-interblock  -fsched-spec 
-fstore-merging 
-fstrict-aliasing 
-fthread-jumps 
-ftree-builtin-call-dce 
-ftree-pre 
-ftree-switch-conversion  -ftree-tail-merge 
-ftree-vrp
```

-O3
```
-fgcse-after-reload 
-finline-functions 
-fipa-cp-clone
-floop-interchange 
-floop-unroll-and-jam 
-fpeel-loops 
-fpredictive-commoning 
-fsplit-paths 
-ftree-loop-distribute-patterns 
-ftree-loop-distribution 
-ftree-loop-vectorize 
-ftree-partial-pre 
-ftree-slp-vectorize 
-funswitch-loops 
-fvect-cost-model 
-fversion-loops-for-strides
```

-O0, -Os, -Ofast, -Og, mainly those on the gcc.gnu.org <a href="https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html" target="_blank">onlinedocs</a>.

---

## Inputs

A Tetriminos is a 4-blocks geometric figure in the following format.
```
....
.##.
.#..
.#..

.##.
..##
....
....
```

Example of invalid format.
```
....
....
#.#.
.#.#

..o.
..#.
....
....
```

---



