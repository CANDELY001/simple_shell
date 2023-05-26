#include "shell.h"
/**
 * replace_variable - function
 * @arr_words: parameter
 * @var: parameter
 * @value: parameter
 * 
*/
void replace_variable(char **arr_words, const char *var, const char *value)
{
    int i = 0;
    size_t new_len, char *new_word;

    while (arr_words[i] != NULL)
    {
        char *pos = _strstr(arr_words[i], var);
        if (pos != NULL)
        {
            if (_strcmp(var, "$?") == 0)
            {
                char exit_code_str[EXIT_CODE_STR_SIZE];
                snprintf(exit_code_str, EXIT_CODE_STR_SIZE, "%s", value);
                new_len = _strlen(arr_words[i]) - _strlen(var) + _strlen(exit_code_str);
                new_word = malloc((new_len + 1) * sizeof(char));

                if (new_word == NULL)
                {
                    exit(EXIT_FAILURE);
                }
                _strncpy(new_word, arr_words[i], pos - arr_words[i]);
                new_word[pos - arr_words[i]] = '\0';
                _strcat(new_word, exit_code_str);
                _strcat(new_word, pos + strlen(var));
                free(arr_words[i]);
                arr_words[i] = new_word;
            }
            else if (strcmp(var, "$$") == 0)
            {
                char pid_str[PID_STR_SIZE];
                snprintf(pid_str, PID_STR_SIZE, "%s", value);
                new_len = _strlen(arr_words[i]) - _strlen(var) + _strlen(pid_str);
                new_word = malloc((new_len + 1) * sizeof(char));

                if (new_word == NULL)
                {
                    exit(EXIT_FAILURE);
                }
                _strncpy(new_word, arr_words[i], pos - arr_words[i]);
                new_word[pos - arr_words[i]] = '\0';
                _strcat(new_word, pid_str);
                _strcat(new_word, pos + _strlen(var));
                free(arr_words[i]);
                arr_words[i] = new_word;
            }
            else if (_strcmp(var, "$") == 0 && _strlen(var) == 1)
            {
                char *env_value = env_vars(value, environ);

                if (env_value != NULL)
                {
                    new_len = _strlen(arr_words[i]) - _strlen(var) + _strlen(env_value);
                    new_word = malloc((new_len + 1) * sizeof(char));

                    if (new_word == NULL)
                    {
                        exit(EXIT_FAILURE);
                    }
                    _strncpy(new_word, arr_words[i], pos - arr_words[i]);
                    new_word[pos - arr_words[i]] = '\0';
                    _strcat(new_word, env_value);
                    free(arr_words[i]);
                    arr_words[i] = new_word;
                }
            }
        }
        i++;
    }
}
