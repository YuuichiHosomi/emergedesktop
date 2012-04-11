#define CONFIG_WIDTH      280
#define CONFIG_WIDTH_2    140 // CONFIG_WIDTH/2
#define CONFIG_WIDTH_4    70  // CONFIG_WIDTH/4
#define CONFIG_HEIGHT     220

#define EMERGE_MAJOR_VERSION 6
#define EMERGE_MINOR_VERSION 0
#define EMERGE_RELEASE_VERSION 0

// As per http://gcc.gnu.org/onlinedocs/cpp/Stringification.html:
// "If you want to stringify the result of expansion of a macro argument, you
// have to use two levels of macros."
#ifndef STRINGIFY
#define STRINGIFY(s) TOSTRING(s)
#define TOSTRING(s) #s
#endif

#define POINT_VERSION STRINGIFY(EMERGE_MAJOR_VERSION.EMERGE_MINOR_VERSION.EMERGE_RELEASE_VERSION.BUILD_VERSION)
#define COMMA_VERSION EMERGE_MAJOR_VERSION,EMERGE_MINOR_VERSION,EMERGE_RELEASE_VERSION,BUILD_VERSION
