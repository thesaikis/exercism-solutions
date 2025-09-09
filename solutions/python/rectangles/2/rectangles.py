def rectangles(strings):
    count = 0

    for r, row in enumerate(strings):
        for c, char in enumerate(row):
            # Interpret found corner as a top-left corner
            if char == "+":
                # Search out for any possible top-right corners
                for tr in range(c + 1, len(row)):
                    if strings[r][tr] == "+":
                        # Search out for any possible bottom-left corners
                        for bl in range(r + 1, len(strings)):
                            if strings[bl][c] == "+":
                                # Now we need to see if there exists a bottom-right corner given all our corners
                                # We also need to check if there are valid sides
                                if (
                                    strings[bl][tr] == "+"
                                    and all(
                                        strings[bl][br] in "+-" for br in range(c, tr)
                                    )
                                    and all(
                                        strings[br][tr] in "+|" for br in range(r, bl)
                                    )
                                ):
                                    count += 1
                            elif strings[bl][c] != "|":
                                break
                    elif strings[r][tr] != "-":
                        break

    return count
