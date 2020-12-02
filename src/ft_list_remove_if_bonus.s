;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_list_remove_if_bonus.s                          :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/29 16:50:42 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/30 11:45:06 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global	_ft_list_remove_if
	extern	_free

;params: 	rdi = t_list **head, rsi = void *data_ref, rdx = cmp

_ft_list_remove_if:
	cmp		rdi, 0
	je		return
	cmp		rsi, 0
	je		return
	cmp		rdx, 0
	je		return
	mov		r9, [rdi]
	jmp		compare_element

next_element:
	mov		r8, r9				; r8 = r9 (save r8 as previous)
	mov		r9, [r9 + 8]		; r9 = r9->next (go to next)
	
compare_element:
	cmp		r9, 0				; if (!r9)
	je		return				;	return
	push	rdi					; store the **head
	push	rsi
	push	rdx
	push	r8
	push	r9
	mov		rdi, [r9]			; rdi = r9->content
	call	rdx					; compare r9 with rsi
	pop		r9
	pop		r8
	pop		rdx
	pop		rsi
	pop		rdi					; retrieve **head
	cmp		rax, 0				; check output return of cmp
	jne		next_element		; 	if not equal, next element
	cmp		r9, [rdi]			; if (r9 == *head)
	jne		link_element		; 	if not equal, link prev to next
	mov		r10, [r9 + 8]		; r10 = (*head)->next
	mov		[rdi], r10			; *head = r10
	jmp		free_element

link_element:
	mov		r10, [r9 + 8]		; r10 = r9->next
	mov		[r8 + 8], r10		; prev->next = r10
	
free_element:
	mov		r11, r9				; store r9 in a tmp
	mov		r9, [r9 + 8]		; r9 = r9->next
	push	rdi
	push	rsi
	push	rdx
	push	r8
	push	r9
	mov		rdi, r11			; rdi = r11
	call	_free				; free(rdi);
	pop		r9
	pop		r8
	pop		rdx
	pop		rsi
	pop		rdi
	jmp		compare_element
	
return:
	ret
