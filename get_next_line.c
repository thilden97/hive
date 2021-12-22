/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_my.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:51:05 by thilden           #+#    #+#             */
/*   Updated: 2021/12/22 18:35:03 by thilden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_appendline(char **saved, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*saved)[len] != '\n' && (*saved)[len] != '\0') /* len kasvaa niin kauan kunnes rivinvaihto tai null terminaattori loytyy */
		len++;
	if ((*saved)[len] == '\n') /*string indexit alkavat paikasta "0". Lenin arvo on esimerkissa "koira" 5, "k" loytyy kohdasta 0 ja "a" kohdasta 4. rivinvaihdon paikka olisi 5 joten tassa se osoittaa siihen*/
	{
		*line = ft_strsub(*saved, 0, len); /*siirramme tekstin/linen jonka loysimme ennen rivinvaithoa muuttujaan "line"*/
		temp = ft_strdup(&((*saved)[len + 1])); /*tassa siirramme rivinvaihdon jalkeisen tiedon talteen temp muuttujaan*/
		free(*saved); /*jalleen vapautamme tilaa muistivuotojen estamiseksi koska temp pitaa jo tarvitsemamme tiedon sisallaan*/
		*saved = temp; /*palautamme jalleen lukemamme tiedon muuttujaan saved tyhjennyksen jalkeen */
		if ((*saved)[0] == '\0')
			ft_strdel(saved); /* aiemmin laitoimme temppiin kaiken rivinvaihdon jalkeisein sisallon ja tallensimme muuttujaan saved, jos ei ole enaa mitaan luettavaa vaan olemme valmiita niin ehto tulee tayteen, talloin poistamme kaiken mallocoidun tiedon muistivuotojen estamiseksi*/
	}
	else /* tama tulee voimaan kun olemme paasseet linen  loppuun ja ei ole enempaa luettavaa talloin palautamme "1" ja meidan ei tarvitse ajaa ohjelmaa enempaa*/
	{
		*line = ft_strdup(*saved);
		ft_strdel(saved); /* poistaa kaiken tiedon savedista ja tekee siita nullin, jolloin mennaan takaisin ft_outputiin ja ajetaan ohjelma uudelleen tiedolla  saved[fd] on null ja ja ohjelman suoritus loppuu ft_outputtiin siihen etta saved on NULL jolloin palautusarvo on "0"*/
	}
	return (1); /*returnataan 1 kun kaikki ok, line on loytynyt*/
}

static int	ft_output(char **saved, char **line,  int ret, int fd)
{
	if (ret < 0)
		return (-1); /* tama tarkistaa onko tullut virhetta filua luettaessa, jos on niin palauttaa -1 eli virhe message*/
	else if (ret == 0 && saved[fd] == NULL) /* jos filu on luettu loppuun niin palautetaan 0*/
		return (0);
	else
		return (ft_appendline(&saved[fd], line)); /* jos on luettavaa yha eika mikaan ole mennyt pieleen, kutsutaan seuraavaa apufunktiota*/
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*temp;
	char		buff[BUFF_SIZE + 1];
	static char	*saved;

	if (fd < 0 || FD_BUFF < 1 || BUFF_SIZE < 1 || fd > FD_BUFF || line == NULL)
		return (-1);
	ret = read(fd, buff, BUFF_SIZE); /* lukee buff sizen verran filusta fd ja lisaa luetun sisallon muuttujaan buff ja tallentaa luetun maaran numerona muuttujaan ret*/
	while (ret > 0) /* lukee niin kauan kun sisaltoa loytyy buff sizen verran kerrallaan, viimeisella kierroksella ei ole enaa luettavaa joten siirrymme palauttamaan luetun*/
	{
		buff[ret] = '\0'; /* muuttujaan buff, paikkaaan ret lisataan null terminaattori*/
		if (saved[fd] == NULL) /* tama ehto tulee tayteen vain ensimmaisella kierroksella, tarkastamme etta muuttuja johon tallennetaan aina missa mennaan on tyhja*/
			saved[fd] = ft_strdup(buff); /* tassa tallennetaan staattiseen muuttujaan jo luetut characterit*/
		else /*tama looppi on meidan paa looppi jota loopataan kunnes kaikki on luettu*/
		{
			temp = ft_strjoin(saved[fd], buff); /*tallennetaan valiaikaiseen muuttujaan sisaltoa  jota ollaan luettu, jokaisella kierroksella tama kasvaa*/
			free(saved[fd]); /*vapautetaan tilaa muistivuotojen estamiseksi*/
			saved[fd] = temp; /*otetaan valiaikaisesta muistista tieto takaisin staattiseen muuttujaan jotta tiedamme missa mennaan*/
		}
		if (ft_strchr(saved[fd], '\n'))  /*etsitaan strchr funktiolla rivinvaihtoa tekstista*/
			break ; /*lopettaa loopin koska loysimme yhen rivinvaihdon paasemme nyt viimeiseen riviin funktiossa*/
	}
	return (ft_output(saved, line, ret, fd)); /*tahan paasemme vasta kun olemme loytaneet rivinvaihdon tai kun tiedosto on luettu loppuun tai jos lukemisessa on tapahtunut virhe*/
}
