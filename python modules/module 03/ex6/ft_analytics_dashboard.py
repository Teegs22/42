
from data_generator import PixelDataGenerator



def list_comprehension():
    generator = PixelDataGenerator()
    analytics = generator._analytics_for_dashboard()
    players_dict = analytics['players']
    players_sessions = analytics['sessions']

    active_players = sorted([session['player'] for session in players_sessions if not session['completed']])
    unique_players = []
    for player in active_players:
        if len(unique_players) == 0 or unique_players[-1] != player:
            unique_players += [player]
        
    print("=== Game Analytics Dashboard ===")
    print("\n=== List Comprehension Examples ===")
    print(f"High scorers (>2000): {[player for player, data in players_dict.items() if data['total_score'] > 2000]}")
    print(f"Scores doubled: {[(session['score'] * 2) for session in players_sessions]}")
    print(f"Active players: {unique_players}")

def dict_comprehension():
    generator = PixelDataGenerator()
    analytics = generator._analytics_for_dashboard()
    players_dict = analytics['players']
    players_sessions = analytics['sessions']

    player_scores = {player: players_dict[player]['total_score'] for player in players_dict}
    score_cat = {cat: }
    print("\n=== Dict Comprehension Examples ===")
    print(f"Player scores: {player_scores}")




if __name__ == "__main__":
    list_comprehension()
    dict_comprehension()
