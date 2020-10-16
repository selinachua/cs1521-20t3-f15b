# $t0 = i


        .text
main:
        li      $t0, 0          # int i = 0;
while:
        bge     $t0, 10, end_while

        # la      $t1, numbers    # $t1 = &numbers
        # mul     $t2, $t0, 4     # $t2 = i * 4 = offset
        # add     $t2, $t2, $t1   # $t2 = $t2 + $t1 = &numbers[i]
        # lw      $t2, ($t2)      # *($t2) = *(&numbers[i])

        mul     $t1, $t0, 4      # $t1 = i * 4
        lw      $t1, numbers($t1)       # *(numbers + $t1)
        
        li      $v0, 1          # $v0 = 1
        move    $a0, $t2        # $a0 = num
        syscall

        addi    $t0, $t0, 1     # i++;
        j       while
end_while:

        jr      $ra

###############################
        .data
numbers:
        .word   0 1 2 3 4 5 6 7 8 9