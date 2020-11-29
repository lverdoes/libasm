# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_list_remove_if_bonus.s                          :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/29 16:50:42 by lverdoes      #+#    #+#                  #
#    Updated: 2020/11/29 23:59:05 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

section .text
	global	_ft_list_remove_if
	extern	_free

_ft_list_remove_if:         rdi = t_list **head, rsi = void *data_ref, rdx = cmp
	cmp		rdi, 0				;
	je		return
	cmp		rsi, 0
	je		return
	cmp		rdx, 0
	je		return
	mov		r9, [rdi]
	jmp		compare_element

next_element:
	mov		r8, r9
	mov		r9, [r9 + 8]
	
compare_element:
	cmp		r9, 0
	je		return
	push	rdi
	push	rsi
	push	rdx
	push	r8
	push	r9
	mov		rdi, [r9]
	call	rdx
	pop		r9
	pop		r8
	pop		rdx
	pop		rsi
	pop		rdi
	cmp		rax, 0				; if (rax)
	jne		next_element		; check next element
	cmp		r9, [rdi]			; if (r9 == *head)
	jne		link_element		; link prev to next
	mov		r10, [r9 + 8]		; r10 = (*head)->next
	mov		[rdi], r10			; *head = r10
	jmp		free_element

link_element:
	mov		r10, [r9 + 8]
	mov		[r8 + 8], r10
	
free_element:

	mov		r11, r9
	mov		r9, [r9 + 8]
	push	rdi
	push	rsi
	push	rdx
	push	r8
	push	r9
	mov		rdi, r11
	call	free
	pop		r9
	pop		r8
	pop		rdx
	pop		rsi
	pop		rdi
	jmp		compare_element
	
return:
	ret

; r8 = previous element
; r9 = current element
; r10 = tmp
;_ft_list_remove_if:
;	cmp rdi, 0
;	je return
;	cmp rsi, 0
;	je return
;	cmp rdx, 0
;	je return
;	mov r9, [rdi]		 ; r9 = first element of the list
;	jmp compare_loop
;next_element:
;	mov r8, r9			; previous = cur element
;	mov r9, [r9 + 8]	; cur = cur->next
;compare_loop:
;	cmp r9, 0			; check if the list is 0
;	je return
;	push rdx
;	push rsi
;	push rdi
;	push r8
;	push r9
;	mov rdi, [r9]		; put the data from the element in rdi
;	call rdx			; call the compare function
;	pop r9
;	pop r8
;	pop rdi
;	pop rsi
;	pop rdx
;	cmp rax, 0			; check if compare is equal
;	jne next_element	; if not equal, go to next_element
;	cmp r9, [rdi]		; check if it is the first element of the list
;	jne make_new_link	; if not, create a new link
;	mov rcx, [r9 + 8]	; *begin_list -> list
;	mov [rdi], rcx		; rdi is now the new begin of the list
;	jmp free_element
;make_new_link:
;	mov rcx, [r9 + 8]	; put cur->next in rcx
;	mov [r8 + 8], rcx	; link the previous with the next element
;free_element:
;	mov r10, r9			; put cur in tmp so it can be freed
;	mov r9, [r9 + 8]	; cur = cur->next
;	push rdx
;	push rsi
;	push rdi
;	push r8
;	push r9
;	mov rdi, r10		; put the temp in rdi for free argument
;	call _free			; free element
;	pop r9
;	pop r8
;	pop rdi
;	pop rsi
;	pop rdx
;	jmp compare_loop
;return:
;	ret