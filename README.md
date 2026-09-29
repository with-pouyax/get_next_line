# get_next_line

A 42 C exercise that returns the next line from a file descriptor on each call. It combines buffered reads with a static remainder for later calls.

## Interface

```c
char *get_next_line(int fd);
```

The caller frees each returned line. `NULL` marks end of file or a read/allocation error. Set `BUFFER_SIZE` at compile time or use the header default.

## Run the included harness

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
./gnl
```

The included [`main.c`](main.c) reads the repository's [`test.txt`](test.txt) and additionally checks that each line ends in `1`; it does not accept a filename argument. To use the line reader in another program, compile the two implementation files with your own main.

**Current scope:** The implementation uses one static buffer, so it should not be presented as independently maintaining multiple file descriptors. [License](LICENSE).
