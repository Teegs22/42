class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age


def info_assign():
    flower1 = Plant("Rose", 25, 30)
    flower2 = Plant("Sunflower", 80, 45)
    flower3 = Plant("Cactus", 15, 120)
    print("=== Garden Plant Registry ===")
    print(f"{flower1.name}: {flower1.height}cm, {flower1.age} days old")
    print(f"{flower2.name}: {flower2.height}cm, {flower2.age} days old")
    print(f"{flower3.name}: {flower3.height}cm, {flower3.age} days old")
# if __name__ == "__main__":
#    info_assign():
