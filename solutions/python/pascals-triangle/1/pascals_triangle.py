def rows(row_count):
    if row_count < 0:
        raise ValueError("number of rows is negative")

    return tri(row_count)

def tri(row):
    if row == 0:
        return []
    elif row == 1:
        return [[1]]
    
    all_rows = tri(row - 1)
    previous_row = all_rows[-1]
    current_row = [1] + [previous_row[i] + previous_row[i + 1] for i in range(len(previous_row) - 1)] + [1]
    all_rows.append(current_row)
    
    return all_rows
