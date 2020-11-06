        .text
main:
# row = $t0
# col = $t1
        li      $t0, 0          # row = 0
loop1:
        bge     $t0, 6, end_loop1

        li      $t1, 0          # col = 0
loop2:
        bge     $t1, 12, end_loop2

        la      $t2, flag
        mul     $t3, $t0, 12
        add     $t3, $t3, $t1 
        add     $t4, $t2, $t3   # &flag[row][col]
        lb      $t4, ($t4)      # $t4 = flag[row][col]

        li      $v0, 11
        move    $a0, $t4
        syscall

        addi    $t1, $t1, 1
        j       loop2
end_loop2:

        li      $v0, 11
        li      $a0, '\n'
        syscall

        addi    $t0, $t0, 1     # row++
        j       loop1  
end_loop1:

        jr      $ra

###########################
	.data
flag:
	.byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
	.byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
	.byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
	.byte '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.' '.'
	.byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'
	.byte '#' '#' '#' '#' '#' '.' '.' '#' '#' '#' '#' '#'