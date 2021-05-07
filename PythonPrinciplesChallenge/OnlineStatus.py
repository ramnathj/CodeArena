def online_count(statuses):
    return len(list(filter(lambda x: x == "online", statuses.values())))


statuses = {
    "Alice": "online",
    "Bob": "offline",
    "Eve": "online",
}

print(online_count(statuses))
