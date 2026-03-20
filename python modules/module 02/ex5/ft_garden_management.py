class GardenError(Exception):
    def __init__(self, message):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message):
        super().__init__(message)


class GardenManager:
    def add_plant(garden, plant_name, water_level, sunlight_hours):
        try:
            if plant_name is None:
                raise PlantError("Plant name cannot be empty!")
            elif not isinstance(plant_name, str):
                raise PlantError(f"{plant_name} is an invalid plant name!")
            garden += [[plant_name, water_level, sunlight_hours]]
            print(f"Added {plant_name} successfully")
        except PlantError as e:
            print("Error:", e)
        except Exception:
            print(f"Error adding {plant_name}")

    def water_plants(garden):
        print("Opening watering system")
        try:
            if not garden:
                raise PlantError("No plants to water!")
            for plant in garden:
                if not isinstance(plant[0], str):
                    raise WaterError(f"Cannot water {plant[0]}"
                                     " - invalid plant!")
                print(f"Watering {plant[0]} - success")
        except Exception as e:
            print("Error:", e)
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(garden):
        try:
            for plant in garden:
                if plant[0] is None:
                    raise PlantError("Plant name cannot be empty!")
                elif not isinstance(plant[0], str):
                    raise PlantError(f"Plant name {plant[0]} is invalid")
                elif not isinstance(plant[1], int):
                    raise WaterError(f"Water level {plant[1]} is invalid")
                elif not isinstance(plant[2], int):
                    raise PlantError(f"Sunlight hours {plant[2]} is invalid")
                elif plant[1] > 10:
                    raise WaterError(f"Water level {plant[1]}"
                                     " is too high (max 10)")
                elif plant[1] < 1:
                    raise WaterError(f"Water level {plant[1]}"
                                     " is too low (min 1)")
                elif plant[2] > 12:
                    raise PlantError(f"Sunlight hours {plant[2]}"
                                     " is too high (max 12)")
                elif plant[2] < 2:
                    raise PlantError(f"Sunlight hours {plant[2]}"
                                     " is too low (min 2)")
                else:
                    print(f"{plant[0]}: healthy "
                          f"(water: {plant[1]}, sun: {plant[2]})")
        except Exception as e:
            print(f"Error checking {plant[0]}:", e)


def test_garden_manager():
    garden = []
    print("=== Garden Management System ===")
    print("\nAdding plants to garden...")
    GardenManager.add_plant(garden, "tomato", 5, 7)
    GardenManager.add_plant(garden, "lettuce", 15, 7)
    GardenManager.add_plant(garden, None, 5, 7)
    print("\nWatering plants...")
    GardenManager.water_plants(garden)
    print("\nChecking plant health...")
    GardenManager.check_plant_health(garden)
    print("\nTesting error recovery...")
    test_plant = ["cucumber", 0, 6]
    try:
        if not isinstance(test_plant[0], str):
            raise PlantError("Plant name is invalid!")
        elif not isinstance(test_plant[1], int):
            raise WaterError("Water level value invalid")
        elif not isinstance(test_plant[2], int):
            raise PlantError("Sunlight hours value invalid")
        elif test_plant[1] < 1:
            raise WaterError("Not enough water in tank")
        elif test_plant[1] > 10:
            raise WaterError("Too much water in tank")
        elif test_plant[1] < 2:
            raise PlantError("Not enough sunlight hours")
        elif test_plant[1] > 12:
            raise PlantError("Too many sunlight hours")
    except GardenError as e:
        print("Caught GardenError:", e)
        print("System recovered and continuing...")
    print("\nGarden management system test complete!")


# if __name__ == "__main__":
#    test_garden_manager()
