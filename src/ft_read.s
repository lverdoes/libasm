;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_read.s                                          :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/11 15:57:42 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/11 15:57:43 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global  _ft_read
	extern	___error

_ft_read:					; rdi = int fildes, rsi = void *buf, rdx = size_t nbyte
	mov		rax, 0x02000003	; move syscall number for read to rax
	syscall					; rax = read(rdi, rsi, rdx)
	jc		error
	ret

error:
;	push	rax
;	call	___error
;	pop		rax
;	mov		rax, -1
;	ret

	push	rbp
	mov		rbx, rax
	call	___error
	mov		[rax], rbx
	pop		rbp
	mov		rax, -1
	ret
