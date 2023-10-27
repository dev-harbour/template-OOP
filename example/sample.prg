PROCEDURE Main()

   // Create a new Point object
   LOCAL o := Point():New( 10, 20 )

   // Display its initial x and y values
   ? "X: ", o:x
   ? "Y: ", o:y

   // Modify its x and y values
   o:x = 25
   o:y = 50

   // Display its modified x and y values
   ? "X: ", o:x
   ? "Y: ", o:y

   // Display the PointData
   ? "PointData: ", o:PointData

   // Set the width of the Point object to 100
   o:setWidth( 100 )
   // Display the current width of the Point object
   ? "Width: ", o:getWidth()

   // Set the height of the Point object to 200
   o:setHeight( 200 )
   // Display the current height of the Point object
   ? "Height: ", o:getHeight()

   // Destroy the Point object
   o:Destroy()

   // Display the PointData after destroying the object
   ? "PointData: ", o:PointData

RETURN
