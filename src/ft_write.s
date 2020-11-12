;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_write.s                                         :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/12 07:55:04 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/12 07:59:05 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global  _ft_write
	extern  ___error

_ft_write:
	mov		rax, 0x02000004
	syscall
	jc		error
	ret

error:
	push	rbp
	mov		rbx, rax
	call	___error
	mov		[rax], rbx
	pop		rbp
	mov		rax, -1
	ret
