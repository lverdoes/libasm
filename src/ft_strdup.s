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
	push	rbp
	mov		rbp, rsp
	sub		rsp, 8
	mov		[rsp], rdi
	call 	_ft_strlen		; get len
	mov		rdi, rax
	inc		rdi
	call	_malloc			; call malloc with argument rdi (strlen + 1)
	cmp		rax, 0			; malloc error check
	je		return			; if malloc error, exit
	mov		rdi, rax		; rdi now points to dst
	mov		rsi, [rsp]		; rsi now points to src
	call	_ft_strcpy		; copy rsi to rdi and rax points to dst
return:
	add		rsp, 8
	mov		rsp, rbp
	pop		rbp
	ret
