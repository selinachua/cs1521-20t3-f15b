# $t0 = i

        .text
main:
        li      $t0, 0          # int i = 0
while:
        bge     $t0, 10, end_while

        la      $t1, numbers    # $t1 = &numbers
        mul     $t2, $t0, 4     # $t2 = i * 4 = offset
        add     $t2, $t2, $t1   # $t2 = $t2 + $t1 = &numbers[i]
        lw      $t2, ($t2)      # *($t2) = *(&numbers[i])

if:
        bge     $t2, 0, end_if
        addi    $t2, $t2, 42    # num += 42

        la      $t1, numbers 
        mul     $t3, $t0, 4     # i * 4
        add     $t3, $t3, $t1   # $t3 = &numbers[i]
        sw      $t2, ($t3)      # numbers[i] = num;
end_if:

        addi    $t0, $t0, 1     # i++;
        j       while
end_while:

        jr      $ra             # return 0;

################
        .data
numbers:
        .word   0 1 2 -3 4 -5 6 -7 8 9