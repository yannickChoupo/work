
def arithmetic_arranger(problems, enable=False):

    if len(problems) > 5:
        return "Error: Too many problems."

    firstline = ""
    secondline = ""
    line = ""
    result_line = ""
    result = ""

    for x in range(len(problems)):
        problem = problems[x]
        blockwidth = 0
        splited = problem.split()
        operand1 = splited[0]
        operand2 = splited[2]
        operator = splited[1]

        # retur error if there are any not digit chareacter in the strings
        if operand1.isdigit() != True or operand2.isdigit() != True:
            result = "Error: Numbers must only contain digits."
            return result

        # return error if the operation in not an addition or a substraction
        if operator not in "+-":
            result = "Error: Operator must be '+' or '-'."
            return result

        # return an error if there are more than 5 digit in any operand
        if len(operand1) >= 5 or len(operand2) >= 5:
            result = "Error: Numbers cannot be more than four digits."
            return result

        # determine the length of the longuest operand
        if len(operand2) > len(operand1):
            blockwidth = len(operand2)
        else:
            blockwidth = len(operand1)

        # format each operand depending on the length of the longuest string
        operand1 = '{0:>{1}s}'.format(operand1, blockwidth)
        operand2 = '{0:>{1}s}'.format(operand2, blockwidth)

        # format each line

        if operator == "+":
            result = int(operand1) + int(operand2)
        else:
            result = int(operand1) - int(operand2)

        if x < len(problems) - 1:
            space = "    "
            firstline = firstline + "  " + operand1 + space
            secondline = secondline + operator + " " + operand2 + space
            line += '{0:->{1}s}'.format("", blockwidth + 2) + space
            if enable == True:
                result_line += '{0:>{1}d}'.format(result,
                                                  blockwidth + 2) + space

        else:
            space = '\n'
            firstline = firstline + "  " + operand1 + space
            secondline = secondline + operator + " " + operand2 + space
            if enable == False:
                line += '{0:->{1}s}'.format("", blockwidth + 2)
            else:
                line += '{0:->{1}s}'.format("", blockwidth + 2) + '\n'
                result_line += '{0:>{1}d}'.format(result, blockwidth + 2)

    result = firstline + secondline + line + result_line
    return result


print(arithmetic_arranger(['32 - 698', '1 - 3801',
      '45 + 43', '123 + 49', '988 + 40'], True))
