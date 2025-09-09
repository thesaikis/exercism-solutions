def saddle_points(matrix):
    if any(len(matrix[i]) != len(matrix[0]) for i in range(1, len(matrix))):
        raise ValueError("irregular matrix")

    row_maxes = list(max(row) for row in matrix)
    col_mins = list(min(col) for col in zip(*matrix))

    return list(
        {"row": row_idx + 1, "column": col_idx + 1}
        for row_idx in range(len(matrix))
        for col_idx in range(len(matrix[row_idx]))
        if matrix[row_idx][col_idx] >= row_maxes[row_idx]
        and matrix[row_idx][col_idx] <= col_mins[col_idx]
    )
