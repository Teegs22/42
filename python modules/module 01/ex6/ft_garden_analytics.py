class Plant:
    def __init__(self, garden, name, age, old_height, new_height):
        self.name = name
        self.age = age
        self.old_height = old_height
        self.new_height = new_height
        self.garden = garden
        print(f"Added {self.name} to {self.garden}'s garden")

    def ageing(self, new_age):

        age_difference = new_age - self.age
        self.age = new_age
        self.new_height = self.new_height + age_difference


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


class PrizeFlower(FloweringPlant):
    def __init__(self, garden, name,
                 age, old_height, new_height, color, prize):
        super().__init__(garden, name, age, old_height, new_height, color)
        self.prize = prize


class GardenManager:
    class GardenStats:
        @staticmethod
        def totalp_garden(garden):
            count = 0
            for item in garden[1:]:
                count += 1
            return (count)

        @staticmethod
        def total_gardens(gardens):
            count = 0
            for garden in gardens:
                count += 1
            return (count)

        @staticmethod
        def points_earnt_per_garden(garden):
            points = 0
            for item in garden[1:]:
                if type(item) is FloweringPlant:
                    points += 50
                elif type(item) is PrizeFlower:
                    points += 50
                    points += item.prize
                elif type(item) is Plant:
                    points += 100
            return (points)

        @staticmethod
        def num_regular(garden):
            count = 0
            for item in garden[1:]:
                if type(item) is Plant:
                    count += 1
            return (count)

        @staticmethod
        def num_flowering(garden):
            count = 0
            for item in garden[1:]:
                if type(item) is FloweringPlant:
                    count += 1
            return (count)

        @staticmethod
        def num_prize(garden):
            count = 0
            for item in garden[1:]:
                if type(item) is PrizeFlower:
                    count += 1
            return (count)

        @staticmethod
        def total_growth(garden):
            growth = 0
            for item in garden[1:]:
                growth += item.new_height - item.old_height
            return (growth)

        @staticmethod
        def plant_growth(old, new):
            total = new - old
            return (total)

        @staticmethod
        def height_validation(gardens):
            height_valid = True
            for garden in gardens:
                for item in garden[1:]:
                    if item.old_height < 0:
                        height_valid = False
                    elif item.new_height < item.old_height:
                        height_valid = False
            return (height_valid)

    gardens = []

    @classmethod
    def make_plants_grow(cls, addage):
        for item in cls.gardens[0][1:]:
            age = item.age + addage
            item.ageing(age)

    @classmethod
    def helping_grow(cls):
        if cls.gardens:
            for garden in cls.gardens:
                owner = garden[0]
                print(f"\n{owner} is helping all plants grow...")
                for item in garden[1:]:
                    g_p = GardenManager.GardenStats.plant_growth(
                        item.old_height, item.new_height)
                    print(f"{item.name} grew {g_p}cm")

    @classmethod
    def create_garden_network(cls):
        print("=== Garden Management System Demo ===\n")
        cls.gardens = [
            [
                "Alice",
                Plant("Alice", "Oak Tree", 30, 100, 100),
                FloweringPlant("Alice", "Rose", 25, 25, 25, "red"),
                PrizeFlower("Alice", "Sunflower", 60, 50, 50, "yellow", 10)
            ],
            [
                "Bob",
                Plant("Bob", "Spruce Tree", 1809, 300, 300),
                FloweringPlant("Bob", "Daisy", 78, 5, 5, "brown"),
                PrizeFlower("Bob", "Tulip", 20, 50, 50, "green", 20)
            ]
        ]

    @classmethod
    def garden_report(cls):
        if not cls.gardens:
            print("No gardens being managed yet")
        else:
            for garden in cls.gardens:
                owner = garden[0]
                print(f"\n==={owner}'s Garden Report === ")
                print("Plants in garden:")
                for item in garden[1:]:
                    if type(item) is PrizeFlower:
                        is_blooming = item.bloom(item.name, item.color)
                        print(f"- {item.name}: {item.new_height}cm,"
                              f"{item.color} flowers ({is_blooming}),"
                              f" Prize points: {item.prize}")
                    elif type(item) is FloweringPlant:
                        is_blooming = item.bloom(item.name, item.color)
                        print(f"- {item.name}: {item.new_height}cm,"
                              f" {item.color} flowers ({is_blooming})")
                    elif type(item) is Plant:
                        print(f"- {item.name}: {item.new_height}cm")
                total_plants = GardenManager.GardenStats.totalp_garden(garden)
                growth = GardenManager.GardenStats.total_growth(garden)
                num_regular = GardenManager.GardenStats.num_regular(garden)
                num_flowering = GardenManager.GardenStats.num_flowering(garden)
                num_prize = GardenManager.GardenStats.num_prize(garden)
                print(f"\nPlants added: {total_plants},"
                      f" Total growth: {growth}cm")
                print(f"Plant types: {num_regular} regular, {num_flowering}"
                      f" flowering, {num_prize} prize flowers")

    @classmethod
    def last_info(cls):
        print("\nHeight validation test: "
              f"{GardenManager.GardenStats.height_validation(cls.gardens)}")
        print("Garden scores -", end=" ")
        for garden in cls.gardens:
            points = GardenManager.GardenStats.points_earnt_per_garden(garden)
            owner = garden[0]
            print(f"{owner}: {points},", end=" ")
        print("\nTotal gardes managed: "
              f"{GardenManager.GardenStats.total_gardens(cls.gardens)}")

# if __name__ == "__main__":
#      GardenManager.create_garden_network()
#      GardenManager.make_plants_grow(5)
#      GardenManager.helping_grow()
#      GardenManager.garden_report()
#      GardenManager.last_info()
