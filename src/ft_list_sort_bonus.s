;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_list_sort_bonus.s                               :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/22 10:36:41 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/22 21:51:54 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section	.text
	global	_ft_list_sort

;params		rdi = t_list **head, rsi = int (*cmp)()

_ft_list_sort:
	cmp		rsi, 0					; if (!rsi)
	je		return					;	return
	cmp		rdi, 0					; if (!rdi)
	je		return					;	return
	push	r12
	push	r13
	push	r14
	mov		r10, [rdi]				; r10 = *head
	mov		rdi, [rdi]				; rdi = *head
	jmp		check_end

go_to_next:
	mov		rdi, [rdi + 8]			; rdi = rdi->next

check_end:
	cmp		rdi, 0					; if (!rdi)
	je		return					;	return

compare_element:
	mov		r11, [rdi + 8]			; r11 = rdi->next
	cmp		r11, 0					; if (!r11)
	je		return					; 	return
	push	rdi;					; save rdi
	push	rsi;					; save rsi
	mov		r14, rsi				; r14 = cmp()
	mov		rdi, [rdi]				; rdi = rdi->content
	mov		rsi, [r11]				; rsi = rdi->next->content
	call	r14						; cmp(rdi, rsi)
	pop		rsi						; retrieve rsi
	pop		rdi						; retrieve rdi
	cmp		rax, 0					; if (!cmp)
	je		go_to_next				; 	restart loop for next elements
	jg		swap					; swap if rdi is greater than rsi
	jmp		go_to_next				; restart loop for next elements

swap:
	mov		r12, [rdi]				; set the first element in tmp1
	mov		r13, [r11]				; set the second element in tmp2
	mov		[r11], r12				; set tmp1 in second element
	mov		[rdi], r13				; set tmp2 in first element
	mov		rdi, r10				; 
	jmp		compare_element

return:
	pop		r14
	pop		r13
	pop		r12
	mov		rax, 0
	ret
