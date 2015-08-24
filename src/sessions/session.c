/* session.c - Provide session handlers for the Constitution framework. */

/* Core functions. */
int session_init( ) {
    /* Initialise a session. */
    
}

int session_free( ) {
    /* Destroy a session. */
    
}

int session_add( char *key, void *value ) {
    /* Add a key/value pair to a session. */
    
}

int session_rm( char *key ) {
    /* Remove a key/value pair from a session. */

}

/* Helper Functions. */
void *session_get_val( char *key ) {
    /* Retrieve a value from a session based on its key. */
    
}

int session_get( char *session_id, char *userid ) {
    /* Retrieve an existing session. */
    
}

int session_set_id( char *id ) {
    /* Set the ID for a session. */
    
}

int session_serialise( ) {
    /* Encode session data for storage. */
    
}

int session_deserialise( ) {
    /* Decode session data from storage. */
    
}

char *session_keyhash( ) {
    /* Generate a session id. */
}
