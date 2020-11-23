;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_list_push_front_bonus.s                         :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/23 18:25:27 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/23 18:25:33 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global	_ft_list_push_front
	extern	_malloc

_ft_list_push_front:				; rdi = **list, rsi = *data
	cmp		rdi, 0					; check if head exists
	je		return
	push	rdi
	push	rsi
	push	rbp						; *
	mov		rbp, rsp				; *
	sub		rsp, 16					; *
	mov		rdi, 16					; param 1 = 16 (bytes for malloc)
	call	_malloc					; rax points to new mem
	mov		rsp, rbp				; *
	pop		rbp						; *
	pop		rsi
	pop		rdi
	cmp		rax, 0					; check if malloc was succesful
	je		return					; return if malloc failed
	mov		[rax], rsi				; point 1st 8-byte block of new mem to argument data (rsi)
	mov		r8, [rdi]				; copy adres of head to r8
	mov		[rax + 8], r8			; put adres of (old) head in 2nd 8-byte block of new mem
	mov		[rdi], rax				; the new head of list is now the new mem

return:
	ret
