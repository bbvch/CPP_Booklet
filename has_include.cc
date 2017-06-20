#if __has_include(<unistd.h>)
    #define OPEN_SHARDED dlopen
#elif __has_include(<windows.h>)
    #define OPEN_SHARED LoadLibrary
#else
    #pragma error("loading shared libraries not supported");

int main(int, char**)
{
	
}