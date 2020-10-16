# Practice how to convert C variables into MIPS data directives.
# uninitialised variable -> int i;      -> .space
# initialised variable   -> int i = 0;  ->

	.data

# prompt = "Enter a number:"
prompt:
        .asciiz "Enter a number:"
# int u; -> uninitialised -> .space
u:
        .space  4
# int v = 42; -> initialised -> .word
v:
        .word   42
# char w; -> uninitialised
w:
        .space  1
# char x = 'a'; -> initialised 
x:
        .byte   'a'
# double y; -> un
y:
        .space  8
# int z[20] -> un
z: 
        .space  80
# int numbers = {0, 1, 2, 3};
numbers: 
        .word   0 1 2 3
# char chs = {'a', 'b'};
chs:
        .byte   'a' 'b'