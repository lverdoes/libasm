;# **************************************************************************** #
;#                                                                              #
;#                                                         ::::::::             #
;#    ft_read.s                                          :+:    :+:             #
;#                                                      +:+                     #
;#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
;#                                                    +#+                       #
;#    Created: 2020/11/11 15:57:42 by lverdoes      #+#    #+#                  #
;#    Updated: 2020/11/11 15:57:43 by lverdoes      ########   odam.nl          #
;#                                                                              #
;# **************************************************************************** #

section .text
	global  _ft_read
	extern	___error

;params		rdi = int fildes, rsi = void *buf, rdx = size_t nbyte

_ft_read:					
	mov		rax, 0x02000003			; move syscall number for read to rax
	syscall							; rax = read(rdi, rsi, rdx)
	jc		error
	ret

error:
	sub		rsp, 8					; stack alignment
	mov		r8, rax					; save read return in r8
	call	___error
	mov		[rax], r8				; move r8 into errno ptr
	add		rsp, 8					; stack alignment
	mov		rax, -1
	ret
