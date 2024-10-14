#include <stdio.h>
#include <fcntl.h> // For open()
#include <unistd.h> // For close()
#include "get_next_line.h" // Assuming this is your header for get_next_line

int	main(void)
{
	int		fd;
	char	*line;
	int		ret;

	// Open the file "test.txt" for reading
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	// Read and print each line until EOF
	line = get_next_line(fd);
    while (line != NULL)
	{
		printf("%s\n", line); // Print the line
		free(line); // Free the allocated line
        line = get_next_line(-1); // Read the next line
    }

	// Close the file
	close(fd);
	return (0);
}
