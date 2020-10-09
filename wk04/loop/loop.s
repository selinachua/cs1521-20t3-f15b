        .text
main:
        li      $t0, 24         
loop:
        bge     $t0, 42, end_loop

        li      $v0, 1
        move    $a0, $t0        # $a0 = $t0
        syscall

        addi    $t0, $t0, 3     # x = x + 3
        j       loop
end_loop:

        jr      $ra             # return;

        .data




        li      $t0, 0          # i = 0;
loop:
        bge     $t1, $t0, end_loop 

        li      $t1, 0          # j = 0;
loop2:
        bge     ..., end_loop2 

        ...

        addi    $t1, $t1, 1     #j++;
        j       loop2
end_loop2:
        
        addi    $t0, $t0, 1     # i++;
        j       loop
end_loop: