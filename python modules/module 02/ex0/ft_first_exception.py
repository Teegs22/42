def check_temperature(temp_str):
    try:
        temp_str = int(temp_str)
        if temp_str >= 0 and temp_str <= 40:
            print(f"Temperature {temp_str}°C is perfect for plants!")
        elif temp_str > 40:
            print(f"Error: {temp_str}°C is too hot for plants (max 40°C)")
        else:
            print(f"Error: {temp_str}°C is too cold for plants (min 0°C)")
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number")


def test_temperature_input():
    print("=== Garden Temperature Checker ===")
    print("\nTesting temperature: 25")
    check_temperature("25")
    print("\nTesting temperature: abc")
    check_temperature("abc")
    print("\nTesting temperature: 100")
    check_temperature("100")
    print("\nTesting temperature: -50")
    check_temperature("-50")
    print("\nAll tests completed - program didn't crash!")

# if __name__ == "__main__" :
#     test_temperature_input()
