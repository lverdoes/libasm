;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_strcmp.s                                        :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/10/30 09:54:16 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/10/30 09:54:17 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global	_ft_strcmp

_ft_strcmp:						
	xor		rax, rax
	xor 	rcx, rcx
	xor 	rdx, rdx

loop:
	movsx 	rax, BYTE [rdi + rcx]
	movsx 	rdx, BYTE [rsi + rcx]
	cmp		rax, 0
	je		return
	cmp 	rax, rdx
	jne		return
	inc		rcx
	jmp		loop

return:
	sub		rax, rdx
	ret
