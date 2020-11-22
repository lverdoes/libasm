;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_lst_push_front_bonus.s                          :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/21 20:17:43 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/21 20:17:44 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section	.data:
	%define SIZEOF_T_LIST 16

section .text:
	global	_ft_lst_push_front
	extern	_malloc

_ft_lst_push_front:					; rdi = **list, rsi = *data
	cmp		rdi, 0					; check if head exists
	je		return
	push	rdi						; save head
	push	rsi						; save data
	mov		rdi, 16					; param 1 = 16 (bytes for malloc)
	call	_malloc					; rax points to new mem
	pop		rsi
	pop		rdi
	cmp		rax, 0					; check if malloc was succesful
	je		ret						; return if malloc failed
	mov		[rax], rsi				; point 1st 8-byte block of new mem to argument data (rsi)
	mov		r8, [rdi]				; copy adres of head to r8
	mov		[rax + 8], r8			; put adres of (old) head in 2nd 8-byte block of new mem
	mov		[rdi], rax				; the new head of list is now the new mem

return:
	ret
