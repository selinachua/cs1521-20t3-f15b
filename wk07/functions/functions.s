        .text
main:
        sw	$fp, -4($sp)
	la	$fp, -4($sp)
	sw	$ra, -4($fp)
	addi	$sp, $sp, -8
# x = $t0
# y = $t1
# i = $t6
# sum = $t3
        # TODO: Add code here
        li      $t6, 0          # i = 0
        
        li      $v0, 5
        syscall
        move    $t0, $v0        # scanf("%d", &x);

        li      $v0, 5
        syscall
        move    $t1, $v0        # scanf("%d", &y);

        # TODO: Add code here
        # 1. Set up arguments (correct values are in the correct $a registers)
        # 2. Call jal
        # 3. Set up return value 
        move    $a0, $t0        # $a0 = x = $t0 
        move    $a1, $t1        # $a1 = y
        jal     add_nums
        move    $t3, $v0        # $t3 = $v0

        move    $a0, $t3
        li      $v0, 1
        syscall

        li      $a0, '\n'
        li      $v0, 11
        syscall

        # TODO: Add code here
        lw	$ra, -4($fp)
   	la	$sp, 4($fp)
   	lw	$fp, ($fp)

        jr      $ra

add_nums:
        sw	$fp, -4($sp)
	la	$fp, -4($sp)
	sw	$ra, -4($fp)
	addi	$sp, $sp, -24

        li      $t6, 10         # i = 0

        add     $t5, $a0, $a1
        move    $v0, $t5        # $v0 = sum

	lw	$ra, -4($fp)
   	la	$sp, 4($fp)
   	lw	$fp, ($fp)

        jr      $ra             # return
        


#######################################
        .data