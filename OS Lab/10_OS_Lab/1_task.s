	.file	"1_task.c"
	.text
	.section	.rodata
.LC0:
	.string	"received SIGUSR1"
.LC1:
	.string	"received SIGKILL"
.LC2:
	.string	"received SIGSTOP"
	.text
	.globl	handler_siguser1
	.type	handler_siguser1, @function
handler_siguser1:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$10, -4(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L5
.L2:
	cmpl	$9, -4(%rbp)
	jne	.L4
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L5
.L4:
	cmpl	$19, -4(%rbp)
	jne	.L5
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L5:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	handler_siguser1, .-handler_siguser1
	.section	.rodata
.LC3:
	.string	"\ncan't catch SIGUSR1"
.LC4:
	.string	"\ncan't catch SIGKILL"
.LC5:
	.string	"\ncan't catch SIGSTOP"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$268435456, -24(%rbp)
	leaq	handler_siguser1(%rip), %rax
	movq	%rax, -160(%rbp)
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$10, %edi
	call	sigaction@PLT
	cmpl	$-1, %eax
	jne	.L7
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L7:
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$9, %edi
	call	sigaction@PLT
	cmpl	$-1, %eax
	jne	.L8
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L8:
	leaq	-160(%rbp), %rax
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$19, %edi
	call	sigaction@PLT
	cmpl	$-1, %eax
	jne	.L10
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L10:
	call	getpid@PLT
	movl	$10, %esi
	movl	%eax, %edi
	call	kill@PLT
	movl	$2, %edi
	call	sleep@PLT
	call	getpid@PLT
	movl	$19, %esi
	movl	%eax, %edi
	call	kill@PLT
	movl	$2, %edi
	call	sleep@PLT
	call	getpid@PLT
	movl	$9, %esi
	movl	%eax, %edi
	call	kill@PLT
	jmp	.L10
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
