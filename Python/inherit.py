class Person:
    def __init__(self, name, health):
        self.name = name
        self.health = health

    def attack(self, other):
        other.health -= 1

    def __str__(self):
        return self.name +' ' + str(self.health)

class Magician(Person):

    def __init__(self, name, health, mana):
        Person.__init__(self, name, health)
        self.mana=mana

    def spell(self, other):
        other.health -= 10
        self.mana -=2

class Warrior(Person):
    def __init__(self, name, health):
        Person.__init__(self,name,health)     #상속의 개념
    def smash(self, other):
        other.health -=5

Lee = Person('Lee', 10)
Park = Magician('Park', 10,10)
Kim = Warrior('Kim', 20)

print(Lee, Park, Kim)

Park.attack(Lee)

print(Lee, Park, Kim)

Lee.attack(Park)

print(Lee, Park, Kim)

Park.spell(Lee)

print(Lee, Park)
