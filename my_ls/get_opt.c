/*
**
*/
#include "my_ls.h"

/*
**
*/

t_opt* init_opt()
{
    return (t_opt*)my_init(sizeof(t_opt));
}

int get_opt_int(char c)
{
    t_opt_list opt[]=
    {
        {'a', OPT_a},
        {'t', OPT_t},
        {'R', OPT_R},
        
        {0,0}
    };
    t_opt_list* temp = opt;

    while (temp->opt_char != 0)
    {
        if (temp->opt_char == c)
        {
            return (temp->opt_int);
        }
        temp += 1;
    }

    return 0;
}

void set_option(t_opt* opt, char* str)
{
    int index = 0;

    while (str[index] != '\0')
    {
        opt->options |= get_opt_int(str[index]);
        index += 1;
    }
}

t_opt* get_opt(int ac, char** av)
{
    t_opt* opt = init_opt();
    int index = 0;

    while (index < ac)
    {
        if (is_option(av[index]) == 1)
        {
            set_option(opt, av[index] + 1);
        }
        index += 1;
    }

    return opt;
}