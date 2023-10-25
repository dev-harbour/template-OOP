PROCEDURE Main()

   LOCAL o := Point():New( 10, 20 )

   ? "X: ", o:x
   ? "Y: ", o:y

   o:x = 25
   o:y = 50

   ? "X: ", o:x
   ? "Y: ", o:y

   ? "PointData: ", o:PointData
   o:Destroy()

   ? "PointData: ", o:PointData

RETURN