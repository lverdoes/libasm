;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_write.s                                         :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/12 07:55:04 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/12 07:59:05 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global  _ft_write
	extern  ___error

;params		rdi = int fildes, rsi = const void *buf, rdx = size_t nbyte

_ft_write:
	mov		rax, 0x02000004			; move syscall number for write to rax
	syscall							; rax = write(rdi, rsi, rdx)
	jc		error
	ret

error:
	sub		rsp, 8					; stack alignment
	mov		r8, rax					; save write return in r8
	call	___error
	mov		[rax], r8				; move r8 into errno ptr
	add		rsp, 8					; stack alignment
	mov		rax, -1
	ret
