from interface import *

# ------------------------------------------------------------
# Ejemplo de uso básico
# ------------------------------------------------------------
if __name__ == "__main__":
	app = Aplication(b"My Game")
	man = app.CreateEntityManager()
	man.LoadSprite("assets/Animacion.png","SPRITE")
	man.CreateEntity("SPRITE","CAPA")
	e = man.SearchEntity("CAPA")
	man.SetFrame(e,2,2,AnimationToken.DYNAMIC)
	man.SetDimension(e,0.5)
	speed=10
	x=100
	y=100
	while not app.EventProcess():
		app.DrawBegin()
		e = man.SearchEntity("CAPA")
		if app.GetEvent(EventKeys.UP):
			y-=speed
		if app.GetEvent(EventKeys.DOWN):
			y+=speed
		if app.GetEvent(EventKeys.RIGHT):
			x+=speed
		if app.GetEvent(EventKeys.LEFT):
			x-=speed
		man.SetPosition(e,x,y)
		man.Draw(app.GetDeltaTime(),app.GetCam())
		app.DrawEnd()
	man.Free()
	app.Quit()





