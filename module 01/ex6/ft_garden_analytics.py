class GardenManager:
    print ("=== Garden Management System Demo ===\n")
    create_garden_network()
    elements = 0
    num_plants = 0
    for garden in gardens:
        print (f"==={garden[0]}'s Garden Report ===")
        print ("Plants in garden:")
        for name in garden[1:]:
            if isinstance(name, Flower)
            print (f"- {gardens[elements][num_plants][0]}: {gardens[elements][num_plants][4]}cm")
            num_plants += 1
        elements += 1
    if elements == 0:
        print ("No gardens being managed yet")

    class GardenStats:


class Plant:
    def __init__(self, garden, name, age, old_height, new_height):
        self.name = name
        self.age = age
        self.old_height = old_height
        self.new_height = new_height
        self.garden = garden
        print(f"Added {self.name} to {self.garden}'s garden")

    def ageing(self, new_height, age):
        self.age = age + 6
        if age <= 60:
            self.grow(new_height, 1)

    def grow(self, new_height, num):
        new_height += num
        self.new_height = new_height
        self.growth = num

class FloweringPlant(Plant):
    def __init__(self, garden, name, age, old_height, new_height, color):
        super().__init__(garden, name, age, old_height, new_height)
        self.color = color

    def bloom(self, name, color):
        if "green" in color:
            return ("going to bloom soon!")
        elif "brown" in color:
            return ("dying")
        else:
            return ("blooming")
    
class PrizeFlower(Plant):
    def __init__(self, garden, name, age, old_height, new_height, color, prize):
        super().__init__(garden, name, age, old_height, new_height)
        self.color = color
        self.prize = prize


def create_garden_network():
    global gardens 
    gardens = [
        [
            ["Alice"],
            [Plant("Alice", "Oak Tree", 30, 100, 100)],
            [FloweringPlant("Alice", "Rose", 25, 25, 25, "red")],
            [PrizeFlower("Alice", "Sunflower", 60, 50, 50, "yellow", 10)]
        ],
        [
            ["Bob"],
            [Plant("Bob", "Spruce Tree", 1809, 300, 300)],
            [FloweringPlant("Bob", "Daisy", 78, 5, 5, "brown")],
            [PrizeFlower("Bob", "Tulip", 20, 50, 50, "green", 20)]
        ]
    ]
