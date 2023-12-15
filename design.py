class Game:
    def __init__(self):
        self.screen = None

    def run(self):
        pass

class Entity:
    def __init__(self):
        self.sprite = None
        self.pos = [0,0]
        self.hp = 100
        self.frame_cycle = 0
        self.frame_count = 0

    def start(self):
        pass

    def show(self):
        pass

    def update(self):
        pass

class Player(Entity):
    def shoot(self):
        pass

class Enemy(Entity):
    pass

class Projectile(Entity):
    pass

class Runner(Enemy):
    pass

class Shooter(Enemy):
    def shoot(self):
        pass

class Memory(Entity):
    pass
