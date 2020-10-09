### MIPS Program to print the square of a number

        .text
main:
        # use $t0 as x, use $t1 as y

        # syscall steps:
        # 1. Right code inside $v0
        # 2. Right arguments 
        # 3. syscall
        li      $v0, 4
        la      $a0, prompt
        syscall

        li      $v0, 5
        syscall                 # scanf("%d", &$v0)
        move    $t0, $v0        # $t0 = $v0

        mul     $t1, $t0, $t0   # $t1 = $t0 * $t0

        li      $v0, 1
        move    $a0, $t1        # $a0 = y = $t1
        syscall

        jr      $ra             # return;

        .data
prompt:
        .asciiz "Enter a number: "