;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_strcpy.s                                        :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/10/22 14:11:55 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/10/22 16:09:25 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global  _ft_strcpy

_ft_strcpy:
	xor 	rcx, rcx

loop:
	mov		dl, BYTE [rsi + rcx]
	mov		BYTE [rdi + rcx], dl
	cmp		BYTE dl, 0
	je		return
	inc		rcx
	jmp		loop

return:
	mov		rax, rdi
	ret
