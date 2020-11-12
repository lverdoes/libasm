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

_ft_read:
	mov		rax, 0x02000003
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
