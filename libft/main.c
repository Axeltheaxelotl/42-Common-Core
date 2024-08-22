/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:16:31 by alanty            #+#    #+#             */
/*   Updated: 2024/03/04 18:19:30 by alanty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char transform(unsigned int index, char c)
{
    // Cette fonction simple retourne chaque caractère en majuscule
    if (c >= 'a' && c <= 'z')
        return c - 32; // Conversion en majuscule
    return c; // Renvoie le caractère inchangé s'il n'est pas en minuscule
}

int main()
{
    // Chaîne de caractères initiale
    char *str = "Bonjour, le monde!";
    
    // Appel de ft_strmapi avec la fonction de transformation
    char *result = ft_strmapi(str, &transform);

    if (result == NULL)
    {
        printf("Erreur lors de l'allocation mémoire.\n");
        return 1;
    }

    // Affichage de la chaîne transformée
    printf("Chaîne transformée: %s\n", result);

    // Libération de la mémoire allouée pour la nouvelle chaîne
    free(result);

    return 0;
}
