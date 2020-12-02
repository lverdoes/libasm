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

;params:	rdi = char *str,    rsi = char *base

_ft_atoi_base:
	cmp     rdi, 0	                
	je      end						
	cmp     rsi, 0					
	je      end	
	push	r12
	push	r13
	push	r14
	push	r15
	xor		rax, rax					; ret = 0	
	xor     rcx, rcx           		 	; i = 0			index of *str
	xor     r15, r15            		; j = 0			index of *base
	xor		rdx, rdx           		 	; neg = 0		negative is false/off
	jmp		check_base

incr_base_index:
	add		r15, 1						; j++;

check_base:
	movsx	r10, BYTE [rsi + r15]		; r10 = base[j]
	cmp		r10, 0						; if (base[j] == '\0')
	je		end_of_base					; 		go to end of base 
	mov		r14, r15					; create a tmp index for base

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

end_of_base:
	cmp		r15, 1						; base should not be empty or size 1
	jle		end
	jmp		check_white_space

incr_white_space:
	add		rcx, 1						; i++

check_white_space:
	movsx	r10, BYTE [rdi + rcx]		; r10 = str[i]
	cmp		r10, 32						; check for space ' '
	je		incr_white_space
	cmp		r10, 9						; if str[i] < 9, it's not a whitespace
	jl		check_sign
	cmp		r10, 13						; if str[i] > 13, it's not a whitespace
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
	add		rcx, 1						; i++

atoi:
	movsx	r10, BYTE [rdi + rcx]		; r10 = str[i]
	cmp		r10, 0
	je		end
	xor		r12, r12					; k = 0, reset index for inner loop
	jmp		convert

incr_base_index_2:
	add		r12, 1

convert:								; loop through *base untill str[i] == base[k]
	movsx	r9, BYTE [rsi + r12]		; r9 = base[k]
	cmp		r9, 0
	je		end
	movsx	r11, BYTE [rdi + rcx]		; r11 = str[i]
	cmp		r11, r9						; if str[i] == base[k], go to calc_ret
	jne		incr_base_index_2

calc_ret:								; multiply and add up the index position
	imul	rax, r15					; ret = ret * base_len
	add		rax, r12					; ret = ret + k
	jmp		incr_str_index

end:
	cmp		rdx, 0
	je		return
	neg		rax

return:
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	ret
