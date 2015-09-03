/* dispatch.c - parse query string and hand over to relevant functions. */

#include "_dispatch.h"

/* Uses constant VIEWPATH, defined at compile time. */
void dispatch( char *querystr, http_t *http ) {
    int i;

    if( strcmp( querystr, "" ) == 0 ) {
        strcpy( querystr, "index" );
        dispatch( querystr, http );
        return;
    }

    for( i = 0; i < NUMVIEWS; i++ ) {
        if( strcmp( dispatcher[ i ].name, querystr ) == 0 ) {
            http->data = dispatcher[ i ].function( );
            break;
        }
    }

    if( http->data == NULL ) {
        dispatch( "404", http );
    }
}

int countheads( char *path ) {

    DIR *dp = opendir( path );
    int count = 0;
    struct dirent *entry;
    const char * d_name;
    char *ext;
    char err[256];

    if( ! dp ) {
        sprintf( err, "Couldn't open directory '%s' to build dispatch table.\n" );
        perror( err );
    }
    while( 1 ) {
        entry = readdir( dp );
        if( ! entry ) {
            break;
        }
        d_name = entry->d_name;
        if( entry->d_type & DT_DIR ) {
            continue;
        }
        if( ( ext = strchr( d_name, '.' ) ) &&
            *( ext + 1 ) == 'h' ) {
            count++;
        }
    }
}
