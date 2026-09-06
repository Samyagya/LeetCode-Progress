# 286. Walls and Gates

**Difficulty:** Medium  
[View on LeetCode](https://leetcode.com/problems/walls-and-gates/)

---

You are given an `m x n` grid `rooms` initialized with these three possible values:

- `-1` - A wall or an obstacle.
- `0` - A gate.
- `2147483647` - An empty room. `2147483647` is treated as `INF`, meaning infinity.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, the room should remain filled with `INF`.

The distance between two adjacent cells is `1`. Two cells are adjacent if they are horizontally or vertically neighboring.

**Example 1:**

```
Input: rooms = [
	[2147483647, -1,           0, 2147483647],
	[2147483647, 2147483647,  2147483647, -1],
	[2147483647, -1,           2147483647, -1],
	[0,           -1,           2147483647, 2147483647]
]

Output: [
	[3, -1, 0, 1],
	[2, 2, 1, -1],
	[1, -1, 2, -1],
	[0, -1, 3, 4]
]
```

**Constraints:**

- `m == rooms.length`
- `n == rooms[i].length`
- `1 <= m, n <= 250`
- `rooms[i][j]` is `-1`, `0`, or `2147483647`.
