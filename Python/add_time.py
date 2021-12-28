dayofweek = ("monday", "tuesday", "wednesday",
             "thursday", "friday", "saturday", "sunday")


class Time:
    def __init__(self, time):
        if len(time.split()) > 1:
            self.zone = time.split()[1]
        else:
            self.zone = ""
        self.time = time
        self.hours = int(time.split()[0].split(":")[0])
        self.minutes = int(time.split()[0].split(":")[1])

    def gettotalminutes(self):
        return self.hours * 60 + self.minutes

    def gethours(self):
        return self.hours

    def getminutes(self):
        return self.minutes

    def gettimestr(self):
        return str(self.hours) + ":" + formatnumber(self.minutes)


def isInZoneRange(start, duration):
    return (start.gettotalminutes() + duration.gettotalminutes()) < 12*60


def isIndayRange(start, duration):
    return (start.gettotalminutes() + duration.gettotalminutes()) < 2*12*60


def formatnumber(nmber):
    if nmber < 10:
        return "0" + str(nmber)
    else:
        return str(nmber)


def determineDay(start_day, numberofdays):
    start_day = (start_day).lower()
    actualdayPos = 0
    newDayPos = 0
    newDay = ""

    for x in range(len(dayofweek)):
        if dayofweek[x] == start_day:
            actualdayPos = x + 1

    if actualdayPos + numberofdays <= 7:
        newDayPos = numberofdays + actualdayPos
        # return dayofweek[numberofdays + actualdayPos]
    else:
        newDayPos = (numberofdays + actualdayPos) % 7

    newDay = (dayofweek[newDayPos - 1]).title()
    return newDay


def add_time(start, duration, day=""):
    new_time = ""
    new_minutes = ""
    new_hours = ""
    new_zone = ""

    start_day = day
    new_day = ""
    days_later = ""

    # daytotalminutes = 24*60
    # resulttime = ""
    # theday = ""
    # if the total from the start time and the endtime is less than 12:00
    # -> we are still in the same day and zone so we can just add the minutes
    # to minutes and seconds to seconds

    # add the duration to the time and compare with 12*60*60
    Start = Time(start)
    Duration = Time(duration)

    totalminutes = Start.gettotalminutes() + Duration.gettotalminutes()
    numberofchange = int(totalminutes / (12*60))

    # Determine new minutres
    minutes = totalminutes % 60
    new_minutes = minutes

    if totalminutes < 12*60:
        new_hours = int(totalminutes / 60)
        new_minutes = totalminutes % 60
        if start_day != "":
            new_day += ", " + start_day

        new_zone = " " + Start.zone

        # new_time = Start.gettimestr() + Start.zone + day
    elif totalminutes < 24*60:
        new_minutes = totalminutes % 60
        new_hours = int(totalminutes / 60) % 12
        if new_hours == 0:
            new_hours = 12
        # AM
        if Start.zone == "AM":
            # nextday
            new_zone = " PM"
            if start_day != "":
                new_day = Start.determineDay(Start, 1)
                print(new_day)
        # PM
        if Start.zone == "PM":
            new_zone = " AM"
            new_day = " (next day)"
    else:
        numberofchange = int(totalminutes / (12*60))
        new_minutes = totalminutes % 60
        new_hours = int(totalminutes / 60) % 12
        if new_hours == 0:
            new_hours = 12

        if numberofchange == 2:
            # same zone
            if start_day != "":
                new_day += ", " + determineDay(start_day, 1)

            new_zone = " " + Start.zone
            new_day += " (next day)"
        else:
            # numberofchange if inpair
            # new zone
            if Start.zone == "AM":
                new_zone = " PM"
            else:
                new_zone = " AM"

            # determine the number total of days
            numberOfDays = round(totalminutes / (24*60))
            print("Number total of days : %d" % numberOfDays)

            if start_day != "":
                new_day += ", " + determineDay(start_day, numberOfDays)

            new_day += " (" + str(numberOfDays) + " days later)"

    if new_minutes < 10:
        new_minutes = "0" + str(new_minutes)
    else:
        new_minutes = str(new_minutes)

    new_time = '{}:{}{}{}{}'.format(
        new_hours, new_minutes, new_zone, new_day, days_later)
    return new_time


print(add_time("11:59 PM", "24:05"))
