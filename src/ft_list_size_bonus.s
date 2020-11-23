;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_list_size_bonus.s                               :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/23 11:46:24 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/23 11:46:27 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global	_ft_list_size

_ft_list_size:
	xor		rax, rax

loop:
	cmp		rdi, 0
	je		return
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		loop

return:
	ret
