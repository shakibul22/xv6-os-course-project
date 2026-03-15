# xv6-riscv

A re-implementation of Dennis Ritchie's and Ken Thompson's Unix Version 6 (v6), adapted for a modern RISC-V multiprocessor using ANSI C.

Based on the original xv6 from MIT's [6.1810 Operating System Engineering](https://pdos.csail.mit.edu/6.1810/) course.

## Building and Running

### Prerequisites

- RISC-V GNU toolchain (`riscv64-unknown-elf-gcc` or `riscv64-none-elf-gcc`)
- QEMU compiled for `riscv64-softmmu`

Install on Ubuntu/Debian:

```bash
sudo apt install gcc-riscv64-unknown-elf qemu-system-misc
```

### Build and run

```bash
make qemu
```

To exit QEMU: press `Ctrl-A` then `X`.

## Custom System Calls

This fork adds two system calls beyond the standard xv6:

| System call | Number | Description |
|---|---|---|
| `getyear()` | 24 | Returns the current year (2026) |
| `getfreemem()` | 25 | Returns approximate free kernel memory in KB |

### User programs

- `getyear` — prints the current year
- `getfreemem` — prints free memory in KB

## Project Structure

```
kernel/     Kernel source (proc, vm, syscall, trap, fs, ...)
user/       User-space programs and libraries
mkfs/       Tool to build the initial filesystem image
```

## Adding a New System Call

1. Add `#define SYS_foo <number>` to `kernel/syscall.h`
2. Implement `sys_foo()` in `kernel/sysproc.c`
3. Add `extern` declaration and dispatch entry to `kernel/syscall.c`
4. Add prototype to `user/user.h`
5. Add `entry("foo")` to `user/usys.pl`
6. Add a user program under `user/foo.c` and register it in `Makefile`

## License

MIT — see [LICENSE](LICENSE).
