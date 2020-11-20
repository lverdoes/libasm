;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_strdup.s                                        :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/10/30 11:43:43 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/10/30 11:43:44 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global	_ft_strdup
	extern	_ft_strlen
	extern	_ft_strcpy
	extern	_malloc

_ft_strdup:
	call 	_ft_strlen
	push	rdi
	mov		rdi, rax		
	inc		rdi
	call	_malloc
	cmp		rax, 0
	je		error
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret

error:
	pop		rdi
	ret
