;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_list_push_front_bonus.s                         :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/23 18:25:27 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/29 17:01:59 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global	_ft_list_push_front
	extern	_malloc

;params:	rdi = **head, rsi = *data

_ft_list_push_front:
	cmp		rdi, 0					; if (!head)
	je		return					; 	return
	push	rdi						; save rdi
	push	rsi						; save rsi
	sub		rsp, 8					; stack alignment
	mov		rdi, 16					; rdi = 16
	call	_malloc					; rax = malloc(rdi)
	add		rsp, 8					; stack alignment
	pop		rsi						; retrieve rsi
	pop		rdi						; retrive rdi
	cmp		rax, 0					; if (!rax)
	je		return					; 	return if malloc failed
	mov		[rax], rsi				; rax->content = rsi
	mov		r8, [rdi]				; r8 = *head
	mov		[rax + 8], r8			; rax->next = *head
	mov		[rdi], rax				; *head = rax

return:
	ret
