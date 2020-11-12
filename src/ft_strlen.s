;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_strlen.s                                        :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/09/29 15:03:35 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/09/29 15:03:37 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global	_ft_strlen

_ft_strlen:
	xor 	rax, rax				

loop:
	cmp 	BYTE [rdi + rax], 0
	je		return
	inc		rax
	jmp		loop

return:
	ret						
