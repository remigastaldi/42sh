/*
** alias.c for alias in /home/gastal_r/rendu/42sh/sources
**
** Made by
** Login   <gastal_r@epitech.net>
**
** Started on  Thu Jun  2 01:35:59 2016
** Last update	Thu Jun 02 14:44:28 2016 Full Name
*/

#include		"42sh.h"

char			**test_alias(t_plist *plist, char *cmd)
{
  t_alias		*alias;

  alias = plist->begin_a;
  if (alias == NULL)
    return (NULL);
  while (my_strcmp(alias->alias, cmd) != 0)
    {
      alias = alias->next;
      if (alias == NULL)
      	return (NULL);
    }
  return (alias->cmd);
}

void			add_alias(t_plist *list, char *alias, char *cmd)
{
  t_alias               *new;

  new = list->begin_a;
  if (!list)
    return;
  if ((new = malloc(sizeof(t_list))) == NULL)
    return;
  new->alias = my_strdup(alias);
  new->cmd = order_args(my_str_to_wordtab(cmd), -1, 2);
  new->prev = NULL;
  new->next = NULL;
  if (list->begin_a == NULL)
    {
      list->begin_a = new;
      list->end_a = new;
    }
  else
    {
      list->end_a->next = new;
      new->prev = list->end_a;
      list->end_a = new;
    }
}

void	add_alias_cmd(char **tab, t_plist *list)
{
  char	*alias;
  char	*cmd;
  int	i;

  alias = my_strdup(tab[1]);
  i = 2;
  while (tab[i])
  {
    alias = my_strcat(alias, " ", -1, -1);
    alias = my_strcat(alias, tab[i], -1, -1);
    i++;
  }
  i = 0;
  while (alias[i] != '\'')
    i++;
  cmd = (char *)alias + i + 1;
  alias[i - 1] = '\0';
  i = 0;
  while (cmd[i])
    i++;
  cmd[i - 1] = '\0';
  add_alias(list, alias, cmd);
}
