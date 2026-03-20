class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age


def creation():
    flowers = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120),
    ]
    num = 0
    for f in flowers:
        print(f"Created: {f.name} ({f.height}cm, {f.age}days)")
        num += 1
    print(f"\nTotal plants created: {num}")

# if __name__ == "__main__":
#    creation()
