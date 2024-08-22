#include "main.h"
/**
 * handle_sigint - Handles the SIGINT signal (Ctrl+C).
 * @sig: The signal number received (should be SIGINT).
 *
 * Description: This function is called when the SIGINT signal
 * is received by the program. It prints a message indicating
 * that the signal was caught and then exits the program.
 * The signal number is passed as an argument but is typically
 * not used in the function logic.
 */
void handle_sigint(int sig)
{
	printf("\nCaught signal %d. Exiting...\n", sig);
	exit(0);
}
