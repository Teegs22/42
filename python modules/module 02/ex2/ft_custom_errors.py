class GardenError(Exception):
    def __init__(self, message):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message):
        super().__init__(message)


def check_temp(temp):
    plant = "tomato"
    if temp < 0 or temp > 40:
        raise PlantError(f"The {plant} plant is wiltering!")


def check_water(percent_water):
    if percent_water < 35:
        raise WaterError("Not enough water in the tank!")


def try_errors(error_type):
    if error_type == "PlantError":
        try:
            check_temp(-6)
        except PlantError as e:
            print("Caught PlantError:", e)
    elif error_type == "WaterError":
        try:
            check_water(34)
        except WaterError as e:
            print("Caught WaterError:", e)
    else:
        try:
            check_temp(-6)
        except GardenError as e:
            print("Caught a garden error:", e)
        try:
            check_water(34)
        except GardenError as e:
            print("Caught a garden error:", e)


def error_checker():
    print("=== Custom Garden Errors Demo ===")
    print("\nTesting PlantError...")
    try_errors("PlantError")
    print("\nTesting WaterError...")
    try_errors("WaterError")
    print("\nTesting catching all garden errors...")
    try_errors("GardenError")
    print("\nAll custom error types work correctly!")


# if __name__ == "__main__" :
#     error_checker()
