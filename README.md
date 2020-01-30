# Ft_print - @ Codam Coding College
My own made version of the famous printf. It includes the following specifiers.
`cspdiuxX%` and also with the following flags `-0.*# +`

#### How do I use it?
You can use it by including the `ft_printf.h` and compile by running `make`.
This will generate an library called `libftprinf.a`.

So run these commands in order.
```
git clone https://github.com/bdekonin/ft_printf.git
cd ft_printf
make
```
If you include the `libft.h` in your project. You can now compile with the `libft.a` and use my functions

#### Makefile Commands
- `make` - Used to compile everything. this will make object files and create a library out of it.
- `make clean` - This will remove any temporary files, including the objects files.
- `make fclean` - This command will first run `make clean` once finished, it will also remove the `libftprintf.a` file. It will also delete the objects folder.
- `make re` - This will be used to recompile everything. So it will remove any files it would normally have made. Then compile normally with `make`.
- `make compile` - Used to compile everything without typing it manually everytime. It will automatically compile with a file called `main.c`
