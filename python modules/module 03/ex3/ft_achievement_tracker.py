def player_or_players(num):
    if num == 1:
        return "player"
    else:
        return "players"


def ft_achievement_tracker():
    a = set(('first_kill', 'level_10', 'treasure_hunter', 'speed_demon'))
    b = set(('first_kill', 'level_10', 'boss_slayer', 'collector'))
    c = set(('level_10', 'treasure_hunter', 'boss_slayer',
             'speed_demon', 'perfectionist'))
    unique = a.union(b, c)
    len_unique = len(unique)
    common = a.intersection(b, c)
    players_rare = 0
    rare = (a-b-c) | (b-a-c) | (c-a-b)
    if len(a-b-c) > 0:
        players_rare += 1
    if len(b-a-c) > 0:
        players_rare += 1
    if len(c-b-a) > 0:
        players_rare += 1
    ab_common = a.intersection(b)
    a_unique = a - b
    b_unique = b - a
    print("=== Achievement Tracker System ===")
    print(f"\nPlayer Alice achievements: {a}")
    print(f"Player Bob achievements: {b}")
    print(f"Player Charlie achievements: {c}")
    print("\n=== Achievement Analytics ===")
    print(f"All unique achievements: {unique}")
    print(f"Total unique achievements: {len_unique}")
    print(f"\nCommon to all players: {common}")
    print(f"Rare achievements ({players_rare} "
          f"{player_or_players(players_rare)}): {rare}")
    print(f"\nAlice vs Bob common: {ab_common}")
    print(f"Alice unique: {a_unique}")
    print(f"Bob unique: {b_unique}")


# if __name__ == "__main__":
#     ft_achievement_tracker()
