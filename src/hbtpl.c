#include "hbtpl.h"

// Set the x value for the Point object
HB_FUNC_STATIC( POINT_SETX )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p;

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
   p = hb_parptr( -1 );

   if( p )
   {
      p->x = hb_parni( 1 );
   }
   else
      hb_retni( 0 ); // raise an error ?
}

// Get the x value from the Point object
HB_FUNC_STATIC( POINT_GETX )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p;

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
   p = hb_parptr( -1 );

   if( p )
      hb_retni( p->x );
   else
      hb_retni( 0 ); // raise an error ?
}

// Set the y value for the Point object
HB_FUNC_STATIC( POINT_SETY )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p;

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
   p = hb_parptr( -1 );

   if( p )
   {
      p->y = hb_parni( 1 );
   }
   else
      hb_retni( 0 ); // raise an error ?
}

// Get the y value from the Point object
HB_FUNC_STATIC( POINT_GETY )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p;

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
   p = hb_parptr( -1 );

   if( p )
      hb_retni( p->y );
   else
      hb_retni( 0 ); // raise an error ?
}

// Set the width for the Point object
HB_FUNC_STATIC( POINT_SETWIDTH )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p;

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
   p = hb_parptr( -1 );

   if( p )
   {
      p->width = hb_parni( 1 );
   }
   else
      hb_retni( 0 ); // raise an error ?
}

// Get the width from the Point object
HB_FUNC_STATIC( POINT_GETWIDTH )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p;

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
   p = hb_parptr( -1 );

   if( p )
      hb_retni( p->width );
   else
      hb_retni( 0 ); // raise an error ?
}

// Set the height for the Point object
HB_FUNC_STATIC( POINT_SETHEIGHT )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p;

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
   p = hb_parptr( -1 );

   if( p )
   {
      p->height = hb_parni( 1 );
   }
   else
      hb_retni( 0 ); // raise an error ?
}

// Get the height from the Point object
HB_FUNC_STATIC( POINT_GETHEIGHT )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p;

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
   p = hb_parptr( -1 );

   if( p )
      hb_retni( p->height );
   else
      hb_retni( 0 ); // raise an error ?
}

// Retrieve Point data and place it on the return stack
HB_FUNC_STATIC( POINT_GETPOINTDATA )
{
   PHB_ITEM pSelf = hb_stackSelfItem();

   hb_arrayGet( pSelf, 1, hb_stackReturnItem() );
}

// Destroy a Point object and free its memory
HB_FUNC_STATIC( POINT_DESTROY )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   PHB_ITEM p = hb_itemNew( NULL ), pNull;

   hb_arrayGet( pSelf, 1, p );
   if( hb_itemGetPtr( p ) )
      hb_xfree( hb_itemGetPtr( p ) );
   hb_arraySet( pSelf, 1, pNull = hb_itemPutPtr( NULL, NULL ) );
   hb_itemRelease( p );
   hb_itemRelease( pNull );
}

HB_FUNC_STATIC( POINT_NEW )
{
   PHB_ITEM pSelf = hb_stackSelfItem();
   Point *p = ( Point * ) hb_xgrab( sizeof( Point ) );

   p->x = hb_parni( 1 );
   p->y = hb_parni( 2 );

   hb_arraySetPtr( pSelf, 1, p );
   hb_itemReturn( pSelf );  // return Self
}

// class creation
HB_FUNC( POINT )
{
   // Create class
   static HB_USHORT uiClass = 0;

   if( uiClass == 0 )
   {
      // Create class
      uiClass = hb_clsCreate( 1, "POINT" );  // it has just one DATA
      // Add methods to the class
      hb_clsAdd( uiClass, "_X",        HB_FUNCNAME( POINT_SETX ) );
      hb_clsAdd( uiClass, "X",         HB_FUNCNAME( POINT_GETX ) );
      hb_clsAdd( uiClass, "_Y",        HB_FUNCNAME( POINT_SETY ) );
      hb_clsAdd( uiClass, "Y",         HB_FUNCNAME( POINT_GETY ) );
      hb_clsAdd( uiClass, "SETWIDTH",  HB_FUNCNAME( POINT_SETWIDTH ) );
      hb_clsAdd( uiClass, "GETWIDTH",  HB_FUNCNAME( POINT_GETWIDTH ) );
      hb_clsAdd( uiClass, "_HEIGHT",   HB_FUNCNAME( POINT_SETHEIGHT ) );
      hb_clsAdd( uiClass, "HEIGHT",    HB_FUNCNAME( POINT_GETHEIGHT ) );
      hb_clsAdd( uiClass, "POINTDATA", HB_FUNCNAME( POINT_GETPOINTDATA ) );
      hb_clsAdd( uiClass, "DESTROY",   HB_FUNCNAME( POINT_DESTROY ) );
      hb_clsAdd( uiClass, "NEW",       HB_FUNCNAME( POINT_NEW ) );
   }

   // create the object
   hb_clsAssociate( uiClass );
}
