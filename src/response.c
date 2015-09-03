/* response.c - forms the response for the web browser. */
#include "response.h"
#include "http.h"

void sendresponse( http_t *http ) {
    
    char httpfrmt[] = "Content-Type: %s;charset=utf-8\n\n\n%s\r\n";

    printf( httpfrmt, "text/html", http->data );
}
