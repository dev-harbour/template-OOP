PROCEDURE Main()
   LOCAL p := INIT()

   ? "X:", p:GetX()
   ? "Y:", p:GetY()

   p:SetX( 100 )
   p:SetY( 200 )

   ? "X:", p:GetX()
   ? "Y:", p:GetY()

RETURN
