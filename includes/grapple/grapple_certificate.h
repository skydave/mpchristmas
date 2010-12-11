#ifndef GRAPPLE_CERTIFICATE_H
#define GRAPPLE_CERTIFICATE_H

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  char *serial;
  time_t not_before;
  time_t not_after;
  char *issuer;
  char *subject;
} grapple_certificate;

extern int grapple_certificate_dispose(grapple_certificate *);

#ifdef __cplusplus
}
#endif

#endif
