def water_plants(plant_list):
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant is None or not isinstance(plant, str):
                raise ValueError(f"Cannot water {plant} - invalid plant!")
            print(f"Watering {plant}")
    except ValueError as e:
        print("Error:", e)
        raise
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system():
    success = True
    print("=== Garden Watering System ===\n")
    plant_list = ["tomato", "lettuce", "carrots"]
    print("Testing normal watering...")
    try:
        water_plants(plant_list)
    except Exception:
        success = False
    finally:
        if success:
            print("Watering completed successfully!")
    plant_list = [123, None, "carrots"]
    print("\nTesting with error...")
    success = True
    try:
        water_plants(plant_list)
    except Exception:
        success = False
    finally:
        if success:
            print("Watering completed successfully!")
    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
