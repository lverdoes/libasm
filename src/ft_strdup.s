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

;params		rdi = char *src

_ft_strdup:
	call 	_ft_strlen			; rax = ft_strlen(rdi)
	push	rdi					; save src
	mov		rdi, rax			; rdi = rax
	add		rdi, 1
	call	_malloc				; rax = malloc(rdi)
	cmp		rax, 0				; malloc check
	je		error
	mov		rdi, rax			; rdi = void *malloced byte
	pop		rsi					; rsi = src
	call	_ft_strcpy			; rax = ft_strcpy(rdi, rsi)
	ret

error:
	pop		rdi
	ret
