def argument(*args, **kwargs):
    for x in args:
        print(x)

    for x in kwargs:
        print(x)
        print(kwargs[x])


argument(first="first", second="second")
