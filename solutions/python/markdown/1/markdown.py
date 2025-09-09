import re


def parse(markdown):
    lines = markdown.split('\n')
    res = []
    list_mode = False

    for line in lines:
        if line[0] == "*":
            if not list_mode:
                res.append("<ul>")
            list_mode = True
            res.append("<li>")
            line = line[2:]
        elif list_mode:
            list_mode = False
            res.append("</ul>")

        line = re.sub(r"__(.*)__", lambda m: f"<strong>{m.group(1)}</strong>", line)
        line = re.sub(r"_(.*)_", lambda m: f"<em>{m.group(1)}</em>", line)
        line, is_header = re.subn(r"^(#{1,6}) (.*)", lambda m: f"<h{len(m.group(1))}>{m.group(2)}</h{len(m.group(1))}>", line, count=1)

        if not is_header and not list_mode:
            res.append(f"<p>{line}</p>")
        else:
            res.append(line)
        
        if list_mode:
            res.append("</li>")

    if list_mode:
        res.append("</ul>")

    return "".join(res)
