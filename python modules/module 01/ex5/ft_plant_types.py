class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age


class Tree(Plant):
    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self, height):
        return (((height / 100) ** 2) * 3.142)


class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self, name, color):
        if "green" in color:
            return (f"{name} is going to bloom soon!")
        elif "brown" in color:
            return (f"your {name} has died.")
        else:
            return (f"{name} is blooming beautifully!")


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season

    def nutrition(self, harvest_season):
        if "summer" in harvest_season:
            return ("vitamin c")
        if "winter" in harvest_season:
            return ("calcium")
        if "spring" in harvest_season:
            return ("magnesium")
        if "autumn" in harvest_season:
            return ("potassium")


def info_assign():
    the_plants = [
        Flower("Rose", 25, 30, "red color"),
        Flower("Sunflower", 40, 20, "green color"),
        Flower("Lily", 40, 60, "brown color"),
        Tree("Oak", 500, 1825, 50),
        Tree("Spruce", 900, 2098, 43),
        Vegetable("Tomato", 20, 54, "summer harvest"),
        Vegetable("Carrot", 80, 94, "autumn harvest"),
    ]
    print("=== Garden Plant Types ===\n")
    for i in the_plants:
        if isinstance(i, Flower):
            print(f"{i.name} (Flower): {i.height}cm, "
                  "{i.age} days, {i.color}")
            print(f"{i.bloom(i.name, i.color)}\n")
        elif isinstance(i, Tree):
            print(f"{i.name} (Tree): {i.height}cm, {i.age} days, "
                  "{i.trunk_diameter}cm diameter")
            print(f"{i.name} provides {int(i.produce_shade(i.height))} "
                  "square meters of shade\n")
        else:
            print(f"{i.name} (Vegetable): {i.height}cm, {i.age} days, "
                  "{i.harvest_season}")
            print(f"{i.name} is rich in {i.nutrition(i.harvest_season)}\n")


# if __name__ == "__main__":
#    info_assign()
