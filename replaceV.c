#include "shell.h"
/**
 * replace_exit_code - replaces $? with the exit code value
 * @w: pointer to word to replace in
 * @v: variable to replace
 * @value: value to replace with
 * @pos: position of variable in the word
 */
void replace_exit_code(char **w, const char *v, const char *value, char *pos)
{
    char exit_code_str[EXIT_CODE_STR_SIZE];
 
    snprintf(exit_code_str, EXIT_CODE_STR_SIZE, "%s", value);
    size_t new_len = _strlen(*w) - _strlen(v) + _strlen(exit_code_str);
    char *new_word = malloc((new_len + 1) * sizeof(char));

    if (new_word == NULL)
    {
        exit(EXIT_FAILURE);
    }

    _strncpy(new_word, *w, pos - *w);
    new_word[pos - *w] = '\0';
    _strcat(new_word, exit_code_str);
    _strcat(new_word, pos + _strlen(v));

    free(*w);
    *w = new_word;
}

/**
 * replace_process_id - replaces $$ with the process ID value
 * @word: pointer to word to replace in
 * @v: variable to replace
 * @val: value to replace with
 * @pos: position of variable in the word
 */
void replace_process_id(char **word, const char *v, const char *val, char *pos)
{
    char pid_str[PID_STR_SIZE];

    snprintf(pid_str, PID_STR_SIZE, "%s", val);
    size_t new_len = _strlen(*word) - _strlen(v) + _strlen(pid_str);
    char *new_word = malloc((new_len + 1) * sizeof(char));

    if (new_word == NULL)
    {
        exit(EXIT_FAILURE);
    }

    _strncpy(new_word, *word, pos - *word);
    new_word[pos - *word] = '\0';
    _strcat(new_word, pid_str);
    _strcat(new_word, pos + _strlen(v));

    free(*word);
    *word = new_word;
}

/**
 * replace_env_v - replaces $env with its value
 * @word: pointer to word to replace in
 * @var: variable to replace
 * @value: value to replace with
 * @pos: position of variable in the word
 */
void replace_env_v(char **word, const char *var, const char *value, char *pos)
{
    char *env_value = env_vars(value, environ);

    if (env_value != NULL)
    {
        size_t new_len = _strlen(*word) - _strlen(var) + _strlen(env_value);
        char *new_word = malloc((new_len + 1) * sizeof(char));

        if (new_word == NULL)
        {
            exit(EXIT_FAILURE);
        }

        _strncpy(new_word, *word, pos - *word);
        new_word[pos - *word] = '\0';
        _strcat(new_word, env_value);
        free(*word);
        *word = new_word;
    }
}

/**
 * replace_variable - replaces variables in arr_words with their values
 * @arr_words: array of words
 * @var: variable to replace
 * @value: value to replace with
 */
void replace_variable(char **arr_words, const char *var, const char *value)
{
    int i = 0;

    while (arr_words[i] != NULL)
    {
        char *pos = _strstr(arr_words[i], var);

        if (pos != NULL)
        {
            if (_strcmp(var, "$?") == 0)
            {
                replace_exit_code(&arr_words[i], var, value, pos);
            }
            else if (_strcmp(var, "$$") == 0)
            {
                replace_process_id(&arr_words[i], var, value, pos);
            }
            else if (_strcmp(var, "$") == 0 && _strlen(var) == 1)
            {
                replace_env_v(&arr_words[i], var, value, pos);
            }
        }
        i++;
    }
}
