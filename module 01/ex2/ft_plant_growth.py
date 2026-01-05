class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def ageing(self, height, age):
        self.age = age + 6
        if age <= 60:
            self.grow(height, 6)
        else:
            self.grow(height, 6 - (age - 60))

    def grow(self, height, num):
        height += num
        self.height = height
        self.growth = num


def get_info():
    print("=== Day 1 ===")
    flower = Plant("Rose", 25, 30)
    print(f"{flower.name}: {flower.height}cm, {flower.age} days old")
    flower.ageing(25, 30)
    print("=== Day 7 ===")
    print(f"{flower.name}: {flower.height}cm, {flower.age} days old")
    print(f"Growth this week: +{flower.growth}cm")
# if __name__ == "__main__":
#    get_info()
# stops growing at day 60
# im simulating a week so input
