from collections import defaultdict, deque


class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        # Build the adjacency list
        adj = defaultdict(list)
        for source, dest, travel_time in times:
            adj[source].append((travel_time, dest))

        # Array to store the earliest time signal reaches each node
        signal_received_at = [float('inf')] * (n + 1)
        signal_received_at[k] = 0  # Time for the starting node is 0

        # BFS with a queue
        queue = deque([k])

        while queue:
            curr_node = queue.popleft()

            for travel_time, neighbor in adj[curr_node]:
                arrival_time = signal_received_at[curr_node] + travel_time

                if arrival_time < signal_received_at[neighbor]:
                    signal_received_at[neighbor] = arrival_time
                    queue.append(neighbor)

        # Find the maximum signal received time
        answer = max(signal_received_at[1:])  # Skip index 0

        # If any node is unreachable, return -1
        return -1 if answer == float('inf') else answer
