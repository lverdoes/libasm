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
	xor 	rcx, rcx
	xor		rdx, rdx
	xor		rax, rax

loop:
	mov 	dl, BYTE [rdi + rcx]
	cmp 	dl, BYTE [rsi + rcx]
	ja		return_below
	jb		return_above
	cmp		dl, 0
	je		return_equal
	inc		rcx
	jmp		loop

return_below:
	sub		dl, BYTE [rsi + rcx]
	mov		rax, rdx
	ret

return_above:
;	mov		dl, BYTE [rsi + rcx]
	sub		dl, BYTE [rsi + rcx]
	mov		rax, rdx
	ret

return_equal:
	xor		rax, rax
	ret
