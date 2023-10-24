#include "hbtpl.h"

// Set the x value for the Point object
HB_FUNC( POINT_SETX )
{
   // Retrieve the pointer to the Point object from the Harbour object
   Point *p = ( Point * ) hb_parptr( 1 );

   // Retrieve the new value for x
   int new_x = hb_parni( 2 );

   // Set the new value for x
   if( p )
      p->x = new_x;
}

// Get the x value from the Point object
HB_FUNC( POINT_GETX )
{
   // Retrieve the pointer to the Point object from the Harbour object
   Point *p = ( Point * ) hb_parptr( 1 );

   if( p )
      hb_retni( p->x );
}

// Set the y value for the Point object
HB_FUNC( POINT_SETY )
{
   // Retrieve the pointer to the Point object from the Harbour object
   Point *p = ( Point * ) hb_parptr( 1 );

   // Retrieve the new value for y
   int new_y = hb_parni( 2 );

   // Set the new value for y
   if( p )
      p->y = new_y;
}

// Get the y value from the Point object
HB_FUNC( POINT_GETY )
{
   // Retrieve the pointer to the Point object from the Harbour object
   Point *p = ( Point * ) hb_parptr( 1 );

   if( p )
      hb_retni( p->y );
}

HB_FUNC( POINT_DESTROY )
{
   // Retrieve the pointer to the Point object from the Harbour object
   Point *p = ( Point * ) hb_parptr( 1 );

   // Free up memory
   if( p )
      hb_xfree( p );
}

// Initialize function
HB_FUNC( INIT )
{
   Point *p = ( Point * ) hb_xgrab( sizeof( Point ) );
   p->x = 10;
   p->y = 20;

   // Create class
   HB_USHORT uiClass = hb_clsCreate( 0, "POINT" );

   // Add methods to the class
   hb_clsAdd( uiClass, "SetX", hb_dynsymGet( "POINT_SETX" ) );
   hb_clsAdd( uiClass, "GetX", hb_dynsymGet( "POINT_GETX" ) );
   hb_clsAdd( uiClass, "SetY", hb_dynsymGet( "POINT_SETY" ) );
   hb_clsAdd( uiClass, "GetY", hb_dynsymGet( "POINT_GETY" ) );
   hb_clsAdd( uiClass, "Destroy", hb_dynsymGet( "POINT_DESTROY" ) );

   // Retrieve the pointer to the class of the object
   PHB_DYNS pDynSym = hb_dynsymFind( "POINT" );
   PHB_ITEM pObject = hb_objSendMsg( pDynSym, "_New", 0, NULL );

   // Associate the class with the object
   hb_clsAssociate( uiClass );

   // Add the pointer to the Point structure as the object's data
   // (A different function may be needed here to properly set the object's data)
   hb_objSetClass( pObject, "POINTDATA", ( void * ) p );

   hb_itemReturnRelease( pObject );
}
