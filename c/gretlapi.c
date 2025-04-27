#include <gretl/libgretl.h>
#include <gretl/gretl_win32.h>

#if (defined __GNUC__) && !(defined __clang__)
# define COMPILER_IDENT "GCC " __VERSION__
#elif (defined __GNUC__) && (defined __clang__)
# define COMPILER_IDENT __VERSION__
#elif (defined _MSC_VER) && !(defined __clang__)
# define COMPILER_IDENT _MSC_VER
#elif (defined __VERSION__)
# define COMPILER_IDENT __VERSION__
#else
# define COMPILER_IDENT 0
#endif

int main (void)
{
	gretl_bundle *b = NULL;
    PRN *prn = NULL;
	int err = 0;

	libgretl_init();
#if defined(_WIN32)
    win32_cli_read_rc();
#else
    cli_read_rc();
#endif

#if defined(_MSC_VER) && !(defined __clang__)
    printf("compiler used: MSC v.%d\n", COMPILER_IDENT);
#else
    printf("compiler used: %s\n", COMPILER_IDENT);
#endif
	printf("libgretl_version: %d\n\n", libgretl_version());

	b = get_sysinfo_bundle(&err);
	if (!err) {
		prn = gretl_print_new(GRETL_PRINT_STDOUT, NULL);
		err = gretl_bundle_print(b, prn);
		gretl_print_destroy(prn);
	}

	libgretl_cleanup();

	return 0;
}
