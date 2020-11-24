#pragma once
#include "../header.h"

/*
* Taken from Careercup
*
* We can think about
- reducing the response time of the server
---- by using a distributed system to share the load based on geography
---- by using a central server but many caching servers at various geographical locations
---- what would be the right database design

- reducing the storage space
---- database design

- backup and failover

- security issues
---- prevent people from creating links to ---whatever---

- handling old/obsolete urls
---- may be, while creating the url we can say to the user that it will be deleted if the url is never used for more than say 3 years
---- may be allow the user to login and delete unused ones

- how a company like bit.ly is going to make profit out of this service! how can that be improved

- user friendly things
---- browser plugins to speed up creating links (youtube sharing has an option to create short urls)
---- giving report to user about the usage statistics
---- mobile app to create urls quickly

Redirect Part:

When you click on a link of any tiny url, an HTTP Request is sent to their server with the full URL, like http // bit.ly / b9 (not a real one).

They read the path part (here b9), which maps to their Database.

In the Database, they find the real URL. Then they issue a redirect, which is a HTTP 302 response and the target URL in the header.

Encoding Part:

One of the most popular URL shortening services simply take the ID in the database of the URL and then convert it to Base 62[a-zA-Z0-9].


import static org.testing.AssertJUnit.assertEquals ;

public class TinyURL {
    private static final String ALPHABET_MAP = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" ;
    private static final int BASE = ALPHABET_MAP.length() ;

    public static String encode ( int IndexNum ) {
        StringBuilder sb = new StringBuilder() ;

        while ( IndexNum > 0 ) {
            sb.append ( ALPHABET_MAP.charAt ( IndexNum % BASE ) ) ;
            IndexNum /= BASE ;
        }
        return sb.reverse().toString() ;
    }

    public static int decode ( String str ) {
        int Num = 0 ;

        for ( int i = 0, len = str.length(); i < len; i++ ) {
            Num = Num * BASE + ALPHABET_MAP.indexOf ( str.charAt(i) ) ;
        }
        return Num ;
    }

    public static void main ( String[] args ) {
        //System.out.println ( "Encoding for 123 is " + encode(123) ) ;
        //System.out.println ( "Decoding for b9 is " + decode ("b9" ) ) ;

        assertEquals ( "b9", encode(123) ) ;
        assertEquals ( 123, decode("b9") ) ;
    }
}
*/

// Implement me complete