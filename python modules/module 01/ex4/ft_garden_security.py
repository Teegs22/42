class SecurePlant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def get_height(self):
        return self.height

    def get_age(self):
        return self.age

    def set_height(self, new_height):
        if new_height >= 0:
            self.height = new_height
            print(f"Height updated: {new_height}cm [OK]")
        else:
            print("\nInvalid operation attempted: "
                  f"height {new_height}cm [REJECTED]")
            print("Security: Negative height rejected")

    def set_age(self, new_age):
        if new_age >= 0:
            self.age = new_age
            print(f"Age updated: {new_age} days [OK]")
        else:
            print("Invalid operation attempted: "
                  f"age {new_age} days [REJECTED]")
            print("Security: Negative age rejected")


def info_assign():
    plant = SecurePlant("Rose", 25, 30)
    print("=== Garden Security System ===")
    print(f"Plant created: {plant.name}")
    plant.set_height(25)
    plant.set_age(30)
    plant.set_height(-5)

    print(f"\nCurrent plant: {plant.name} "
          "({plant.get_height()}cm, {plant.get_age()} days)")
# if __name__ == "__main__":
#    info_assign()
