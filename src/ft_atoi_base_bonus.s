# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_atoi_base_bonus.s                               :+:    :+:             #
#                                                      +:+                     #
#    By: lverdoes <lverdoes@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/22 19:30:44 by lverdoes      #+#    #+#                  #
#    Updated: 2020/11/22 19:31:14 by lverdoes      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

section .text
    global  _ft_atoi_base

_ft_atoi_base:
    xor     rax, rax