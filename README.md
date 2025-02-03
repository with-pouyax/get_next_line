# get_next_line
![code](https://i.pinimg.com/736x/56/67/93/5667936906181a6fbe0501b471e2b5bd.jpg)

## Overview
`get_next_line` is a function that reads a file descriptor line by line until the end of the file (EOF). This project is part of the 42 curriculum and helps in understanding file I/O operations, buffer management, and memory allocation.

## Features
- Reads from a file descriptor one line at a time.
- Handles multiple file descriptors simultaneously.
- Manages memory efficiently to avoid leaks.
- Works with any buffer size defined by `BUFFER_SIZE`.

## Installation
Clone the repository:
```sh
git clone https://github.com/yourusername/get_next_line.git
cd get_next_line
```

## Usage
Compile with a main function:
```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```
Run the executable with a file:
```sh
./gnl input.txt
```

## Function Prototype
```c
char *get_next_line(int fd);
```
- `fd`: The file descriptor to read from.
- Returns the next line read from the file, or `NULL` if there is nothing more to read or an error occurs.

## Implementation Details
- Uses a static buffer to store read data between calls.
- Reads characters in chunks (`BUFFER_SIZE`) and appends them until a newline is found.
- Allocates memory dynamically to store the result.
- Handles edge cases like empty files, multiple newlines, and incorrect file descriptors.

## Example
```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main() {
    int fd = open("test.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd))) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Mandatory vs Bonus
### Mandatory
- Works for a single file descriptor.
- Reads one line at a time.

### Bonus
- Handles multiple file descriptors at the same time.
- Properly frees memory after each call.

## Allowed Functions
- `read`, `malloc`, `free`

## Notes
- Ensure `BUFFER_SIZE` is properly defined during compilation.
- Free allocated memory to prevent leaks.

## License
This project is under the MIT License.

## Author
**Pouya** - [GitHub](https://github.com/yourusername)
