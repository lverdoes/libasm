;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_lst_size.s                                      :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/21 14:43:04 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/21 14:43:06 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global	_ft_lst_size

_ft_lst_size:
	xor		rax, rax

loop:
	cmp		rdi, 0
	je		return
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		loop

return:
	ret
