;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_atoi_base_bonus.s                               :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/22 19:30:44 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/22 19:31:14 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global  _ft_atoi_base

_ft_atoi_base:                  		; rdi = char *str,    rsi = char *base
	cmp     rdi, 0	                
	je      end						
	cmp     rsi, 0					
	je      end	
	xor		rax, rax					; ret = 0	
	xor     rcx, rcx           		 	; i = 0		index of *str
	xor		rdx, rdx           		 	; negative is false/off
	xor     r15, r15            		; j = 0		index of *base
	jmp		check_base

incr_base_index:
	add		r15, 1

check_base:
	movsx	r10, BYTE [rsi + r15]
	cmp		r10, 0
	je		check_base_len
	mov		r14, r15

incr_check_base_dup:
	add		r14, 1

check_base_dup:
	movsx	r11, BYTE [rsi + r14]
	cmp		r11, 0
	je		check_invalid_chars
	movsx	r12, BYTE [rsi + r15]
	cmp		r11, r12
	je		end
	jmp		incr_check_base_dup

check_invalid_chars:
	movsx	r13, BYTE [rsi + r15]
	cmp		r13, 9
	je		end
	cmp		r13, 13
	je		end
	cmp		r13, 45
	je		end
	cmp		r13, 43
	je		end
	cmp		r13, 32
	je		end
	jmp		incr_base_index


check_base_len:
	cmp		r15, 1
	jle		end
	jmp		check_white_space

incr_white_space:
	add		rcx, 1

check_white_space:
	movsx	r10, BYTE [rdi + rcx]
	cmp		r10, 32
	je		incr_white_space
	cmp		r10, 9
	jl		check_sign
	cmp		r10, 13
	jg		check_sign
	jmp		incr_white_space

check_sign:
	movsx	r10, BYTE [rdi + rcx]
	cmp		r10, 45						; check minus '-'
	je		sign_negative
	cmp		r10, 43						; check plus '+'
	je		incr_str_index
	jmp		atoi						; else, start with numbers

sign_negative:
	mov		rdx, 1						; negative is true/on

incr_str_index:
	add		rcx, 1

atoi:
	movsx	r10, BYTE [rdi + rcx]
	cmp		r10, 0
	je		end
	xor		r12, r12					; index_2 for base
	jmp		convert

incr_base_index_2:
	add		r12, 1

convert:
	movsx	r9, BYTE [rsi + r12]
	cmp		r9, 0
	je		end
	movsx	r11, BYTE [rdi + rcx]
	cmp		r11, r9
	jne		incr_base_index_2

calc_ret:
	imul	rax, r15
	add		rax, r12
	jmp		incr_str_index

end:
	cmp		rdx, 0
	je		return
	neg		rax

return:
	ret
