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

   ? "PointData: ", o:PointData
   
   // Destroy the Point object
   o:Destroy()

   ? "PointData: ", o:PointData

RETURN