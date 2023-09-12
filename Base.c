#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAM_VERSION "1.0"

void printVersion()
{
    printf("Program Version: %s\n", PROGRAM_VERSION);
}

void printCodeToStdout(char *language)
{
    char *file_extension = "";

    if (strcmp(language, "Java") == 0)
    {
        printf("public class Main {\n\n    public static void main(String[] args) {\n        System.out.println(\"Hello, world!\");\n    }\n}\n");
    }
    else if (strcmp(language, "C") == 0)
    {
        printf("#include <stdio.h>\n\nint main() {\n    printf(\"Hello, world!\");\n    return 0;\n}\n");
    }
    else if (strcmp(language, "C++") == 0)
    {
        printf("#include <iostream>\n\nint main() {\n    std::cout << \"Hello, world!\" << std::endl;\n    return 0;\n}\n");
    }
    else if (strcmp(language, "Bash") == 0)
    {
        printf("#!/bin/bash\n\necho \"Hello, world!\"\n");
    }
    else
    {
        printf("The given language is not supported.\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    int printToStdout = 0;

    if (argc > 1)
    {
        if (strcmp(argv[1], "-v") == 0)
        {
            printVersion();
            return 0;
        }
        else if (argc > 2 && strcmp(argv[2], "--stdout") == 0)
        {
            printToStdout = 1;
        }

        char *language = argv[1];

        if (printToStdout)
        {
            printCodeToStdout(language);
        }
        else
        {
            char *file_extension = "";

            if (strcmp(language, "Java") == 0)
            {
                file_extension = ".java";
            }
            else if (strcmp(language, "C") == 0)
            {
                file_extension = ".c";
            }
            else if (strcmp(language, "C++") == 0)
            {
                file_extension = ".cpp";
            }
            else if (strcmp(language, "Bash") == 0)
            {
                file_extension = ".sh";
            }
            else
            {
                printf("The given language is not supported.\n");
                return 1;
            }

            char file_name[100];
            strcpy(file_name, language);
            strcat(file_name, file_extension);

            FILE *checkfile = fopen(file_name, "r");
            if (checkfile != NULL)
            {
                fclose(checkfile);
                printf("Error: File already exists: %s\n", file_name);
                return 1;
            }

            FILE *fp = fopen(file_name, "w");

            if (fp == NULL)
            {
                printf("Error creating file: %s\n", file_name);
                return 1;
            }

            if (strcmp(language, "Java") == 0)
            {
                fprintf(fp, "public class Main {\n\n    public static void main(String[] args) {\n        System.out.println(\"Hello, world!\");\n    }\n}\n");
            }
            else if (strcmp(language, "C") == 0)
            {
                fprintf(fp, "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, world!\");\n    return 0;\n}\n");
            }
            else if (strcmp(language, "C++") == 0)
            {
                fprintf(fp, "#include <iostream>\n\nint main() {\n    std::cout << \"Hello, world!\" << std::endl;\n    return 0;\n}\n");
            }
            else if (strcmp(language, "Bash") == 0)
            {
                fprintf(fp, "#!/bin/bash\n\necho \"Hello, world!\"\n");
            }

            fclose(fp);
            printf("File created successfully: %s\n", file_name);
        }
    }
    else
    {
        printf("Usage: %s language\nOptions: -v --stdout\n", argv[0]);
        printf("Available languages: Bash, C, C++, Java\n");
        return 1;
    }

    return 0;
}

