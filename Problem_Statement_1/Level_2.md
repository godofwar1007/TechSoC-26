# 🔍 Level 2 — The Pattern Watcher

[![Difficulty](https://img.shields.io/badge/Difficulty-Intermediate-e67e22?style=flat-square)](#)
[![Concepts](https://img.shields.io/badge/Concepts-Modular%20Design%20|%20Toroidal%20Topology%20|%20Cycle%20Detection-0d6efd?style=flat-square)](#)

---

## Background

Level 1 used a bounded grid — cells at the edge simply had fewer neighbors, since anything outside the grid was treated as dead. Level 2 removes that limitation and adds the ability to automatically classify how a pattern behaves over time, instead of watching it manually.

---

## Your Task

Build on your Level 1 code and implement the following features:

| # | Feature | Description |
|---|---|---|
| 1 | **Toroidal Wrap-Around Mode** | Cells at the edge connect seamlessly to the opposite edge (donut topology). |
| 2 | **Automated Pattern Classifier** | Detect if a pattern is a **Still Life**, **Oscillator (with period $P$)**, **Extinct**, or **Active**. |
| 3 | **Center of Mass & Bounding Box** | Compute the bounding box dimensions ($H \times W$) and center of mass $(r_{avg}, c_{avg})$ of live cells. |

---

## Rules

- Any programming language (Python, C++, Java, Rust, JavaScript, etc.)
- Single program file, runs in your terminal
- No GUI frameworks or third-party game libraries — clean modular code

---

## Concepts You'll Use

| Concept | Description |
|---|---|
| Modular Functions | Structuring logic into distinct callable components |
| Toroidal Coordinates | Wrap-around indexing using modulo arithmetic: `(r + dr + R) % R` |
| State Hashing / History | Storing past grid snapshots to identify repeated cyclic states |
| Center of Mass | Calculating average coordinates: $\bar{r} = \frac{\sum r_i}{N}, \bar{c} = \frac{\sum c_i}{N}$ |

---

## Feature Specifications & Test Cases

---

### Feature 1: Toroidal Wrap-Around Mode

In Level 1, a grid has edges — a cell in the top row has no neighbors above it, since those spots fall outside the grid and count as dead. **Toroidal mode removes those edges** by connecting each side of the grid to the opposite side, like Pac-Man walking off one side of the screen and reappearing on the other.

- Off the **top** → reappear at the **bottom**
- Off the **bottom** → reappear at the **top**
- Off the **left** → reappear at the **right**
- Off the **right** → reappear at the **left**

If you physically bent a flat grid so the top edge met the bottom, then bent the resulting tube so its two ends met too, you'd get the shape of a donut — a **torus**. That's where "toroidal" comes from. A cell in the corner now has a full 8 neighbors instead of 3, since the "missing" ones are found by wrapping around.

Formally: row $-1$ maps to row $R-1$, and row $R$ maps to row $0$. Column $-1$ maps to column $C-1$, and column $C$ maps to column $0$. This is implemented with modulo arithmetic — no special-casing corners or edges needed:

```
neighbor_row = (r + dr + R) % R
neighbor_col = (c + dc + C) % C
```

<details>
<summary><strong>🧪 Feature 1 — Test Case 1: Blinker on Grid Border</strong></summary>
<br>

*A vertical blinker split across the top and bottom edges seamlessly connects and oscillates to a horizontal blinker wrapping across the left and right edges.*

**Input:**
```
toroidal
5 5
1
#....
#....
.....
.....
#....
```

**Output:**
```
Mode: Toroidal
Initial Population: 3
Final Population: 3
Final Grid:
##..#
.....
.....
.....
.....
```
</details>

<details>
<summary><strong>🧪 Feature 1 — Test Case 2: Glider Boundary Traverse</strong></summary>
<br>

*A glider wraps across the border and continues moving.*

**Input:**
```
toroidal
4 4
4
.#..
..#.
###.
....
```

**Output:**
```
Mode: Toroidal
Initial Population: 5
Final Population: 4
Final Grid:
#...
.#.#
....
#...
```
</details>

---

### Feature 2: Automated Pattern Classifier

Simulate the grid step-by-step and identify its state:

- **`Extinct`**: All cells have died (population = 0 at step $S$).
- **`Still Life`**: The grid configuration at step $S$ is identical to step $S-1$ (Period 1).
- **`Oscillator (Period P)`**: The grid configuration at step $S$ is identical to a previous step $S - P$ where $P \ge 2$.
- **`Active`**: The grid has not repeated or died out within the step limit.

**Step limit:** The base `classify` command always uses a fixed limit of **K = 10** steps. You don't read this from input — just use 10 directly in your code.

**Input format:**
```
classify
R C
<row 1>
...
<row R>
```

<details>
<summary><strong>🧪 Test Case 1: Block (Still Life)</strong></summary>
<br>

**Input:**
```
classify
4 4
....
.##.
.##.
....
```

**Output:**
```
Classification: Still Life
Stable at Step: 0
Period: 1
Final Population: 4
```
</details>

<details>
<summary><strong>🧪 Test Case 2: Blinker (Oscillator Period 2)</strong></summary>
<br>

**Input:**
```
classify
5 5
.....
.###.
.....
.....
.....
```

**Output:**
```
Classification: Oscillator
Period: 2
First Repeat Step: 2 (matches Step 0)
Population: 3
```
</details>

<details>
<summary><strong>🧪 Test Case 3: Toad (Oscillator Period 2)</strong></summary>
<br>

**Input:**
```
classify
6 6
......
..###.
.###..
......
......
......
```

**Output:**
```
Classification: Oscillator
Period: 2
First Repeat Step: 2 (matches Step 0)
Population: 6
```
</details>

<details>
<summary><strong>🧪 Test Case 4: Extinction</strong></summary>
<br>

**Input:**
```
classify
3 3
#..
.##
...
```

**Output:**
```
Classification: Extinct
Extinction Step: 2
Final Population: 0
```
</details>

---

#### Bonus: Custom Step Limit

Add a second command, `classifyk`, which reads an explicit `K` value from input right after `R C`, and uses that instead of the fixed default of 10.

**Input format:**
```
classifyk
R C
K
<row 1>
...
<row R>
```

<details>
<summary><strong>🧪 Bonus Test Case: Blinker with K = 1</strong></summary>
<br>

*With only 1 step to check, the Blinker's period-2 oscillation hasn't repeated yet — so it's correctly classified as Active, even though it's an oscillator if given more steps.*

**Input:**
```
classifyk
5 5
1
.....
.###.
.....
.....
.....
```

**Output:**
```
Classification: Active
Reason: No repeat or extinction detected within K = 1 steps
Final Population: 3
```
</details>

---

### Feature 3: Center of Mass & Bounding Box

For a given grid with $N$ live cells located at coordinates $(r_1, c_1), (r_2, c_2), \dots, (r_N, c_N)$:
- **Bounding Box:** $H = (r_{max} - r_{min} + 1)$, $W = (c_{max} - c_{min} + 1)$
- **Center of Mass:** $(\bar{r}, \bar{c}) = \left(\frac{\sum r_i}{N}, \frac{\sum c_i}{N}\right)$ rounded to 2 decimal places.
- If $N = 0$, print `Live Cells: 0`, `Bounding Box: 0 x 0`, and `Center of Mass: N/A` (see Test Case 2 below).

<details>
<summary><strong>🧪 Test Case 1: Glider Metrics</strong></summary>
<br>

**Input:**
```
metrics
5 5
0
.#...
..#..
###..
.....
.....
```

**Output:**
```
Live Cells: 5
Bounding Box: 3 x 3 (Rows 0-2, Cols 0-2)
Center of Mass: (1.40, 1.20)
```
</details>

<details>
<summary><strong>🧪 Test Case 2: Empty Grid</strong></summary>
<br>

**Input:**
```
metrics
3 3
0
...
...
...
```

**Output:**
```
Live Cells: 0
Bounding Box: 0 x 0
Center of Mass: N/A
```
</details>

---

*Ready for the ultimate challenge? Head over to [Level 3 — Real-Time Evolution](Level_3.md)!*
