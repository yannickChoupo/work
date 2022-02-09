class Category:
    def __init__(self, name):
        self.ledger = []
        self.name = name

    def deposit(self, amount, description=""):
        self.ledger.append({"amount": amount, "description": description})

    def withdraw(self, amount, description=""):
        if amount > 0:
            amount *= (-1)

        enoughFund = self.check_funds(amount)
        if enoughFund:
            self.ledger.append({"amount": amount, "description": description})
            return True
        else:
            return False

    def get_balance(self):
        curBalance = 0
        for idx in range(len(self.ledger)):
            curBalance += self.ledger[idx]["amount"]

        return curBalance

    def get_draw(self):
        totaldraw = 0
        for idx in range(len(self.ledger)):
            amount = self.ledger[idx]["amount"]
            if amount < 0:
                amount *= (-1)
                totaldraw += amount
        return totaldraw

    def transfer(self, amount, otherBudget):

        enoughFund = self.check_funds(amount)
        if enoughFund:
            drawDescription = "Transfer to " + otherBudget.name
            self.withdraw(amount, drawDescription)
            depositDescription = "Transfer from " + self.name
            otherBudget.deposit(amount, depositDescription)
            return True
        else:
            return False

    def check_funds(self, amount):
        if amount < 0:
            amount *= (-1)
        if self.get_balance() < amount:
            return False
        else:
            return True

    def __str__(self):
        lines = '{:*^30s}\n'.format(self.name)

        for idx in range(len(self.ledger)):
            amount = self.ledger[idx]["amount"]
            description = self.ledger[idx]["description"]
            if len(description) > 23:
                description = description[:23]

            lines += '{:23s}{:>7.2f}\n'.format(description, amount)

        lines += 'Total: {}'.format(self.get_balance())

        return lines


def myround(x, base=5):
    return base * round(x/base)


def create_spend_chart(categories):
    deposit = categories[0].ledger[0]["amount"]
    print("DEPOSIT : %f" % deposit)
    # print 10 lines with x|_
    # for each if there is categorie in the range of the actual percentage
    # - get categorie positions
    # - add "o" at those position
    percentages = list()
    line = "Percentage spent by category\n"

    totaldraws = 0
    for categorie in categories:
        totaldraws += round(categorie.get_draw())

    print("TOTAL DRAWS : %f" % totaldraws)
    for categorie in categories:
        print(categorie)

        draw = categorie.get_draw()
        print("Total for {}".format(categorie.name))
        print("DRAW %f" % draw)

        percentage = (draw / totaldraws) * 100
        #percentage = 10 * round(percentage / 10)

        print("categorie name : %s" % categorie.name)

        percentages.append([categorie.name, percentage])
        print("Percentage : %f" % percentage)

    #percentages.sort(reverse = True)

    for percent in range(100, -10, -10):
        line += "{:>3s}|".format(str(percent))
        for idx in range(len(percentages)):
            percentage = percentages[idx][1]
            if percentage > percent:
                line += '{:^3s}'.format('o')
            else:
                line += "   "

        line += ' \n'

    line += '    {0:->{1}s}\n'.format("", (len(percentages)*3) + 1)

    # position labels
    # determine the longuest key
    longuestKey = 0

    for categorie in categories:
        print(categorie.name)
        length = len(categorie.name)
        if length > longuestKey:
            longuestKey = length

    print("Longuest key : %d" % longuestKey)

    for charPos in range(longuestKey):
        line += "{:^4s}".format(" ")
        for categorie in categories:
            key = categorie.name
            if charPos <= (len(key) - 1):
                char = key[charPos]
            else:
                char = "{:^3s}".format(" ")

            #print("key len : %d" % len(key))
            #print("char pos : %d" % charPos)
            line += '{:^3s}'.format(char)

        if charPos == (longuestKey - 1):
            line += ' '
        else:
            line += ' \n'

    return line
