#include "main.h"
/**
 * see_elf - Checks if a file is an ELF file.
 * @identity: A pointer to an array containing the ELF magic numbers.
 * Description: If the file is not an ELF file - exit code 98.
 */

void see_elf(unsigned char *identity)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (identity[index] != 127 &&
            identity[index] != 'E' &&
            identity[index] != 'L' &&
            identity[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printing_new_stuff - Prints the magic numbers of an ELF header.
 * @identity: A pointer to an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */

void printing_new_stuff(unsigned char *identity)
{
    int index;

    printf("  Magic:   ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", identity[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printing_new_clas - Prints the class of an ELF header.
 * @identity: A pointer to an array containing the ELF class.
 */

void printing_new_clas(unsigned char *identity)
{
    printf("  Class:                             ");

    switch (identity[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", identity[EI_CLASS]);
    }
}

/**
 * data_display - Prints the data of an ELF header.
 * @identity: A pointer to an array containing the ELF class.
 */

void data_display(unsigned char *identity)
{
    printf("  Data:                              ");

    switch (identity[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", identity[EI_CLASS]);
    }
}

/**
 * version_display - Prints the version of an ELF header.
 * @identity: A pointer to an array containing the ELF version.
 */

void version_display(unsigned char *identity)
{
    printf("  Version:                           %d",
           identity[EI_VERSION]);

    switch (identity[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * osac_display - Prints the OS/ABI of an ELF header.
 * @identity: A pointer to an array containing the ELF version.
 */

void osac_display(unsigned char *identity)
{
    printf("  OS/ABI:                            ");

    switch (identity[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", identity[EI_OSABI]);
    }
}

/**
 * magic_display - Prints the ABI version of an ELF header.
 * @identity: A pointer to an array containing the ELF ABI version.
 */

void magic_display(unsigned char *identity)
{
    printf("  ABI Version:                       %d\n",
           identity[EI_ABIVERSION]);
}

/**
 * tpes_display - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @identity: A pointer to an array containing the ELF class.
 */

void tpes_display(unsigned int e_type, unsigned char *identity)
{
    if (identity[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf("  Type:                              ");

    switch (e_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

/**
 * entrypoint_display - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @identity: A pointer to an array containing the ELF class.
 */
void entrypoint_display(unsigned long int e_entry, unsigned char *identity)
{
    printf("  Entry point address:               ");

    if (identity[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (identity[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);

    else
        printf("%#lx\n", e_entry);
}

/**
 * ending - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void ending(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't close fd %d\n", elf);

        exit(98);
    }
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *header;
    int o, r;

    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    header = malloc(sizeof(Elf64_Ehdr));
    if (header == NULL)
    {
        ending(o);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    r = read(o, header, sizeof(Elf64_Ehdr));
    if (r == -1)
    {
        free(header);
        ending(o);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    see_elf(header->identity);
    printf("ELF Header:\n");
    printing_new_stuff(header->identity);
    printing_new_clas(header->identity);
    data_display(header->identity);
    version_display(header->identity);
    osac_display(header->identity);
    magic_display(header->identity);
    tpes_display(header->e_type, header->identity);
    entrypoint_display(header->e_entry, header->identity);

    free(header);
    ending(o);
    return (0);
}
