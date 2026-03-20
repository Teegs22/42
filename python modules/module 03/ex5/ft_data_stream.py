from typing import Generator
from data_generator import PixelDataGenerator


# use typing generator


def stream_events(events):
    for event in events:
        yield event


def game_event_stream(num):
    generator = PixelDataGenerator()
    events = generator._events_for_stream(num)
    events_stream = stream_events(events)

    event_num = 1
    high_level = 0
    treasure_events = 0
    level_up = 0
    for event in events_stream:
        player = event["player"]
        level = event["data"]["level"]
        event_type = event["event_type"]

        if event_type == "level_up":
            text = "leveled up"
            level_up += 1
        elif event_type == "item_found":
            treasure_events += 1
            text = "found treasure"
        elif event_type == "kill":
            text = "killed monster"
        elif event_type == "death":
            text = "died"
        elif event_type == "login":
            text = "logged in"
        else:
            text = "logged out"
        print(f"Event {event_num}: Player {player} (level {level}) {text}")
        event_num += 1
        if level >= 10:
            high_level += 1
    print("\n=== Stream Analytics ===")
    print(f"Total events processed: {event_num - 1}")
    print(f"High-level players (10+): {high_level}")
    print(f"Treasure events: {treasure_events}")
    print(f"Level-up events: {level_up}\n")

# cme back to i dont understand

# if __name__ == "__main__":
#     game_event_stream(1000)
